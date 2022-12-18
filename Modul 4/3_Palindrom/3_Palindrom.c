#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char kata[100];
char sts[100];
char copy_kata[100];
char mengulang = 'y';
int i,j,statusku,status,panjang_kata,pnj,c,x,count[26];

void cetakfile();
void tentukanpalindrom();
void input();


int main(){
    while(mengulang == 'y'){
        input();
        tentukanpalindrom();
        cetakfile();
        printf("\n\nIngin mengulangi lagi?(y/else): ");
        scanf("%c", &mengulang);
        system("cls");
   }
   return 0;
}

void input(){
    status=0;
    statusku=1;
    c=0;
    for(i=0;i<27;i++){
        count[i] = 0;
    }
    printf("+======================================================+\n");
    printf("|                                                      |\n");
    printf("|           PROGRAM PENGECEKAN KATA PALINDROM          |\n");
    printf("|                   OLEH KELOMPOK 12                    |\n");
    printf("|                                                      |\n");
    printf("+======================================================+\n\n");
    printf("\nMasukkan kata: ");
    fflush(stdin);
    gets(kata);
    fflush(stdin);
    panjang_kata = strlen(kata);
    strlwr(kata);
    while(statusku>0){
        statusku = 0;
        for(i=0;i<panjang_kata;i++){
            if(kata[i]<'a' || kata[i]>'z'){
                kata[i]=kata[i+1];
                for(j=i+1;j<panjang_kata-1;j++){
                    kata[j]=kata[j+1];
                    kata[j+1]='\0';
                    }
                }
        }
        pnj = strlen(kata);
        for(i=0;i<pnj;i++){
            if(kata[i]<'a' || kata[i]>'z'){
                statusku=statusku+1;
                }
        }
    }
}


void tentukanpalindrom(){
    FILE *in = fopen("kamuskata.txt","a");
    pnj = strlen(kata);
    printf("\nString yang dinputkan(setelah divalidasi): %s\n", kata);
    fprintf(in,"%s(%d): ",kata,pnj);
    strcpy(copy_kata,kata);
    strrev(copy_kata);
    printf("\nHasil kata setelah dibalik: ");
    //printf("%s", copy_kata);
    for(i=0;i<pnj;i++){
        if(kata[i]!=copy_kata[i]){
            status = status + 1;
        }
    }
    if(status!=0){
        printf("\nString bukan palindrome\n");
        strcpy(sts,"Bukan Palindrome");
    }
    else{
        printf("\nString adalah palindrome\n");
        strcpy(sts,"Palindrome");
    }
    fclose(in);
}

void cetakfile(){
    FILE *in = fopen("kamuskata.txt","a");
    printf("\nFrekuensi karakter yang muncul dalam string: \n");
    while (kata[c] != '\0'){
        if (kata[c] >= 'a' && kata[c] <= 'z'){
            x = kata[c] - 'a';
            count[x]++;
        }
        c++;
    }
    for(i=0;i<26;i++){
        if(count[i]!=0){
            printf("%c muncul sebanyak %d kali dalam string.\n", i + 'a', count[i]);
            fprintf(in,"%c=%d ", i + 'a', count[i]);
        }
    }
    fprintf(in," : %s\n", sts);
    fclose(in);
}
