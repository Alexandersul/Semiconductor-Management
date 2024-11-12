#include "stdafx.h"
#include "Windows.h"
#include "time.h"
#include "profileapi.h"
#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
	cout << GetSystemInfo() << '\n';
}
