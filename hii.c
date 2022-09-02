#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int process(char *buffer, char **argv)
{
        pid_t pid;
        pid = fork();
        if (pid == -1)
                return (-1);
if (pid == 0)
{
int x = execve(buffer, argv, NULL);
if (x == -1)
{
perror("error");
exit(EXIT_FAILURE);
}
execve(buffer, argv, NULL);
}
return (1);
}
/**
main - entry point
*
*@argc: number of arguments
*@argv: string pointer
*Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t i = 1024;
	int status = 1;
	char *str;
	pid_t pid;
	do {
		printf("$ ");
		getline(&buffer, &i, stdin);
		str=strtok(buffer, "\n");
		status = process(str, argv);
		printf("this is %s\n", buffer);
	} while (status);
	return (status);
}

                                    

