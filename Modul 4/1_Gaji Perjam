#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
typedef struct{
 	char nama[100];
 	int jamkerjaTotal;
 	int jamLembur;
 	int waktuPokok;
 	int gajiPokok;
 	int gajiLembur;
 	int totalGaji;
} Gaji;

int validasiint(int *var){
 	char buff[1024];
 	char x;
 	fflush(stdin);
 	if(fgets(buff, sizeof(buff), stdin) != NULL){
 		if(sscanf(buff, "%d %c", var, &x) == 1) {
 			return 1;
 		}
	}
return 0;
}

void repeatint(int *var){
	while(1){
 		if(validasiint(var)){
 			break;
 			printf("Inputan tidak valid\nInputkan Ulang \t:");
		}
	}
}

void kembali(){
 	char pil[2];
 	printf("\nApakah anda ingin mengulang program ini? (y/t) \n");
 	scanf("%s",&pil);
 	if(strcmpi(pil,"y")==0){
 		system("cls");
 		main();
 	}
 	else if(strcmpi(pil,"t")==0){
 		printf("\n");
 		printf("\t+===============================================+\n");
 		printf("\t| Terima Kasih |\n"); 
		printf("\t+===============================================+\n\n");
 		exit(1);
 	}
 	else{
 		printf("Silahkan Masukkan Pilihan Yang Benar!! ");
 		kembali();
 	}
	getch();
}

int main(){
 	system ("cls");
 	Gaji g;
 	g.jamkerjaTotal=0;
 	g.jamLembur=0;
 	g.waktuPokok=0;
 	g.gajiPokok=0;
 	g.gajiLembur=0;
 	g.totalGaji=0;
 
 	printf("+==============================================+\n");
	printf("|        PROGRAM MENGHITUNG GAJI PEKERJA       |\n");
	printf("|                 KELOMPOK 12                  |\n");
 	printf("+==============================================+\n\n");
 	printf("Masukan Nama Anda: ");
 	scanf("%s",&g.nama);
 	printf("Masukan Jam Kerja Anda : ");
 	repeatint(&g.jamkerjaTotal);
 	if(g.jamkerjaTotal>8){
 		g.waktuPokok=8;
 		g.jamLembur=g.jamkerjaTotal-8;
 		g.gajiPokok=8*10625;
 		g.gajiLembur=(g.jamLembur*85000);
 	}
 	else{
 		g.gajiPokok=10625*g.jamkerjaTotal;
 		g.waktuPokok=g.jamkerjaTotal;
 	}
 	g.totalGaji = g.gajiLembur + g.gajiPokok;
 	printf("\n\nHalo %s!",g.nama);
 	printf("\nTotal Jam Kerja : %d jam\n",g.jamkerjaTotal);
 	printf("Jam Kerja Pokok  : %d jam\n",g.waktuPokok);
 	printf("Jam Kerja Lembur : %d jam\n",g.jamLembur);
 	printf("Gaji Pokok : %d rupiah\n",g.gajiPokok);
 	printf("Total Gaji Lembur : %d rupiah\n",g.gajiLembur);
 	printf("Total Gaji Anda : %d rupiah\n",g.totalGaji);
 	kembali();

}
