#include <stdio.h>
#include <stdlib.h>

int validInt(int *var){
	char buff[1020];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%d %c", var, &cek) == 1) {
			return 1;
		}
	}
}
void reVldInt(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validInt(var)) {
			break;
		}
		printf("Input hanya boleh  berupa angka!! \n");
		printf("\n");
	}
}

int validFloat(float *var){
	char buff[1020];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%f %c", var, &cek) == 1) {
			return 1;
		}
	}
}
void reVldFloat(float *var, char *prompt){
	while(1){
		printf(prompt);
		if(validFloat(var)) {
			break;
		}
		printf("Input hanya boleh  berupa tipe data float! \n");
		printf("\n");
	}
}
void perhitungan()
{
    int absensi;
    float tugas, quiz, uts, uas;
    float hasil_absensi;
    float hitung;

    printf("\n==================================================================\n");
	reVldInt(&absensi, "masukan jumlah kehadiran (maksimal 15)    : ");
	fflush(stdin);
	reVldFloat(&tugas, "masukan nilai tugas : ");
	fflush(stdin);
	reVldFloat(&quiz, "masukan nilai quiz  : ");
    fflush(stdin);
    reVldFloat(&uts, "masukan nilai uts   : ");
    fflush(stdin);
	reVldFloat(&uas, "masukan nilai uas   : ");
	fflush(stdin);
	printf("\n==================================================================\n");
    hasil_absensi = (absensi*100)/15;
    hitung = (hasil_absensi*0.05) + (tugas*0.2) + (quiz*0.15) + (uts*0.3) + (uas*0.3);
    printf("Nilai Total = %.2f\n", hitung);

      if ( hitung<45){
        printf("Nilai Akhir  = E");
      }
      else if(hitung>=45 && hitung<50){
        printf("Nilai Akhir = D");
      }
      else if(hitung>=50 && hitung<55){
        printf("Nilai Akhir = D+");
      }
      else if(hitung>=55 && hitung<60){
        printf("Nilai Akhir = C");
      }
    else if(hitung>=60 && hitung<65){
    printf("Nilai Akhir = C+");
  }
  else if(hitung>=65 && hitung<75){
    printf("Nilai Akhir = B");
  }
  else if(hitung>=75 && hitung<80){
    printf("Nilai Akhir = B+");
  }
  else {
    printf("Nilai Akhir = A");
  }

}

int main(){
    int menu;
    char ulang;
    do {
    system("cls");
    printf("\n\t===================================================");
    printf("\n\t        PROGRAM PERHITUNGAN NILAI RATA-RATA        ");
    printf("\n\t===================================================");
    printf("\n\t------------------MENU PILIHAN :-------------------");
    printf("\n\t 1. Hitung Rata-Rata");
    printf("\n\t 2. Keluar");
	printf("\n\t==================================================");
	reVldInt(&menu, "\nPILIH INPUT PROGRAM (dalam angka): ");

switch(menu){
	case 1:
		perhitungan();
		break;
	case 2:
        printf("\n=============================================\n");
        printf("   Terima kasih telah menggunakan Program ini   ");
        printf("\n=============================================\n");
        exit(0);
		break;
	default:
	   printf("INPUT SALAH!! INPUT ANGKA 1-2");
}

printf ("\nApakah anda ingin mengulang kembali? (Y/N): "); scanf (" %c", &ulang);
    } while (ulang == 'y' || ulang == 'Y');
    printf("\n=============================================\n");
 	printf("   Terima kasih telah menggunakan Program ini   ");
 	printf("\n=============================================\n");

exit(0);

}


