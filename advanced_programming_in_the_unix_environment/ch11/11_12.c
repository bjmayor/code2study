#include <limits.h>
#include <string.h>

#define MAXSTRINGSZ 4096
static char envbuf[MAXSTRINGSZ];

extern char **environ;//这里有线程安全问题

char *getenv(const char *name)
{
    int i, len;
    for (i=0; environ[i]!=NULL;i++)
    {
        if ((strncmp(name, environ[i],len)==0) && (environ[i][len]=='='))
        {
            strncpy(envbuf, &environ[i][len+1], MAXSTRINGSZ-1);
            return (envbuf);
        }
    }
    return (NULL);
}