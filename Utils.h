#pragma once
#include <msclr/marshal_windows.h>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <map>
#include <string>
#include <vector>

using namespace System::Runtime::InteropServices;

struct cmp_str
{
	bool operator()(char const* a, char const* b) const
	{
		return std::strcmp(a, b) < 0;
	}
};

extern std::map<CHAR*, DWORD, cmp_str> processes;

CHAR* ToCHAR(System::String^ str);
WCHAR* ToWCHAR(System::String^ str);
std::wstring ToWstring(System::String^ str);