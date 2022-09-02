#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 *@argc: number of arguments
 *@argv: string pointer
 *Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;

	size_t i = 1024;
	
	int read;
	pid_t pid;
	char *token, *saveptr1;
	char *new_argv[] = {"usr/bin/ls", NULL};

	pid = fork();

	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		int x = execve(new_argv[0], new_argv, NULL);

		if (x == -1)
		{
			perror("error");
		}
	}
	else
	{
		wait(NULL);
		if (argc == 1)
		{
			while(1)
			{
			printf("$");
			read = getline(&buffer, &i, stdin);
			if (read == EOF)
				perror("Error");
			printf(">>>>%s\n", buffer);
			token = strtok(buffer, saveptr1);
			if (token == NULL )
				break;
			  printf("%s\n", token);
			  
			}
		}
	}
	exit(EXIT_SUCCESS);
}
