#include "anes.h"
#include "utility/console.h"
#include "utility/utility.h"

static CConsole* console = NULL;

Canes::Canes()
{
    console = new CConsole();
}

Canes::~Canes()
{
    SafeDelete(console);
}

void Canes::Initialize()
{
    printf("ANES: Initialize\n");

    if (console) {
        CConsole::InitDesc desc;
        console->Initialize(desc);
    }
}

void Canes::Run()
{
    printf("ANES: Run\n");

    while (console->Run()) {
        ;
    }
}

void Canes::Finalize()
{
    printf("ANES: Finalize\n");

    if (console) {
        console->Finalize();
    }
}
