#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define PERMS 0666

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
typedef struct {
    unsigned int _READ : 1;
    unsigned int _WRITE : 1;
    unsigned int _UNBUF : 1;
    unsigned int _EOF : 1;
    unsigned int _ERR : 1;
} _mode;

typedef struct _iobuf {
    int cnt;//剩余的字符数
    char *ptr;//下一个字符的位置
    char *base;//缓冲区的位置
    _mode flag;//文件访问模式
    int fd;//文件描述符
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])


int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) (((p)->flag._EOF) ==1)
#define ferror(p) (((p)->flag._ERR)==1)
#define fileno(p) ((p)->fd)
#define getc(p) (--(p)->cnt >=0 \
                 ? (unsigned char ) *(p)->ptr++ : _fillbuf(p))
#define putc(p) (--(p)->cnt >=0 \
                 ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode !='r' && *mode !='w' && *mode !='a')
    {
        return NULL;
    }

    for (fp = _iob; fp < _iob+OPEN_MAX; fp++)
    {
        if (fp->flag._READ==1 || fp->flag._WRITE==1 )
        {
            break;
        }
    }

    if (fp >= _iob+OPEN_MAX)
    {
        return NULL;
    }

    if (*mode == 'w')
    {
        fd = create(name, PERMS);
    }
    else if(*mode == 'a')
    {
        if ((fd = open(name, O_WRONLY,0)) == -1)
        {
            fd = create(name, PERMS);
        }
        lseek(fd, 0L, 2);
    }
    else
    {
        fd = open(name, O_RDONLY, 0);
    }

    if (fd == -1)
    {
        return NULL;
    }

    fp->fd = fd;
    fp->cnt =0 ;
    fp->base = NULL;
    if(*mode == 'r')
    {
        fp->flag._READ = 1;
    }
    else
    {
        fp->flag._WRITE = 1;
    }
    return fp;
}