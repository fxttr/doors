#include <door.h>
#include <stdlib.h>
#include <err.h>
#include <fcntl.h>

int
main(void)
{
	int door, result;
	char *path = "test.door";

	if((door = open(path, O_RDONLY)) == -1)
		err(1, "Could not open door.");

	if((result = door_call(door, NULL)) == -1)
		err(1, "Could not call door.");

	return 0;
}
