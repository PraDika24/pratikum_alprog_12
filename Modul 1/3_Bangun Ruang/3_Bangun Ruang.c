#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PHI 3.14

void menu();
void ulangi();
void tabung();
void bola();
void limas();
void prismasegitiga();
void kerucut();

int main(){
    system("cls");
    system("pause");
    system("cls");
    menu();
    return 0;
}

double input(){
    double pilihan, select;
    char enter;
    pilihan = scanf("%lf%c", &select, &enter);
    if (pilihan != 2 || enter != '\n'){
        getchar();
        printf("Hanya masukan angka. Tolong masukan ulang : ");
        return input();
    }else if (select<=0){
        printf("Pilihan Tidak Tersedia, Tolong Masukan Pilihan yang Ada : ");
        return input();
    }else{
        return select;
    }
}

void ulangi(){
    double input;
    printf("\n\nTekan tombol enter untuk melanjutkan program.");
    getchar();
    system("cls");
    printf("\nIngin Menghitung Kembali?\n\n");
    printf("1. Kembali Menghitung \n");
    printf("2. Keluar\n");
    printf("Pilih 1-2 : ");
    scanf("%lf",&input);
        getchar();
    if(input==1)
    {
    system("cls");
    main();
    }else if (input==2) {
        system("cls");
        printf("\n=============================================\n");
        printf("   Terima kasih telah menggunakan Program ini  \n");
        printf("\n=============================================\n");
        getchar();
        exit(1);
    }else{
        printf("Pilihan salah, Masukan Pilihan 1-2!");
        getchar();
        ulangi();
    }
}


void menu(){
    double pilihan;
    int pilih;
    printf("\n\t===================================================");
    printf("\n\t   PROGRAM PERHITUNGAN LUAS PERMUKAAN DAN VOLUME   ");
    printf("\n\t===================================================");
    printf("\n\t------------------MENU PILIHAN :-------------------");
    printf("\n\t 1. Tabung");
    printf("\n\t 2. Bola");
	printf("\n\t 3. Limas Segiempat");
	printf("\n\t 4. Prisma");
	printf("\n\t 5. Kerucut");
	printf("\n\t 6. Keluar");
	printf("\n\t==================================================\n");

   printf("Pilih 1-6 : ");
    pilihan = input();
    pilih = ceil(pilihan);
    if(pilih == pilihan){
        system("cls");
        switch(pilih){
            case 1:
                tabung();
                ulangi();
            break;
            case 2:
                bola();
                ulangi();
            break;
            case 3:
                limas();
                ulangi();
            break;
            case 4:
                prismasegitiga();
                ulangi();
            break;
            case 5:
                kerucut();
                ulangi();
            break;
            case 6:
                printf("\n=============================================\n");
                printf("   Terima kasih telah menggunakan Program ini  \n");
                printf("\n=============================================\n");
                exit(1);
            break;
            default :
                printf("Hanya masukan angka 1 sampai 6. Tolong masukan ulang pilihan");
                getchar();
                ulangi();
            break;
        }
    }else{
        printf("Hanya masukan angka 1 sampai 6.Tolong masukan ulang pilihan");
        ulangi();
    }
}

double lp_tabung (double jari, double tinggi){
double luas;
    luas = (2*PHI *jari*jari) + (PHI*2*jari*tinggi);
return luas;
}

double v_tabung (double jari, double tinggi){
double volume;
    volume = PHI*jari*jari*tinggi;
return volume;
}

