/*
	set bit count - Kernighan Algoritması
	
	-> Bitwise and işlemi; 
	Bir sayıyı kendisinin bir eksiği ile and'lerseniz sağdan ilk 1 bitini sıfır yapmış olursunuz. 
	Bu mantık çerçevesinde bir sayıda bulunan 1 bitlerinin sayısını bulmuş oluruz.
	
	NOT: 2'nin kuvveti sayıların tek bir biti 1 değerine sahiptir.
	0000 0010 -> 2	(2^1, bir biti 1 değerinde.)
	0000 0100 -> 4	(2^2, bir biti 1 değerinde.)
	0010 0000 -> 32 (2^5, bir biti 1 değerinde.)
	
	NOT: -1 sayısının bütün bitleri 1'dir.
	1111 1111 -> -1
	
	Aşağıdaki programda giriş olarak decimal sayı giriyoruz. Ardından 1 byte gösteriminde kaç biti 1 değerine sahip bu değere ulaşıyoruz.
*/

#include <stdio.h>


int sbc(int x)
{
	  int cnt = 0;
	  while (x) {
		
	    	x &= x - 1;
		    ++cnt;
	
	  }
  
	  return cnt;
}

int main(void)
{
	int ival;
	
	scanf("%d", &ival);
	int result = sbc(ival);
	
	printf("cnt = %d\n", result);
	return 0;
  
}
