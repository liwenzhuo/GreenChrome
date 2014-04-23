#ifndef __MAIN_H__
#define __MAIN_H__

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/OPT:NOWIN98")

#define WINVER 0x600
#define _WIN32_IE 0x600

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <shlwapi.h>
#include <shlobj.h>

#include "winmm.h"
#include "StringSplit.h"
#include "DefaultConfig.h"
#include "ModifyLnk.h"
#include "GetParent.h"

#define EXTERNC extern "C"
#define EXPORT EXTERNC __declspec(dllexport) void __cdecl

#pragma comment(lib, "shlwapi.lib")

#endif // __MAIN_H__