#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

int panjang_sisi;
struct unsur{
	int sisi;
	int luas_permukaan;
	int volume;
};

union unsurkbs{
	int sisi;
	int luas_permukaan;
	int volume;
};

void main();
void clean(){
	while (getchar() != '\n');
}

int validasi(int *var){
    if (scanf("%d", var) !=1){
		clean();
        printf("\t\t    mohon maaf input salah!\n");
        printf("\t\t    silakan inputkan ulang (angka)\n");
        printf("\t\t    Pilihan Anda: ");
        validasi(var);
    }
    return 1;
}

void ulang(){
	char pil[2];
	printf("\t\t   Apakah Anda ingin mengulang?\n");
	printf("\t\t   (y/t): ");
	scanf("%s", &pil);
	if(strcmp(pil, "y")==0){
		system("cls");
		main();
	}else if(strcmp(pil, "t")==0){
	    system("cls"); // nambahini
	    printf("\n\n\n\n");
		printf("\t\t\|*|----------------------------\t|*|\n");
		printf("\t\t|*|\t***Terima kasih!***\t|*|");
		exit(0);
	}else{
		printf("\t\t|*|---------------------------\t|*|\n");
		printf("\t\t|*|Mohon maaf, INPUT SALAH!\t|*|\n");
		printf("\t\t|*| Silakan inputkan kembali\t|*|\n");
		printf("\t\t|*|---------------------------\t|*|\n");
		ulang();
	}
}
void hitung_kubus_struct(){
	struct unsur struct_kubus;
	system("cls");
	printf("\t\t=================================\n");
	printf("\t\t|*|PROGRAM KUBUS DENGAN STRUCT\t|*|\n");
	printf("\t\t|*|===========================\t|*|\n");
	printf("\t\t    Masukkan panjang sisi: ");
	validasi(&panjang_sisi);

	struct_kubus.sisi = panjang_sisi;
	struct_kubus.luas_permukaan = 6*panjang_sisi*panjang_sisi;
	struct_kubus.volume = panjang_sisi*panjang_sisi*panjang_sisi;
	printf("\t\t|*|---------------------------\t|*|\n");
	printf("\t\t|*|Panjang sisi\t\t:%d\t|*|\n", struct_kubus.sisi);
	printf("\t\t|*|Luas permukaan\t:%d\t|*|\n", struct_kubus.luas_permukaan);
	printf("\t\t|*|Volume\t\t:%d\t|*|\n", struct_kubus.volume);
	printf("\t\t|*|Memori\t\t:%d\t|*|\n", sizeof(struct_kubus));
	printf("\t\t|*|---------------------------\t|*|\n");
	ulang();
}

void hitung_kubus_union(){
	union unsurkbs union_kubus[3];
	system("cls");
	printf("\t\t=================================\n");
	printf("\t\t|*|PROGRAM KUBUS DENGAN UNION\t|*|\n");
	printf("\t\t|*|===========================\t|*|\n");
	printf("\t\t    Masukkan panjang sisi: ");
	validasi(&panjang_sisi);
	union_kubus[0].sisi = panjang_sisi;
	union_kubus[1].luas_permukaan = 6*panjang_sisi*panjang_sisi;
	union_kubus[2].volume = panjang_sisi*panjang_sisi*panjang_sisi;

	printf("\t\t|*|---------------------------\t|*|\n");
	printf("\t\t|*|Panjang sisi\t\t:%d\t|*|\n", union_kubus[0].sisi);
	printf("\t\t|*|Luas permukaan\t:%d\t|*|\n", union_kubus[1].luas_permukaan);
	printf("\t\t|*|Volume\t\t:%d\t|*|\n", union_kubus[2].volume);
	printf("\t\t|*|Memori\t\t:%d\t|*|\n", sizeof(union_kubus[0]));
	printf("\t\t|*|---------------------------\t|*|\n");
	ulang();
}
void main(){
	int pilihan;
	printf("\t\t=============================================\n");
	printf("\t\t|*| PROGRAM LUAS PERMUKAAN DAN VOLUME KUBUS |*|\n");
	printf("\t\t|*|            OLEH KELOMPOK 12             |*|\n");
	printf("\t\t|*|-----------------------------------------|*|\n");
	printf("\t\t|*|\t\t*** M E N U ***\t\t    |*|\n");
	printf("\t\t|*|-----------------------------------------|*|\n");
	printf("\t\t|*|1.Kubus dengan struct                    |*|\n");
	printf("\t\t|*|2.Kubus dengan union                     |*|\n");
	printf("\t\t|*|3.keluar                                 |*|\n");
	printf("\t\t=============================================\n");
	printf("\t\t  Silakan inputkan pilihan Anda: ");
	validasi(&pilihan);
	switch (pilihan){
		case 1:
			hitung_kubus_struct();
			break;
		case 2:
			hitung_kubus_union();
			break;
		case 3:
			printf("\t\t|*|-----------------------------------------|*|\n");
			printf("\t\t|*|***Terima kasih telah mencoba!***        |*|\n");
			printf("\t\t|*|-----------------------------------------|*|\n");
			exit(0);
		default:
			printf("\t\tinput salah! silakan input ulang\n\t\t");
			system("pause");
			system("cls");
			main();
	}
}
