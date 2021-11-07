#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//double F(double x) {
//	return (-3 * x * x + 2 * x + 9);
//}
double I(double a, double b, int n, double y) {
	return ((b - a) / (2 * n) * y); 
}

double f(double x)
{
	return sin(x * x + 2 * x);
}

int main() {
	double a, b, eps;
	double nom = 0;
	printf("Enter your variant");
	do {
		
		scanf("\t%lf", &nom);
		
		/*if (nom != 1 && nom != 2 && nom != 3 && nom != 4)
		{
			fprintf(stdout, "%s\n ", " Error");

		}*/

	} while (nom != 1 && nom != 2 && nom != 3 && nom != 4);

 

	if (nom == 1)
	{
		printf("Metod1");
		
		double a, b;
		int n;
		printf("\na = ");
		scanf("%lf", &a);
		printf("\nb = ");
		scanf("%lf", &b);
		printf("\nn = ");
		scanf("%i", &n);
		double s = (f(a) + f(b)) / 2;
		double h = (b - a) / n;
		for (int i = 1; i <= n - 1; i++)
		{
			s += f(a + i * h);
		}
		double I = h * s;
		printf("%lf", I);
	}
	else if (nom == 2)
	{
		printf("Metod2");
		double a, b;
		int n;
		printf("\na = ");
		scanf("%lf", &a);
		printf("\nb = ");
		scanf("%lf", &b);
		printf("\nn = ");
		scanf("%i", &n);
		double s = (f(a) + f(b)) / 2;
		double h = (b - a) / n;
		for (int i = 1; i <= n - 1; i++)
		{
			s += f(a + i * h);
		}
		double I = h * s;
		printf("%lf", I);
	}
	else if (nom == 3)
	{
		printf("Metod3");
		int n ;
		double a, b, y = 0, dy, In;
		printf("\na = ");
		scanf("%lf", &a);
		printf("\nb = ");
		scanf("%lf", &b);
		printf("\nn = ");
		scanf("%i", &n);
		if (n > 1) {
			dy = (b - a) / n;
			y += f(a) + f(b);
			for (int i = 1; i < n; i++) { y += 2 * (f(a + dy * i)); }
			In = I(a, b, n, y);
			printf("%lf", In);
		}
		else {
			printf("Error");
		}
		
	}
	else if (nom == 4)
	{
		printf("Metod4");
		printf("\na = ");
		scanf("%lf", &a);
		printf("\nb = ");
		scanf("%lf", &b);
		eps = 0.0001;


		double I = eps + 1, I1 = 0;
		for (int N = 2; (N <= 4) || (fabs(I1 - I) > eps); N *= 2)
		{
			double h, sum2 = 0, sum4 = 0, sum = 0;
			h = (b - a) / (2 * N);
			for (int i = 1; i <= 2 * N - 1; i += 2)
			{
				sum4 += f(a + h * i);
				sum2 += f(a + h * (i + 1));
			}
			sum = f(a) + 4 * sum4 + 2 * sum2 - f(b);
			I = I1;
			I1 = (h / 3) * sum;
		}
		printf("%lf", I1);
	}

	
	
	return 0;
}

//int main(){
//
//	int n = 30;
//	double h;
//	int a, b;
//	a = 1;
//		b = 2;
//		h = (b - a) / n;
//		printf("%u",h);
//	
//
//		
//	return 0;
//}



//
//
//double F(double x)
//{
//	double f;
//	f = 1+sqrt(x) + cos(x); 
//	return f;
//}
//
//void krok()
//{
//
//
//
//	int n;
//	double h, b, a, sum, k, x, y, z, S;
//	S = 0;
//
//	printf("enter the number of intervals \n");
//	scanf("%i", &n);
//	if (n <= 0)
//	{
//		do {
//			printf("the number of split intervals must be a positive integral \n");
//			scanf("%i", &n);
//		} while (n <= 0);
//	}
//	system("cls");
//	printf("%i", n);
//
//
//	printf("\n enter the boundaries of the integral  \n");
//	printf("a -");
//	scanf(" %lf", &a);
//	printf("b - ");
//	scanf("%lf", &b);
//	if (a >= b)
//	{
//		do
//		{
//			printf("\n a should be less then b  \n");
//			printf("a -");
//			scanf(" %lf", &a);
//			printf("b - ");
//			scanf("%lf", &b);
//		} while (a >= b);
//	}
//
//	h = (b - a) / n;
//	printf("%lf", h);
//	system("cls");
//
//	printf("step h = %lf\n boards of integration - a = %lf b = %lf\n the number of partition intervals n = %i\n", h, a, b, n);
//
//	x = a + h;
//	while (x < b) {
//		S = S + 4 * F(x);
//		x = x + h;
//		if (x >= b)break;
//		{
//			S = S + 2 * F(x);
//			x = x + h;
//
//		}
//		S = (h / 3) * (S + F(a) + F(b));
//		printf("\n%f", S);
//		//_getch();
//	}
//}
//
//
//int main()
//{
//
//	system("chcp 1251");
//	system("cls");
//
//	int n;
//	double sum, k, m, h, b, a, x, y, nom;
//	//y = x * x;
//	//h - krok
//	// a,b mezi integruvannja
//	//nom - metod
//
//
//	printf("select the method number to calculate from the suggested ones \n");
//	printf("\n1)method rectangles(method left rectangles) \n2)method right rectangles  \n3)method trapezoidal \n4)Simpson method (parabola method)  \n");
//
//	do {
//		//printf("a: \n");
//		scanf("\t%lf", &nom);
//		//printf("Ви обрали номер: %u", nom);
//		if (nom != 1 && nom != 2 && nom != 3 && nom != 4)
//		{
//			fprintf(stdout, "%s\n ", " - this number does not exist \t \n choose one of four options");
//		}
//
//	} while (nom != 1 && nom != 2 && nom != 3 && nom != 4);
//
//	if (nom == 1)
//	{
//		printf("the method of left rectangles was chosen \n");
//		krok();
//
//		//y = x * x;
//
//
//
//
//
//
//
//
//	}
//	else if (nom == 2)
//	{
//		printf("the method of right rectangles was chosen \n");
//		krok();
//	}
//	else if (nom == 3)
//	{
//		printf("method trapezoidal was chosen \n");
//		krok();
//	}
//	else if (nom == 4)
//	{
//		printf("Simpson method (parabola method) was chosen \n");
//		krok();
//	}
//
//
//
//	//tablica ldjaw wwdoda
//	//esli wsybral nomer 3 to metod budet 3 
//
//
//	return 0;
//}
//
//
//
//
