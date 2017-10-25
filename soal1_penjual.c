#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void menuPenjual()
{
	printf("Senjata: MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE\n");
	printf("1. Lihat stock senjata\n");
	printf("2. Tambah stock senjata\n");
	printf("Pilihan: ");
}

struct input // berisi nama weapon dan stock
{
	int jumlah;
	char nama[8];
}

/*void *fungsiPenjual(void *arg) {

	if(pthread_equal(id,tid[1])){
		if(strcmp(input->nama, "MP4A1") == 0)
                {
                        if(*mp4a1 != 0)
                                printf("%s %d\n", input->nama, *mp4a1);
                } else if(strcmp(input->nama, "PM2-V1") == 0)
                {
                        if(*pm2v1 != 0)
                                printf("%s %d\n", input->nama, *pm2v1);
                } else if(strcmp(input->nama, "SPR-3") == 0)
                {
                        if(*spr3 != 0)
                               	printf("%s %d\n", input->nama, *spr3);
                } else if(strcmp(input->nama, "SS2-V5") == 0)
                {
                        if(*ss2v5 != 0)
                                printf("%s %d\n", input->nama, *ss2v5);
		} else if(strcmp(input->nama, "SPG1-V3") == 0)
                {
                        if(*spg1v3 != 0)
                                printf("%s %d\n", input->nama, *spg1v3);
                } else if(strcmp(input->nama, "MINE") == 0)
                {
                        if(*mine != 0)
                                printf("%s %d\n", input->nama, *mine);
                }
        }
	else if(pthread_equal(id,tid[2])){
		if(strcmp(input->nama, "MP4A1") == 0)
		{
			if(*mp4a1 != 0) {*mp4a1 += input->jumlah; printf("Jumlah MP4A1 di stock = %d barang", *mp4a1);}
			else {*mp4a1 = input->jumlah; printf("Jumlah MP4A1 di stock = %d barang", *mp4a1);}
		} else if(strcmp(input->nama, "PM2-V1") == 0)
                {
                        if(*pm2v1 != 0) {*pm2v1 += input->jumlah; printf("Jumlah PM2-V1 di stock = %d barang", *pm2v1);}
                        else {*pm2v1 = input->jumlah; printf("Jumlah PM2-V1 di stock = %d barang", *pm2v1);}
                } else if(strcmp(input->nama, "SPR-3") == 0)
                {
                       	if(*spr3 != 0) {*spr3 += input->jumlah; printf("Jumlah SPR-3 di stock = %d barang", *spr3);}
                        else {*spr3 = input->jumlah; printf("Jumlah SPR-3 di stock = %d barang", *spr3);}
                } else if(strcmp(input->nama, "SS2-V5") == 0)
                {
                        if(*ss2v5 != 0) {*ss2v5 += input->jumlah; printf("Jumlah SS2-V5 di stock = %d barang", *ss2v5);}
                        else {*ss2v5 = input->jumlah; printf("Jumlah SS2-V5 di stock = %d barang", *ss2v5);}
                } else if(strcmp(input->nama, "SPG1-V3") == 0)
                {
                        if(*spg1v3 != 0) {*spg1v3 += input->jumlah; printf("Jumlah SPG1-V3 di stock = %d barang", *spg1v3);}
                        else {*spg1v3 = input->jumlah; printf("Jumlah SPG1-V3 di stock = %d barang", *spg1v3);}
                } else if(strcmp(input->nama, "MINE") == 0)
                {
                        if(*spr3 != 0) {*spr3 += input->jumlah; printf("Jumlah SPR-3 di stock = %d barang", *spr3);}
                        else {*spr3 = input->jumlah; printf("Jumlah SPR-3 di stock = %d barang", *spr3);}
                }
	}
}*/

int main(void)
{
	struct input *inputan = malloc(sizeof(struct input));

	key_t key = 1234;
	int shmid = shmget(key, sizeof(struct input)*6, IPC_CREAT | 0666);
	
	inputan = (struct input*)shmat(shmid, NULL, 0);

	// inisialisasi nama weapon
	strcpy(inputan[0].nama = "MP4A1");
	strcpy(inputan[1].nama = "PM2-V1");
	strcpy(inputan[2].nama = "SPR-3");
	strcpy(inputan[3].nama = "SS2-V5");
	strcpy(inputan[4].nama = "SPG1-V3");
	strcpy(inputan[5].nama = "MINE");

	//inisialisasi stock weapon
	inputan[0].jumlah = "MP4A1");
	inputan[1].jumlah = "PM2-V1");
	inputan[2].jumlah = "SPR-3");
	inputan[3].jumlah = "SS2-V5");
	inputan[4].jumlah = "SPG1-V3");
	inputan[5].jumlah = "MINE");

	/*while(1){
		printf("Penjual atau pembeli? ");
		scanf("%s", pengguna);

		int op, err = 0;

		if(strcmp(pengguna, "penjual") == 0)
		{
			menuPenjual();

			scanf("%d", &op);
			printf("\n");
			scanf("%s %d", input->nama, input->jumlah);
			
			err=pthread_create(&(tid[op]), NULL, fungsiPenjual, input);
			if (err!=0)
			{
				printf("\nCan't create thread: [%s]", strerror(err));
			}
		} else if (strcmp(pengguna, "pembeli") == 0) {
			menuPembeli();

			scanf("%d", &op);
			printf("\n");
			scanf("%s %d", input->nama, input->jumlah);

			err=pthread_create(&(tid[op]), NULL, fungsiPembeli, input);

			if (err!=0)
                        {
                                printf("\nCan't create thread: [%s]", strerror(err));
                        }
		}
	}*/
    return 0;
}