void tabung(){
    double jari, tinggi,pilih;
    printf("=======================Tabung=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Volume Tabung\n");
	printf(" 2. Menghitung Luas Permukaan Tabung\n");
	printf(" 3. Kembali ke Menu\n");
    printf("====================================================\n\n");
    printf("Pilih 1-3 : ");
	pilih=input();
    if(pilih==1){
        printf("\nMasukkan Nilai Jari-Jari dan Tinggi Untuk Menghitung Volume Tabung\n");
        printf("Input Jari-Jari (cm)\t: ");
        jari =input();
        printf("Input Tinggi (cm)\t: ");
        tinggi=input();
        printf("\nVolume Tabung \t= %.2lf cm3", v_tabung(jari, tinggi));
    }else if (pilih==2){
        printf("\nMasukkan Nilai Jari-Jari dan Tinggi Untuk Menghitung Luas Permukaan tabung\n");
        printf("Input Jari-Jari (cm)\t: ");
        jari =input();
        printf("Input Tinggi (cm)\t: ");
        tinggi=input();
        printf("\nLuas Permukaan Tabung \t= %.2lf cm2", lp_tabung(jari,tinggi));
        }
        else if(pilih==3){
        menu();
        }
        else{
            printf("Pilihan salah, Masukan Angka 1-3!");
            ulangi();
        }

}

double lp_bola (double jari){
double luas;
    luas = 4 * PHI * jari * jari;
return luas;
}

double v_bola (double jari){
double volume;
    volume = 4/3 * PHI * jari * jari * jari;
return volume;
}

void bola(){
    double jari,pilih;
    printf("=======================Bola=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Volume Bola\n");
	printf(" 2. Menghitung Luas Permukaan Bola\n");
	printf(" 3. Kembali ke Menu\n");
    printf("==================================================\n\n");
    printf("Pilih 1-3 : ");
    pilih=input();
    if(pilih==1){
        printf("\nMasukkan Nilai Untuk Menghitung Volume Bola\n");
        printf("Input Jari-jari (cm)\t: ");
        jari = input();
         printf("\nVolume Bola \t= %.2lf cm3", v_bola(jari));
    }else if(pilih==2){
        printf("\nMasukkan Nilai Untuk Menghitung Luas Permukaan Bola\n");
        printf("Input Jari-jari (cm)\t: ");
        jari = input();
        printf("\nLuas Permukaan Bola \t= %.2lf cm2", lp_bola(jari));
    }
        else if(pilih==3){
        menu();
        }
        else{
            printf("Pilihan salah, Masukan Angka 1-3!");
            ulangi();
        }
}

double v_limas (double sisi, double tinggi_l){
    double volume;
    volume = 1/3*(sisi*sisi*tinggi_l);
return volume;
}

double lp_limas (double sisi, double tinggi){
    double luas;
    double tinggi_s, luas_s;
    tinggi_s = sqrt((sisi*0.5)*(sisi*0.5)+(tinggi*tinggi));
    luas_s = 0.5*sisi*tinggi_s;
    luas = (sisi*sisi) + (4*luas_s);
return luas;
}

void limas(){
    double sisi, tinggi_s,pilih;
    printf("=======================Limas Segiempat=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Volume Limas Segiempat\n");
	printf(" 2. Menghitung Luas Permukaan Limas Segiempat\n");
	printf(" 3. Kembali ke Menu\n");
    printf("=============================================================\n\n");
    printf("Pilih 1-3 : ");
    pilih=input();
    if(pilih==1){
        printf("\nMasukkan Nilai Sisi Untuk Menghitung Volume Limas Segiempat\n");
        printf("Input Sisi (cm)\t: ");
        sisi = input();
        printf("Input Tinggi Limas (cm)\t: ");
        tinggi_s = input();
        printf("\nVolume Limas segiempat = %.2lf cm3", v_limas(sisi,tinggi_s));
    }else if(pilih==2){
        printf("\nMasukkan Nilai Sisi Untuk Menghitung Luas Permukaan Limas Segiempat\n");
        printf("Input Sisi (cm)\t: ");
        sisi = input();
        printf("Input Tinggi Limas (cm)\t: ");
        tinggi_s = input();
        printf("\nLuas Permukaan Limas sgiempat = %.2lf cm2", lp_limas(sisi,tinggi_s));
    }
    else if(pilih==3){
        menu();
    }
    else{
        printf("Pilihan salah, Masukan Angka 1-3!");
        ulangi();
    }


}

double lp_prisma(double alas, double sisib, double sisic, double tinggi_p, double tinggi_s){
    double luas;
    double luassegitiga, luasselimut ;
    luassegitiga = alas * tinggi_s /2;
    luasselimut = (alas + sisib + sisic)*tinggi_p;
    luas = 2*luassegitiga + luasselimut;
return luas;
}

