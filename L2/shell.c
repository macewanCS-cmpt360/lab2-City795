/* Question Shell.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{

	char *cmdline;
	char *token = NULL;
	int i, rc;
	char *args[10];
	int run_background = 0;

	cmdline = calloc(1, 1024);
	i = 0;

	printf("prompt> ");
	fgets(cmdline, 1024, stdin);
	fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);

	token = strtok(cmdline, "\n ");
	while (token != NULL) {
		//printf("%s\n", token);
		args[i++] = strdup(token);
		token = strtok(NULL, "\n ");
	}

	if (strcmp(args[i-1], "&") == 0) {
		args[i-1] = NULL;
		run_background = 1;
	}

	rc = fork();
	if (rc < 0) {
		//fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		//Child (new process)
		execvp(args[0], args);
	} else {
		//Parent (original process)
		if (run_background == 0)
			wait(NULL);
	}

	//args[i] = NULL;

	free(cmdline);
	return 0;

}
