#### Hatırlatma : a << b

* Negatif işaretli tamsayıların sola kaydırılması tanımsız davranış.
* Sol operand işaretli pozitif tamsayi ise ve sola kaydırma işleminde elde edilen değer işaretli tamsayı range'ini aşıyorsa tanımsız davranış.

------------------------------------------------------------------------------------------------------------------------------------------------------

#### ctype kütüphanesindeki test işlevlerinin implementasyonu

```c
int isupper(int c);
int isdigit(int c);
```
* 128 elemanlı bir lookup table oluşturalım ve büyük, küçük harf vs gibi özelliklerini bu lookuptable'da saklayalım.
* Bu lookup table ı oluşturmak için aşağıdaki şekilde <ctype.h> dosyasından yardım alalım.

```c
#include <stdio.h>
#include <ctype.h>

#define		UPPER	1
#define		LOWER	2
#define		DIGIT	4
#define		XDIGIT	8
#define		SPACE	16
#define		PUNCT	32
#define		PRINT	64
#define		CONTROL	128


int main(void)
{
    for (int i = 0; i < 128; ++i) {

        if (i && i % 16 == 0)
            printf("\n");

        int x = 0;

        if (isupper(i)) {
            x |= UPPER;
        }

        if (islower(i)) {
            x |= LOWER;
        }

        if (isdigit(i)) {
            x |= DIGIT;
        }

        if (isspace(i)) {
            x |= SPACE;
        }

        if (ispunct(i)) {
            x |= PUNCT;
        }

        if (isxdigit(i)) {
            x |= XDIGIT;
        }

        if (isprint(i)) {
            x |= PRINT;
        }

        if (iscntrl(i)) {
            x |= CONTROL;
        }
        printf("%d, ", x);
    }

}
```

```c
// OUTPUT
const unsigned int arr_ctype[] = {
128, 128, 128, 128, 128, 128, 128, 128, 128, 144, 144, 144, 144, 144, 128, 128,
128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
80, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96,
76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 96, 96, 96, 96, 96, 96,
96, 73, 73, 73, 73, 73, 73, 65, 65, 65, 65, 65, 65, 65, 65, 65,
65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 96, 96, 96, 96, 96,
96, 74, 74, 74, 74, 74, 74, 66, 66, 66, 66, 66, 66, 66, 66, 66,
66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 96, 96, 96, 96, 128,
};
```

* Yukarıdaki kod ile lokkup table oluşturduk. Bu lookup table'ın mantığı şu 128 karakter var bu karakterlerin herbirinin özelliklerini x değişkeninin bitlerinde 1 veya 0 şeklinde sakladık. her karakter için elde edilen değeri o indisli elemana yazdık. daha sonra fonksiyonel makrolar ile hangi durumu sorgulamak istiyorsak o ilgili bitlerin 1 veya 0 olma durumlarını karşılaştıran fonksiyonel makroları yazdık. (test kodu, myctype.h ve myctype.c  aşağıda yer almaktadır.)


#### TEST KODU
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"


int main(void)
{
    int ch;

    printf("bir karakter girin : ");
    ch = getchar();

    if (ISUPPER(ch))
        printf("buyuk harf\n");
    else
        printf("kucuk harf\n");

}
```

#### myctype.c
```c
#include "myctype.h"

const unsigned int arr_ctype[] = {
128, 128, 128, 128, 128, 128, 128, 128, 128, 144, 144, 144, 144, 144, 128, 128,
128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
80, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96,
76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 96, 96, 96, 96, 96, 96,
96, 73, 73, 73, 73, 73, 73, 65, 65, 65, 65, 65, 65, 65, 65, 65,
65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 96, 96, 96, 96, 96,
96, 74, 74, 74, 74, 74, 74, 66, 66, 66, 66, 66, 66, 66, 66, 66,
66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 96, 96, 96, 96, 128,
};
```


#### myctype.h
```c
myctype.h

#ifndef MYCTYPE_H
#define MYCTYPE_H


