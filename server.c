#include <door.h>
#include <err.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void
callback(void *cookie, char *args, size_t argc, door_desc_t* descriptors, uint_t ndescriptors)
{
	printf("Callback got called!");
	
	door_return(NULL, 0, NULL, 0);
}

int
main(void)
{
	int door, fd, attachment;
	char *path = "test.door";

	if((door = door_create(&callback, NULL, 0)) == -1)
		err(1, "Could not create door.");

	if((fd = open(path, O_RDWR|O_CREAT|O_EXCL, 0400)) < 0)
		err(1, "Could not create file descriptor");

	if((attachment = fattach(door, path)) == -1)
		err(1, "Could not attach door");

	sleep(60);

	return 0;
}
