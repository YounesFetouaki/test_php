#include "main.h"
/**
 * rm_whitespace - function that remove leading
 * and trailing whitespace characters from a given string
 * @str: string
 * Return: 1 or 0
 */
int rm_whitespace(char *str)
{
	int len = strlen(str);
	int start = 0;
	int end = len - 1;
	int i;


	while (str[start] == ' ' || str[start] == '\t')
	{
		start++;
	}

	while (end > start && (str[end] == ' ' || str[end] == '\t'))
	{
		end--;
	}


	for (i = 0; i <= end - start; i++)
	{
		str[i] = str[start + i];
	}
	str[i] = '\0';


	return (i == 0);
}
