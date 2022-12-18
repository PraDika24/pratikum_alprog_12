#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int input_bln();
int input_tgl(int bln);
void keluar();
void pilihan_ulang();
void menu_utama();
int main();

int input_bln(){
    char masukan[100];
    int i = 0;
    int isi_depan = 0;
    int salah = 0;
    int hasil;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    if(strcmp(masukan, "Januari") == 0){
        isi_depan = 1;
    }else if(strcmp(masukan, "Februari") == 0){
        isi_depan = 2;
    }else if(strcmp(masukan, "Maret") == 0){
        isi_depan = 3;
    }else if(strcmp(masukan, "April") == 0){
        isi_depan = 4;
    }else if(strcmp(masukan, "Mei") == 0){
        isi_depan = 5;
    }else if(strcmp(masukan, "Juni") == 0){
        isi_depan = 6;
    }else if(strcmp(masukan, "Juli") == 0){
        isi_depan = 7;
    }else if(strcmp(masukan, "Agustus") == 0){
        isi_depan = 8;
    }else if(strcmp(masukan, "September") == 0){
        isi_depan = 9;
    }else if(strcmp(masukan, "Oktober") == 0){
        isi_depan = 10;
    }else if(strcmp(masukan, "November") == 0){
        isi_depan = 11;
    }else if(strcmp(masukan, "Desember") == 0){
        isi_depan = 12;
    }else{
        while(masukan[i] != '\0'){
            if(masukan[0] == '.'){
                salah = 1;
                masukan[0] = '\0';
            }else if(masukan[i] == ' '){
                salah = 1;
                masukan[i] = '\0';
            }else if(masukan[i]>='0' && masukan[i]<='9'){
                isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                i++;
            }else{
                salah = 1;
                masukan[i] = '\0';
            }
        }
    }

    hasil = isi_depan;

    if(salah == 1){
        printf("- Masukkan salah! Tolong masukkan ulang : ");
        return input_bln();
    }else if((hasil < 1) || (hasil > 12)){
        printf("- Masukkan harus 1 - 12 ! Masukkan nilai yang benar : ");
        return input_bln();
    }else{
        return hasil;
    }
}

int input_tgl(int bln){
    char masukan[100];
    int i = 0;
    int isi_depan = 0;
    int salah = 0;
    int hasil;
    int batas_tgl;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    if((bln == 1) || (bln == 3) || (bln == 7) || (bln == 8) || (bln == 10) || (bln == 12)){
        batas_tgl = 31;
    }else if((bln == 4) || (bln == 6) || (bln == 9) || (bln == 11)){
        batas_tgl = 30;
    }else if(bln == 2){
        batas_tgl = 29;
    }

    while(masukan[i] != '\0'){
        if(masukan[0] == '.'){
            salah = 1;
            masukan[0] = '\0';
        }else if(masukan[i] == ' '){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i]>='0' && masukan[i]<='9'){
            isi_depan = (isi_depan * 10) + (masukan[i] - 48);
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    hasil = isi_depan;

    if(salah == 1){
        printf("- Masukkan salah! Masukkan angka yang benar : ");
        return input_tgl(bln);
    }else if((hasil < 1) || (hasil > batas_tgl)){
        printf("- Masukkan harus 1 - %d ! Masukkan nilai yang benar : ", batas_tgl);
        return input_tgl(bln);
    }else{
        return hasil;
    }
}

void keluar(){
    printf("\n  Terima Kasih Telah Menggunakan Program Kami");
	Sleep(1);
}

void pilihan_ulang(){
    char ulang[1];

    printf("\n   Lakukan lagi? yes/no(y/n) : ");
    scanf("%s", &ulang);
    fflush(stdin);

    if((strcmp(ulang, "y") != 0) && (strcmp(ulang, "n") != 0)){
        printf("   Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang();
    }else if((strcmp(ulang, "y") == 0)){
        system("cls");
        menu_utama();
    }else{
        keluar();
    }
}

void menu_utama(){
    char tgl;
    char bln;

    printf(" ================================================\n");
    printf("|                     MODUL 2                    |\n");
    printf("|            PROGRAM MENENTUKAN ZODIAK           |\n");
    printf("|                 OLEH KELOMPOK 12               |\n");
    printf(" ================================================\n");

    printf("\nMasukkan bulan lahir anda\t: ");
    bln=input_bln();
    printf("\nMasukkan tanggal lahir anda\t: ");
    tgl=input_tgl(bln);

    printf("================================================\n");
    printf("           Zodiak anda adalah ");

    //Mencari Zodiak
    if((tgl>=21&&bln==3)||(tgl<=19&&bln==4)){
        printf("Aries");
    }else if((tgl>=20&&bln==4)||(tgl<=20&&bln==5)){
        printf("Taurus");
    }else if((tgl>=21&&bln==5)||(tgl<=20&&bln==6)){
        printf("Gemini");
    }else if((tgl>=21&&bln==6)||(tgl<=22&&bln==7)){
        printf("Cancer");
    }else if((tgl>=23&&bln==7)||(tgl<=22&&bln==8)){
        printf("Leo");
    }else if((tgl>=23&&bln==8)||(tgl<=22&&bln==9)){
        printf("Virgo");
    }else if((tgl>=23&&bln==9)||(tgl<=22&&bln==10)){
        printf("Libra");
    }else if((tgl>=23&&bln==10)||(tgl<=21&&bln==11)){
        printf("Scorpio");
    }else if((tgl>=22&&bln==11)||(tgl<=21&&bln==12)){
        printf("Sagitarius");
    }else if((tgl>=22&&bln==12)||(tgl<=19&&bln==1)){
        printf("Capricorn");
    }else if((tgl>=20&bln==1)||(tgl<=18&&bln==2)){
        printf("Aquarius");
    }else if((tgl>=19&&bln==2)||(tgl<=20&&bln==3)){
        printf("Pisces");
    }

     printf("\n================================================\n");
     pilihan_ulang();
}


int main(){
    system("cls");
    menu_utama();

    return 0;
}

