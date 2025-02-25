
/**
 * puts2 - Prints every other character of a string, starting with the first.
 * @str: Pointer to the string.
 */
void puts2(char *str)
{
	int i = 0;
	if (!str || str[0] == '\0')
	{
		_putchar('\n');
		return;
	}

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i += 2;
	}

	_putchar('\n');
}
