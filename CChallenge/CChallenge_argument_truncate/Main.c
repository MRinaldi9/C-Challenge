#include "utils_methods.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char str[255];
	char* str2;
	printf("Please insert a word: ");
	scanf_s("%255s", &str, _countof(str));
	reverse(str);
	printf("%s", str);
	str2 = cut_first_letter(str);
	printf("%s", str2);
	return 0;
}