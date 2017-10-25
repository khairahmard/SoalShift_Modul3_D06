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
void *addstat_lohan(void *ptr){
   stat_lohan+=10;
}
void *addstat_kepiting(void *ptr){
   stat_kepiting+=10;
}

int main(){
    pthread_t thread[4];

    while(1){
        pthread_create(&(thread[2]),NULL,minstat_lohan,NULL);
        pthread_create(&(thread[3]),NULL,minstat_kepiting,NULL);

        char x;
        scanf("%c",&x);
        if (x=='l'){
           pthread_create(&(thread[0]),NULL,addstat_lohan,NULL);
        }
        else if (x=='k'){
           pthread_create(&(thread[1]),NULL,addstat_kepiting,NULL);
        }
        printf ("Status Lohan = %d Status Kepiting = %d\n", stat_lohan,stat_kepiting);
        if(stat_lohan>100||stat_lohan<=0||stat_kepiting>100||stat_kepiting<=0){
           printf("Game Berakhir");
           break;
        }
    }
}
