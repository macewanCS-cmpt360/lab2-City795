/* Question 2 Answer:
 * Both the parent and the child access the same file descriptor because child
 * is a duplicate of parent.
 *
 * When both are writing to the output the parent will write to the file first
 * and then the child will write it's message right after without erasing the
 * parent's message.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
		int newFile =
			open("./q2.output", O_CREAT|O_WRONLY|O_TRUNC, 0700);
		int rc = fork();

		if (rc < 0) {
			//fork failed; exit
			fprintf(stderr, "fork failed\n");
				exit(1);
		} else if (rc == 0) {
			//Child
			printf("Child file descriptor = %d\n", newFile);

			char *child_msg = "Child Message\n";

			write(newFile, child_msg, strlen(child_msg));

		} else {
			//Parent (original process)
			printf
			("Parent file descriptor = %d\n", newFile);

			char *parent_msg = "Parent Message\n";

			write(newFile, parent_msg, strlen(parent_msg));
		}
		return 0;
}
