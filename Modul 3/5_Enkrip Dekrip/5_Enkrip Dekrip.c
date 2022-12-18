#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>		//untuk memanipulasi karakter
                        //belum di validasi
int main();

int clean(){
	while(getchar() != '\n');
	return 1;
}

void spam(void){
    char spam;
    while ((spam = getchar()) != '\n' && spam != EOF) ;
}

int enkripsi()          // fungsi enkripsi
{
	char text[100], ch;
	char enterCheck;
	int i, key, k, check;
	int exit = 1;
	do{
		system("cls");
		printf("\t\t\t\t=========================================================\n");
        printf("\t\t\t\t||                   PROGRAM ENKRIPSI                  ||\n");
        printf("\t\t\t\t=========================================================\n");
	    printf("\t\t\t\tMasukan pergeseran huruf : ");
		while(((scanf(" %d%c", &key, &enterCheck) != 2 || enterCheck != '\n') && clean() || key<=0 || key >26)){
		        printf("\t\t\t\tInput Anda Salah! Masukkan Bilangan yang Benar!\n ");
		        printf("\t\t\t\tMasukkan pergeseran huruf : ");
                }

		printf("\t\t\t\tMasukan text yang akan di enkripsi : ");
		scanf("%[^\n]c",&text);
		k = strlen (text);

	    for (i=0;i<k; i++){
	    	if (!isdigit(text[i]))
	        {
	        	check = 1;
//	            key = 3;

				for(i = 0; text[i] != '\0'; ++i){
					ch = text[i];
					if(ch >= 'a' && ch <= 'z'){
						ch = ch + key;
						if(ch > 'z'){
							ch = ch - 'z' + 'a' - 1;
						}
						text[i] = toupper(ch);
					}
					else if(ch >= 'A' && ch <= 'Z'){
						ch = ch + key;
						if(ch > 'Z'){
							ch = ch - 'Z' + 'A' - 1;
						}
						text[i] = ch;
					}
				}
				printf("\t\t\t\tHasil Enkripsi : %s\n", text);

			}else{

				printf("\t\t\tInputan yang anda masukkan salah, pilih menu dibawah ini");
				break;
			}
		}

		printf("\n\t\t\t\tTekan '1' untuk mengulang, tekan '0' untuk keluar, tekan 2 untuk ke menu :");
		scanf("%d", &exit);
		if(exit == 2){
			main();
		}

	}while(exit == 1);
	return 0;
}

int dekripsi()          // fungsi deskripsi
{
	char text[100], ch;
	char enterCheck;
	int i,key,k,check, exit;
	do{
		system("cls");
        printf("\t\t\t\t=========================================================\n");
        printf("\t\t\t\t||                   PROGRAM DEKRIPSI                  ||\n");
        printf("\t\t\t\t=========================================================\n");
	    printf("\t\t\t\tMasukan pergeseran huruf : ");
		while(((scanf(" %d%c", &key, &enterCheck) != 2 || enterCheck != '\n') && clean() || key<=0 || key >26)){
		        printf("\t\t\t\tMasukkan Bilangan yang Valid\n ");
		        printf("\t\t\t\tMasukkan pergeseran huruf : ");
	    	}
		printf("\t\t\t\tMasukan text yang akan di dekripsi: ");
		scanf(" %[^\n]c", &text);
		k = strlen (text);

		for (i=0;i<k; i++){
	    	if (!isdigit(text[i]))
	        {
	        	check = 1;
				for(i = 0; text[i] != '\0'; ++i){
				ch = text[i];

				if(ch >= 'a' && ch <= 'z'){
					ch = ch - key;
					if(ch < 'a'){
						ch = ch + 'z' - 'a' + 1;
					}
					text[i] = ch;
				}
				else if(ch >= 'A' && ch <= 'Z'){
					ch = ch - key;
					if(ch < 'A'){
						ch = ch + 'Z' - 'A' + 1;
					}
					text[i] = tolower(ch);
				}
			}

			printf("\t\t\t\tHasil Dekripsi : %s\n", text);

			}else{

				printf("\t\t\t\tInputan yang anda masukkan salah, pilih menu dibawah ini");
				break;
			}
		}
	printf("\n\t\t\t\tTekan '1' untuk mengulang, tekan '0' untuk keluar, tekan 2 untuk ke menu :");
		scanf("%d", &exit);
		if(exit == 2){
			main();
		}

	}while(exit == 1);
	return 0;
}

 int main(void){        // fungsi untuk menampilkan menu
    int menu;
    char enterCheck;
    char opsi[3];

    fflush(stdin);
    system("cls");
    printf("\t\t\t\t=========================================================\n");
    printf("\t\t\t\t||              Program Enkripsi dan Dekripsi          ||\n");
    printf("\t\t\t\t||                        Kelompok 12                  ||\n");
    printf("\t\t\t\t=========================================================\n");
    printf("\t\t\t\t||  I Gede Agus Handika Pratama            2205551026  ||\n");
    printf("\t\t\t\t||  I Gusti Ngurah Agung Candra Wijaya     2205551092  ||\n");
    printf("\t\t\t\t||  Putu Indri Cahyani                     2205551097  ||\n");
    printf("\t\t\t\t||  Luh Putu Christina Ayuni               2205551098  ||\n");
    printf("\t\t\t\t||  Eka Risti Shefanny                     2205551102  ||\n");
    printf("\t\t\t\t||  Satria Andrew Tan                      2205551120  ||\n");
    printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tPilih operasi yang diinginkan:    		\n");
	printf("\t\t\t\t[1] Enkripsi                         		\n");
	printf("\t\t\t\t[2] Dekripsi                         		\n");
	printf("\t\t\t\t[3] Exit                         			\n");
	printf("\t\t\t\tMasukkan Menu : ");
	while(((scanf(" %d%c", &menu, &enterCheck) != 2 || enterCheck != '\n') && clean() || menu<=0 || menu >3)){
	printf("\t\t\t\tInput Anda Salah! Masukkan Bilangan yang Benar!\n ");
	printf("\t\t\t\tMasukkan Menu : ");
	}

    if(menu == 1){
        printf("1");
        system("cls");
        enkripsi();
    }
    else if(menu == 2){
        printf("2");
        system("cls");
        dekripsi();

	}
    else if(menu == 3){
        system("cls");
        printf("\t\t\t=====TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI=====\n");
        exit(0);
    }


return(0);
}
