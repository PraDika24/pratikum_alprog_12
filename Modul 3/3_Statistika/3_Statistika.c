#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


float mean(float[],int);
float median(float[],int);


float mean(float *nilai,int jumlah){
	int i;
	float total=0;

	for(i=0;i<jumlah;i++){
		total=total+nilai[i];
	}

	return (total/jumlah);
}

float median(float *nilai,int jumlah){
	float temp;
	int i,j;

	for(i=0;i<jumlah;i++){
		for(j=i+1;j<jumlah;j++){
			if(nilai[i]>nilai[j]){
 				temp=nilai[j];
 				nilai[j]=nilai[i];
 				nilai[i]=temp;
			}
		}
 	}

	if(jumlah%2==0){
	return (nilai[jumlah/2]+nilai[(jumlah/2)-1])/2;
	} else{
	return nilai[jumlah/2];
	}
}



float input(){
    float pilihan, select;
    char enter;
    pilihan = scanf("%f%c", &select, &enter);
    if (pilihan != 2 || enter != '\n'){
        getchar();
        printf("\t\t\tHanya masukan angka, Tolong Input Ulang\t");
        return input();
    }else if (select<0){
        printf("\t\t\tPilihan Tidak Tersedia, Tolong Masukan Pilihan dalam Angka\t ");
        return input();
    }else{
        return select;
    }
}

int main(){
    float *nilai;
    int jumlah;
    float pilihan;
    int i, j, k=0;
    float mode, max=0, c=1;
    float modus[jumlah];
    int pilih;

    awal:
    printf("\t\t\t====================================================================\n");
    printf("\t\t\t|                                                                  |\n");
	printf("\t\t\t|               SELAMAT DATANG DI PROGRAM STATISTIKA               |\n");
	printf("\t\t\t|                                                                  |\n");
    printf("\t\t\t====================================================================\n");
    printf("\t\t\t| Masukan Nilai Panjang pada Data yang akan dihitung : ");
    jumlah=input();
    nilai = (float*) malloc(jumlah*sizeof(float));
    for(i=0; i<jumlah; i++){
    	printf("\t\t\t| Masukkan data ke-%i : ", i+1);
    	nilai[i]=input();
    }
    printf("\t\t\t====================================================================\n");
    system("cls");

    akhir:
    printf("\t\t\t====================================================================\n");
    printf("\t\t\t|                                                                  |\n");
	printf("\t\t\t|                     DATA YANG ANDA MASUKAN                       |\n");
	printf("\t\t\t|                                                                  |\n");
    printf("\t\t\t====================================================================\n");
    for(i=0; i<jumlah; i++){
    	printf("\t\t\t| Data ke-%i : %.2f\n", i+1, nilai[i]);
    }
    printf("\t\t\t|\n");
	printf("\t\t\t|     Menu Program :\n");
	printf("\t\t\t|          1. Mencari Mean\n");
	printf("\t\t\t|          2. Mencari Median\n");
	printf("\t\t\t|          3. Mencari Modus\n");
	printf("\t\t\t|          4. Mengulangi Input Nilai\n");
	printf("\t\t\t|          5. Keluar\n");
    printf("\t\t\t|     Silahkan Pilih!!! (masukkan nomor) : ");
    pilihan=input();
    pilih = ceil(pilihan);
	switch(pilih){
		case 1:
			printf("\t\t\t====================================================================\n");
			printf("\t\t\t|     Mean      = %.2f\n", mean(nilai, jumlah));
			printf("\t\t\t====================================================================\n");
			system ("pause");
			system ("cls");
			goto akhir;
        break;
		case 2:
			printf("\t\t\t====================================================================\n");
			printf("\t\t\t|     Median    = %.2f\n", median(nilai,jumlah));
			printf("\t\t\t====================================================================\n");
			system ("pause");
			system ("cls");
			goto akhir;
        break;
        case 3:
            for(i = 0; i<jumlah-1; i++)
            {
                mode=0;
                for (j=i+1; j<jumlah; j++){
                    if (nilai[i] == nilai[j]){
                       mode++;
                    }

                }
                if((mode>max) && (mode!=0)){
                    k=0;
                    max=mode;
                    modus[k]=nilai[i];
                    k++;
                }
                else if(mode==max){
                    modus[k]=nilai[i];
                    k++;
                }
            }
            for(i=0; i<jumlah; i++){
                if(nilai[i]==modus[i])
                c++;
            }
            if(c==jumlah){
            printf("\t\t\t====================================================================\n");
            printf("\t\t\t\tTidak ada Modus\n");
            printf("\t\t\t====================================================================\n");
            }else
            {
                printf("\t\t\t====================================================================\n");
                printf("\t\t\t|Modus\t= ");
                for(i=0; i<k; i++)
                printf("%.2f ", modus[i]);

            }
                printf("\n\t\t\t====================================================================\n");
            system ("pause");
            system ("cls");
            goto akhir;
        break;
        case 4:
            system("cls");
            goto awal;
        break;
        case 5:
			printf("\t\t\t\t======================================================\n");
    		printf("\t\t\t\t|     TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI     |\n");
    		printf("\t\t\t\t======================================================\n");
    		exit(1);
        break;
        default:
    		printf("\t\t\t====================================================================\n");
    		printf("\t\t\t|     Input yang Anda tidak tersedia, Masukan Nomor 1-5\t:\n");
    		pilih=input();
    		printf("\t\t\t====================================================================\n");

        break;
	}
    return 0;
}

