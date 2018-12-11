#include "utils_methods.h"

char* cut_first_letter(char *string)
{
	char* str = NULL;
	str = memmove(string, string + 1, strlen(string));

	return str;
}

static void reverse(char* string)
{

	int inputLenght = strlen(string);

	if (inputLenght >= 256)
	{
		printf("%s", "Input string is too long");
		return;
	}

	char out[256] = string;

	for (int i = 0; i < inputLenght; i++)
	{
		out[inputLenght - 1 - i] = string[i];
	}
	printf("%s", out);
}