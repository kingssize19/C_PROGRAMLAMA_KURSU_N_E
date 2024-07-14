//find max number

#include <stdio.h>

int main(void)
{
	int num1, num2, num3;
	int max;
	
	printf("Lutfen 3 adet sayi giriniz : ");
	scanf("%d%d%d", &num1, &num2, &num3);
	
	if (num1 > num2 && num1 > num3)
		max = num1;
	else if (num2 > num3)
		max = num2;
	else
		max = num3;
		
	printf("%d, %d ve %d sayilarinin en buyugu %d\n", num1, num2, num3, max);
	
}	
