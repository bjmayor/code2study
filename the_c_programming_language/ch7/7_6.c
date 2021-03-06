#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1024

int main(int argc, char **argv)
{
    char *fname1;
    char *fname2;
    FILE *fp1;
    FILE *fp2;
    char line1[MAXLINE];
    char line2[MAXLINE];

    if (argc != 3)
    {
        printf("error , usage : ./%s filename1 filename2", argv[0]);
        return 1;
    }
    else
    {
        if ((fp1 = fopen(argv[1],"r"))==NULL)
        {
            printf("can't open %s\n",argv[1]);
            return 2;
        }
        if ((fp2 = fopen(argv[2],"r"))==NULL)
        {
            printf("can't open %s\n",argv[2]);
            return 3;
        }
        while(!feof(fp1) && !feof(fp2))
        {
            fgets(line1,MAXLINE,fp1);
            fgets(line2,MAXLINE,fp2);
            if (strcmp(line1,line2) !=0)
            {
                printf("the first not equal line:\n%s%s\n",line1,line2);
                break;
            }
        }

        return 0;
    }
}
