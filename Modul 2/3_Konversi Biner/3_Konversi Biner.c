#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

void judul();
void reset();
int masukkanDesimal();
int masukkanBiner();
int desimalMenjadiBiner();
int binerMenjadiDesimal();

int angka, hasil, pilih, biner, desimal, sisabagi, hasilbagi;

int main(){
    judul();
    printf(" Jenis Konversi :\n 1. Desimal ke Biner\n 2. Biner ke Desimal\n");
    printf("\n Masukkan Pilihan : ");
    scanf("%d", &pilih);
    if (pilih == 1){
        system("cls");
        judul();
        printf(" 1. Desimal ke Biner");
        printf("\n\n Masukkan Angka Desimal : ");
        desimal = masukkanDesimal();
        hasil = desimalMenjadiBiner(angka);
    }
    else if (pilih == 2){
        system("cls");
        judul();
        printf(" 2. Biner ke Desimal");
        printf("\n\n Masukkan Angka Biner : ");
        biner = masukkanBiner();
        hasil = binerMenjadiDesimal(angka);
    }
    else{
        printf("\n Input Invalid");
        sleep(2);
        system("cls");
        main();
    }
        printf("\n Hasil Konversi\t : %d\n\n", hasil);
        reset();
    return 0;
}
void judul(){
    printf("+================================+\n");
    printf("||      Program Konversi Biner  ||\n");
    printf("+================================+\n");
}

int masukkanDesimal(){
    char ch, *data;
    int cek = 0;
    data = (char *)malloc(sizeof(char));
    while ((ch = getch()) != 13){
        if ((ch >= '0' && ch <= '9')){
            printf("%c", ch);
            data[cek] = ch;
            cek++;
        }
    }
    data[cek] = '\0';
    return atoi(data);
}
int masukkanBiner(){
    char ch, *data;
    int cek = 0;
    data = (char *)malloc(sizeof(char));
    while ((ch = getch()) != 13){
        if (ch == '0' || ch == '1'){
            printf("%c", ch);
            data[cek] = ch;
            cek++;
        }
    }
    data[cek] = '\0';
    return atoi(data);
}
int desimalMenjadiBiner(int angka){
    int biner = 0;
    int bobot = 1;
    angka = desimal;
    if (angka != 0 && angka != 1){
        while (desimal != 0){
            sisabagi = desimal % 2;
            biner = biner + sisabagi * bobot;
            desimal = desimal / 2;
            bobot = bobot * 10;
        }
    }
    else{
        biner = angka;
    }
    return biner;
}
int binerMenjadiDesimal(int angka){
    int desimal = 0;
    int bobot = 1;
    angka = biner;
    while (biner != 0){
        sisabagi = biner % 10;
        desimal = desimal + sisabagi * bobot;
        biner = biner / 10;
        bobot = bobot * 2;
    }
    return desimal;
}

void reset(){
    int ulang;
    printf("\n Ingin Mengulangi? [y / t] ");
    ulang = getch();
    if(ulang == 'y' || ulang == 'Y'){
        system("cls");
        main();
    }
    else if (ulang == 't' || ulang == 'T'){
        return;
    }
    else{
        system("cls");
        judul();
        printf(" Input Invalid\n");
        reset();
    }
}
