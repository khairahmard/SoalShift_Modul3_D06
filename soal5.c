#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[100];

void *cari(void *arg)
{
	int counter = 0;
	char ygdicari[500], text[500];

	FILE *novel;
	novel = fopen("Novel.txt", "r");

	strcpy(ygdicari, arg);

	while(fscanf(novel, "%s", text) != EOF)
	{
		if(strstr(text, ygdicari) != NULL){
			counter++;
		}
	}

	fclose(novel);

	printf("%s : %d\n", ygdicari, counter);
}

int main(int argc, char *argv[])
{
<<<<<<< HEAD
     pthread_t thread[50];//inisialisasi awal
     int  iret;

     while(1){
        iret = pthread_create( &thread, NULL, print_message_function, (void*) message);//membuat thread
        if(iret)//jika eror
        {
            fprintf(stderr,"Error - pthread_create() return code: %d\n",iret);
            exit(EXIT_FAILURE);
        }
     }

  exit(EXIT_SUCCESS);
=======
	int i;

	for(i = 1; i < argc; i++) {
		pthread_create(&tid[i], NULL, &cari, (void*)argv[i]);
	}

	for(i = 1; i < argc; i++) {
		pthread_join(tid[i], NULL);
	}

	return 0;
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
}
