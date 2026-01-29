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

bool Canes::Run()
{
    printf("ANES: Run\n");

    if (0)
    {
        return false;
    }

    return true;
}
