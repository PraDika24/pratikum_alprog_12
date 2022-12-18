#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define maksimal_data 1024
struct mhs{     //deklarasi variabel
	char nama[500];
	char nim[500];
}mhs;

void input_data_mhs(struct mhs data_mhs1);
void cari_data_mhs(struct mhs data_mhs1);
void tampil_data_mhs(struct mhs data_mhs1);
void clean();
int validasi_awal(int *var);
int validasi_nim(const char *nim);
int validasi_nama(const char *nama);
void ulang_input();
void ulang_pencarian();

int main(){     //fungsi untuk menampilkan menu
	int pilihan;
	struct  mhs data_mhs1;
	printf("\t\t\t\t=========================================================\n");
    printf("\t\t\t\t||                 PROGRAM DATA MAHASISWA              ||\n");
    printf("\t\t\t\t||                        KELOMPOK 12                  ||\n");
    printf("\t\t\t\t=========================================================\n");
    printf("\t\t\t\t|   I Gede Agus Handika Pratama            2205551026   |\n");
    printf("\t\t\t\t|   I Gusti Ngurah Agung Candra Wijaya     2205551092   |\n");
    printf("\t\t\t\t|   Putu Indri Cahyani                     2205551097   |\n");
    printf("\t\t\t\t|   Luh Putu Christina Ayuni               2205551098   |\n");
    printf("\t\t\t\t|   Eka Risti Shefanny                     2205551102   |\n");
    printf("\t\t\t\t|   Satria Andrew Tan                      2205551120   |\n");
    printf("\t\t\t\t=========================================================\n");
    printf("\t\t\t\t|                          MENU                         |\n");
    printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|                   [1] Input Data                      |\n");
	printf("\t\t\t\t|                   [2] Pencarian Data                  |\n");
	printf("\t\t\t\t|                   [3] Menampilkan Data                |\n");
	printf("\t\t\t\t|                   [4] Exit                            |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan Menu : ");
	validasi_awal(&pilihan);
	switch(pilihan){
		case 1:
			system("cls");
			input_data_mhs(data_mhs1);
			break;
		case 2:
			system("cls");
			cari_data_mhs(data_mhs1);
			break;
		case 3:
			system("cls");
			tampil_data_mhs(data_mhs1);
			break;
		case 4:
        printf("\t\t\t\t=========================================================\n");
        printf("\t\t\t\t||     TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI      ||\n");
        printf("\t\t\t\t=========================================================\n");
			exit(0);
			break;
		default:
		    printf("\t\t\t\tMohon Maaf, \n\t\t\t\tInput Anda Salah Tidak Sesuai dengan Menu Kami!\n");
            printf("\n\t\t\t\tSilakan Masukkan Ulang Angka 1-4 untuk Memilih Menu\n");
            printf("\t\t\t\tPilihan Anda: ");
			system("pause");
 			system("cls");
			main();
	}
}

