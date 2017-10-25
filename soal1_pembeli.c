#include<stdio.h>
#include<string.h>
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

		scanf("%d", &op);
		printf("\n");
		
		if(op == 1){
			for(i = 0; i < 6; i++) {
				printf("%s %d\n", nama[i], jumlah[i]);
			} 
		} else if(op == 2){
			char name[20];
			scanf("%s %d", name, &beli);

			if(strcmp(name, "MP4A1") == 0)
			{
				if(jumlah[0] >= beli){
					jumlah[0] -= beli;
					printf("Jumlah MP4A1 di stock = %d barang", jumlah[0]);
				} else {
					printf("Barang di stock tidak cukup.");
				}
			} else if(strcmp(name, "PM2-V1") == 0)
		        {
		                if(jumlah[1] >= beli){
					jumlah[1] -= beli;
					printf("Jumlah PM2-V1 di stock = %d barang", jumlah[1]);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SPR-3") == 0)
		        {
		               	if(jumlah[2] >= beli){
					jumlah[2] -= beli;
					printf("Jumlah SPR-3 di stock = %d barang", jumlah[2]);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SS2-V5") == 0)
		        {
		                if(jumlah[3] >= beli){
					jumlah[3] -= beli;
					printf("Jumlah SS2-V5 di stock = %d barang", jumlah[3]);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "SPG1-V3") == 0)
		        {
		                if(jumlah[4] >= beli){
					jumlah[4] -= beli;
					printf("Jumlah SPG1-V3 di stock = %d barang", jumlah[4]);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        } else if(strcmp(name, "MINE") == 0)
		        {
		                if(jumlah[5] >= beli){
					jumlah[5] -= beli;
					printf("Jumlah MINE di stock = %d barang", jumlah[5]);
				} else {
					printf("Barang di stock tidak cukup.");
				}
		        }
		}
	}
shmdt(jumlah);
shmctl(shmid, IPC_RMID, NULL);
}
