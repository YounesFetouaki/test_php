#include "main.h"
/**
 * _path - function that constructs the full path of an executable
 *@b: binary
 *@path: default path
 *@fullpath:the full path
 *Return: -
 */
void _path(char *b, char *path, char **fullpath)
{
	if (b[0] == '/')
	{
		*fullpath = malloc(strlen(b) + 1);
		strcpy(*fullpath, b);

	}
	else
	{
		*fullpath = malloc(strlen(path) + strlen(b) + 1);
		strcpy(*fullpath, path);
		strcat(*fullpath, b);

	}
}
