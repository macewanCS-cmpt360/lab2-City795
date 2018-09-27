/* Question 1 Answer:
 * Because Fork makes a duplicate of the parent both the parent and child will
 * have the same variable value of 100. If it is changed then they will both
 * continue to have the same value.
 */

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
			printf("Child x = %d\n", x);
		} else {
			//Parent (original process)
			printf("Parent x = %d\n", x);
		}
		return 0;
}
