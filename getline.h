#include <stdio.h>
#include <stdlib.h>

extern char *getline(FILE *stream) {
	int c, i = 0, linebufsz = 0, growby = 80;
	char *linebuf = NULL;

	while (1) {
		c = fgetc(stream);
		if (c == EOF) break;
		while (i > linebufsz - 2)
			linebuf = (char*)realloc(linebuf, linebufsz += growby);
		linebuf[i++] = (char)c;
		if (c == '\n' || c == '\0') break;
	}
	if (i == 0) return NULL;
	linebuf[i] = 0;
	return linebuf;
}
