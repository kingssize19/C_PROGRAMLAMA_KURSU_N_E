//find max number 
#include <stdio.h>

int max4(int x, int y, int z, int t)
{
	if (x > y && x > z && x > t)
		return x; 
	else if (y > z && y > t)
		return y;
	else if (z > t)
		return z;
	else
		return t;
}


int main(void)
{
	int n1, n2, n3, n4;
	
	printf("Lutfen 4 adet sayi giriniz: ");
	scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
	
	int max = max4(n1, n2, n3, n4);
	
	printf("%d %d %d %d sayilarinin en buyugu %d", n1, n2, n3, n4, max);
}	
