#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void penambahan_data() ;
void perankingan_data() ;
int validasi(int *var) ;
void revalidasi_int(int *var, char *prompt) ;
void perulangan() ;
int kondisi_lanjut, pilihan ;

struct data_mahasiswa 
{
	char nama[100] ;
	int nilai ;
};

int main(){
	system("cls| clear");
	printf("PROGRAM RANKING MAHASISWA");
	printf("\nPilih menu:");
	printf("\n[1] Tambah data");
	printf("\n[2] Ranking data");
	revalidasi_int(&pilihan, "\nInput menu yang dipilih: ") ;
	switch(pilihan)
	{
		case 1 :
			penambahan_data() ;
			break ;
		case 2 :
			perankingan_data() ;
			break ;
		default :
			printf("\nInput yang anda masukkan salah, silahkan input ulang!");
            main() ;
            break ;
	}
	perulangan() ;
	return 0 ;
}

void penambahan_data()
{
	int no ;
	struct data_mahasiswa mahasiswa ;
	FILE *file1 ;
    printf("Input nama mahasiswa: ") ;
    scanf("%[^\n]s", &mahasiswa.nama) ;
	fflush(stdin) ;
	for(no=0;no<=strlen(mahasiswa.nama);no++)
	{
		if(mahasiswa.nama[no] != '\0' &&  mahasiswa.nama[no] < 32 || mahasiswa.nama[no] >90 && mahasiswa.nama[no] <97 || mahasiswa.nama[no] > 122){ 
			printf("\nInput yang anda masukkan salah, silahkan input ulang!");
			penambahan_data() ;
		}
	}
	revalidasi_int(&mahasiswa.nilai, "Input nilai: ") ;
	while(mahasiswa.nilai<0)
	{
        printf("\n Masukkan salah!") ;
		revalidasi_int(&mahasiswa.nilai, "Input nilai: ") ;
    }
	file1 = fopen("asistenin.txt","a") ;
	fprintf(file1,"%s\n", mahasiswa.nama) ;
	fprintf(file1,"%d\n", mahasiswa.nilai) ;
	fclose(file1) ;
	
	printf("\n Data yang anda inputkan berhasil disimpan\n") ;	
}

void perankingan_data()
{
	char temp[100],temp1[100] ;
	int counter = 0, i, j, temp2 ;
	FILE *file1 ;
	FILE *file2 ;
	struct data_mahasiswa mahasiswa[counter] ;
	file1 = fopen("asistenin.txt", "r+") ;
	if(file1 != 0)
	{
	    while(fscanf(file1,"%[^\n]\n%d\n",&temp, &temp1)!=EOF)
		{
	        counter++ ;
	    }
	    fclose(file1) ;
	    file1 = fopen("asistenin.txt", "r+") ;
		for(i=0; i<counter; i++)
		{
			fscanf(file1,"%[^\n]\n",&temp) ;
			strcpy(mahasiswa[i].nama, temp) ;
			fscanf(file1,"%[^\n]\n",&temp1) ;
			mahasiswa[i].nilai = atoi(temp1) ;
		}
		fclose(file1) ;
		for(i = 0; i < counter-1; i++)
		{
			for(j = 0; j < counter-1-i; j++)
			{
				if(mahasiswa[j].nilai < mahasiswa[j+1].nilai)
				{
					strcpy(temp, mahasiswa[j].nama) ;
					strcpy(mahasiswa[j].nama, mahasiswa[j+1].nama) ;
					strcpy(mahasiswa[j+1].nama, temp) ;
					temp2 = mahasiswa[j].nilai ;
					mahasiswa[j].nilai = mahasiswa[j+1].nilai ;
					mahasiswa[j+1].nilai = temp2 ;
				}
			}
		}
		printf("\n Perankingan berhasil dilakukan.\n") ;
		file2 = fopen("asistenout.txt", "w+") ;
		fprintf(file2, "Nilai mata kuliah Algoritma dan Pemrograman\n") ;
		for(i=0; i<counter; i++)
		{
			printf("%d. %s %d\n", i+1, mahasiswa[i].nama, mahasiswa[i].nilai) ;
			fprintf(file2, "%d. %s %d\n", i+1, mahasiswa[i].nama, mahasiswa[i].nilai) ;
		}
		fclose(file2) ;
	}
	else
	{
		fclose(file1) ;
		printf("File belum tersedia, silahkan tambah data terlebih dahulu \n") ;
		main() ;
	}
}

int validasi(int *var)
{
	char buff[1024] ;
	char cek ;
	fflush(stdin) ;
	if(fgets(buff, sizeof(buff), stdin) != NULL)
	{
		if(sscanf(buff, "%d %c", var, &cek) == 1) 
		{
			return 1 ;
		}
	}
	return 0 ;
}

void revalidasi_int(int *var, char *prompt)
{
	while(1)
	{
		printf(prompt) ;
		if(validasi(var))
			break;
		printf("Input yang anda masukkan salah, silahkan input ulang!\n") ;
	}
}

void perulangan()
{
	char pilihan[2] ;
	printf("\n\nIngin mengulang program (y/n)?") ;
	scanf("%s", &pilihan) ;
	if(strcmp(pilihan, "y")==0)
	{
		system("cls || clear") ;
		main() ;
	}
	else if(strcmp(pilihan, "n")==0)
	{
		printf("\nTERIMA KASIH! SILAHKAN DATANG KEMBALI");
		exit(0) ;
	}
	else
	{
		printf("\nInput yang anda masukkan salah, silahkan input ulang\n") ;
		perulangan() ;
	}

    system("cls || clear") ;
}
