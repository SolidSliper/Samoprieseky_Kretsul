#include <stdio.h>
#include<time.h>
#include <stdlib.h>

char uholnik_testuj_samoprieseky(float* x, float* y, unsigned int n) {
	
}

void nuholnik(int n, float **x, float **y) {
	*y = (float*)malloc(n * sizeof(float));
	*x = (float*)malloc(n * sizeof(float));
	int i = 0;
	for (i; i < n; i++) {
		(*x)[i] = rand()/(RAND_MAX/5.5);
		(*y)[i] = rand() / (RAND_MAX/5.5);
	}
}

int main() {
	int n;
	float* x;
	float* y;
	int i = 0;
	printf("Kolko vrcholov ma n-uholnik? -> ");
	scanf("%i", &n);
	nuholnik(n, &x, &y);
	for (i; i < n; i++) {
		printf("%f %f\n", x[i], y[i]);
	}
}