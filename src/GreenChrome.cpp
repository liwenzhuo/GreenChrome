#define UNICODE
#define _UNICODE

#include "GreenChrome.h"

DWORD WinMainBak;

void GreenChrome()
{
	//exe全路径
	wchar_t fullPath[MAX_PATH];
	GetModuleFileName(NULL, fullPath, MAX_PATH);

	//exe所在路径
	wchar_t exePath[MAX_PATH];
	wcscpy(exePath, fullPath);
	PathRemoveFileSpec(exePath);

	//ini路径
	wchar_t iniPath[MAX_PATH];
	wcscpy(iniPath, exePath);
	wcscat(iniPath, L"\\GreenChrome.ini");

	// 生成默认ini文件
	if(!PathFileExists(iniPath))
	{
		FILE *fp = _wfopen(iniPath, L"wb");
		if(fp)
		{
			fwrite(DefaultConfig, sizeof(DefaultConfig), 1, fp);
			fclose(fp);
		}
	}

	//自动给任务栏pin的快捷方式加上只读属性
	AutoLockLnk(fullPath);

	//构造命令行
	wchar_t *command = GetCommandLine();

	wchar_t parentPath[MAX_PATH];
	if(GetParentPath(parentPath) && _wcsicmp(parentPath, fullPath)!=0) //父进程不是Chrome
	{
		wchar_t *MyCommandLine = (wchar_t *)malloc(1024*20);
		int i;
		int nArgs;
		LPWSTR *szArglist = CommandLineToArgvW(command, &nArgs);
		for(i=0; i<nArgs; i++)
		{
			if(i==0) //在进程路径后面追加参数
			{
				wcscpy(MyCommandLine, L"\"");
				wcscat(MyCommandLine, szArglist[i]);
				wcscat(MyCommandLine, L"\"");

				wchar_t *AddList = (wchar_t *)malloc(1024*20);
				wchar_t *temp = (wchar_t *)malloc(1024*20);
				int AddListLen;
				AddListLen = GetPrivateProfileSection(L"追加参数", AddList, 1024*20, iniPath);

				StringSplit CommandList(AddList,0,AddListLen);
				for(int j=0;j<CommandList.GetCount();j++)
				{
					StringSplit add_cmd(CommandList.GetIndex(j),'=');
					if(add_cmd.GetCount()==2) // xxx=bbb
					{
						if( !wcsstr(command,add_cmd.GetIndex(0)) )
						{
							wcscat(MyCommandLine, L" ");
							wcscat(MyCommandLine, add_cmd.GetIndex(0));
							wcscat(MyCommandLine, L"=");

							ExpandEnvironmentStrings(add_cmd.GetIndex(1), temp, 1024*20);
							wchar_t *_temp = replace(temp, L"%app%", exePath);
							if(wcschr(_temp,' ') && _temp[0]!='\"')
							{
								wcscat(MyCommandLine, L"\"");
								wcscat(MyCommandLine, _temp);
								wcscat(MyCommandLine, L"\"");
							}
							else
							{
								wcscat(MyCommandLine, _temp);
							}
							free(_temp);
						}
					}
					else //不含等号  xxxxx
					{
						if( !wcsstr(command,CommandList.GetIndex(j)) )
						{
							wcscat(MyCommandLine, L" ");
							if(wcschr(CommandList.GetIndex(j),' ') && CommandList.GetIndex(j)[0]!='\"')
							{
								wcscat(MyCommandLine, L"\"");
								wcscat(MyCommandLine, CommandList.GetIndex(j));
								wcscat(MyCommandLine, L"\"");

							}
							else
							{
								wcscat(MyCommandLine, CommandList.GetIndex(j));
							}
						}
					}
				}
				free(temp);
				free(AddList);
			}
			else
			{
				// 原样拼接参数
				wcscat(MyCommandLine, L" \"");
				wcscat(MyCommandLine, szArglist[i]);
				wcscat(MyCommandLine, L"\"");
			}
		}
		LocalFree(szArglist);

		//启动进程
		STARTUPINFO si = {0};
		PROCESS_INFORMATION pi = {0};
		si.cb = sizeof(STARTUPINFO);
		//GetStartupInfo(&si);

		//OutputDebugStringW(MyCommandLine);

		if (CreateProcess(fullPath, MyCommandLine, NULL, NULL, false, CREATE_NEW_CONSOLE | CREATE_UNICODE_ENVIRONMENT | CREATE_DEFAULT_ERROR_MODE, NULL, 0, &si, &pi))
		{
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			ExitProcess(NULL);
		}
	}

	__asm call WinMainBak
}

EXTERNC BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID pv)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		//保持系统dll原有功能
		LoadSysDll();

		//获取程序入口点
		MODULEINFO mi;
		GetModuleInformation(GetCurrentProcess(), GetModuleHandle(NULL), &mi, sizeof(MODULEINFO));

		//检查入口点是否是E8
		BYTE read[5];
		ReadProcessMemory(GetCurrentProcess() ,(LPVOID)mi.EntryPoint, read, sizeof(read), 0);
		if(read[0]==0xE8)
		{
			//备份入口点
			WinMainBak = (DWORD)mi.EntryPoint + *(DWORD *)&read[1] + 5;

			BYTE JmpCode[] =
			{
				0xE8,0x90,0x90,0x90,0x90,	//call xxxx
			};

			*(DWORD *)&JmpCode[1] = (DWORD)GreenChrome - (DWORD)mi.EntryPoint - 5;

			//在入口处加入跳转
			::WriteProcessMemory(GetCurrentProcess(), (LPVOID)mi.EntryPoint, &JmpCode, sizeof(JmpCode),NULL);
		}
	}
	return TRUE;
}
