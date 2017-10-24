#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread

void *print_message_function( void *ptr )
{
     int x=(int)ptr;
     int fac=1;
     for(int i=x;i>=1;i--) fac*=i;
     printf("hasil %d! = %d\n", x,fac);
}

int main()
{
 
     pthread_t thread[50];//inisialisasi awal
     int iret;
     int index[50];
     int jmlindex=0;
     while(1){
        char x;
        scanf("%d%c",&index[jmlindex],&x);
        jmlindex++;
        if(x=='\n') break;
     }

     for(int i=0;i<jmlindex;i++){
        iret = pthread_create( &thread[i], NULL, print_message_function, (void*) index[i]);//membuat thread
        if(iret)//jika eror
        {
            fprintf(stderr,"Error - pthread_create() return code: %d\n",iret);
            exit(EXIT_FAILURE);
        }
     }
     for(int i=0;i<jmlindex;i++){
        pthread_join(thread[i], NULL);
     }

  exit(EXIT_SUCCESS);
}

