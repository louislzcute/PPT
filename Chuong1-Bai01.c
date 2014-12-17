// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 1
// Dap so: 0.9015426773696957140498036211335874930737397192553741 (tinh boi http://www.wolframalpha.com/)

#include <stdio.h>
#include <time.h>
#include <math.h>

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

const double EPSILON = 1e-5;

// return S(n)
double Bai1_S(int n){
	double result = 0;
	int i;
	for (i = 1; i <= n; i++){
		if (i % 2 == 0){
			result -= 1.0 / (i * i * i);
		}
		else {
			result += 1.0 / (i * i * i);
		}
	}
	return result;
}

// return |S(n+1) - S(n)| = 1/(n+1)^3
double Bai1_DeltaS(int n){
	return 1.0 / ((n + 1) * (n + 1) * (n + 1));
}



int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai1_S;				// Ham tinh S(n)
	double(*DeltaS)(int) = Bai1_DeltaS;			// Ham tinh delta S = S(n+1)- S(n)
	double absoluteError = EPSILON;				// sai so tuyet doi
	int initN = 1;								// Gia tri dau tien cua N

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

