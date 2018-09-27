#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
		int x = 100;
		int rc = fork();

		if (rc < 0) {
			//fork failed; exit
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if (rc == 0) {
			//Child (new process)
			printf("Hello");
		} else {
			//Parent (original process)
			sleep(1);
			printf("Goodbye");
		}
		return 0;
}