//Gerçek sayılar arasında maksimumunu bul
#include <stdio.h>

double max3(double x, double y, double z)
{
	if (x > y && x > z)
		return x;
	else if (y > z)
		return y;
	else
		return z;
}

int main(void)
{
	double num1, num2, num3;
	double max;
	
	printf("Lutfen 3 adet sayi giriniz : ");
	scanf("%lf%lf%lf", &num1, &num2, &num3);
	
	max = max3(num1, num2, num3);
		
	printf("%f, %f ve %f sayilarinin en buyugu %f\n", num1, num2, num3, max);
	
}	
