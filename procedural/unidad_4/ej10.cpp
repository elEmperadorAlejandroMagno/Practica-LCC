#include <stdio.h>

#define M 2 // 12
#define C 5 // 15

void getTotalMonth(int fila[], int &acum, int i);
void getAvgPerBus(int matriz[][C], int &avg, int i, int j);
void getMaxPerBus(int matriz[][C], int &max);
void searchByTravels(int matriz[][C], int targ);

int main()
{
	int details[M][C] = {{10, 50, 25, 5, 30},{10,50,32,48,70}};
	int acum = 0;
	int avg = 0;
	int max = 0;
	//getTotalMonth(details[2], acum, 0);
	getAvgPerBus(details, avg, 0, 0);
	//getMaxPerBus(details, max);
	return 0;
};

void getAvgPerBus(int matriz[][C], int &avg, int i, int j)
{
	if(j < C)
	{
		avg = 0;
		if(i < M)
		{
			avg += matriz[i][j];
			getAvgPerBus(matriz, avg, i + 1, 0);
			avg = avg / M;
			printf("promedio de viajes del colectivo %d: %d", j + 1, avg);
		} else getAvgPerBus(matriz, avg, 0, j + 1);
	}
	return;
};


