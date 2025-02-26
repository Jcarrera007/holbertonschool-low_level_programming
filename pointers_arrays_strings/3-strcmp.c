#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: 0 if strings are equal, positive if s1 > s2, negative if s1 < s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]); /* difference found, return immediately */
		i++;
	}

	/* Handle the case where strings differ in length */
	return (s1[i] - s2[i]);
}

