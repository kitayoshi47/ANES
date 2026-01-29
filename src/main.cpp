#include "anes.h"

int main(int argc, char* argv[])
{
	Canes anes;

	anes.Initialize();
	anes.Run();
	anes.Finalize();

	return 0;
}
