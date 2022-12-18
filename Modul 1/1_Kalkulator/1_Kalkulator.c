#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	int operasi,a,b,d, ulang;
	float tambah,kurang,kali,bagi,mod,c;
	
	do{
		mengulang:
		printf("\t\t+=================================+\n");
		printf("\t\t|        PROGRAM KALKULATOR       |\n");
		printf("\t\t|           KELOMPOK 12           |\n");
		printf("\t\t+=================================+\n");
		printf("\t\tMenu Operasi Matematika\n");
		printf("\t\t1.Penjumlahan\n");
		printf("\t\t2.Pengurangan\n");
		printf("\t\t3.Perkalian\n");
		printf("\t\t4.Pembagian\n");
		printf("\t\t5.Modulus\n");
		printf("\t\t6.keluar\n");
		printf("\t\tMasukkan Operasi kalkulator yang ingin digunakan : ");
		scanf("%d", &operasi);
		
		if(operasi>0&&operasi<7){
			goto ganti;
		}
		else{
			printf("\t\t\ninput salah, silahkan coba lagi.");
			exit(0);
		}
		
		ganti:
			switch(operasi){
				case 1 :
					system("cls");
					printf("\t\t+===========================+\n");
					printf("\t\t|     OPERASI PENJUMLAHAN   |\n");
					printf("\t\t+===========================+\n");
					printf("\t\tMasukkan Angka Pertama (a) :  ");
					scanf("%d", &a);
					printf("\t\tMasukkan Angka Kedua (b) :  ");
					scanf("%d", &b);
					c = a+b;
					printf("\t\tHasil dari a+b yaitu %f \n", c);
					printf("\t\t\n\nTerima Kasih Sudah Menggunakan Kalkulator Kami");
					break;
				case 2 :
					system("cls");
					printf("\t\t+===========================+\n");
					printf("\t\t|     OPERASI PENGURANGAN   |\n");
					printf("\t\t+===========================+\n");
					printf("\t\tMasukkan Angka Pertama (a) :  ");
					scanf("%d", &a);
					printf("\t\tMasukkan Angka Kedua (b) :  ");
					scanf("%d", &b);
					c = a-b;
					printf("\t\tHasil dari a-b yaitu %f \n", c);
					printf("\t\t\n\nTerima Kasih Sudah Menggunakan Kalkulator Kami");
					break;
				case 3 :
					system("cls");
					printf("\t\t+===========================+\n");
					printf("\t\t|     OPERASI PERKALIAN     |\n");
					printf("\t\t+===========================+\n");
					printf("\t\tMasukkan Angka Pertama (a) :  ");
					scanf("%d", &a);
					printf("\t\tMasukkan Angka Kedua (b) :  ");
					scanf("%d", &b);
					c = a*b;
					printf("\t\tHasil dari a*b yaitu %f \n", c);
					printf("\t\t\n\nTerima Kasih Sudah Menggunakan Kalkulator Kami");
					break;
				case 4 :
					system("cls");
					printf("\t\t+===========================+\n");
					printf("\t\t|     OPERASI PEMBAGIAN     |\n");
					printf("\t\t+===========================+\n");
					printf("\t\tMasukkan Angka Pertama (a) :  ");
					scanf("%d", &a);
					printf("\t\tMasukkan Angka Kedua (b) :  ");
					scanf("%d", &b);
					c = a/b;
					printf("\t\tHasil dari a/b yaitu %f \n", c);
					printf("\t\t\n\nTerima Kasih Sudah Menggunakan Kalkulator Kami");
					break;
				case 5 :
					system("cls");
					printf("\t\t+===========================+\n");
					printf("\t\t|     OPERASI MODULUS       |\n");
					printf("\t\t+===========================+\n");
					printf("\t\tMasukkan Angka Pertama (a) :  ");
					scanf("%d", &a);
					printf("\t\tMasukkan Angka Kedua (b)   :  ");
					scanf("%d", &b);
					d = a%b;
					printf("\t\tHasil dari a modulus b yaitu %d \n", d);
					printf("\t\t\n\nTerima Kasih Sudah Menggunakan Kalkulator Kami");
					break;
				case 6 : 
					printf("\t\t\n\nTerima Kasih Sudah Menggunakan Kalkulator Kami");
					break;		
			}
		printf("\t\t\n1. Ulang");
		printf("\t\t\n2. Tidak");
		printf("\t\t\nApakah anda ingin mengulang kalkulator? ");
		scanf("%d", &ulang);
		system("cls");
		
	}while(ulang==1);
	printf("\t\t\nSampai Jumpa!");
		
	
}
