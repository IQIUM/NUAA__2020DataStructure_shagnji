/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-26 11:07:00
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 11:07:12
 * @FilePath       : \Exercise6\test.cpp
 */
#include <windows.h>
#include <stdio.h>
#include <psapi.h>

// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1
bool AdjustPurview()
{
    TOKEN_PRIVILEGES TokenPrivileges;
    BOOL bRet;
    HANDLE hToken;

    LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &TokenPrivileges.Privileges[0].Luid);
    OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);

    TokenPrivileges.PrivilegeCount = 1;
    TokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    bRet = AdjustTokenPrivileges(hToken, FALSE, &TokenPrivileges, 0, NULL, NULL);

    CloseHandle(hToken);
    return bRet == TRUE;
}
void PrintMemoryInfo(DWORD processID)
{
    TCHAR szProcessName[MAX_PATH];

    AdjustPurview();
    //取得进程的句柄

    HANDLE hProcess;
    PROCESS_MEMORY_COUNTERS pmc;

    /*printf("\nProcess ID: %u\n", processID);*/

    // Print information about the memory usage of the process.

    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
                               PROCESS_VM_READ,
                           FALSE, processID);
    if (NULL == hProcess)
        return;

    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
    {
        GetModuleFileNameEx(hProcess, NULL, szProcessName, MAX_PATH);
        printf(" %-20d%-20s", processID, szProcessName);
        //printf("\t峰值内存使用: %d\n",
        //    pmc.PeakWorkingSetSize/1024);
        printf("\t内存使用: %dMB\n", pmc.WorkingSetSize / (1024 * 1024));

        //printf("\t虚拟内存使用: %d\n", pmc.PagefileUsage / 1024);
        //printf("\t峰值虚拟内存使用: %d\n",
        //    pmc.PeakPagefileUsage / 1024);
    }

    CloseHandle(hProcess);
}

int main(void)
{
    // Get the list of process identifiers.

    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
    {
        return 1;
    }

    // Calculate how many process identifiers were returned.

    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the memory usage for each process

    for (i = 0; i < cProcesses; i++)
    {
        PrintMemoryInfo(aProcesses[i]);
    }

    return 0;
}