#pragma once

#include <string>
#include <windows.h>
#include <map>
#include <comdef.h>

#include "Utils.h"

#define MAX_NAME 256

void InitProcessList() {
	processes.clear();

	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
			HANDLE hToken;
			PTOKEN_USER ptu = NULL;
			OpenProcessToken(hProcess, TOKEN_QUERY, &hToken);

			if (hToken == NULL)
				goto Cleanup;

			DWORD dwLength = 0;

			if (!GetTokenInformation(hToken, TokenUser, (LPVOID)ptu, 0, &dwLength)) {
				if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
					goto Cleanup;

				ptu = (PTOKEN_USER)HeapAlloc(GetProcessHeap(),
					HEAP_ZERO_MEMORY, dwLength);

				if (ptu == NULL)
					goto Cleanup;
			}

			if (!GetTokenInformation(hToken, TokenUser, (LPVOID)ptu, dwLength, &dwLength))
				goto Cleanup;

			DWORD dwSize = MAX_NAME;
			WCHAR lpName[MAX_NAME];
			WCHAR lpDomain[MAX_NAME];
			SID_NAME_USE SidType;
			if (!LookupAccountSid(NULL, ptu->User.Sid, lpName, &dwSize, lpDomain, &dwSize, &SidType)) {
				goto Cleanup;
			}
			else {
				System::String^ processName = gcnew System::String(entry.szExeFile);
				processes[ToCHAR(processName)] = entry.th32ProcessID;
			}

		Cleanup:
			if (ptu != NULL)
				HeapFree(GetProcessHeap(), 0, (LPVOID)ptu);
		}
	}

	CloseHandle(snapshot);
}

DWORD getPIDByName(std::wstring name)
{
	DWORD PID = -1;

	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			std::wstring binaryPath = entry.szExeFile;
			if (binaryPath.find(name) != std::wstring::npos)
			{
				PID = entry.th32ProcessID;
				break;
			}
		}
	}

	CloseHandle(snapshot);
	return PID;
}