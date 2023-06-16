#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char uholnik_testuj_samoprieseky(float* x, float* y, unsigned int n) {
	int i;
	float A1, B1, C1, A2, B2, C2, determinant;
	for (i = 0; i < n; i++) {
		if (i + 2 == n) { //prípad strany s koncovým a počiatočným bodom
		i = 0;
		A1 = y[n-1] - y[n-2];        //rovnica typu A1y + B1x = C1
		B1 = x[n-1] - x[n-2];
		C1 = A1 * x[n-2] + B1 * y[n-2];
		A2 = y[i] - y[n-1];
		B2 = x[i] - x[n-1];
		C2 = A1 * x[n-1] + B1 * y[n-1]; //rovnica typu A1y + B1x = C1
		determinant = A1 * B2 - A2 * B1;
		if (determinant == 0) { printf("strana %i rovnobezna zo stranou %i!\n", i + 1, i + 2); } //sú rovnobežné strany n-uholníka
		break;
		}
		A1 = y[i + 1] - y[i];        //rovnica typu A1y + B1x = C1
		B1 = x[i + 1] - x[i];
		C1 = A1 * x[i] + B1 * y[i];
		A2 = y[i+2] - y[i+1];
		B2 = x[i + 2] - x[i+1];
		C2 = A1 * x[i+1] + B1 * y[i+1]; //rovnica typu A1y + B1x = C1
		determinant = A1 * B2 - A2 * B1;
		if (determinant == 0) { printf("strana %i rovnobezna zo stranou %i!\n", i+1, i+2); continue; } //sú rovnobežné strany n-uholníka
	}
}

void nuholnik(int n, float **x, float **y) { //funkcia generovania súradníc
	srand(time(0));
	*y = (float*)malloc(n * sizeof(float));
	*x = (float*)malloc(n * sizeof(float));
	int i = 0;
	for (i; i < n; i++) {
		//ak dam 5.5, bude to generovat spravne float cisla, v takom v tomto prípade chcem len ukázať, že kontrola rovnobežnosti funguje
		(*x)[i] = rand()/(RAND_MAX/2); 
		(*y)[i] = rand() / (RAND_MAX/2);
	}
}

int main() {
	int n, t;
	float* x;
	float* y;
	int i = 0;
	printf("Kolko vrcholov ma n-uholnik? -> ");
	scanf("%i", &n);
	nuholnik(n, &x, &y);
	for (i; i < n; i++) {
		printf("%.2f %.2f\n", x[i], y[i]);
	}
	uholnik_testuj_samoprieseky(x, y, n);
	printf("Chcete skusit opat? 1 - ano, nieco ine - nie -> ");
	scanf("%i", &t);
	if(t==1) return main();
}