#include "main.h"

/**
 * is_numeric - checks if the input string is a valid number or not
 * @str: string that will be converted to an integer
 * Return: 1 if it's numeric, 0 otherwise
 */
int is_numeric(const char *str)
{
	int i = 0;
	int hasDigits = 0;  /* Added a flag to track if any digits are found */

	if (str == NULL || *str == '\0')
		return (0);

	if (str[i] == '-')
		i++; /* Allow negative numbers */

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			hasDigits = 1; /* Set the flag if a digit is found */
		else
			return (0); /* Non-numeric character found */
		i++;
	}

	return (hasDigits); /* Return 1 if at least one digit is found, else 0 */
}

