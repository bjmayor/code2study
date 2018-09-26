#include <stdio.h>

#define DATAFILE "datafile"

FILE *open_data(void)
{
    FILE *fp;
    char databuf[BUFSIZE];

    if ((fp = fopen(DATAFILE,"r")) == NULL)
    {
        return (NULL);
    }

    if (setvbuf(fp, databuf, _IOLBF) !=0)
    {
        return (NULL);
    }

    return (fp);
}