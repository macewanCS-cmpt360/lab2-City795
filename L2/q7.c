/* Answer Question 7
 * If the standard output is closed in the child process the child message
 * will not print out and only the parent message will be shown.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
		int rc = fork();

		if (rc < 0) {
			//fork failed; exit
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if (rc == 0) {
			//Child
			close(STDOUT_FILENO);
			printf("Child text output\n");
		} else {
			//Parent (original process)
			printf("Parent Message\n");
		}
		return 0;
}
