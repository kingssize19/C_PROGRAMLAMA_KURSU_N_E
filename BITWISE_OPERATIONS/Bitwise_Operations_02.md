# Bitwise Manipulations (2. Bölüm)

* **Bir tamsayının belirli bir bitini birlemek &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to set the bit)**
* **Bir tamsayının belirli bir bitini sıfırlamak &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to reset the bit)**
* **Bir tamsayının belirli bir bitini değiştirmek &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to flip the bit / to toggle the bit)**
* **Bir tamsayının belirli bir bitinin değerini elde etmek &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to get the bit)**


------------------------------------------------------------------------------------------------------------------------------------------------------------------

## to set the bit

* 1000 1000 0?11 0101 &nbsp;&nbsp;&nbsp;&nbsp; ? bitini 1 yapalım.
* 0000 0000 0100 0000 &nbsp;&nbsp;&nbsp;&nbsp; (Bit mask)
* x biti set edilecek tam sayı, n ise set edilecek bitin indeksi olsun.
* x |= (1 << n); &nbsp;&nbsp;&nbsp;&nbsp; x'in n. biti set edilmiş (yani birlenmiş) olur.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <stdint.h>


int main(int argc, char **argv)
{
    uint16_t val = 0;

    bitprint(val);      // 0000 0000 0000 0000

    val |= (1 << 5);    // 5. indeksteki bitini 1 yap anlamında

    bitprint(val);      // 0000 0000 0010 0000

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <stdint.h>
#include <conio.h>

int main(int argc, char **argv)
{
    int x = 0;

    randomize();

    do {

        x |= (1 << rand() % 32);
        bitprint(x);
        _getch();
        system("cls");
 

    } while (x != -1); // Yani x 'in tüm bitleri 1 olana kadar çalış

}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## to reset the bit

* & (ve) işleminde 1 etkisiz eleman 0 yutan elemandır.
* 1111 1111 1011 1111 gibi bir bitmask ile bir sayının bitlerini maskelersek o ilgili biti sıfırlamış oluruz.

* **x &= ~(1 << n);** &nbsp;&nbsp;&nbsp;&nbsp; işlemi ile ilgili n indeksli bit'i sıfırlamış oluruz.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <stdint.h>
#include <conio.h>

int main(int argc, char **argv)
{
    int x = -1;

    bitprint(x);

    int n;
    printf("Kacinci bit reset edilsin : ");
    scanf("%d", &n);

    x &= ~(1 << n);

    bitprint(x);

/*
    Çıktı : 

    11111111111111111111111111111111
    Kacinci bit reset edilsin : 8
    11111111111111111111111011111111
*/

}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## to flip the bit &nbsp;&nbsp; / &nbsp;&nbsp; to toggle the bit

* Yani bit 1 ise 0 yapacağız. Bit 0 ise 1 yapacağız.
* Özel veya işleminde 0 etkisiz eleman olduğu için diğer bitler değişmez. Veya işleminde kullandığımız (1 << n) maskesi ile ilgili biti toggle yapmış oluruz.
* Özel veya'da 1 karşıdaki biti ters çevirir.
* **x ^= (1 << n) &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; n. biti toggle yapar.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <stdint.h>
#include <conio.h>

int main(int argc, char **argv)
{
    int x = 565;
                                
    bitprint(x);    // 0000000000000000000000100 0 110101

    x ^= (1 << 6);  // 6. biti toggle yapar

    bitprint(x);    // 0000000000000000000000100 1 110101

}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## to get the bit

* Tam sayının bir bitinin 1'mi yoksa 0'mı olduğunu öğrenmemizi sağlar.
* **x & (1 << n)** &nbsp;&nbsp;&nbsp;&nbsp; maskesi ile sayımızı &'lersek ve bu ifadeyi lojik yorumlamaya tabi tutarsak o biti get etmiş oluruz.
* **if (x & (1 << n))**
  * if'in doğru kısmına girmesi demek sayının n. bitinin 1 olması demektir.
  * if'in yanlış kısmına girmesi demek sayının n. bitinin 0 olması demektir.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <stdint.h>
#include <conio.h>

int main(int argc, char **argv)
{
    int x;
    
    printf("Bir tamsayi giriniz : ");
    scanf("%d", &x);

    int n;

    bitprint(x);

    printf("Kacinci bit : ");
    scanf("%d", &n);

    if (x & (1 << n)) {
        printf("%d. bit 1\n", n);
    }
    else {
        printf("%d. bit 0\n", n);
    }
/*
    Çıktı : 

    Bir tamsayi giriniz : 12568845
    00000000101111111100100100001101
    Kacinci bit : 8
    8. bit 1
*/

}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------------

| İşlem | İfade |
|--|--|
| n. biti set etmek | x \|= (1 << n) |
| n. biti reset etmek | x &= ~(1 << n) |
| n. biti toggle etmek | x ^= (1 << n) |
| n. biti get etmek | if (x & (1 << n)) |

------------------------------------------------------------------------------------------------------------------------------------------------------------------

* **x & y << z | a ^ b; &nbsp;&nbsp;&nbsp;&nbsp; ifadesi işlem önceliğine göre &nbsp;&nbsp;&nbsp;&nbsp; (x & (y << z)) | (a ^ b); &nbsp;&nbsp; anlamına gelir.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

































































































