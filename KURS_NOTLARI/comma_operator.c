#include <stdio.h>

/* 
	Comma (,) operatörü önemli noktalar. Örnek 2 kullanım şekli.
*/

int main(void)
{
	//Program çıktısı "Yanlis"
	double x = 4.5;
	
	if (x > 4,0)
		printf("Dogru.");
	else
		printf("Yanlis.\n");
		
	//Aşağıdaki çıktı 5 6 7
	printf("%d %d %d\n", (3, 4, 5), 6, 7);
	
	
}	
