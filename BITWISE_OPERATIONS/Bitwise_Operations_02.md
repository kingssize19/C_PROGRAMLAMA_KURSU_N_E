# Bitwise Manipulations (2. Bölüm)

* **Bir tamsayının belirli bir bitini birlemek &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to set the bit)**
* **Bir tamsayının belirli bir bitini sıfırlamak &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to reset the bit)**
* **Bir tamsayının belirli bir bitini değiştirmek &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to flip the bit / to toggle the bit)**
* **Bir tamsayının belirli bir bitinin değerini elde etmek &nbsp;&nbsp;&nbsp; (to get the bit)**


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

* **x & y << z | a ^ b;** &nbsp;&nbsp;&nbsp;&nbsp; ifadesi işlem önceliğine göre &nbsp;&nbsp;&nbsp;&nbsp; **(x & (y << z)) | (a ^ b);** &nbsp;&nbsp; anlamına gelir.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

#### Bir tam sayının tek mi çift mi olduğunu sınamak.

* **x & 1 ;**
  * sayının 0.bitinin 1' mi yoksa 0'mı olduğunu test eder.
  * sayının 0. biti 1 ise o tek sayıdır.

* **if (x & 1)** ile sayının tek veya çift olduğu bulunabilir.
  * sayı tek ise if'in doğru kısmına girer.
  * sayı çift ise if'in yanlış kısmına girer.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

#### Bir sayıyı 1 eksiği ile &'lemek ne sonucunu doğurur?

```c
17 sayısı olsun        0001 0001
17 - 1 = 16            0001 0000
--------------------------------
Bu ikisin &'lersek :   0001 0000
```

**NOT :** Bir sayıyı 1 eksiği ile &'lersek ilk 1 olan biti sıfırlamış oluruz.

```c
36 : 0010 0100
35 : 0010 0011
--------------
&  : 0010 0000   
```

* Yukarıda 36 sayısını 35 ile &'ledik 36 sayısının ilk 1 biti 0 oldu.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

#### power of two

* Bir tam sayının 2'nin kuvveti olup olmadığını test etmek.
* Bir tam sayı ikinin kuvveti ise sayının bir biti 1'dir.

```c
x ikinin kuvveti olsun yani x = 0100 0000

x & (x - 1) : Bu ifadenin sonucu 0'dır. Bir sayıyı kendinden 1 eksiği ile &'lersek ilk 1 bitini 0'lamış oluruz.
x sayısı 2'nin kuvveti ise tek biti 1'dir o bitte 0'lanınca x in sonucu 0 olur.
```

* Bu kurala uyan ve 2'nin kuvveti olmayan tek sayı 0 sayısıdır.

```c
x = 0 olsun x'in 1 eksiği -1'dir yani tüm bitleri 1 olur.

x       = 0000 0000
x - 1   = 1111 1111
--------------------
x&(x-1) = 0000 0000   -> Sonuç 0 oldu fakat 0'sayısı 2 nin kuvveti değil.
```

* Aşağıdaki if ifadesi ile sayı 2'nin kuvveti mi değil mi sorgusu yapılabilir.

```c
if (x && !(x & (x-1)))
```


```c
#include <stdio.h>

#define POWER_OF_2(a)       ((a) && !((a) & ((a) - 1)))

int main() {
    
    int x;
    printf("Bir tamsayi girin : ");
    scanf("%d", &x);
    
    if (x && !(x & (x - 1))) {
        printf("power of two\n");
    }
    else {
        printf("not power of two\n");
    }
    /*
    if (POWER_OF_2(x)) {
        printf("power of two\n");
    }
    else {
        printf("not power of two\n");
    }
    */
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------------

#### Bir tamsayının en düşük anlamlı 4 bitinin oluşturduğu tam sayının değeri nedir?

* Sayımız **10100110011001110111** olsun.

```c
1010011001100111 0111  -> Bu sayının en düşük anlamlı 4 bitinin oluşturduğu değeri bulmak istiyoruz.
0000000000000000 1111  -> Bu maske ile &'lersek en düşük anlamlı 4 bitin değerini elde elde etmiş oluruz.

1010011001100111 0111
0000000000000000 1111
--------------------- & işlemi
0000000000000000 0111 
```

**NOT :** & (ve) işleminde 0 yutan eleman, 1 etkisiz eleman olduğu için son 4 bitin oluşturduğu tam0000000000000000 1111sayı değerini elde ederiz.

**NOT :** En düşük anlamlı byte'ının değerini elde etmek için 255 değeri ile & işlemi yaparız.

**NOT :** 16 bit'lik 0101 01010010 0101 sayısının ortadaki 8 bitini get etmek isteseydik :

```c
0101 01010010 0101 sayısı olsun
     ||||||||
     01010010  -> Bu bitleri get etmek isteseydik.

1. Yöntem
------------------------------------------------------------------------------------------------------
* Sayıyı 4 sağa kaydırırız.
* Bu 4 sağa kaydırılmış sayıyı 0000000011111111 sayısı ile &'lersek o sayıyı elde ederiz.
* Yani x bit'lik bir tam sayı ise ortadaki 8 biti get etmek için.
* ((x >> 4) & 255) işlemini yaparak sonuca ulaşabiliriz.
------------------------------------------------------------------------------------------------------

2. Yöntem
------------------------------------------------------------------------------------------------------
* Sayıyı 4 bit sola kaydırırız. Bizim 8 bitimiz en yüksek anlamlı 8 bit olur.
* Daha sonra 8 bit sağa kaydırırızç İşaretsiz sayılarda sağa kaydırmada soldan 0 besleme olduğu için.
* Bu yöntem ile 16 bitlik sayının ortadaki 8 bitini get etmiş oluruz.
* ((x << 4) >> 8) işelmi ile sonucu buluruz.
------------------------------------------------------------------------------------------------------
```

------------------------------------------------------------------------------------------------------------------------------------------------------------------

#### Sayının bitlerini yazdırman : bit_print() fonksiyonu

**1. Algoritma**

* Bu algoritmada x sayısını 00000001 ile maskeliyoruz. Sayıyı 31. bitten başlayarak 0'a kadar sağa kaydırıyoruz.

```c
#include <stdio.h>
#include <limits.h>

void bit_print(int x)
{
    for (int i = (int)sizeof(int)*CHAR_BIT - 1; i >= 0; --i) {
        putchar((x >> i) & 1 ? '1' : '0');
    }
    putchar('\n');
}

int main() {

    bit_print(32);  // 00000000000000000000000000100000
    
}
```

**2. Algoritma**

* Bu algoritmada x sayısını 10000000 maskesi ile &'leriz.
* Döngünün her turunda maskeyi 1 bit sağa kaydırırız.

```txt
10000000 maskesini elde etmenin yöntemi :
* İlk olarak, ilk değer olarak int türünün en küçük değerini vermek.
* unsigned int mask = INT_MIN;


10000000 maskesini elde etmenin başka yolu :

0000 0000 0000 0000 -> Bu sayı sıfır.
1111 1111 1111 1111 -> Bu sayı yukarıdaki 0 sayısının 1'e tümleyeni
0111 1111 1111 1111 -> Bir bit sağa kaydırınca elde edilen değer.
1000 0000 0000 0000 -> Yukarıdaki sayının bitsel değil'ini alırsak maskeyi elde etmiş oluruz.

```


















































































