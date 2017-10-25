#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

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
	int i;

	for(i = 0; i < argc; i++) {
		pthread_create(&(tid[i]), NULL, &cari, (void*)argv[i]);
	}

	for(i = 0; i < argc; i++) {
		pthread_join(tid[i], NULL);
	}

	return 0;
}
