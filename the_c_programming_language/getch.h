#ifndef GETCH_H

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);

#endif
