#include <stdio.h>
int strend(char *s, char *t);

main()
{
    char *s1 = "testbegin";
    char *t1 = "begin";

    char *s2 = "testbegintest";
    char *t2 = "begin";
    printf("%s %s strend %d\n",s1,t1,strend(s1,t1));
    printf("%s %s strend %d\n",s2,t2,strend(s2,t2));
}
int strend(char *s, char *t)
{
    for(int i=0;*(s+i);i++)
    {
        if ( *(s+i) == *t)
        {
            int j=0;
            while(*(s+j+i)!='\0' && *(t+j)!='\0' && *(s+j+i) == *(t+j)) {j++;}
            return  (*(s+j+i) == '\0' && *(t+j) == '\0') ? 1 : 0;
        }
    }
    return 0;
}