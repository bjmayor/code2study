#include <pthread.h>
struct msg{
    struct msg *next;
};

struct msg *workq;

pthread_cont_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg(void)
{
    struct msg *mp;

    for (;;)
    {
        pthread_mutex_lock(&qlock);
        while (workq == NULL)
        {
            pthread_cond_wait(&qready, &qlock);
        }
        mp = workq;
        workq = mp->next;
        pthread_mutex_unlock(&qlock);
        /** deal with mp */
    }
}

void enqueue(struct msg *mp)
{
    pthread_mutex_lock(&qlock);
    mp->next = workq;
    workq = wp;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);
}