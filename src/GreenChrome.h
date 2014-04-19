#ifndef __MAIN_H__
#define __MAIN_H__

#define WINVER 0x600
#define _WIN32_IE 0x600

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <shlwapi.h>
#include <Shlobj.h>

#include "winmm.h"
#include "StringSplit.h"
#include "DefaultConfig.h"

#define EXTERNC extern "C"
#define EXPORT EXTERNC __declspec(dllexport) void __cdecl

#pragma comment(lib, "Shlwapi.lib")

#endif // __MAIN_H__