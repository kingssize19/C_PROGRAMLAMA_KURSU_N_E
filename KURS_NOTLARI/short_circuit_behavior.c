/*
	*** Short Circuit Behavior ***
	Aşağıdaki örnek kodda  && operatörünün sol operandı yani x = 0 olduğu için sağ operanda hiç bakılmadan ifade sona erecek.
	z'nin değeri 0 olacak ++y ifadesine uğranmadığı için y nin değeri arttırılmayacak.
 
*/ 
#include <stdio.h>

int main(void)
{

	int x = 0;
	int y = 47;
	
	int z = x && ++y;
	
	printf("z = %d\n", z);
	printf("y = %d\n", y);
	

}
