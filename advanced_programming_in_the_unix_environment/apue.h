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

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define DIR_MODE (FILE_MODE | S_IXUSER | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int);

#if defined(SIG_IGN) && !defined(SIG_ERR)
#define SIG_ERR ((Sigfunc *)-1)
#endif

#define min(a,b) ((a)<(b) ? (a) : (b))
#define max(a,b) ((a)>(b) ? (a) : (b))

char *path_alloc(int*);
long open_max(void);
void clr_fl(int, int);
void set_fl(int, int);
void pr_exit(int);
void pr_mask(const char *);
Sigfunc *signal_intr(int, Sigfunc*);

int tty_cbreak(int);
int tty_raw(int);
int tty_reset(int);
void tty_atextit(void);

#ifdef ECHO 
struct termino *tty_termios(void);
#endif

void sleep_us(unsigned int);
ssize_t readn(int ,void *, size_t);
ssize_t writen(int, const void *, size_t);
void daemonize(const char *);

int s_pipe(int *);
int recv_fd(int , ssize_t (*func)(int, const void *, size_t));
int send_fd(int ,int);
int send_err(int, int, const char *);
int serv_listen(const char*);
int serv_accept(int ,uid_t *);
int cli_conn(const char *);
int buf_args(char *, int (*func)(int, char**));

int ptym_open(char *, int);
int ptys_open(char *);

#ifdef TIOCGWINSZ
pid_t pty_fork(int *, char *, int ,const struct termios *, const struct winsize *);
#endif

#endif /* _APUE_H */

