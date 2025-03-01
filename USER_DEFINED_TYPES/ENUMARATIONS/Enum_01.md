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







































































































