## Enumarations (Numaralandırma)

* Kısıtlı sayıda değeri tamsayılarla ifade etmeye yarar.
* Bazen numaralandırma değerleri yerine makrolarda kullanılabilir.

#### macrolar;
* Derleyicinin görmediği ön işlemci programı tarafından yer değiştirmeye tabi tutulur.
* Scope'ları yoktur.
* Bir tür kavramı yoktur. Yani iki tane birbiriyle alakası olmayan değer iki tane macro ile define edilmiş olabilir. Bunlar bir tür kapsamında değildir.

------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
enum Suit { Club, Diamond, Heart, Spade };

int main()
{
  enum Suit s;    // legal
// Suit s; -> C'de illegal. C++'da legal   
}
```
* **Suit :** enumaration Tag.
* **{ } :** Bunun arasında tanıtılan isimlere (Club, Diamond...) enumaration constant veya enumarator denir.
  
------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
typedef enum Suit { Club, Diamond, Heart, Spade }Suit;

int main(int argc, char **argv)
{
    Suit s; // legal
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
enum Suit { Club, Diamond, Heart, Spade };
enum Color { White, Gray, Red, Blue, Brown, Black };

int main()
{
    Heart;   // Bu bir tamsayı sabiti ve bu bir constant expression. Bu ifadenin türü enum Suit türüdür.
}
```

* Club, Diamond, Gray, Red gibi isimlere enumarator ya da enumarations constant denir.
* Bu isimler birer tamsayı sabiti.

------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
enum Suit { Club, Diamond, Heart, Spade };

// Club    -> 0
// Diamond -> 1
// Heart   -> 2
// Spade   -> 3
```

* Default olarak numaralandırma sabitlerinin değerleri 0'dan başlayarak birer artan değerlerdir.
* Numaralandırma sabitlerinin değerlerini kendimiz belirleyebiliriz.

```c
enum Suit { Club = 675, Diamond = 875, Heart = 312, Spade = 771 };
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
enum Color {White, Gray, Red, Blue};

int main(int argc, char **argv)
{
    printf("%d %d %d %d\n", White, Gray, Red, Blue); // 0123
}
```

```c
enum Color {White = 375, Gray = 676, Red = 371, Blue = 909};

