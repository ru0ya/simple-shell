#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

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
        size_t i = 0;
        int read;
        pid_t pid;
        char *new_argv[] = {"usr/bin/", NULL};
	int p;

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
                        printf("$");
                        read = getline(&buffer, &i, stdin);
                        if (read == EOF)
                                perror("Error");
			for(p = 0; p < argc; p++)
			{
				printf("this argv[%d]: %s\n", argv[p]);
			}
                        printf(">>>>%s\n", buffer);
                }
        }
        return (0);
}

