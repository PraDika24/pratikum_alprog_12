#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void header();
void segitiga();
void luasSegitiga();
void kelilingSegitiga();
void akhir();
void belahKetupat();
void luasBelahKetupat();
void kelilingBelahKetupat();
void jajarGenjang();
void luasJajarGenjang();
void kelilingJajarGenjang();
void trapesium();
void luasTrapesium();
void kelilingTrapesium();
void lingkaran();
void luasLingkaran();
void kelilingLingkaran();
double checkinput();

int main(){
	system("cls");
	int pilih;
	printf("\n\n\n\n\n\n");
	printf("\t\t>>>>> PERHITUNGAN LUAS DAN KELILING BANGUN DATAR <<<<<\n");
	printf("\t\t|                        Oleh                         |\n");
	printf("\t\t|                     Kelompok 12                     |\n");
	printf("\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	printf("\t\t  Pilihlah Bangun Datar Dibawah Ini.\n");
	printf("\t\t   1. Segitiga Sembarang\n");
	printf("\t\t   2. Belah Ketupat\n");
	printf("\t\t   3. Jajar Genjang\n");
	printf("\t\t   4. Trapesium\n");
	printf("\t\t   5. Lingkaran\n");
	printf("\t\t   6. Keluar\n");
	printf("\t\t  Masukkan pilihan anda : ");
	pilih=checkinput();

	if (pilih==1){
		system("cls");
		segitiga();
	}
	else if (pilih==2){
		system("cls");
		belahKetupat();
	}
	else if (pilih==3){
		system("cls");
		jajarGenjang();
	}
	else if(pilih==4){
		system("cls");
		trapesium();
	}
	else if(pilih==5){
		lingkaran();
	}
	else if(pilih==6){
		akhir();
	}
	else{
		system("cls");
		printf("Input yang anda masukkan salah\nMasukan angka yang benar :");
		main();
	}

}

void header(){
	system("cls");
	printf("\t\t    PERHITUNGAN LUAS DAN KELILING\n");
	printf("\t\t            BANGUN DATAR         \n");
	printf("\t\t=======================================\n\n");
}

void akhir(){
	header();
	int keluar;
	printf("Silahkan pilih langkah yang ingin anda lakukan selanjutnya\n");
	printf(" 1. Kembali ke Menu Utama\n");
	printf(" 2. Keluar\n");
	printf("Masukkan pilihan anda > ");
	keluar=checkinput();

	if(keluar==1){
		main();
	}
	else if (keluar==2){
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t*******************************************\n");
		printf("\t\t\tTERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI\n");
		printf("\t\t\t*******************************************\n");
	}
	else{
		printf("Perhatikan Lagi Inputan Anda!!!");
	}
}

void segitiga(){
	header();
	int pilih;
	printf("=======================\nSegitiga Sembarang\n=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Luas Segitiga Sembarang\n");
	printf(" 2. Menghitung Keliling Segitiga Sembarang\n");
	printf(" 3. Kembali\n");
	printf(" 4. Keluar\n");
	printf("Input pilihan anda : ");
	pilih=checkinput();

	if (pilih == 1){
		luasSegitiga();
	}
	else if (pilih ==2){
		kelilingSegitiga();
	}
	else if (pilih==3){
		main();
	}
	else if (pilih==4){
		akhir();
	}
	else{
		printf("Input yang anda masukkan salah");
	}
}

void luasSegitiga(){
	float sisi1,sisi2,sisi3,keliling,s,luas;
	printf(">>>>>>>>> MENGHITUNG LUAS SEGITIGA SEMBARANG <<<<<<<<<\n\n");
	printf("                         Rumus :                        \n");
	printf("      akar(s*(s - sisi 1)*(s - sisi2)*(s - sisi 3))     \n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("  Inputkan nilai sisi pertama : ");
	sisi1=checkinput();
	printf("  Inputkan nilai sisi kedua   : ");
	sisi2=checkinput();
	printf("  Inputkan nilai sisi ketiga  : ");
	sisi3=checkinput();

	if(sisi1==sisi2 || sisi2==sisi3 || sisi3==sisi1){
		printf("Panjang Ketiga Sisi Segitiga Sembarang Tidak Boleh Sama\n");
		getch();
		system("cls");
		luasSegitiga();
	}
	else{
		keliling = sisi1+sisi2+sisi3;
		s = keliling/2;
		luas = sqrt(s*(s-sisi1)*(s-sisi2)*(s-sisi3));
		printf("LUAS SEGITIGA SEMBARANG = %.2f", luas);
		getch();
		akhir();
	}
}

void kelilingSegitiga(){
	int sisi1,sisi2,sisi3,keliling;
	printf(">>>>>>>>> MENGHITUNG KELILING SEGITIGA SEMBARANG <<<<<<<<<\n\n");
	printf("                          Rumus :                           \n");
	printf("                    sisi1+sisi2+sisi3                       \n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("  Inputkan nilai sisi pertama : ");
	sisi1=checkinput();
	printf("  Inputkan nilai sisi kedua   : ");
	sisi2=checkinput();
	printf("  Inputkan nilai sisi ketiga  : ");
	sisi3=checkinput();

	if(sisi1==sisi2 || sisi2==sisi3 || sisi3==sisi1){
		printf("Panjang Ketiga Sisi Segitiga Sembarang Tidak Boleh Sama\n");
		getch();
		system("cls");
		luasSegitiga();
	}
	else{
		keliling = sisi1+sisi2+sisi3;
		printf("KELILING SEGITIGA SEMBARANG = %d", keliling);
		getch();
		akhir();
	}
}

void belahKetupat(){
	header();
	int pilih;
	printf("=======================\nBelah Ketupat\n=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Luas Belah Ketupat\n");
	printf(" 2. Menghitung Keliling Belah Ketupat\n");
	printf(" 3. Kembali\n");
	printf(" 4. Keluar\n");
	printf("Input pilihan anda : ");
	pilih=checkinput();

	if (pilih == 1){
		luasBelahKetupat();
	}
	else if (pilih ==2){
		kelilingBelahKetupat();
	}
	else if(pilih==3){
		main();
	}
	else if(pilih==4){
		akhir();
	}
	else{
		printf("Input yang anda masukkan salah");
	}
}

void luasBelahKetupat(){
	system("cls");
	int diagonal1,diagonal2,luas;
	printf(">>>>>>>>> MENGHITUNG LUAS BELAH KETUPAT <<<<<<<<<\n\n");
	printf("                      Rumus :                      \n");
	printf("             1/2*diagonal1*diagonal2               \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("   Masukkan nilai diagonal 1 : ");
	diagonal1=checkinput();
	printf("   Masukkan nilai diagonal 2 : ");
	diagonal2=checkinput();

	luas = diagonal1*diagonal2/2;
	printf("LUAS BELAH KETUPAT= %d", luas);
	getch();
	akhir();
}

void kelilingBelahKetupat(){
	system("cls");
	int sisi, keliling;
	printf(">>>>>>>>> MENGHITUNG KELILING BELAH KETUPAT <<<<<<<<<\n\n");
	printf("                        Rumus :                        \n");
	printf("                        sisi*4                         \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("Masukkan nilai sisi belah ketupat : ");
	sisi=checkinput();

	keliling = sisi*4;
	printf("KELILING BELAH KETUPAT = %d", keliling);
	getch();
	akhir();
}

void jajarGenjang(){
	header();
	int pilih;
	printf("=======================\nJajar Genjang\n=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Luas Jajar Genjang\n");
	printf(" 2. Menghitung Keliling Jajar Genjang\n");
	printf(" 3. Kembali\n");
	printf(" 4. Keluar\n");
	printf("Input pilihan anda : ");
	pilih=checkinput();

	if (pilih == 1){
		luasJajarGenjang();
	}
	else if (pilih ==2){
		kelilingJajarGenjang();
	}
	else if (pilih==3){
		main();
	}
	else if(pilih==4){
		akhir();
	}
	else{
		printf("Input yang anda masukkan salah");
	}
}

void luasJajarGenjang(){
	system("cls");
	int alas,luas;
	printf(">>>>>>>>> MENGHITUNG LUAS JAJAR GENJANG <<<<<<<<<\n\n");
	printf("                    Rumus :                        \n");
	printf("                    alas*4                         \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("Masukkan nilai alas jajar genjang : ");
	alas=checkinput();

	luas=alas*4;
	printf("LUAS JAJAR GENJANG = %d", luas);
	getch();
	akhir();
}

void kelilingJajarGenjang(){
	system("cls");
	int sisi1,sisi2,keliling;
	printf(">>>>>>>>> MENGHITUNG KELILING JAJAR GENJANG <<<<<<<<<\n\n");
	printf("                       Rumus :                         \n");
	printf("                  2*(sisi1+sisi2)                      \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("Masukkan nilai sisi 1 : ");
	sisi1=checkinput();
	printf("Masukkan nilai sisi 2 : ");
	sisi2=checkinput();

	keliling = 2*(sisi1+sisi2);
	printf("KELILING JAJAR GENJANG = %d", keliling);
	getch();
	akhir();
}

void trapesium(){
	header();
	int pilih;
	printf("=======================\nTrapesium\n=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Luas Trapesium\n");
	printf(" 2. Menghitung Keliling Trapesium\n");
	printf(" 3. Kembali\n");
	printf(" 4. Keluar\n");
	printf("Input pilihan anda : ");
	pilih=checkinput();

	if (pilih == 1){
		luasTrapesium();
	}
	else if (pilih ==2){
		kelilingTrapesium();
	}
	else if (pilih==3){
		main();
	}
	else if(pilih==4){
		akhir();
	}
	else{
		printf("Input yang anda masukkan salah");
	}
}

void luasTrapesium(){
	system("cls");
	int a,b,t,luas;
	printf(">>>>>>>>> MENGHITUNG LUAS TRAPESIUM <<<<<<<<<\n\n");
	printf("                   Rumus :                     \n");
	printf("          (sisi a+sisi b)*tinggi/2             \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("Masukkan nilai sisi a           : ");
	a=checkinput();
	printf("Masukkan nilai sisi b           : ");
	b=checkinput();
	printf("Masukkan nilai tinggi trapesium : ");
	t=checkinput();

	luas = (a+b)*t/2;
	printf("LUAS TRAPESIUM = %d", luas);
	getch();
	akhir();
}

void kelilingTrapesium(){
	system("cls");
	int a,b,c,d, keliling;
	printf(">>>>>>>>> MENGHITUNG KELILING TRAPESIUM <<<<<<<<<\n\n");
	printf("                      Rumus :                      \n");
	printf("        sisi a + sisi b + sisi c + sisi d          \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("Masukkan nilai panjang sisi a : ");
	a=checkinput();
	printf("Masukkan nilai panjang sisi b : ");
	b=checkinput();
	printf("Masukkan nilai panjang sisi c : ");
	c=checkinput();
	printf("Masukkan nilai panjang sisi d : ");
	d=checkinput();

	keliling = a+b+c+d;
	printf("KELILING TRAPESIUM = %d", keliling);
	getch();
	akhir();
}

void lingkaran(){
	header();
	int pilih;
	printf("=======================\nLingkaran\n=======================\n\n");
	printf("Menu : \n");
	printf(" 1. Menghitung Luas Lingkaran\n");
	printf(" 2. Menghitung Keliling Lingkaran\n");
	printf(" 3. Kembali\n");
	printf(" 4. Keluar\n");
	printf("Input pilihan anda : ");
	pilih=checkinput();

	if (pilih == 1){
		luasLingkaran();
	}
	else if (pilih ==2){
		kelilingLingkaran();
	}
	else if(pilih==3){
		main();
	}
	else if(pilih==4){
		akhir();
	}
	else{
		printf("Input yang anda masukkan salah");
	}
}

void luasLingkaran(){
	system("cls");
	float r,luas;
	printf(">>>>>>>>> MENGHITUNG LUAS LINGKARAN <<<<<<<<<\n\n");
	printf("                    Rumus :                    \n");
	printf("                   phi*r^2                     \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("Masukkan nilai jari-jari lingkaran : ");
	r=checkinput();

	luas=3.14*r*r;
	printf("LUAS LINGKARAN = %.3lf", luas);
	getch();
	akhir();
}

void kelilingLingkaran(){
	system("cls");
	float r,keliling;
	printf(">>>>>>>>> MENGHITUNG KELILING LINGKARAN <<<<<<<<<\n\n");
	printf("                      Rumus :                      \n");
	printf("                     2*phi*r                       \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("Masukkan nilai jari-jari lingkaran : ");
	r=checkinput();

	keliling=2*3.14*r;
	printf("KELILING LINGKARAN = %.3lf", keliling);
	getch();
	akhir();
}

double checkinput(){
	double d;
	char checkchar;
	int cek;
	cek=scanf("%lf%c", &d,&checkchar);

	if(cek!=2 || checkchar!='\n'){
		printf("\n\t\t  Input Invalid!");
		printf("\nMasukkan angka yang tepat : ");
		fflush(stdin);
		cek=1;
		return checkinput();
	}
	else if(d<=0){
		printf("\n\t\t  Input Invalid!\n");
		printf("\t\t  Masukkan angka selain 0 : ");
		fflush(stdin);
		cek=1;
		return checkinput();
	}
	else{
		cek=0;
		fflush(stdin);
		return d;
	}
}