void input_data_mhs(struct mhs data_mhs1){      //fungsi untuk menginput data mahasiswa
	int histori=0;
	char buffer[maksimal_data];

	printf("\t\t\t\t=========================================================\n");
    printf("\t\t\t\t||                  INPUT DATA MAHASISWA               ||\n");
    printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan NIM Anda: ");
	scanf("%s", data_mhs1.nim);
	while(!validasi_nim(data_mhs1.nim)){
		printf("\t\t\t\tInput Anda Salah! Masukkan NIM dengan Benar\n");
		printf("\t\t\t\tMasukkan NIM Anda: ");
		scanf("%s", data_mhs1.nim);
	}
	fflush(stdin);
	printf("\t\t\t\tMasukkan Nama Anda: ");
	scanf("%s", data_mhs1.nama);
	while(!validasi_nama(data_mhs1.nama)){
		printf("\t\t\t\tInput Anda Salah! Masukkan Nama Anda dengan Benar\n");
		printf("\t\t\t\tMasukkan Nama Anda : ");
		scanf("%s", data_mhs1.nama);
	}

	FILE*datamhs;
	datamhs = fopen("datamahasiswa.txt", "r");
    if (datamhs == NULL){
        printf("\t\t\t\tMohon Maaf File Data Tidak Ditemukan \n");
    }else{
        rewind(datamhs);
        while(fgets(buffer, maksimal_data, datamhs)){
                buffer[strcspn(buffer, "%s # %[^#] #\n")] = 0;
                if (strcmp(buffer, data_mhs1.nim) == 0){
                    printf("\n\t\t\t\tData dengan NIM %s Sudah Pernah Diinput\n", buffer);
                    histori = 1;
                }
            }
		fclose(datamhs);
        }
    if(histori == 0){
       	FILE *datamhs = fopen("datamahasiswa.txt", "a");
        fprintf(datamhs, "%s # %s # \n",data_mhs1.nim, data_mhs1.nama);
        printf("\t\t\t\tSELAMAT DATA ANDA BERHASIL DIINPUT!\n\n");
        fclose(datamhs);
    }
    histori = 0;
    fflush(stdin);
    ulang_input();
}

void cari_data_mhs(struct mhs data_mhs1){       //fungsi untuk melakukan pencarian data mahasiswa
    int histori = 0;
    char nim[500];

	printf("\t\t\t\t=========================================================\n");
    printf("\t\t\t\t||              PENCARIAN DATA MAHASISWA               ||\n");
    printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan NIM Anda: ");
    scanf("%s", &nim);

	while(!validasi_nim(nim)){
		printf("\t\t\t\tInput Anda Salah! Masukkan Data dengan Benar\n");
		printf("\t\t\t\tMasukkan NIM Anda : ");
		scanf("%s", nim);
	}
    fflush(stdin);
	FILE *datamhs;
	datamhs = fopen("datamahasiswa.txt", "r");

    if(datamhs == NULL){
        printf(" Mohon maaf, file tidak ditemukan !\n");
    }else{
        while (!feof(datamhs)){
            fflush(stdin);

            fscanf(datamhs, "%s # %[^#] #\n", &data_mhs1.nim, &data_mhs1.nama);
            if(strcmp(data_mhs1.nim, nim) == 0){
                printf("\n\t\t\t\tSELAMAT DATA ANDA BERHASIL DITEMUKAN!\n");
            	printf("\t\t\t\t=========================================================\n");
                printf("\t\t\t\t||           HASIL PENCARIAN DATA MAHASISWA            ||\n");
                printf("\t\t\t\t=========================================================\n");
                printf("\t\t\t\tNIM  : %s\n", data_mhs1.nim);
                printf("\t\t\t\tNama : %s\n", data_mhs1.nama);
                histori = 1;
            }
        }
        fclose(datamhs);
    }
    if (histori == 0){
		printf("\t\t\t\tMohon Maaf, \n\t\t\t\tData Mahasiswa dengan NIM %s Tidak Dapat Ditemukan!\n", nim);
    }

    histori = 0;
    fflush(stdin);
    ulang_pencarian();
}

