#include<stdio.h>
#include<string.h>
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

		scanf("%d", &op);
		printf("\n");
		
		if(op == 1){
			for(i = 0; i < 6; i++) {
				printf("%s %d", inputan[i].nama, inputan[i].jumlah);
			} 
		} else if(op == 2){
			scanf("%s %d", name, &beli);

			if(strcmp(name, "MP4A1") == 0)
			{
				if(inputan[0].jumlah >= beli){
					inputan[0].jumlah -= beli;
					printf("Jumlah MP4A1 di stock = %d barang", inputan[0].jumlah);
				} else {
					printf("Barang di stock tidak cukup.");
				}
			} else if(strcmp(name, "PM2-V1") == 0)
		        {
		                if(inputan[1].jumlah >= beli){
					inputan[1].jumlah -= beli;
					printf("Jumlah PM2-V1 di stock = %d barang", inputan[1].jumlah);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SPR-3") == 0)
		        {
		               	if(inputan[2].jumlah >= beli){
					inputan[2].jumlah -= beli;
					printf("Jumlah SPR-3 di stock = %d barang", inputan[2].jumlah);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SS2-V5") == 0)
		        {
		                if(inputan[3].jumlah >= beli){
					inputan[3].jumlah -= beli;
					printf("Jumlah SS2-V5 di stock = %d barang", inputan[3].jumlah);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SPG1-V3") == 0)
		        {
		                if(inputan[4].jumlah >= beli){
					inputan[4].jumlah -= beli;
					printf("Jumlah SPG1-V3 di stock = %d barang", inputan[4].jumlah);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "MINE") == 0)
		        {
		                if(inputan[5].jumlah >= beli){
					inputan[5].jumlah -= beli;
					printf("Jumlah MINE di stock = %d barang", inputan[5].jumlah);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        }
		}
	}
shmdt(inputan);
shmctl(shmid, IPC_RMID, NULL);

return 0;
}
