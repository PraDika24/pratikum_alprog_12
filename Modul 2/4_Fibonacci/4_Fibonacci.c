#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int validasi_fibo(int *var){
    char buff[1024];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%d %c", var, &cek) == 1) {
            return 1;
        }
    }
    return 0;
}
void revalidasi_fibo(int *var, char *nama){
    while(1){
        printf("%s", nama);
        fflush(stdin);
        if(validasi_fibo(var))
            break;
        printf("\nInput yang Anda masukkan salah, silahkan ulangi\n");
    }
}
void ranvalidasi_fibo(int *var, int range1, int range2, char *nama){
    while(1){
        revalidasi_fibo(var, nama);
        fflush(stdin);
        if(*var >= range1  &&*var <= range2)
            break;
        printf("\nInput yang Anda masukkan salah, silahkan ulangi!\n");
    }
}
void ranvalidasi_fibo_end(int *var, int range1, int range2, char *nama){
    while(1){
        revalidasi_fibo(var, nama);
        fflush(stdin);
        if(*var == range1 || *var == range2)
            break;
        printf("\nInput yang Anda masukkan salah, hanya masukkan angka 0 & 9!\n");
    }
}
 int main(){
	int a = 0, b = 1, c, result, n, i, input, read;
	do{
		printf("\t\t\t==============================================\n");
		printf("\t\t\t         PROGRAM DERET BILANGAN FIBONACCI     \n");
		printf("\t\t\t         1. Metode Rekursif                   \n");
		printf("\t\t\t         2. Metode Iteratif                   \n");
		printf("\t\t\t         3. Keluar Program                    \n");
		printf("\t\t\t==============================================\n");
		ranvalidasi_fibo(&input, 0, 2, "Pilih metode yang ingin digunakan : ");
		system("cls");
		switch(input){
			case 1:
		    	ranvalidasi_fibo(&n, 1, 47, "Input jumlah deret Fibonacci : ");
				for (int i = 0 ; i < n ; i++ ){ 
        			if ( i <= 1 ){ 
       					c = i;
					}else{ 
            			c = a + b; 
            			a = b; 
           				b = c; 
        			}
					printf("%d ",c); 
				}
				printf("\n");
				break;
			case 2 :
			 	ranvalidasi_fibo(&n, 1, 47, "Input jumlah deret Fibonacci : ");
			
				a = 0;
   				b = 1;

   				for (i=1; i<=n; i++){
      				printf("%d ", a);
        			result = a + b;
    				a = b;
        			b = result;
				}break;
				printf("\n");
				break;
    	}
		printf("\n\t\t\t Apakah Anda ingin mengulang program?\n");
		ranvalidasi_fibo_end(&read, 0, 9, "\t\t\t (0 = no / 9 = yes): ");
		system("cls");

	}while(read == 9);
	printf("\t\t\t Have a nice day:) \n");
	system("pause");
	return 0;
}