void tampil_data_mhs(struct mhs data_mhs1){     //fungsi untuk menampilkan data mahasiswa
	int no = 1;
	system("cls");
	char pil[2];

	printf("\t\t\t\t=========================================================\n");
    printf("\t\t\t\t||              MENAMPILKAN DATA MAHASISWA             ||\n");
    printf("\t\t\t\t=========================================================\n");

	FILE *datamhs;
	datamhs = fopen("datamahasiswa.txt", "r");
 	if (datamhs == NULL){
 		printf("\t\t Mohon maaf, data tidak tersedia\n");
 	}else{
 		while (!feof(datamhs)){
 			fflush(stdin);
 			fscanf(datamhs, "%s # %[^#] #\n", &data_mhs1.nim, &data_mhs1.nama);
 			printf("\t\t\t\t[%d] NIM  : %s\n", no, data_mhs1.nim);
 			printf("\t\t\t\t    Nama : %s\n", data_mhs1.nama);
 			no++;
			printf("\t\t\t\t---------------------------------------------------------\n");
 		}
 		fclose(datamhs);
 	}

 	printf("\n\t\t\t\tApakah Anda Ingin Kembali ke Menu Utama?\n");
    printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|         [1]Tekan '1' untuk Kembali ke Menu            |\n");
	printf("\t\t\t\t|         [3]Tekan Sembarang untuk Keluar               |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan Pilihan Anda: ");
 	scanf("%s", &pil);

	if(strcmp(pil, "1")==0){
		system("cls");
		main();
	}else{
		system("cls");
        printf("\t\t\t\t=========================================================\n");
        printf("\t\t\t\t||     TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI      ||\n");
        printf("\t\t\t\t=========================================================\n");
		exit(0);
	}
}

void ulang_input(){         //fungsi untuk menginput ulang data mahasiswa
	char pil[2];
	struct  mhs data_mhs1;
	printf("\t\t\t\tApakah Anda Ingin Mengulang?\n");
    printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|         [1]Tekan '1' untuk Mengulang                  |\n");
	printf("\t\t\t\t|         [2]Tekan '0' untuk Kembali ke Menu            |\n");
	printf("\t\t\t\t|         [3]Tekan Sembarang untuk Keluar               |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan Pilihan Anda: ");
	scanf("%s", &pil);
	if(strcmp(pil, "1")==0){
		system("cls");
		input_data_mhs(data_mhs1);
	}else if(strcmp(pil, "0")==0){
		system("cls");
		main();
	}else{
		system("cls");
		printf("\t\t\t\t=========================================================\n");
        printf("\t\t\t\t||     TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI      ||\n");
        printf("\t\t\t\t=========================================================\n");
		exit(0);
	}
}


void ulang_pencarian(){     //fungsi untuk melakukan pencarian ulang data mahasiswa
	char pil[2];
	struct  mhs data_mhs1;
	printf("\n\t\t\t\tApakah Anda Ingin Mengulang?\n");
    printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|         [1]Tekan '1' untuk Mengulang                  |\n");
	printf("\t\t\t\t|         [2]Tekan '0' untuk Kembali ke Menu            |\n");
	printf("\t\t\t\t|         [3]Tekan Sembarang untuk Keluar               |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan Pilihan Anda: ");
	scanf("%s", &pil);
	if(strcmp(pil, "1")==0){
		system("cls");
		cari_data_mhs(data_mhs1);
	}else if(strcmp(pil, "0")==0){
		system("cls");
		main();
	}else{
		system("cls");
		printf("\t\t\t\t=========================================================\n");
        printf("\t\t\t\t||     TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI      ||\n");
        printf("\t\t\t\t=========================================================\n");
		exit(0);
	}
}

void clean(){
	while (getchar() != '\n');
}

int validasi_awal(int *var){            //validasi pilihan menu awal
    if (scanf("%d", var) !=1){
		clean();
        printf("\t\t\t\tMohon Maaf,\n\t\t\t\tInput Anda Salah Tidak Sesuai dengan Menu Kami!\n");
        printf("\n\t\t\t\tSilakan Masukkan Ulang Angka 1-4 untuk Memilih Menu\n");
        printf("\t\t\t\tPilihan Anda: ");
        validasi_awal(var);
    }
    return 1;
}

int validasi_nim(const char *nim){      //validasi nim
	int i;
    for (i = 0; i < strlen(nim); i++){
        if (!isdigit(nim[i])){
            return 0;
        }
    }
    return 1;
}

int validasi_nama(const char *nama){    //validasi nama
	int i;
    for (i = 0; i < strlen(nama); i++){
        if (!isalpha(nama[i]) && !isspace(nama[i])){
            return 0;
        }
    }
    return 1;
}
