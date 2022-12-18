#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int validasi(){
    int pilih;
    if (scanf("%d", &pilih) != 1){
        printf("\nHanya masukkan angka!");
        printf("\nMasukan Pilihan Ulang : ");
        fflush(stdin);
        validasi();
    }
    return pilih;
}

//pembangkitan bilangan random
void randomBil(int arr[], int n){
    int i;
    srand(0);
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

//duplikasi array
void duplikatArray(int asal[], int target[], int n){
    int i;
    for (i = 0; i < n; i++)
        target[i] = asal[i];
}

//print array
void arrayPrint(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nAngka ke-%d = %d", i + 1, arr[i]);
    }
}

//acuan QuickSort
int pivot(int arr[], int low, int high){
    int p = arr[high];
    int temp;
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++){
        if (arr[j] <= p){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

//QuickSort
void quickSort(int arr[], int low, int high){
    int p = pivot(arr, low, high);
    if (low < high){
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
 
//InsertionSort
void insertionSort(int arr[], int n){
    int i, j, key;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//BubbleSort
void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Sorting
int sort(){
    clock_t start, end;
    double time1, time2, time3;
    int i, n;
    char pilih2;
    system("cls");
    printf("+==========================================+\n");
    printf("| Pilihan Jumlah Data |\n");
    printf("|==========================================|\n");
    printf("| 1. 1000 Data |\n");
    printf("| 2. 16000 Data |\n");
    printf("| 3. 64000 Data |\n");
    printf("| 4. Keluar |\n");
    printf("+==========================================+\n");
    printf("\n");
    printf("\nMasukkan pilih Anda : ");
    pilih2 = validasi();
    if(pilih2 < 1 || pilih2 > 4){
        system("cls");
        printf("\nMasukkan input dari angka 1 sampai 4\n\n");
        sort();
    }
    else{
        if(pilih2 == 1){
            n = 1000;
        }
        else if(pilih2 == 2){
            n = 16000;
        }
        else if(pilih2 == 3){
            n = 64000;
        }
        else if(pilih2 == 4){
            exit(0);
        }
    }
    int arr[n];
    int arr2[n];
    int arr3[n];


//print bilangan random
    randomBil(arr, n);
    printf("\n\n");
    printf("=================================");
    printf("Array %d random sebelum di sort :\n", n);
    arrayPrint(arr, n);
    duplikatArray(arr, arr2, n);
    duplikatArray(arr, arr3, n);

//insertion Sort
    start = clock();
    insertionSort(arr, n);
    end = clock();
    time1 = (double)(end - start) / CLOCKS_PER_SEC;

//bubble Sort
    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    time2 = (double)(end - start) / CLOCKS_PER_SEC;

//quick Sort
    start = clock();
    quickSort(arr3, 0, n - 1);
    end = clock();
    time3 = (double)(end - start) / CLOCKS_PER_SEC;
    
//print bilangan setelah disorting
    printf("\n\n");
    printf("==============================");
    printf("\n%d angka setelah disorting :\n", n);
    sleep(2);
    arrayPrint(arr, n);
 
//waktu yang diperlukan
    printf("\n\n");
    printf("\n+=========================================--+");
    printf("\n| Hasil Waktu |");
    printf("\n+-------------------------------------------+");
    printf("\nWaktu Insertion Sort = %f", time1);
    printf("\nWaktu Bubble Sort = %f", time2);
    printf("\nWaktu Quick Sort = %f\n", time3);

//pembandingan
    if(time1 == time2 && time1 == time3){
        printf("\n+===========================================+");
        printf("\n| Kecepetan yang Dimiliki Sama! |");
        printf("\n+===========================================+");
    }
    else if(time1 == time2){
        printf("\n+===========================================+");
        printf("\n| Insertion dan Bubble Sort Setara! |");
    printf("\n+===========================================+");
    }
    else if(time1 == time3){
        printf("\n+===========================================+");
        printf("\n| Insertion dan Quick Sort Setara! |");
        printf("\n+===========================================+");
    }
    else if(time2 == time3){
        printf("\n+===========================================+");
        printf("\n| Bubble dan Quick Sort Setara! |");
        printf("\n+===========================================+");
    }
    else if(time1 <= time2 && time1 <= time3){
        printf("\n+===========================================+");
        printf("\n| Insertion Sort Paling Cepat! |");
        printf("\n+===========================================+");
    }
    else if(time2 <= time1 && time2 <= time3){
        printf("\n+===========================================+");
        printf("\n| Bubble Sort Paling Cepat! |");
        printf("\n+===========================================+");
    }
    else if(time3 <= time1 && time3 <= time2){
        printf("\n+===========================================+");
        printf("\nWaktu Insertion Sort = %f", time1);
        printf("\nWaktu Bubble Sort = %f", time2);
        printf("\nWaktu Quick Sort = %f\n", time3);
    
//pembandingan
    if(time1 == time2 && time1 == time3){
        printf("\n+===========================================+");
        printf("\n| Kecepetan yang Dimiliki Sama! |");
        printf("\n+===========================================+");
    }
    else if(time1 == time2){
        printf("\n+===========================================+");
        printf("\n| Insertion dan Bubble Sort Setara! |");
        printf("\n+===========================================+");
    }
    else if(time1 == time3){
        printf("\n+===========================================+");
        printf("\n| Insertion dan Quick Sort Setara! |");
        printf("\n+===========================================+");
    }
    else if(time2 == time3){
        printf("\n+===========================================+");
        printf("\n| Bubble dan Quick Sort Setara! |");
        printf("\n+===========================================+");
    }
    else if(time1 <= time2 && time1 <= time3){
        printf("\n+===========================================+");
        printf("\n| Insertion Sort Paling Cepat! |");
        printf("\n+===========================================+");
    }
    else if(time2 <= time1 && time2 <= time3){
        printf("\n+===========================================+");
        printf("\n| Bubble Sort Paling Cepat! |");
        printf("\n+-------------------------------------------+");
    }
    else if(time3 <= time1 && time3 <= time2){
        printf("\n+===========================================+");
        printf("\n| Quick Sort Paling Cepat! |");
        printf("\n+===========================================+");
    }
    pilihAksi();
    }
}

//metode sequential search
double sequentialSearch(int arr[], int n, int angkaDicari) {
    clock_t start, end;
    double waktu;
    int i, counter = 0;
    start = clock();
    for (i = 0; i < n; i++){
        if (arr[i] == angkaDicari){
            counter++;
        }
        printf("Angka ke-%d = %d", i+1, arr[i]);
        printf("\n");
    }
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    if (counter == 0){
        printf("\n\n====================================================");
        printf("\nMencari dengan menggunakan metode Sequential Search");
        printf("\nAngka %d tidak terdapat pada array", angkaDicari);
        printf("\n===================================================\n");
    }
    else{
        int indexAngkaDicari[counter];
        counter = 0;
        for (i = 0; i < n; i++){
            if (arr[i] == angkaDicari){
                indexAngkaDicari[counter] = i;
                counter++;
            }
        }
    printf("\n===================================================");
    printf("\nMencari dengan menggunakan metode Sequential Search");
    printf("\nAngka terdapat pada indeks ke-");
    for (i = 0; i < counter; i++){
        if (i == 0 && i == counter - 1){
            printf(" %d.", indexAngkaDicari[i]);
        }
        else{
            if (i == counter - 1){
                printf(" dan %d.", indexAngkaDicari[i]);
            }
            else{
                printf(" %d,", indexAngkaDicari[i]);
            }
        }
    }
printf("\n===================================================")
;
 }
 return waktu;
}

double binarySearch(int arr[], int low, int high, int angkaDicari) {
 	clock_t start, end;
 	double waktu;
 	int i, counter = 0;
 	start = clock();
 	while (low <= high){
 		int mid = low + (high - low) / 2;
 		if (arr[mid] == angkaDicari){
 			counter++;
 			for (i = mid + 1; i < high + 1 && arr[i] == angkaDicari; i++){
 				counter++;
 			}
 			for (i = mid - 1; i < high + 1 && arr[i] == angkaDicari; i++){
 				counter++;
 			}
 			break;
 		}
 		else if (arr[mid] > angkaDicari){
 			high = mid - 1;
 		}
 		else{
 			low = mid + 1;
 		}
 	}
 	end = clock();
 	waktu = (double)(end - start) / CLOCKS_PER_SEC;
 	if (counter == 0){ 
		printf("\n\n===============================================");
		printf("\nMencari dengan menggunakan metode Binary Search");
		printf("\nAngka %d tidak terdapat array",angkaDicari);
 		printf("\n===============================================\n");
 	}
 
 	else{
 		int indexAngkaDicari[counter];
 		counter = 0;
 	while (low <= high) {
 		int mid = low + (high - low) / 2;
 		if (arr[mid] == angkaDicari){
 		indexAngkaDicari[counter] = mid;
		counter++;
 			for (i = mid + 1; i < high + 1 && arr[i] == angkaDicari; i++){
 				indexAngkaDicari[counter] = i;
				counter++;
 			}
			for (i = mid - 1; i > 0 && arr[i] == angkaDicari; i--){
 				indexAngkaDicari[counter] = i;
				counter++;
 			}
			break;
 		}
 		else if (arr[mid] > angkaDicari){
 			high = mid - 1;
 		}
 		else {
 			low = mid + 1;
 		}
 	}
 
	printf("\n\n=============================================");
 	printf("\nMencari dengan menggunakan metode Binary Search");
 	printf("\nAngka berada di array pada indeks ke-");
 	insertionSort(indexAngkaDicari, counter);
 	for (i = 0; i < counter; i++) {
 		if (i == 0 && i == counter - 1){
 			printf(" %d.", indexAngkaDicari[i]);
 		}
 		else {
 			if (i == counter - 1) {
 				printf(" dan %d.", indexAngkaDicari[i]);
 			}
			else {
 				printf("%d,", indexAngkaDicari[i]);
 			}
 		}
 	}	
	printf("\n===============================================\n");
 }
return waktu;
}

int search(){
 	clock_t start, end;
 	double time1, time2;
 	int i, n, menu, pilih2, angkaDicari;
 	char karakterSearch;
 	system("cls");
 	printf("+===========================================|+\n");
 	printf("|           Pilihan Jumlah Data             |\n");
 	printf("|===========================================|\n");
 	printf("| 1. 1000 Data                              |\n");
 	printf("| 2. 16000 Data                             |\n");
 	printf("| 3. 64000 Data                             |\n");
 	printf("| 4. Keluar                                 |\n");
 	printf("+===========================================|+\n");
 	printf("\n");
 	printf("\nMasukkan pilihan Anda : ");
 	pilih2 = validasi();
 	if(pilih2 < 1 || pilih2 > 4){
 		system("cls");
 		printf("\nMasukkan input dari angka 1 sampai 4\n\n");
 		search();
 	}
 	else{
 		if(pilih2 == 1){
 			n = 1000;
 		}
 		else if(pilih2 == 2){
 			n = 16000;
 		}
 		else if(pilih2 == 3){
 			n = 64000;
 		}
 		else if(pilih2 == 4){
 			exit(0);
 		}
 	}
 	int arr[n];
 	int arr2[n];
 	randomBil(arr, n);
	printf("\n\n\nMasukkan Angka Yang Ingin Dicari: ");
 	inputAngka :
 	angkaDicari = validasi();
 	if (angkaDicari < 0) {
 		printf("Input Invalid! Angka tidak boleh dibawah '0'");
 		goto inputAngka;
 	}
	insertionSort(arr, n);
 	time1 = sequentialSearch(arr, n, angkaDicari);
 	time2 = binarySearch(arr, 0, n - 1, angkaDicari);
 	printf("\n+===========================================+");
 	printf("\n| Hasil Waktu |");
 	printf("\n+===========================================+");
 	printf("\n1. Sequential Search = %f", time1);
 	printf("\n2. Binary Search = %f\n", time2);
 	if(time1 < time2){
 		printf("\n+===========================================+");
 		printf("\n| Sequential Search Lebih Cepat! |");
 		printf("\n+-------------------------------------------+");
 	}
 	else if(time2 < time1){
 		printf("\n+===========================================+");
 		printf("\n| Binary Search Lebih Cepat! |");
 		printf("\n+-------------------------------------------+");
 	}
 	else if( time1 == time2){
	 	printf("\n+===========================================+");
 		printf("\n| Sequential dan Binary Search Setara! |");
 		printf("\n+===========================================+");
 	}
 	pilihAksi();
	}	

int main(){
 	char pilih, karakter;
 	int cek;
 	system("cls");
 
	printf("\n=======================================================");
 	printf("\n PRAKTIKUM ALGORITMA PEMROGRAMAN MODUL 3 ");
	printf("\n Kelompok 12 ");
 	printf("\n=======================================================");
 	printf("\n-------------------Sorting dan Searching---------------");
 
 	//pilih program
 	printf("\n\n");
 	printf("\n+======================+");
 	printf("\n| PILIHAN PROGRAM      |");
 	printf("\n+======================+");
 	printf("\n|[1] Sorting           |");
 	printf("\n|[2] Searching         |");
 	printf("\n|[3] Exit              |");
 	printf("\n+======================+");
 	printf("\n\nMasukkan nomor urut dari pilihan anda : ");
 	pilih = validasi();
 	if(pilih < 1 || pilih > 3){
 		system("cls");
 		printf("\nInput Anda salah! Silahkan masukan angka 1 sampai 3.");
 		printf("\n\n");
 		main();
 	}
 	else if(pilih == 1){
 		sort();
 	}
 	else if(pilih == 2){
 		search();
 	}
 	else if(pilih == 3){
 		exit(0);
 	}
}	

//menu memilih aksi setelah berjalannya program
int pilihAksi(){
 	printf("\n\n");
 	printf("\n+=================================+");
 	printf("\n| Pilihan                         |");
 	printf("\n+=================================+");
 	printf("\n|Apakah anda ingin mengulang?     |");
 	printf("\n|=================================|");
 	printf("\n|1. Ya                            |");
 	printf("\n|2. Tidak                         |");
 	printf("\n+=================================|+");
 	printf("\nMasukkan Pilihan Anda : ");
 	int pilih = validasi();
 
	if(pilih == 1){
 		system("cls");
 		main();
 	}
 	else if(pilih == 2){
 		exit(0);
 	}
 	else{
 		printf("\nAngka yang anda input salah! Input angka yang sesuai!");
 		system("cls");
 		pilihAksi();
 	}
}
