#include "anes.h"

int main(int argc, char* argv[])
{
	Canes anes;
	Canes::InitDesc desc;

	anes.Initialize(desc);
	anes.Run();
	anes.Finalize();

	return 0;
}
