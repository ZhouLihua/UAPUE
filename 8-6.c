#include <unistd.h>
#include <stdio.h>

static void charatatime(char *);

int main()
{
	pid_t pid;

	if((pid = fork()) < 0)
	{
		printf("Fork error.");
		return -1;
	}

	else if(pid == 0)
	{
		charatatime("output from child.\n");
	}

	else
	{
		charatatime("Output from parent.\n");
	}

	return 0;
}

static void charatatime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout, NULL);

	for(ptr = str; (c = *ptr++) != 0; )
		putc(c,stdout);
}
