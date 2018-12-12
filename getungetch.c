/* getch and ungetch functions */

#include <stdio.h>

#define	BUFSIZE	256

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch:  too many characters\n");
	else
		buf[bufp++] = c;
}

void resetbuf()
{
	bufp = 0;
}
