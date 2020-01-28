#include <stdlib.h>
#include <string.h>

/* concatenate char arrays together */
char* concat(const char* string1, const char* string2) {
	size_t len = strlen(string1) + strlen(string2) + 1; /* size of both strings plus null terminator */
	char* dest = (char*)malloc(len);
	strcpy(dest, string1);
	strcat(dest, string2);
	return dest;
}
