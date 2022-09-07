#ifndef _SHELL_H_
#define _shell_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void);

int process(char *buffer, char **argv);
int main(int argc, char *argv[]);
#endif
