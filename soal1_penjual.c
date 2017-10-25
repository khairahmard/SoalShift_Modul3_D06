#include<stdio.h>
#include<string.h>
<<<<<<< HEAD
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

	int op, i, tambah;
	char name[8];

	while(1){
		
		menuPenjual();
=======
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main()
{
	int *jumlah;
	int i, op, tambah;

	key_t key = 1234;
	int shmid = shmget(key, sizeof(int)*6, IPC_CREAT | 0666);
	
	jumlah = shmat(shmid, NULL, 0);

	//inisialisasi nama weapon
	char nama[6][10] = {"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1-V3", "MINE"};

	/*//inisialisasi stock weapon
	for(i = 0; i < 6; i++){
		jumlah[i] = 0;
	}*/

	

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
				if(inputan.jumlah > 0) printf("%s %d", inputan[i].nama, inputan[i].jumlah);
			} 
		} else if(op == 2){
=======
				if(jumlah[i] > 0){
					printf("%s %d\n", nama[i], jumlah[i]);
				}
			} 
		}
		else if(op == 2){
			char name[20];
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
			scanf("%s %d", name, &tambah);

			if(strcmp(name, "MP4A1") == 0)
			{
<<<<<<< HEAD
				inputan[0].jumlah += tambah;
				printf("Jumlah MP4A1 di stock = %d barang", inputan[0].jumlah);
				//else {inputan[0].jumlah = tambah; printf("Jumlah MP4A1 di stock = %d barang", inputan[0].jumlah);}
			} else if(strcmp(name, "PM2-V1") == 0)
		        {
		                inputan[1].jumlah += tambah;
				printf("Jumlah PM2-V1 di stock = %d barang", inputan[1].jumlah);
		                //else {inputan[1].jumlah = tambah; printf("Jumlah PM2-V1 di stock = %d barang", inputan[1].jumlah);}
		        } else if(strcmp(name, "SPR-3") == 0)
		        {
		               	inputan[2].jumlah += tambah;
				printf("Jumlah SPR-3 di stock = %d barang", inputan[2].jumlah);
		                //else {inputan[2].jumlah = tambah; printf("Jumlah SPR-3 di stock = %d barang", inputan[2].jumlah);}
		        } else if(strcmp(name, "SS2-V5") == 0)
		        {
		                inputan[3].jumlah += tambah;
				printf("Jumlah SS2-V5 di stock = %d barang", inputan[3].jumlah);
		                //else {inputan[3].jumlah = tambah; printf("Jumlah SS2-V5 di stock = %d barang", inputan[3].jumlah);}
		        } else if(strcmp(name, "SPG1-V3") == 0)
		        {
		                inputan[4].jumlah += tambah;
				printf("Jumlah SPG1-V3 di stock = %d barang", inputan[4].jumlah);
		                //else {inputan[4].jumlah = tambah; printf("Jumlah SPG1-V3 di stock = %d barang", inputan[4].jumlah);}
		        } else if(strcmp(name, "MINE") == 0)
		        {
		                inputan[5].jumlah += tambah;
				printf("Jumlah SPR-3 di stock = %d barang", inputan[5].jumlah);
		                //else {inputan[5].jumlah = tambah; printf("Jumlah SPR-3 di stock = %d barang", inputan[5].jumlah);}
		        }
		}
	}
shmdt(inputan);
shmctl(shmid, IPC_RMID, NULL);

return 0;
=======
				jumlah[0] += tambah;
				printf("Jumlah MP4A1 di stock = %d barang\n", jumlah[0]);
			}
			else if(strcmp(name, "PM2-V1") == 0)
		        {
		                jumlah[1] += tambah;
				printf("Jumlah PM2-V1 di stock = %d barang\n", jumlah[1]);
		        }
			else if(strcmp(name, "SPR-3") == 0)
		        {
		               	jumlah[2] += tambah;
				printf("Jumlah SPR-3 di stock = %d barang\n", jumlah[2]);
		        }
			else if(strcmp(name, "SS2-V5") == 0)
		        {
		                jumlah[3] += tambah;
				printf("Jumlah SS2-V5 di stock = %d barang\n", jumlah[3]);
		        }
			else if(strcmp(name, "SPG1-V3") == 0)
		        {
		                jumlah[4] += tambah;
				printf("Jumlah SPG1-V3 di stock = %d barang\n", jumlah[4]);
		        }
			else if(strcmp(name, "MINE") == 0)
		        {
		                jumlah[5] += tambah;
				printf("Jumlah SPR-3 di stock = %d barang\n", jumlah[5]);
		        }
		}
	}
shmdt(jumlah);
shmctl(shmid, IPC_RMID, NULL);
>>>>>>> cd224d21d0a688562c67eb09335386711828766f
}
