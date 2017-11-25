#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    struct netent *ent;
    char *address;
    setnetent(1);
    while((ent = getnetent())!=NULL)
    {
        printf("%s--%s\n", ent->n_name, inet_ntop(AF_INET, (void *)ent->n_net, address, INET_ADDRSTRLEN));
    }
    endnetent();
}
