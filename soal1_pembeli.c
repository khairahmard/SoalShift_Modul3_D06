#include<stdio.h>
#include<string.h>
<<<<<<< HEAD
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void menuPembeli()
{
	printf("Senjata: MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE\n");
	printf("1. Lihat stock senjata\n");
	printf("2. Beli senjata\n");
	printf("Pilihan: ");
}

struct input // berisi nama weapon dan stock
{
	int jumlah;
	char nama[8];
}

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
	inputan[0].jumlah = 0;
	inputan[1].jumlah = 0;
	inputan[2].jumlah = 0;
	inputan[3].jumlah = 0;
	inputan[4].jumlah = 0;
	inputan[5].jumlah = 0;

	int op, i, beli;
	char name[8];

	while(1){
		
		menuPembeli();
=======
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main()
{
	int *jumlah;
	int i, op, beli;

	key_t key = 1234;
	int shmid = shmget(key, sizeof(int)*6, IPC_CREAT | 0666);
	
	jumlah = shmat(shmid, NULL, 0);

	//inisialisasi nama weapon
	char nama[6][10] = {"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1-V3", "MINE"};

	//inisialisasi stock weapon
	for(i = 0; i < 6; i++){
		jumlah[i] = 0;
	}

	while(1){
		
		printf("Senjata: MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE\n");
		printf("1. Lihat stock senjata\n");
		printf("2. Tambah stock senjata\n");
		printf("Pilihan: ");
>>>>>>> cd224d21d0a688562c67eb09335386711828766f

		scanf("%d", &op);
		printf("\n");
		
		if(op == 1){
			for(i = 0; i < 6; i++) {
<<<<<<< HEAD
				printf("%s %d", inputan[i].nama, inputan[i].jumlah);
			} 
		} else if(op == 2){
=======
				printf("%s %d\n", nama[i], jumlah[i]);
			} 
		} else if(op == 2){
			char name[20];
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
			scanf("%s %d", name, &beli);

			if(strcmp(name, "MP4A1") == 0)
			{
<<<<<<< HEAD
				if(inputan[0].jumlah >= beli){
					inputan[0].jumlah -= beli;
					printf("Jumlah MP4A1 di stock = %d barang", inputan[0].jumlah);
=======
				if(jumlah[0] >= beli){
					jumlah[0] -= beli;
					printf("Jumlah MP4A1 di stock = %d barang", jumlah[0]);
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
				} else {
					printf("Barang di stock tidak cukup.");
				}
			} else if(strcmp(name, "PM2-V1") == 0)
		        {
<<<<<<< HEAD
		                if(inputan[1].jumlah >= beli){
					inputan[1].jumlah -= beli;
					printf("Jumlah PM2-V1 di stock = %d barang", inputan[1].jumlah);
=======
		                if(jumlah[1] >= beli){
					jumlah[1] -= beli;
					printf("Jumlah PM2-V1 di stock = %d barang", jumlah[1]);
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SPR-3") == 0)
		        {
<<<<<<< HEAD
		               	if(inputan[2].jumlah >= beli){
					inputan[2].jumlah -= beli;
					printf("Jumlah SPR-3 di stock = %d barang", inputan[2].jumlah);
=======
		               	if(jumlah[2] >= beli){
					jumlah[2] -= beli;
					printf("Jumlah SPR-3 di stock = %d barang", jumlah[2]);
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SS2-V5") == 0)
		        {
<<<<<<< HEAD
		                if(inputan[3].jumlah >= beli){
					inputan[3].jumlah -= beli;
					printf("Jumlah SS2-V5 di stock = %d barang", inputan[3].jumlah);
=======
		                if(jumlah[3] >= beli){
					jumlah[3] -= beli;
					printf("Jumlah SS2-V5 di stock = %d barang", jumlah[3]);
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SPG1-V3") == 0)
		        {
<<<<<<< HEAD
		                if(inputan[4].jumlah >= beli){
					inputan[4].jumlah -= beli;
					printf("Jumlah SPG1-V3 di stock = %d barang", inputan[4].jumlah);
=======
		                if(jumlah[4] >= beli){
					jumlah[4] -= beli;
					printf("Jumlah SPG1-V3 di stock = %d barang", jumlah[4]);
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "MINE") == 0)
		        {
<<<<<<< HEAD
		                if(inputan[5].jumlah >= beli){
					inputan[5].jumlah -= beli;
					printf("Jumlah MINE di stock = %d barang", inputan[5].jumlah);
=======
		                if(jumlah[5] >= beli){
					jumlah[5] -= beli;
					printf("Jumlah MINE di stock = %d barang", jumlah[5]);
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        }
		}
	}
<<<<<<< HEAD
shmdt(inputan);
shmctl(shmid, IPC_RMID, NULL);

return 0;
=======
shmdt(jumlah);
shmctl(shmid, IPC_RMID, NULL);
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
}
