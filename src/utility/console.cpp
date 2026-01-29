#include <Windows.h>
#include "console.h"

CConsole::CConsole() : test(0)
{
    //AllocConsole();
}

CConsole::~CConsole()
{
    //FreeConsole();
}
