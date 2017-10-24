#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

pthread_t tid[10];

int main(void)
{

	char pengguna[10];

	while(1){
		printf("Penjual atau pembeli? ");
		scanf("%s", pengguna);

		int op, err = 0;

		if(strcmp(pengguna, "penjual") == 0)
		{
			menuPenjual();

			scanf("%d", &op);
			
			err=pthread_create(&(tid[op]), NULL, &fungsiPenjual, NULL);
			if (err!=0)
			{
				printf("\nCan't create thread: [%s]", strerror(err));
			}
		} else if (strcmp(pengguna, "pembeli") == 0) {
			menuPembeli();

			scanf("%d", &op);

			err=pthread_create(&(tid[op]), NULL, &fungsiPembeli, NULL);

			if (err!=0)
                        {
                                printf("\nCan't create thread: [%s]", strerror(err));
                        }
		}
	}
    return 0;
}
