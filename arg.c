#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	/*int i;*/
	char *buffer = NULL;
	size_t n = 0;
	int read;
	while (1)
	{
		printf("$ ");
		read = getline(&buffer, &n, stdin);
		if (read != EOF)
		printf("%d %s\n", argc, buffer);
	}
	return (0);
}
