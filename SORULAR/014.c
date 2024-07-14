//find max number
#include <stdio.h>

int max3(int x, int y, int z)
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
	int num1, num2, num3;
	int max;
	
	printf("Lutfen 3 adet sayi giriniz : ");
	scanf("%d%d%d", &num1, &num2, &num3);
	
	max = max3(num1, num2, num3);
		
	printf("%d, %d ve %d sayilarinin en buyugu %d\n", num1, num2, num3, max);
	
}		
