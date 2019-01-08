#include <stdio.h>
int alann(int kisa, int uzun);
int cevree(int kisa, int uzun);
int main(){
	int kisa, uzun, alan, cevre;
	printf("Kisa kenari giriniz: ");
	scanf("%d",&kisa);
	printf("Uzun kenari giriniz: ");
	scanf("%d",&uzun);
	alan = alann(kisa, uzun);
	cevre = cevree(kisa, uzun);
	printf("Cevre: %d\n",cevre);
	printf("Alan: %d",alan);
	return 0;
}
int alann(int kisa, int uzun){
	int alan;
	alan = kisa*uzun;
	return alan;
}
int cevree(int kisa, int uzun){
	int cevre;
	cevre = 2*kisa + 2*uzun;
	return cevre;
}