#define		UPPER	1
#define		LOWER	2
#define		DIGIT	4
#define		XDIGIT	8
#define		SPACE	16
#define		PUNCT	32
#define		PRINT	64
#define		CONTROL	128

extern const unsigned int arr_ctype[];

#define		ISUPPER(c)		(arr_ctype[c] & UPPER)
#define		ISLOWER(c)		(arr_ctype[c] & LOWER)
#define		ISALPHA(c)		(arr_ctype[c] & (LOWER | UPPER))
#define		ISDIGIT(c)		(arr_ctype[c] & DIGIT)
#define		ISALNUM(c)		(arr_ctype[c] & (LOWER | UPPER | DIGIT))
#define		ISSPACE(c)		(arr_ctype[c] & SPACE)
#define		ISPUNCT(c)		(arr_ctype[c] & PUNCT)
#define		ISPRINT(c)		(arr_ctype[c] & PRINT)



#endif
```

------------------------------------------------------------------------------------------------------------------------------------------------------

* 16 bitlik bir değişkenimiz olsun.
* xxxyyyyzzzzztttt
* 16 biti tek bir tamsayı olarak kullanmak yerine,
  * Örneğin ilk 3 biti ayrı bir tamsayı, ondan sonraki 4 biti ayrı bir tamsayı vs. gibi kullanabilirmiyiz ?
* Cevap : Evet (Gömülü sistemlerde çok kullanılır.)
* xxxyyyy zzzzz tttt
* zzzz bitlerinin oluşturduğu sayıyı elde etmek isteyelim :
  * xxxyyyyzzzzztttt sayısını 4 bit sağa kaydıralım 0000xxxyyyyzzzzz sayısını elde ederiz.
  * 0000xxxyyyyzzzzz sayısını 0000 0000 0001 1111 maske'si ile &'lersek zzzzz bitlerinin oluşturduğu sayının değerine ulaşırız.

------------------------------------------------------------------------------------------------------------------------------------------------------

* xxxyyyyzzzzztttt sayısının zzzzz bitlerine bir değer yazmak isteyelim. 5 bit olduğu için val 0-31 arasında değer alır.
* xxx yyyy zzzzz tttt -> uval
* 111 1111 00000 1111 -> mask
* uval'i mask ile &'lersek zzzzz bitlerini 0'lamış oluruz.
* Ondan sonra zzzzz bitlerine yazmak istediğimiz değeri 4 bit sola kaydırıp bu değerin zzzzz bitlerine denk gelmesini sağlarız. Ardından |= işlemini gerçekleştirerek bu zzzzz bitlerine yazma işlemini gerçekleştiririz.
* uval |= (val << 4)

------------------------------------------------------------------------------------------------------------------------------------------------------

**NOT :** Hiçbir bitsel işlemi doğrudan yapmadan tamamen derleyicinin üreteceği kod'la bir tam sayının belirli bitlerini ayrı değişken olarak kullanabiliriz.

------------------------------------------------------------------------------------------------------------------------------------------------------

# Yapıların Bit Alanı Elemanları (Bitfield Members of Structures)

```c
struct Data {
  int x;
  int y : 3;    // bitfield member -> ismi y, türü int, 3 bitlik alanda tutulacak.
  int z : 5;    // ismi z, türü int, 5 bitlik alanda tutulacak.
};
```

```c
int y : 3;    // (3) Bu eleman constant expression olmak zorunda

//----------------------------------------------------------------
//----------------------------------------------------------------

int n = 5;
int y : n;  // (n) constant expression değil. Sentaks hatası. Bu kod illegal.
```

**NOT :** Yapıların bitfield elemanlarının kaç bitlik alanda tutulacağı bilgisi constant expression olmak zorundadır.

**NOT :** Eğer eleman bit seviyesinde tutulacaksa (int y : 3; gibi) burada türün ya işaretli int olması lazım, ya işaretsiz int olması lazım ya da (C99'da) _Bool türünden olması lazım. (unsigned int, signed int, _Bool)

```c
long y : 5;
short z : 3;