int main(int argc, char **argv)
{
    printf("%d %d %d %d\n", White, Gray, Red, Blue); // 375 676 371 909
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

* Değer verilmeyen değişkenler bir önceki değişkenin değerinin 1 fazlası olur.

```c
enum Nec {A = 700, B, C, D, E};

int main(int argc, char **argv)
{
    printf("%d %d %d %d %d\n", A, B, C, D, E); // 700 701 702 703 704
}
```

```c
enum Nec {A = 300, B, C = 400, D, E};

int main(int argc, char **argv)
{
    printf("%d %d %d %d %d\n", A, B, C, D, E); // 300 301 400 401 402
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

* Enumarator'ler negatif değerde olabilirler.

```c
enum Nec {A = 900, B = -875, C = 1007, D = -25};

int main(int argc, char **argv)
{
    printf("%d %d %d %d\n", A, B, C, D); // 900 -875 1007 -25
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

#### Not : 

* Numaralandırma türleri hem integer types hem de user defined types tür kategorilerinin öğesidir.

------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
typedef enum Color { White, Gray, Red, Blue }Color;
```

* Bu türün ismi hem enum Color hem de Color olur.

```c
typedef enum{ White, Gray, Red, Blue }Color;
```
* Bu türün ismi sadece Color olur.

------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
enum { White, Gray, Red, Blue };
```

* enum keyword'ünü kullanıp bir Tag ismi kullanmadanda bu şekilde numaralandırma türü oluşturabiliriz.
* Fakat bu türden bir değişken tanımlama şansımız olmaz.
* Başka bir yerde bu numaralandırma sabitlerini kullanabiliriz.

------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
enum Nec { A, B, C, D, E};

int main(int argc, char **argv)
{
    enum Nen c1 = A;
    enum Nec c2 = C;

    if (c1 < c2) {      // legal kod. True çıktısını verir.
        printf("True\n");
    }
    else {
        printf("False\n");
    }
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
enum Nec { A, B, C = 1, D, E};      // legal sentaks. Hata yok.

// A = 0,
// B = 1,
// C = 1,
// D = 2,
// E = 3,
```

```c
enum Nec { A, B, C = 1, D = 1, E = 1};      // legal. sentaks Hatası yok.

// A = 0,
// B = 1,
// C = 1,
// D = 1,
// E = 1,
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

* enum türünden bir değişken tanımlayabiliriz.

```c
enum Color mycolor = Red;
```

* Yapının elemanları enum türünden olabilir.

```c
enum Nec { Club, Dia, Heart, Spade };
enum Erg { two = 2, three = 3, four = 4 };

struct Data {
    enum Nec n;
    enum Erg e;
};
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

* Enum türü derleyici tarafında işaretli int türü ile ifade ediliyor.
* Yani C'de sizeof int ile sizeof enum türünün aynı olduğuna güvenerek kod yazabiliriz.

```c
typedef enum {A, B, C, D}Suit;

int main(int argc, char **argv)
{
    printf("sizeof(int) : %zu\n", sizeof(int));     // sizeof(int) : 4
    printf("sizeof(Suit) : %zu\n", sizeof(Suit));   // sizeof(Suit) : 4
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

## Dezavantajları 

* En önemli dezavantajı scope konusudur.

* Numaralandırma türlerinden tamsayı - gerçek sayı türlerine ya da tamsayı - gerçek sayı türlerinden numaralandırma türlerine örtülü dönüşümün olması C'de bir dezavantajdır.
* Derleyici bu dönüşümleri kontrol etmek zorunda değil.
* Bu hatayı tespit etmek için ya kendimiz bir kod yazacağız ya da statik kod analizi yapan bir program kullanmalıyız.

------------------------------------------------------------------------------------------------------------------------------------------------------------

* Farklı enum türleri arasındada örtülü dönüşüm olabilir.

```c
enum Color { White, Gray, Red, Blue, Brown, Black };
enum Fruit { Apple, Orange, Banana };

int main(void)
{
    enum Color mycolor = Orange; // Legal kod. Sentaks hatası yok. C++'da sentaks hatası.
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------------

* enum türlerinin scope alanı vardır.
* enumarator olan isimlerinde scope alanı vardır.
* enum türünün scope'u ile o türün enumarator'lerinin scope'ları arasında bir fark yoktur.

-------------------------------------------------------------------------------------------------------------------------------------------------------------

* Birden fazla .h dosyasını kullandığımızda enum'ların çakışma durumu söz konusu olabilir. Bu durumda derleyici Sentaks Hatası verir.

```c
//#include "screen.h"
enum ScreenColor { White, Gray, Red, Blue, Brown, Black };

//#include "traffic.h"
enum TrafficLight { Yellow, Red, Green };

// Bu iki enum yapısıbirbiriyle çakışır. Sentaks Hatası
```

* Bu başlık dosyalarında bu enumarator isimleri özelleştirilerek çakışmaların büyük ölçüde önüne geçilmektedir.

```c
//#include "screen.h"
enum ScreenColor { ScreenColorWhite, ScreenColorGray, ScreenColorRed, ScreenColorBlue, ScreenColorBrown, ScreenColorlack };

//#include "traffic.h"
enum TrafficLight { TrafficLightYellow, TrafficLightRed, TrafficLightGreen };


// Bu şekilde çakışmaların önüne büyük ölçüde geçilir.
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------

#### Macrolara aşağıdaki kullanım biçimiyle bir scope kazandırılabilir. Fakat bu gerçek anlamda bir scope değil.

```c
#define SIZE   100

void func(void)
{
    #undef  SIZE
    #define  SIZE   100

    #undef  SIZE  
}
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------

* Numaralandırma sabiti, define makrosundan daha iyi alternatifli şekilde kullanılabilir.

```c
void func(void)
{
    enum { SIZE = 100 };
    int a[SIZE] = { 0 };
}
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------

* Bir diğer kullanışlı biçimi. Kodda değişiklik yapıp yeni bir enumarator eklediğimizde NumberOf enumarator'u bu sabitler'in sayısı olacaktır.

```c
enum Nec { A, B, C, D, E, NoOfNec };

int main()
{
    // int nec[NoofNec];
    // for (int i = 0; i < NoOfNec; ++i);
}
```


























































































































