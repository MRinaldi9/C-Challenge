#include "utils_methods.h"

char* cut_first_letter(char *string)
{
	char* str = NULL;
	str = memmove(string, string + 1, strlen(string));

	return str;
}