#include "Utils.h"

std::map<CHAR*, DWORD, cmp_str> processes;

CHAR* ToCHAR(System::String^ str)
{
	CHAR* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
	return str2;
}

WCHAR* ToWCHAR(System::String^ str)
{
	WCHAR* str2 = (WCHAR*)(void*)Marshal::StringToHGlobalAnsi(str);
	return str2;
}

std::wstring ToWstring(System::String^ str) {
	return msclr::interop::marshal_as<std::wstring>(str);
}