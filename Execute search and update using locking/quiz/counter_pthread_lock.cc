#include "lock.h"
uint Counter = 0;

void *
worker(void *arg)
{
  for (uint i = 0; i < NbLoop; i++) { // this part is modified
    pthread_mutex_lock(&Lock); // lock the thread so we can safely increment
    Counter++; // increment
    pthread_mutex_unlock(&Lock); // unlock the thread so that it can be accessed again
  }

  return NULL;
}

int
main(void)
{
  pthread_t thread[NbThread];

  if ((pthread_mutex_init(&Lock, NULL)) == -1) ERR;

  for (uint i = 0; i < NbThread; i++) {
    pthread_create(&thread[i], NULL, worker, NULL);
  }
  for (uint i = 0; i < NbThread; i++) {
    pthread_join(thread[i], NULL);
  }
  printf("Counter: %u (Ref. %u)\n", Counter, NbThread * NbLoop);

  return 0;
}
