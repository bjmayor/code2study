#ifndef _APUE_H
#define _APUE_H

#define _XOPEN_SOURCE 600

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/termios.h>

#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#define MAXLINE 4096

#define FILE_MODE (S_IRUSER | S_IWUSER | S_IRGRP | S_IROTH)
#endif /* _APUE_H */