// Bu kullanımlar standart değil. Ama sentaks hatasıda değil yani derleyiciye bırakılmış.
```

------------------------------------------------------------------------------------------------------------------------------------------------------

**NOT :** En çok karşımıza çıkacak tema; Yapının bütün elemanlarının bitfield member olması.

```c
// Doğru kullanım. Hata yok.

struct Data {
  int x;
  int y : 3;
  int z : 5;    
};
```

```c
// En sık karşılaşacağımız kullanım şekli.

struct Data {
  int x : 2;
  int y : 3;
  int z : 5;
};
```

------------------------------------------------------------------------------------------------------------------------------------------------------

```c
struct Data {
  int x : 5;
  int y : 3;
  int z : 5;
};


int main(void)
{
//    struct Data mydata = { .y = 5, .x = 24, .z = 2 };
//    struct Data mydata = { 20, 4, 16 };

    struct Data mydata;
    struct Data* p = &mydata;
    p->x = 4;
}
```
* Bu işlemler, erişimler şüphesiz bitsel işlemler ile yapılıyor ama bu bitsel işlemlerin kodlarını derleyici oluşturduğu için bize ait olan iş yükü azalıyor.

------------------------------------------------------------------------------------------------------------------------------------------------------

* Aşağıdaki Data yapısı için :
  * sizeof(struct Data) değeri 4'tür.
  * Hizalama nedeniyle (padding byte olduğu için) 4 byte.

```c
struct Data {
  int x : 5;
  int y : 2;
};

int main(void)
{
    printf("%zu\n", sizeof(struct Data));   // 4
}
```

* Aşağıdaki Data yapısı için :
  * sizeof(struct Data) değeri 4'tür.

```c
struct Data {
  int x1 : 5;
  int x2 : 3;
  int x3 : 5;
  int x4 : 3;
  int x5 : 6;
  int x6 : 2;
  int x7 : 4;
  int x8 : 4;
};

int main(void)
{
    printf("%zu\n", sizeof(struct Data));   // 4
}
```

* x8 : 5; olsaydı 4'byte'ı (yani 32 bit'i) aşardı.
* Bu yüzden struct Data sizeof'u 8 byte olurdu. (5 byte olmazdı)
* Sebebi yine hizalamadan dolayı.
* Yani sistemlerde tipik olarak bit alanı eleman yada elemanlara sahip yapıların sizeof'u hizalama nedeniyle sistemdeki int türünün katları olarak artar. (**storage unit**)

------------------------------------------------------------------------------------------------------------------------------------------------------

```c
struct Data {
  int a : 5;
  int b : 3;
  
  // aaaaabbb
  // bbbaaaaa
  
  // Hangisi şeklinde olduğu derleyiciye bağlı
};
```

* Yani derleyici arka planda bit alanı elemanlarının bitlerinin yerleştireceği konusunda, ne şekilde kod üreteceği konusunda büyük ölçüde serbesttir.
* Bit elemanları aynı byte'a sığıyorsa derleyici bu elemanları aynı byte'a koymak zorunda fakat aynı byte'a sığmıyorsa aşağıdaki gibi bir kodda üretilebilir.

```c
struct Data {
  int a : 5;
  int b : 4;
  
  // aaaaabbb
  // b*******
  
  // Ya da
  
  // aaaaa???
  // bbbb????
  
  // şeklinde yerleştirilebilirdi.
};
```

* Bu yüzden ;
* Yapıların bit alanı elemanlarını kullanıyorsanız. Yapının elemanlarına bitsel işlemler ile erişmeye çalışmayın.
* Çünkü bu büyük ölçüde derleyiciye bağlı.

------------------------------------------------------------------------------------------------------------------------------------------------------

```c
struct Data {
  int a : 5;
  int _ : 3;
  int b : 4;
};
```

* Yukarıdaki kullanım ile b'nin ayrı bir byte'ta olması garanti altında.
* Bu şekilde b'nin bitlerinin birden fazla byte'a yayılmasını, dolayısıyla b'nin üstünde yapılan işlemlerin yüksek maliyetle yapılmasına engel olmak için.

------------------------------------------------------------------------------------------------------------------------------------------------------

#### DOS sistemi 16 bitlik işletim sistemi.

```c
struct DosDate {
  unsigned int day : 5;
  unsigned int mon : 4;
  unsigned int year : 7;
};

