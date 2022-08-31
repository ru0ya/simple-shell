#include <stdio.h>
#include<unistd.h>
/**
 * main - Entry point
 * Return: Always 0 (success)
 */
int main(void)
{
	float a, b, result;


	printf("Enter num A :");
	scanf("%f\n", &a);
	printf("Enter num B :");
	scanf("%f\n", &b);
	result = a + b;
	printf("Your total is %f\n", result);
	return (0);
}
