/*
film güncelleme
film siralama
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void film_ekle();
void film_goruntule();
void film_cikar();
void menu();
void tamam();
void film_ara();
struct film {

	char ad[50], yonetmen[50], senarist[50], basrol[50], yil[5];
};
int main(){
	int l;
	menu();
	scanf("%d", &l);
	if (l == 1) {
		film_ekle();
		tamam();
	}
	else if (l == 2) {
		film_cikar();
		tamam();
	}
	else if (l == 3) {
		film_goruntule();
		tamam();
	}
	else if (l == 4) {

	}
	else if (l == 5) {
		film_ara();
		tamam();
	}
	else {
		printf("Hatali deger girdiniz.");
	}
	return 0;
}
void film_ekle(){
	FILE *dosya;
	film arsiv;
	dosya = fopen("film.txt", "a");
	printf("Filmin ciktigi yili giriniz: ");
	scanf("%s", &arsiv.yil);
	printf("Filmin adini giriniz: ");
	scanf("%s", &arsiv.ad);
	printf("Filmin yonetmenini giriniz: ");
	scanf("%s", &arsiv.yonetmen);
	printf("Filmin senaristini giriniz: ");
	scanf("%s", &arsiv.senarist);
	printf("Filmin basrolunu giriniz: ");
	scanf("%s", &arsiv.basrol);
	printf("Bilgiler basariyla kaydedildi.");
	fprintf(dosya, "%s ", arsiv.yil);
	fprintf(dosya, "%s ", arsiv.ad);
	fprintf(dosya, "%s ", arsiv.yonetmen);
	fprintf(dosya, "%s ", arsiv.senarist);
	fprintf(dosya, "%s\n", arsiv.basrol);
	fclose(dosya);
}
void film_cikar(){
	FILE *yedek, *dosya;
	dosya = fopen("film.txt", "r");
	yedek = fopen("yedek.txt", "w");
	char sil[50];
	printf("Silinecek filmin adini giriniz: ");
	scanf("%s", sil);
	char a[50], b[50], c[50], d[50], e[50];
	while (!feof(dosya)) {
		fscanf(dosya, "%s %s %s %s %s\n", a, b, c, d, e);
		if (strcmp(sil, b) != 0) {
			fprintf(yedek, "%s %s %s %s %s\n", a, b, c, d, e);
		}
	}
	fclose(dosya);
	fclose(yedek);
	remove("film.txt");
	rename("yedek.txt","film.txt");
}
void film_goruntule(){
	film yazdir;
	FILE *dosya;
	dosya = fopen("film.txt","r");
	while (!feof(dosya)) {
		fscanf(dosya, "%s %s %s %s %s\n", yazdir.yil, yazdir.ad, yazdir.yonetmen, yazdir.senarist, yazdir.basrol);
		printf("Film: %s %s %s %s %s\n", yazdir.yil, yazdir.ad, yazdir.yonetmen, yazdir.senarist, yazdir.basrol);
	}
	fclose(dosya);
}
void tamam(){
	char secim[1];
	printf("Devam etmek ister misiniz? (Yy/Hh)");
	scanf("%s", secim);
	switch (*secim) {
	case 'y': {
		main();
		break;
	}
	case 'Y': {
		main();
		break;
	}
	case 'h': {
		break;
	}
	case 'H': {
		break;
	}
	default: {
		printf("Yanlis deger girdiniz!\n");
		tamam();
		break;
	}
	}
}
void menu(){
	printf("    Menu\n");
	printf("1-Film ekle.\n");
	printf("2-Film cikar.\n");
	printf("3-Filmleri goruntule.\n");
	printf("4-Film guncelle.\n");
	printf("5-Film ara.\n");
}
void film_ara(){
	FILE *dosya;
	dosya = fopen("film.txt","r");
	int sec;
	printf("Hangi filmi aramistiniz? \n");
	printf("1-Yilina gore.\n");
	printf("2-Adina gore.\n");
	printf("3-Yonetmenine gore.\n");
	printf("4-Senaristine gore.\n");
	printf("5-Basrol oyuncusuna gore.\n");
	scanf("%d", &sec);
		switch (sec){
			case 1:{
				char ara[50];
				printf("Filmin yilini giriniz: ");
				scanf("%s",ara);
				char a[50], b[50], c[50], d[50], e[50];
				while (!feof(dosya)) {
					fscanf(dosya,"%s %s %s %s %s\n", a, b, c, d, e);
					if (strcmp(ara,a) == 0) {
						printf("%s %s %s %s %s\n", a, b, c, d, e);
					}
				}
				fclose(dosya);
				break;
			}
			case 2:{
				char ara[50];
				printf("Filmin adini giriniz: ");
				scanf("%s",ara);
				char a[50], b[50], c[50], d[50], e[50];
				while (!feof(dosya)) {
					fscanf(dosya,"%s %s %s %s %s\n", a, b, c, d, e);
					if (strcmp(ara,b) == 0) {
						printf("%s %s %s %s %s\n", a, b, c, d, e);
					}
				}
				fclose(dosya);
				break;
			}
			case 3:{
				char ara[50];
				printf("Filmin yonetmenini giriniz: ");
				scanf("%s",ara);
				char a[50], b[50], c[50], d[50], e[50];
				while (!feof(dosya)) {
					fscanf(dosya,"%s %s %s %s %s\n", a, b, c, d, e);
					if (strcmp(ara,c) == 0) {
						printf("%s %s %s %s %s\n", a, b, c, d, e);
					}
				}
				fclose(dosya);
				break;
			}
			case 4:{
				char ara[50];
				printf("Filmin senaristini giriniz: ");
				scanf("%s",ara);
				char a[50], b[50], c[50], d[50], e[50];
				while (!feof(dosya)) {
					fscanf(dosya,"%s %s %s %s %s\n", a, b, c, d, e);
					if (strcmp(ara,d) == 0) {
						printf("%s %s %s %s %s\n", a, b, c, d, e);
					}
				}
				fclose(dosya);
				break;
			}
			case 5:{
				char ara[50];
				printf("Filmin basrolunu giriniz: ");
				scanf("%s",ara);
				char a[50], b[50], c[50], d[50], e[50];
				while (!feof(dosya)) {
					fscanf(dosya,"%s %s %s %s %s\n", a, b, c, d, e);
					if (strcmp(ara,e) == 0) {
						printf("%s %s %s %s %s\n", a, b, c, d, e);
					}
				}
				fclose(dosya);
				break;
			}
			default:{
				printf("Yanlis deger girdiniz!");
				film_ara();
				break;
			}
		}
}








