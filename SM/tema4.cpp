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
    unsigned int a = 0;
    __asm {mov eax, a} //registrul eax ia valorea 0
    unsigned int b, c, e, f, g, h, i;
    __asm {
        cpuid
        mov a, ebx
        mov b, edx
        mov c, ecx
    }
    string d;
    d = a;
    cout << d;
    d = b;
    cout << d;
    d = c;
    cout << d;
    a = 1;
    __asm {mov eax, a} //registrul eax ia valorea 1
    __asm {
        cpuid
        mov e, eax
        mov g, ebx
        mov i, edx
    }
    h = e;
    e = e >> 2;
    f = 5;
    f = e & f;
    cout << "Model Number: ";
    cout << f << '\n';
    e = e >> 4;
    f = 5;
    f = e & f;
    cout << "Family Code: ";
    cout << f << '\n';
    e = e >> 4;
    f = 3;
    f = e & f;
    cout << "Processor Type: ";
    cout << f << '\n';
    e = e >> 5;
    f = 5;
    f = e & f;
    cout << "Extended Mode: ";
    cout << f << '\n';
    e = e >> 4;
    f = 8;
    f = e & f;
    cout << "Extended Family: ";
    cout << f;
    f = 8;
    f = g & f;
    cout << "Brand ID: ";
    cout << f << '\n';
    //Proprietati:
    if (i % 2 == 0)
        cout << "Floting-point Unit On-Chip: FALSE" << '\n';
    else
        cout << "Floting-point Unit On-Chip: TRUE" << '\n';
    i = i / 2;
    if (i % 2 == 0)
        cout << "Virtual Mode Extension: FALSE" << '\n';
    else
        cout << "Virtual Mode Extension: TRUE" << '\n';
    i = i / 2;
    if (i % 2 == 0)
        cout << "Debugging Extension: FALSE" << '\n';
    else
        cout << "Debugging Extension: TRUE" << '\n';
    i = i / 2;
    if (i % 2 == 0)
        cout << "Page Size Extension: FALSE" << '\n';
    else
        cout << "Page Size Extension: TRUE" << '\n';
    f = 5;
    f = h & f;
    cout << "Nr procesoare logice:: "
        cout << f;
    f = 8;
    f = g & f; Debugging Extension
        cout << f;
    //Nu situ sigur daca nr de procesoare este EAX[0:4] sau EBX[0:10]
    //le-am afisat pe ambele desii EAX[0:4] pare mai plauzibil
    a = 2;
    __asm {mov eax, a} //registrul eax ia valorea 1
    __asm {
        cpuid
        mov f, eax
    }
    // stiu ca info trebuie luate din eax si ar venii facut ca la proprietati
    // dar nu stiu care ifo trebuie sau cate; nu a fost specificat
    // mi se pare ca ar trebuii sa fac un if pen1tru toate cazurile din 2-7
    // e mult de facut asa ca voi face doar verificarea din tabelul 2-6
    f = f >> 30;
    if (f == 0)
        cout << "8-bit descriptors: TRUE";
    else
        cout << "Reserved: TRUE";
}