#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[10];

void *cari(void *arg)
{
	int counter = 0;
	char buf[500], key[500];
	strcpy(key, arg);

	FILE *novel;
	novel = fopen("Novel.txt", "r");

	

	while(fscanf(novel, "%s", buf) == 1) //fgets(buf,500,novel) != NULL
	{
		if(feof(novel)) break;

		if(strstr(buf, key) != NULL){
			counter++;
		}
	}

	fclose(novel);

	printf("%s : %d\n", key, counter);
}

int main(int argc, const char *argv[])
{
	int i = 1;

	while(i < argc){
		pthread_create(&tid[i], NULL, &cari, (void*)argv[i]);
		i++;
	}

	i = 1;
	
	while(i < argc){
		pthread_join(tid[i], NULL);
		i++;
	}

	return 0;
}
