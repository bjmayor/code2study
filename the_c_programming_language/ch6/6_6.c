#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN 1
#define OUT 0
struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if (strcmp(s,np->name)==0)
        {
            return np;
        }
    }
    return NULL;
}


struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL )
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name))==NULL)
        {
            return NULL;
        }

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
    {
        free((void*) np->defn);
    }

    if ((np->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }
    return np;
}

void undef(char *name)
{
    struct nlist *np;
    struct nlist *prep;
    unsigned hashval;

    hashval = hash(name);
    for (np = hashtab[hash(name)]; np != NULL; prep=np,np = np->next)
    {
        if (strcmp(name,np->name)==0)
        {
            prep->next = np->next;
            free(np);
        }
    }
}

int main(int argc, char **argv)
{
    int c, state;
    char *name, *defn;

    state = OUT;
    //todo
    while((c=getch()) !=EOF)
    {
       if (c=='#') 
       {
           state = IN;
       }
    }
}
