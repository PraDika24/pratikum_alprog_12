#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAKS 100

void perkalian();
void penjumlahan();
void hitung_tranpose();
void matriks_perkalian();
void matriks_penjumlahan();
int matriks1[MAKS][MAKS], matriks2[MAKS][MAKS];
int bil, i,j, baris1, kolom1, baris2, kolom2, isiMatriks2=0, isiOrdo=0;

int cek_input(int *jml){
char buff[1024];
char term;
if(fgets(buff, sizeof(buff), stdin) != NULL && sscanf(buff, "%d %c", jml, &term) == 1){
        if(isiOrdo==1){
            if(isiMatriks2==1){
                if(kolom1 != *jml){
                    printf("\n\n!!Total baris  ke-2 harus sama dengan total kolom ke-1!!\n");
                    printf("Input ulang total baris!");
                    printf("\n\n[Baris] >> ");
                    return 0;
                }
                else if(*jml<1){
                    printf("\n\n Input ordo tidak sesuai, silahkan input ulang!\n");
                    return 0;
                }
                }
        }
        return 1;
}
printf("\n\nInput yang anda masukkan salah >:(\n");
return 0;
}
void vlds_baca(int *var, char *prompt){
while(1){
printf(prompt);
if(cek_input(var))
break;
}
}
void range_Validasi_Int(int *var, int range1, int range2, char *nama){
    while(1){
        vlds_baca(var, nama);
        fflush(stdin);
        if(*var >= range1  &&*var <= range2)
        break;
        printf("\n\nInput yang anda masukkan salah\n");
    }
}
void range_Validasi_Int_Baca(int *var, int range1, int range2, char *nama){
    while(1){
        vlds_baca(var, nama);
        fflush(stdin);
        if(*var == range1 || *var == range2)
        break;
        printf("\n\nInput yang anda masukkan salah\n");
    }
}
void matriks_perkalian (void){
    isiOrdo=1;
    printf("Input ordo matriks ke-1: \n");
    printf("Baris : ");
    vlds_baca(&baris1, "");
    printf("Kolom : ");
    vlds_baca(&kolom1, "");
    isiOrdo=0;
    printf("Input elemen matriks ke-1: \n");
    for (i=0;i<baris1;i++){
        for (j=0;j<kolom1;j++){
            printf("Matriks [%d][%d] :",i,j);
            vlds_baca(&matriks1[i][j],"");
        }
    }
    printf("\n======================================\n\n");
    isiOrdo=1;
    printf("Input ordo matriks ke-2: \n");
    isiMatriks2=1;
    printf("Baris : ");
    vlds_baca(&baris2, "");
    isiMatriks2=0;
    printf("Kolom : ");
    vlds_baca(&kolom2, "");
    isiOrdo=0;
    printf("Input elemen matriks ke-2: \n");
    for (i=0;i<baris2;i++){
        for (j=0;j<kolom2;j++){
            printf("Matriks [%d][%d] : ",i,j);
            vlds_baca(&matriks2[i][j],"");
        }
    }
}
void perkalian (int baris1,int kolom1, int baris2, int kolom2, int matriks_1[MAKS][MAKS] , int matriks_2[MAKS][MAKS]){
    int i, j, k, matriks_3[MAKS][MAKS];
    system("cls");
    printf("=======================================\n");
    printf("|           PERKALIAN MATRIKS         |\n");
    printf("=======================================\n\n");
    printf("------------Matriks Pertama------------\n");
    for(i=0 ; i<baris1 ; i++){
            for(j=0 ; j<kolom1 ; j++){
                printf("%d", matriks1[i][j]);
                if(j==(kolom1-1)) printf("\n");
                else printf(" ");
            }
    }
    printf("------------Matriks Kedua------------\n");
    for(i=0 ; i<baris2 ; i++){
        for(j=0 ; j<kolom2 ; j++){
            printf("%d", matriks2[i][j]);
            if(j==(kolom2-1)) printf("\n");
            else printf(" ");
        }
    }
    printf("----------Hasil Perkalian-----------\n");
    for (i=0;i<baris1;i++){
        for (j=0;j<kolom2;j++){
            matriks_3[i][j] = 0;
            for (k=0;k<baris2;k++){
                matriks_3[i][j] =matriks_3[i][j]+(matriks_1[i][k] * matriks_2[k][j]);
            }
            printf("%d", matriks_3[i][j]);
            if (j == (kolom2-1)) printf("\n");
            else printf(" ");
        }
    }
}
void matriks_penjumlahan (void){
    isiOrdo=1;
    printf("Input ordo matriks ke-1: \n");
    printf("Baris : ");
    vlds_baca(&baris1, "");
    printf("Kolom : ");
    vlds_baca(&kolom1, "");
    isiOrdo=0;
    printf("Input elemen matriks ke-1: \n");
    for (i=0;i<baris1;i++){
            for (j=0;j<kolom1;j++){
            printf("Matriks [%d][%d] :",i,j);
            vlds_baca(&matriks1[i][j],"");
            }
    }
    printf(" \n===================================\n\n");
    isiOrdo=1;
    printf("Input ordo matriks ke-2: \n");
    printf("Baris : ");
    vlds_baca(&baris2, "");
    printf("Kolom : ");
    vlds_baca(&kolom2, "");
    printf("Input elemen matriks ke-2: \n");
    isiOrdo=0;
    for (i=0;i<baris2;i++){
        for (j=0;j<kolom2;j++){
            printf("Matriks [%d][%d] : ",i,j);
            vlds_baca(&matriks2[i][j],"");
        }
    }
}
void penjumlahan(int barisa, int koloma, int barisb, int kolomb, int matriks_1[MAKS][MAKS], int matriks_2[MAKS][MAKS]){
    int matriks_3[MAKS][MAKS], i, j, barisx, kolomx;
    if(barisa>barisb){
            barisx=barisa;
    }else{
            barisx=barisb;
    }
    if(koloma>kolomb){
        kolomx=koloma;
    }else{
        kolomx=kolomb;
    }
    system("cls");
    printf("=======================================\n");
    printf("|         PENJUMLAHAN MATRIKS         |\n");
    printf("=======================================\n\n");
    printf("------------Matriks Pertama------------\n");
    for(i=0 ; i<baris1 ; i++){
        for(j=0 ; j<kolom1 ; j++){
            printf("%d", matriks1[i][j]);
            if(j==(kolom1-1)) printf("\n");
            else printf(" ");
        }
    }
    printf("------------Matriks Kedua------------\n");
    for(i=0 ; i<baris2 ; i++){
        for(j=0 ; j<kolom2 ; j++){
        printf("%d", matriks2[i][j]);
        if(j==(kolom2-1)) printf("\n");
        else printf(" ");
        }
    }
    printf("----------Hasil Penjumlahan-----------\n");
    for(i=0 ; i<barisx ; i++){
        for(j=0 ; j<kolomx ; j++){
            matriks_3[i][j]=matriks_1[i][j]+matriks_2[i][j];
            printf("%d", matriks_3[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void hitung_tranpose(){
    int i, j, baris, kolom;
    isiOrdo=1;
    printf("Input ordo matriks: \n");
    printf("Baris : ");
    vlds_baca(&baris, "");
    printf("Kolom : ");
    vlds_baca(&kolom, "");
    isiOrdo=0;
    int matriks_1[baris][kolom], matriks_2[kolom][baris];
    printf("Input elemen matriks: \n");
    for (i=0;i<baris;i++){
            for (j=0;j<kolom;j++){
                printf("Matriks [%d][%d] : ",i,j);
                vlds_baca(&matriks_1[i][j],"");
            }
    }
    for(i=0 ; i<baris ; i++){
        for (j=0; j<kolom ; j++){
        matriks_2[j][i]=matriks_1[i][j];
        }
    }
    system("cls");
    printf("=======================================\n");
    printf("|          TRANSPOSE MATRIKS          |\n");
    printf("=======================================\n\n");
    printf("-----------SEBELUM TRANSPOSE-----------\n");
    for(i=0 ; i<baris ; i++){
        for(j=0 ; j<kolom ; j++){
        printf("%d", matriks_1[i][j]);
        printf(" ");
        }
    printf("\n");
    }
    printf("-----------SETELAH TRANSPOSE-----------\n");
    for(i=0 ; i<kolom ; i++){
        for(j=0 ; j<baris ; j++){
            printf("%d", matriks_2[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int input, read;
	do{
		printf("Pilih menu matriks: \n");
		printf("[1] Perkalian\n");
		printf("[2] Penjumlahan\n");
		printf("[3] Transpose\n");
		printf("[0] Keluar\n");
		
		range_Validasi_Int(&input, 0, 3, "Input menu matriks yang dipilih: ");
		system("cls");
		switch(input){
		    case 1:
            system("cls");
            printf("=======================================\n");
            printf("|          PERKALIAN MATRIKS          |\n");
            printf("=======================================\n\n");
            matriks_perkalian();
            perkalian(baris1,kolom1,baris2,kolom2,matriks1,matriks2);
            break;
            case 2:
            system("cls");
            printf("=======================================\n");
            printf("|         PENJUMLAHAN MATRIKS         |\n");
            printf("=======================================\n\n");
            matriks_penjumlahan();
            penjumlahan(baris1,kolom1,baris2,kolom2,matriks1,matriks2);
            break;
            case 3:
            system("cls");
            printf("=======================================\n");
            printf("|          TRANSPOSE MATRIKS          |\n");
            printf("=======================================\n\n");
            hitung_tranpose();
            break;
            default:
            printf("TERIMA KASIH! SILAHKAN DATANG KEMBALI\n");
            }
            printf("\nIngin mengulang program?\n");
            range_Validasi_Int_Baca(&read,0,9, "(0 = tidak / 9 = iya):");
            system("cls");
	}while(read == 9);
system("pause");
return 0;
}
