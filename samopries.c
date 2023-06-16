#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*Program nie je úplne funkčný, potrebuje určité zmeny v slučkách, ale spôsob porovnávania strán je správny,
pretože strany so spoločným bodom nemôžu mať vlastný priesečník. Problém je pravdepodobne v definícii rovníc "priamok" 
alebo v definícii hraníc priesečníka týchto strán*/

//https://www.dcode.fr/points-plotter

char* uholnik_testuj_samoprieseky(float* x, float* y, unsigned int n) {
	int i, j;
	float A1, B1, C1, A2, B2, C2, determinant;
	//špeciálny prípad, keď máme stranu definovanú počiatočným a koncovým bodom
	for (i = 1; i < n; i++) {
		if (i + 2 == n) break;
		A1 = y[0] - y[n - 1];        //rovnica typu A1y + B1x = C1
		B1 = x[n - 1] - x[0];
		C1 = A1 * x[0] + B1 * y[0];
		A2 = y[i + 1] - y[i];
		B2 = x[i] - x[i + 1];
		C2 = A1 * x[i] + B1 * y[i]; //rovnica typu A2y + B2x = C2
		determinant = A1 * B2 - A2 * B1;
		if (determinant == 0) { printf("strana %i rovnobezna zo stranou %i!\n", i + 1, i + 2); continue; } //sú rovnobežné strany n-uholníka
		float px = (B2 * C1 - B1 * C2) / determinant;
		float py = (A1 * C2 - A2 * C1) / determinant; //súradnice priesečníka priamok v prípade, že sú nekonečné

		/*tu sa pozrieme na rozdiel medzi súradnicami priesečníka a vrcholmi n-uholníka, aby sme určili,
		či tento priesečník leží na stranách alebo je mimo nich*/
		float vzd_xA = (px - x[n - 1]) / (x[0] - x[n - 1]);
		float vzd_yA = (py - y[n - 1]) / (y[0] - y[n - 1]);
		float vzd_xB = (px - x[i]) / (x[i + 1] - x[i]);
		float vzd_yB = (py - y[i]) / (y[i + 1] - y[i]);

		if (((vzd_xA >= 0 && vzd_xA <= 1) || (vzd_yA >= 0 && vzd_yA <= 1)) &&
			((vzd_xB >= 0 && vzd_xB <= 1) || (vzd_yB >= 0 && vzd_yB <= 1))) {
			return "SAMOPRIESEK_ANO";
		}
	}

	//porovnanie strán každej s každou (okrem strany definovanej koncovým a začiatočným bodom)
	for (i = 0; i < n; i++) {
		for (j = i + 2; j < n; j++) { //tu môžeme pre optimalizáciu napísať i+1, pretože nám stačí jedno porovnanie strán
			if (j+1 == n) break;
			A1 = y[i + 1] - y[i];        //rovnica typu A1y + B1x = C1
			B1 = x[i] - x[i + 1];
			C1 = A1 * x[i] + B1 * y[i];
			A2 = y[j + 1] - y[j];
			B2 = x[j] - x[j + 1];
			C2 = A1 * x[j] + B1 * y[j]; //rovnica typu A2y + B2x = C2
			determinant = A1 * B2 - A2 * B1;
			if (determinant == 0) { printf("strana %i rovnobezna zo stranou %i!\n", i + 1, i + 2); continue; } //sú rovnobežné strany n-uholníka
			float px = (B2 * C1 - B1 * C2) / determinant;
			float py = (A1 * C2 - A2 * C1) / determinant; //súradnice priesečníka priamok v prípade, že sú nekonečné

			/*tu sa pozrieme na rozdiel medzi súradnicami priesečníka a vrcholmi n-uholníka, aby sme určili,
			či tento priesečník leží na stranách alebo je mimo nich*/
			float vzd_xA = (px - x[i]) / (x[i + 1] - x[i]);
			float vzd_yA = (py - y[i]) / (y[i + 1] - y[i]);
			float vzd_xB = (px - x[j]) / (x[j + 1] - x[j]);
			float vzd_yB = (py - y[j]) / (y[j + 1] - y[j]);

			if (((vzd_xA >= 0 && vzd_xA <= 1) || (vzd_yA >= 0 && vzd_yA <= 1)) &&
				((vzd_xB >= 0 && vzd_xB <= 1) || (vzd_yB >= 0 && vzd_yB <= 1))) {
				return "SAMOPRIESEK_ANO";
			}
		}
	}
	return "SAMOPRIESEK_NIE";
}

	void nuholnik(int n, float** x, float** y) { //funkcia generovania súradníc
		srand(time(0));
		*y = (float*)malloc(n * sizeof(float));
		*x = (float*)malloc(n * sizeof(float));
		int i = 0;
		for (i; i < n; i++) {
			//ak dam 5.5, bude to generovat spravne float cisla, v takom v tomto prípade chcem len ukázať, že kontrola rovnobežnosti funguje
			(*x)[i] = rand() / (RAND_MAX / 5.5);
			(*y)[i] = rand() / (RAND_MAX / 5.5);
		}
	}

void surCSV(float* x, float* y, int n) {
	FILE* file = fopen("sur.csv", "w"); 
	int i;
	if (file != NULL) {
		for (i = 0; i < n; i++) {
			fprintf(file, "%.2f,%.2f\n", x[i], y[i]);
		}

		fclose(file); 
		printf("Su suradnice ulozene v sur.csv\n");
	}
	else {
		printf("Failed to open file\n");
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
	surCSV(x, y, n);
	char* a = uholnik_testuj_samoprieseky(x, y, n);
	printf("\n%s\n", a);
	printf("Chcete skusit opat? 1 - ano, nieco ine - nie -> ");
	scanf("%i", &t);
	if(t==1) return main();
}
