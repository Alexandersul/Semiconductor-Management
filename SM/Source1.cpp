#include <stdafx.h>
#include "Windows.h"
#include "time.h"
#include "profileapi.h"
#include "psapi.h"
#include "sysinfoapi.h"
#include <iostream>
#include <stdint.h>
using namespace std;

//nu am reusit sa rulez/compilez programul dintr-un motiv straniu nu imi apare butonul pentru functia asta
//sper ca e ok si asa

int main()
{
    LPSYSTEM_INFO lpSystemInfo;
    PPERFORMANCE_INFORMATION pPerformanceInformation;
    DWORD cb;
    LPMEMORYSTATUSEX lpBuffer;

    GetSystemInfo(lpSystemInfo);
    GetPerformanceInfo(pPerformanceInformation, cb);
    GlobalMemoryStatusEx(lpBuffer);

    cout << lpSystemInfo->dwPageSize << '\n';
    //1
    cout << lpSystemInfo->lpMaximumApplicationAddress << '\n';
    cout << lpSystemInfo->lpMinimumApplicationAddress << '\n';
    //2
    cout << pPerformanceInformation->PhysicalTotal << '\n';
    cout << pPerformanceInformation->PhysicalAvailable << '\n';
    //3
    //KerelPaged+KernelUnPaged= kernel total
    cout << pPerformanceInformation->KernelTotal * pPerformanceInformation->PageSize;
    //nu stiu unitatea de maura
    //4
    cout << lpBuffer->ullTotalVirtual << '\n';
    cout << lpBuffer->ullAvailVirtual << '\n';
    //fiecare proces are aceeasi dimensiune
    //5
    cout << lpBuffer->dwMemoryLoad << '\n';
    //6

}
