#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    struct hostent *ent;
    sethostent(1);
    while((ent = gethostent())!=NULL)
    {
        printf("%s--%s\n", ent->h_name, inet_ntoa(*(struct in_addr*)ent->h_addr_list[0]));
    }
    endhostent();
}
