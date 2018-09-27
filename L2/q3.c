/* Answer Question 3:
 * Another way to make the parent wait is to
 * use the sleep functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
		int rc = fork();

		if (rc < 0) {
			//fork failed; exit
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if (rc == 0) {
			//Child (new process)
			printf("Hello\n");
		} else {
			//Parent (original process)
			sleep(1);
			printf("Goodbye\n");
		}
		return 0;
}


