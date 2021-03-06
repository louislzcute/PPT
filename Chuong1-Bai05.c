// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 5
// Tinh e = sum of 1/n! from 0 to n

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_FACTORIAL 1000
const double EPSILON = 1e-5;

// Tinh so chu so tuong ung voi sai so
int getPerciseDigit(double dError){
	double log = -log10(dError);
	if ((double)((int)(log)) == log)
		return (int)log;
	else
		return (int)log + 1;
}

void inputError(double *pError){
	printf("Input absolute error: ");
	scanf("%lf", pError);
}


double factorial[MAX_FACTORIAL];
double CalculateFactorial(int n){
	if (n == 0){
		factorial[n] = 1;
	}
	if (factorial[n] == 0)
		factorial[n] = n*CalculateFactorial(n - 1);
	return factorial[n];
}

double Bai5_S(int n){
	double result = 0;
	int i;
	for (i = 0; i <= n; i++){
		result += 1.0 / CalculateFactorial(i);
	}
	return result;
}

// e(n+1) - e(n) = 1/(n+1)! (chat hon de bai: e(n+1) - e(n) = 1/(n.n!)
double Bai5_DeltaS(int n){
	return 1 / CalculateFactorial(n + 1);
}

int main(int argc, char* argv[])
{
	memset(factorial, 0, sizeof(factorial[0])*MAX_FACTORIAL);
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai5_S;	// Ham tinh S(n)
	double(*DeltaS)(int) = Bai5_DeltaS; // Ham tinh delta S = S(n+1)- S(n)
	double absoluteError = EPSILON; // sai so tuyet doi
	int initN = 0;
	inputError(&absoluteError);
	begin = clock();
	int iStep = initN - 1;
	do
	{
		iStep++;
	} while (DeltaS(iStep) > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("Running time (ms): %10.5f\n", time_spent);
	printf("Number of repeat steps: %d\n", iStep - initN);
	char s[100];
	sprintf(s, "Value of S(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, TinhS(iStep));
	system("pause");
}

