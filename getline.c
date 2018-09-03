/* Read a line from a file stream */
#include <stdio.h>
#include <stdlib.h>

extern char *getline(FILE *stream) {
	static const int GROWBY = 80;
	int ch;
	int idx = 0;
	char *linebuf = NULL;
	int linebufsz = 0;

	while (1) {
		ch = fgetc(stream);
		if (ch == EOF)
			break;
		while (idx > linebufsz - 2)
			linebuf = (char*)realloc(linebuf, linebufsz += GROWBY);
		linebuf[idx++] = (char)ch;
		if (ch == '\n' || ch == '\0')
			break;
	}

	if (idx == 0)
		return NULL;

	linebuf[idx] = 0;
	return linebuf;
}
