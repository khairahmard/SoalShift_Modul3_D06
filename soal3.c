#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread

int stat_lohan=100;
int stat_kepiting=100;

void *minstat_lohan(void *ptr){
   while(1){
       sleep(10);
       stat_lohan-=15;
   }
}
void *minstat_kepiting(void *ptr){
   while(1){
       sleep(20);
       stat_kepiting-=10;
   }
}

