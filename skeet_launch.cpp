
//                         _         _                   _                _        ______ 
//                        | |       | |                 | |              | |       | ___ \
//   _ __ ___    __ _   __| |  ___  | |__   _   _   ___ | | __ ___   ___ | |_  ___ | |_/ /
//  | '_ ` _ \  / _` | / _` | / _ \ | '_ \ | | | | / __|| |/ // _ \ / _ \| __|/ _ \|    / 
//  | | | | | || (_| || (_| ||  __/ | |_) || |_| | \__ \|   <|  __/|  __/| |_|  __/| |\ \ 
//  |_| |_| |_| \__,_| \__,_| \___| |_.__/  \__, | |___/|_|\_\\___| \___| \__|\___|\_| \_|
//                                           __/ |                                        
//                                          |___/                                          

#include "stdafx.h"
#include <iostream>
#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>
//#include <WinBase.h>

using namespace std;
int p=3;

int _tmain(int argc, _TCHAR* argv[])
{
  cout << "######################" << endl;
  cout << "######################" << endl;
  cout << "SKEETERS DAYZ LAUNCHER" << endl;
  cout << "######################" << endl;
  cout << "######################" << endl;
  cout << "Press ENTER to close program" << endl;
  cout << "Type p to load dayZ + The Hunters Den server" << endl;
  cin >> p; 
    
	if (p)
		WinExec("c:\program files (x86)\steam\steamapps\common\arma 2 operation arrowhead", 10);
	
/*	
const bool Hkey = true;
	//Hkey will be used to launch DayZ by pressing H
		if (Hkey)
			BOOL WINAPI CreateProcess(
  _In_opt_     LPCTSTR lpApplicationName,
  _Inout_opt_  LPTSTR lpCommandLine,
  //_In_opt_     LPSECURITY_ATTRIBUTES lpProcessAttributes,
  //_In_opt_     LPSECURITY_ATTRIBUTES lpThreadAttributes,
  //_In_         BOOL bInheritHandles,
  //_In_         DWORD dwCreationFlags,
  //_In_opt_     LPVOID lpEnvironment,
  //_In_opt_     LPCTSTR lpCurrentDirectory,
  //_In_         LPSTARTUPINFO lpStartupInfo,
  //_Out_        LPPROCESS_INFORMATION lpProcessInformation
);
	
	LPTSTR szCmdline = _tcsdup(TEXT("c:\program files (x86)\steam\steamapps\common\arma 2 operation arrowhead"));
	CreateProcess(NULL, szCmdline );
*/

  char Hkey = 56; //spacebar

	if (Hkey){
	
		WinExec("c:\program files (x86)\steam\steamapps\common\arma 2 operation arrowhead", 10);
	}

	cin.get();
	return 0;
}

