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