struct DosTime {
  unsigned int hour : 5;
  unsigned int min : 6;
  unsigned int sec : 5; // 0 - 31
  
  // 5 bitlik alanda 0 - 31 değerleri tutulabilir.
  // DOS işeltim sisteminde 31 ve üzeri saniyeler 2 ile çarpılarak ifade edilir.
  // Bu yüzden DOS'taki deosya oluşturma saniyeleri hep çifttir.
};
```

------------------------------------------------------------------------------------------------------------------------------------------------------

* Bitler adreslemeye tabi değildir.
* C'nin kurallarına göre adreslenebilir en küçük tür 1 byte storage'a sahip char, signed char, unsigned char türleridir.
* Bu yüzden yapıların bit alanı elemanlarının adres operatörünün operandı olması geçerli değildir. Doğrudan sentaks hatası.

```c
typedef struct {
    int x : 5;
    int y : 3;
}Data;

int main(void)
{
    Data mydata = { 2, 4 };
    int* p = &mydata.x;     // illegal code. Sentaks hatası error: cannot take address of bit-field 'x'
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------

# UNION İLE YAPILARIN BİTFİELD ELEMANLARININ KULLANIMI

#### Bir tarih bilgisini 32 bitlik değişkende saklamak.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"
#include <stdint.h>

typedef union {

    uint32_t uval;

    struct {    // Anonymous struct
        unsigned int day : 5;
        unsigned int mon : 4;
        unsigned int year : 7;  // 1980 sonrası için
        unsigned int hour : 5;
        unsigned int min : 6;
        unsigned int sec : 5;   // saniyenin yarisi
    };


}NDate;



int main(void)
{
    NDate mydate = {
        .day = 1,
        .mon = 3,
        .year = 2025 - 1980,
        .hour = 1,
        .min = 16,
        .sec = 58 / 2
    };

    printf("%u\n", mydate.uval);              // 3925957217  tarih bilgilerini bu tamsayı değerinde sakladık

    // 3925957217 bu tamsayı değerinden tekrar tarih bilgisine geri dönebiliriz.
    mydate.uval = 3925957217;


    printf("%02u-%02u-%u %02u-%02u-%02u\n", mydate.day, mydate.mon, mydate.year + 1980, mydate.hour, mydate.min, mydate.sec * 2); //01-03-2025 01-16-58

    // union olduğu için 32 bitlik veri saklayabilir. tarih bilgilerini 32 bitlik bir tamsayı değişkende sakladık.
    // Ardından bu değeri uval e atayıp tarih değerlerini taşıyan elemanları ekrana yazdırdığımızda tarihe eriştik.
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------

#### Yüksek anlamlı 5 bitini 1 yapmak

* ~0u&emsp;&emsp;&emsp;&emsp;// 11111111111111111111111111111111 işaretsiz türden bitleri 1 olan sayıyı ifade eder.
* int n = 5; olsun
* ~0u&emsp;&emsp;&emsp;&emsp;// 11111111111111111111111111111111
* (~0u >> n)&emsp;&emsp;&emsp; // 00000111111111111111111111111111
* ~(~0u >> n)&emsp;&emsp;&emsp;// 11111000000000000000000000000000

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"
#include <stdint.h>
#include "nutility.h"


int main(void)
{
    int n = 5;

    bitprint(~(~0u >> n));  // 11111000000000000000000000000000
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------

#### En düşük anlamlı en bitini 1 yapmak

* ~0u&emsp;&emsp;&emsp;&emsp;// 11111111111111111111111111111111 işaretsiz türden bitleri 1 olan sayıyı ifade eder.
* int n = 5; olsun
* ~0u&emsp;&emsp;&emsp;&emsp;// 11111111111111111111111111111111
* (~0u << n)&emsp;&emsp;&emsp; // 11111111111111111111111111100000
* ~(~0u << n)&emsp;&emsp;&emsp;// 00000000000000000000000000011111

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"
#include <stdint.h>
#include "nutility.h"

int main(void)
{
    int n = 5;

    bitprint(~(~0u << n));  // 00000000000000000000000000011111
}

```

------------------------------------------------------------------------------------------------------------------------------------------------------

#### Bitsel exor işleminin ilginç bir özelliği

* EXOR'lama işleminde sıranın önemi yoktur.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"
#include <stdint.h>
#include "nutility.h"


// exor'lama işleminde sıranın önemi yoktur.

int main(void)
{
    int x = 86521;
    int y = 983874;
    int z = 27643;

    printf("%d\n", (x ^ y) ^ z);        // 932160
    printf("%d\n", (y ^ x) ^ z);        // 932160
    printf("%d\n", (z ^ y) ^ x);        // 932160
}
```

**Hatırlatma :** Bir sayıyı kendisi ile exor'larsak o ifadenin değeri 0 olur.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"
#include <stdint.h>
#include "nutility.h"

int main(void)
{
    // 13  21
    int x = 21;
    
    printf("%d\n", x);    // 21

    // x in değeri 13 ise 21 yapalım. 21 ise 13 yapalım.

    x = x ^ 13 ^ 21;  // Hatırlatma bir sayıyı kendisi ile exor'larsak o ifadenin değeri 0 olur.

    printf("%d\n", x);    // 13
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------

* 16 bitlik bir değişkenimiz olsun. Düşük anlamlı 2 byte'ı ve yüksek anlamlı 2 byte'ı elde etmeye çalışalım.
* Bir byte'ı elde ederken ilgili bitleri 1 diğer bitleri 0 ile &' lersek 0 yutan eleman olduğu için o ilgili bitleri elde etmiş oluruz.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"
#include <stdint.h>
#include "nutility.h"


int main(void)
{
    uint16_t x = 0xEA45;

    uint8_t low_bytes;
    uint8_t high_bytes;

    printf("%X\n", x);      // EA45

    low_bytes  = x & (0xFF);
    high_bytes = (x >> 8) & (0xFF);

    printf("%X\n", low_bytes);  // 45
    printf("%X\n", high_bytes); // EA

}
```

* Aynı işlemi 32 bitlik için yaparsak : 
* Sayımız 0xEA45CB28 olsun.
* x & 0xFFFF -> CB28
* x >> 16 & 0xFFFF -> EA45

------------------------------------------------------------------------------------------------------------------------------------------------------

#### Little-endian ve Big-endian Dönüşümleri

* EA28 little endian olsun bunubig endian'a dönüştürürsek 28EA olur. Bu dönüşümde byte'ları takas ederek olur.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"
#include <stdint.h>
#include "nutility.h"


int main(void)
{
    uint16_t x = 0xEA45;

    // 0x45EA elde etmek istiyoruz.

    printf("%X\n", x);      // EA45

    uint16_t new_x = x >> 8 | x << 8 & 0xFF00;

    printf("%X", new_x);    // 45EA

}
```

* 32 bitlik bir **little endian to big endian** dönüşümü yapalım.
* AB23CF98 olsun bunun 98CF23AB olmasını istiyoruz.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myctype.h"
#include <stdint.h>
#include "nutility.h"


int main(void)
{
    uint32_t x = 0xAB23CF98;

    printf("%X\n", x);      //  AB23CF98

    x = (x << 24) | (x >> 24) | (x >> 8 & 0x0000FF00) | (x << 8 & 0x00FF0000);

    printf("%X\n", x);      // 98CF23AB

}
```































