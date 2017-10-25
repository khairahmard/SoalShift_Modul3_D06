#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

pthread_t tid[10];

void menuPenjual()
{
	printf("Senjata: MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE\n");
	printf("1. Lihat stock senjata\n");
	printf("2. Tambah stock senjata\n");
	printf("Pilihan: ");
}

void menuPembeli()
{
	printf("Senjata: MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE\n");
	printf("1. Lihat stock senjata\n");
	printf("2. Beli senjata\n");
	printf("Pilihan: ");
}

struct input
{
	int jumlah;
	char nama[10];
}

void *fungsiPenjual(void *arg) {
	pthread_t id=pthread_self();

	key_t key = 1234;
	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

	static int *mp4a1, *pm2v1, *spr3, *ss2v5, *spg1v3, *mine;
	int jumlah;
	char nama[10];

	mp4a1 = shmat(shmid, NULL, 0);
	spr3 = shmat(shmid, NULL, 0);
	ss2v5 = shmat(shmid, NULL, 0);
	spg1v3 = shmat(shmid, NULL, 0);
	pm2v1 = shmat(shmid, NULL, 0);
	mine = shmat(shmid, NULL, 0);

	if (mp4a1 == NULL) *mp4a1 = 0;
	if (pm2v1 == NULL) *pm2v1 = 0;
	if (spr3 == NULL) *spr3 = 0;
	if (ss2v5 == NULL) *ss2v5 = 0;
	if (spg1v3 == NULL) *spg1v3 = 0;
	if (mine == NULL) *mine = 0;

	if(pthread_equal(id,tid[1])){
		scanf("%s %d", nama, &jumlah);

		if(strcmp(nama, "MP4A1") == 0)
                {
                        if(*mp4a1 != 0)
                                printf("%s %d\n", nama, *mp4a1);
                } else if(strcmp(nama, "PM2-V1") == 0)
                {
                        if(*pm2v1 != 0)
                                printf("%s %d\n", nama, *pm2v1);
                } else if(strcmp(nama, "MP4A1") == 0)
                {
                        if(*spr3 != 0)
                               	printf("%s %d\n", nama, *spr3);
                } else if(strcmp(nama, "MP4A1") == 0)
                {
                        if(*ss2v5 != 0)
                                printf("%s %d\n", nama, *ss2v5);
		} else if(strcmp(nama, "MP4A1") == 0)
                {
                        if(*spg1v3 != 0)
                                printf("%s %d\n", nama, *spg1v3);
                } else if(strcmp(nama, "MP4A1") == 0)
                {
                        if(*mine != 0)
                                printf("%s %d\n", nama, *mine);
                }
        }
	else if(pthread_equal(id,tid[2])){
		scanf("%s %d", nama, &jumlah);

		if(strcmp(nama, "MP4A1") == 0)
		{
			if(*mp4a1 != 0) {*mp4a1 += jumlah; printf("Jumlah MP4A1 di stock = %d barang", *mp4a1);}
			else {*mp4a1 = jumlah; printf("Jumlah MP4A1 di stock = %d barang", *mp4a1);}
		} else if(strcmp(nama, "PM2-V1") == 0)
                {
                        if(*pm2v1 != 0) {*pm2v1 += jumlah; printf("Jumlah PM2-V1 di stock = %d barang", *pm2v1);}
                        else {*pm2v1 = jumlah; printf("Jumlah PM2-V1 di stock = %d barang", *pm2v1);}
                } else if(strcmp(nama, "SPR-3") == 0)
                {
                       	if(*spr3 != 0) {*spr3 += jumlah; printf("Jumlah SPR-3 di stock = %d barang", *spr3);}
                        else {*spr3 = jumlah; printf("Jumlah SPR-3 di stock = %d barang", *spr3);}
                } else if(strcmp(nama, "SS2-V5") == 0)
                {
                        if(*ss2v5 != 0) {*ss2v5 += jumlah; printf("Jumlah SS2-V5 di stock = %d barang", *ss2v5);}
                        else {*ss2v5 = jumlah; printf("Jumlah SS2-V5 di stock = %d barang", *ss2v5);}
                } else if(strcmp(nama, "SPG1-V3") == 0)
                {
                        if(*spg1v3 != 0) {*spg1v3 += jumlah; printf("Jumlah SPG1-V3 di stock = %d barang", *spg1v3);}
                        else {*spg1v3 = jumlah; printf("Jumlah SPG1-V3 di stock = %d barang", *spg1v3);}
                } else if(strcmp(nama, "MINE") == 0)
                {
                        if(*spr3 != 0) {*spr3 += jumlah; printf("Jumlah SPR-3 di stock = %d barang", *spr3);}
                        else {*spr3 = jumlah; printf("Jumlah SPR-3 di stock = %d barang", *spr3);}
                }
	}
}

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