double v_prisma(double alas, double tinggi_p, double tinggi_s) {
double volume;
    double luasalas;
    luasalas = alas*tinggi_s/2;
    volume = luasalas*tinggi_p;
return volume;
}
void prismasegitiga(){
    double alas, sisiB, sisiC, tinggi_s, tinggi_p,pilih;
    printf("=======================Prisma Segitiga=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Volume Prisma Segitiga\n");
	printf(" 2. Menghitung Luas Permukaan Prisma Segitiga\n");
	printf(" 3. Kembali ke Menu\n");
	printf("=============================================================\n\n");
    printf("Pilih 1-3 : ");
	pilih=input();
    if(pilih==1){
        printf("\nMasukkan Nilai Sisi Untuk Menghitung Volume Prisma Segitiga\n");
        printf("Input Sisi Alas (cm)\t: ");
        alas = input();
        printf("Input Tinggi Prisma (cm)\t: ");
        tinggi_p = input();
        printf("Input Tinggi Segitiga (cm)\t: ");
        tinggi_s = input();
        printf ("===============================================");
        printf("\nVolume Prisma Segitiga\t= %lf cm3", v_prisma(alas, tinggi_s, tinggi_p) );
    }else if(pilih==2){
        printf("\nMasukkan Nilai Untuk Menghitung Luas Permukaan Prisma Segitiga\n");
        printf("Input sisi Alas (cm)\t: ");
        alas = input();
        printf("Input Sisi 1 (cm)\t: ");
        sisiB = input();
        printf("Input Sisi 2 (cm)\t: ");
        sisiC = input();
        printf("Input Tinggi Prisma (cm)\t: ");
        tinggi_p = input();
        printf("Input Tinggi Segitiga (cm)\t: ");
        tinggi_s = input();
        printf ("===============================================");
        printf("\nLuas Permukaan Prisma \t\t= %.2lf cm2", lp_prisma(alas, sisiB, sisiC, tinggi_p, tinggi_s));
        }
        else if(pilih==3){
        menu();
        }
        else{
            printf("Pilihan salah, Masukan Angka 1-3!");
            ulangi();
        }

}

double lp_kerucut(double jari, double tinggi_k){
    double luas;
    double sisimiring ;
    sisimiring = sqrt((jari*jari)*(tinggi_k*tinggi_k));
    luas = (PHI*jari)*(jari + sisimiring);
    return luas;
}

double v_kerucut(double jari, double tinggi_k){
    double volume;
    volume = 1/3 *(PHI*jari*jari*tinggi_k);
    return volume;
}

void kerucut(){
    double jari, tinggi_k,pilih;
    printf("=======================Kerucut=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Volume Kerucut\n");
	printf(" 2. Menghitung Luas Permukaan Kerucut\n");
	printf(" 3. Kembali\n");
	printf("=====================================================\n\n");
    printf("Pilih 1-3 : ");
    pilih=input();
    if(pilih==1){
        printf("\nMasukkan Nilai Sisi Untuk Menghitung Volume Kerucut\n");
        printf("Input Jari-jari (cm)\t: ");
        jari = input();
        printf("Input Tinggi Keurucut (cm)\t: ");
        tinggi_k = input();
        printf("\nVolume Kerucut \t= %.2lf cm3", v_kerucut(jari,tinggi_k) );
    }else if (pilih==2){
        printf("\nMasukkan Nilai Sisi Untuk Menghitung Luas Permukaan Kerucut\n");
        printf("Input Jari-jari (cm)\t: ");
        jari = input();
        printf("Input Tinggi Keurucut (cm)\t: ");
        tinggi_k = input();
        printf("\nLuas Permukaan Kerucut \t= %.2lf cm2", lp_kerucut(jari,tinggi_k));
        }
        else if(pilih==3){
        menu();
        }
        else{
            printf("Pilihan salah, Masukan Angka 1-3!");
            ulangi();
        }
}





