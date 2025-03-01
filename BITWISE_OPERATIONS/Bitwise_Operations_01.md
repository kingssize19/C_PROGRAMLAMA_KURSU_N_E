# Bitsel İşlemler ve Bitsel Operatörler

* Bitwise operations
* Bitwise manipulations

* **Bitwise :** Bit bit işlem yapmak anlamına gelir.

* Tamsayı değişkenlerinin bitleri üstünde işlemler yaparak aslında bitleri ayrı değişkenlermiş gibi kullanma şansını elde ederiz.



## Bitsel Operatörler

| Öncelik Seviyesi | Operatör İsmi| Operatör | 
|--|--|--|
| 2 | Bitwise Not | ~ |
| 5 | Bitwise Shift | >> << | 
| 8 | Bitwise AND | & |
| 9 | EXOR | ^ |
| 10 | Bitwise OR | \| |
| 14 | Diğer İşlemler | &=, ^=, |=, >>=, <<= |


### Ortak Özellikleri

* Tamsayıların bitleri üzerinde işlem yaparlar. Yani değerleri üzerinde değil.
* Bu operatörlerin operandları gerçek sayı türlerinden olamaz.
* Bitsel operatörlerin operandları tamsayı türlerinden olmak zorundadır.


--------------------------------------------------------------------------------------------------------------------------------------------

#### 1. Bitwise NOT Operator (~)

* Yan etkiye sahip değildir.
* ~x ifadesi olsun bu işlem ile x'in değeri değişmez.
* Bitsel değil (~) operatörünün ürettiği değer bitlerin değilinin elde edilmesiyle oluşan tamsayıdır.
  * Yani bire tümleyen değerini üretir.
  * 1 olan bitler yerine 0
  * 0 olan bitler yerine 1 değerini üretir.

```c
x = 16 olsun.

x  : 0000 0000 0001 0000
~x : 1111 1111 1110 1111

~(~x) = x 
```

* Bir sayının bitsel değilinin Bitsel değili sayının kendisidir.

--------------------------------------------------------------------------------------------------------------------------------------------

```c
int main(int argc, char **argv)
{
    int x = 25;

    printf("x = %d\n", x);      // x = 25

    bitprint(~x);

    printf("x = %d\n", x);      // x = 25
   
}
```

* ~ operatörü yan etkiye sahip değil. Yukarıda örnek kod yer almaktadır. x'in değeri değişmemektedir.

--------------------------------------------------------------------------------------------------------------------------------------------

```c
char c = 12; olsun
```

* **sizeof(c);  :** 1 byte. (char türünün sizeof'u)
* **sizeof(+c); :** 4 byte. (işaret operatörü "+" integral promotion'a sebep olur. +c ifadesinin türü int'tir.)
* **sizeof(~c); :** 4 byte. (türü int. Tür dönüşümünü tetikler. Yani operandlar int'ten daha düşük rank'e sahipse tamsayı türüne yükseltilir.)

--------------------------------------------------------------------------------------------------------------------------------------------

#### 1. Bitwise Shift Operators (>> <<)

#### Bitwise Left

```c
x << 2
```
* x tamsayısının bitleri üstünde işlem yapılıyor.
* sağ operand olan 2 ise kaydırmanın kaç pozisyon yapıldığını ifade eder.

--------------------------------------------------------------------------------------------------------------------------------------------

```c
x << 1 olsun. Soldan o kadar bit çıkar. Sağdan da o kaydırılan bit sayısı kadar 0 biti eklenir.
```

--------------------------------------------------------------------------------------------------------------------------------------------

```c
x << 3

-> 1001 0010 0010 0011       (x sayısının bitleri)
-> 100 | 1 0010 0010 0011    (sola 3 bit kaydırdık. Baştaki 3 bit yok oldu.)
-> 1001 0001 0001 1000       (En sağdan 3 adet 0 biti eklendi.)
```

* Yukarıdaki şekilde sola kaydırma işlemi gerçekleştirilir.

--------------------------------------------------------------------------------------------------------------------------------------------

* Sağdan gelen bitleri 0 biti olma garantisi vardır.
* Sağ operandın (yani kaydırılacak pozisyon sayısının) 0'dan küçük olması tanımsız davranış.
* Aynı şekilde sağ operandın, işlemin yapıldığı tamsayı türünün bit sayısına eşit yada bundan büyük olması tanımsız davranıştır.

```c
// int 4 byte olsun.

int x = 762134421;
int y = 32;    // Max 31 olmalı

int z = x << y; // U.B. (Tanımsız Davranış) (<< ve >> her iki operatör içinde tanımsız davranış)

```

--------------------------------------------------------------------------------------------------------------------------------------------

```c
char c = 151;

int x = c << 29;    // Tanımsız davranış yok. c << 29 işlemi integral promotion'dan dolayı int türünde yapılıyor.
```

--------------------------------------------------------------------------------------------------------------------------------------------

* Kaydırma operatörünün yan etkisi yok. O nesnenin değerini değiştirmez.

```c
x = -1; // -1 in bütün bitleri 1'dir.

x << 2;  // 1111 1111 1111 1100  Sağdan 2 tane 0 biti eklendi.
```

--------------------------------------------------------------------------------------------------------------------------------------------

* Sayının sola 1 kaydırılması demek ikilik sayı sisteminde sayının değerini 2 ile çarpmak demektir.

```c
int x = 15 olsun;   // 0000 0000 0000 1111 => 15

x << 1 ifadesinin değeri 30 olur.  // 0000 0000 0001 1110 => 16 + 8 + 4 + 2 = 30
x << 3 ifadesinin değeri 120 olur. Çünkü 3 kere 1 bit sola kaydırılmış olur. 15*2 = 30 (1. kaydırma), 30*2 = 60 (2. kaydırma), 60*2 = 120 (3. kaydırma)
````

--------------------------------------------------------------------------------------------------------------------------------------------

#### Bitwise Right

* Kaydırılacak pozisyon sayısı kadar sağdan bit çıkacak ve ekleme soldan yapılacaktır.

**Not :** Sola kaydırma işleminde sağdan yapılan besleme (feeding) her zaman 0 biti ile olur.
**Not :** Ama bitsel sağa kaydırma işleminde soldan yapılan besleme bir istisna dışında 0 biti ile olur.

* Eğer sayı (yani sol operand) işaretli tamsayı türünden ve negatif ise soldan yapılacak beslemenin 0 yada 1 ile yapılması derleyiciye bağlıdır. (implementation defined)
* Sol operand unsigned ise soldan yapılan besleme herzaman 0'dır.
* Sol operand işaretli ve pozitif ise yapılan besleme 0'dır.
* Sol operand işaretli ve negatif ise derleyiciye bağlı. (Benim derleyicimde soldan eklenen bit 1)
  * Besleme 1 ile yapılıyorsa aritmetik besleme (sign extension)
  * Besleme 0 ile yapılıyorsa logic besleme 

--------------------------------------------------------------------------------------------------------------------------------------------

#### "&", "^", "|"  Operators

* **& :** Bitwise and
* **^ :** Bitwise exor
* **| :** Bitwise or

* Operatörlerin hepsi karşılıklı bitleri işleme sokar.

--------------------------------------------------------------------------------------------------------------------------------------------

```c
 x    = 0101 1101
 y    = 1010 1001
-----------------
x & y = 0000 1001
```

* & işleminde bitlerden en az biri 0 ise sonu 0'dır. Yani & işleminde 0 yutan elemandır.
* Sonucun 1 olabilmesi için karşılıklı iki bitin 1 olması gerekir. Yani & işleminde 1 etkisiz elemandır.

--------------------------------------------------------------------------------------------------------------------------------------------

```c
 x    = 0101 1101
 y    = 1010 1001
-----------------
x | y = 1111 1101
```

* | işleminde bitlerden en az biri 1 ise sonuç 1'dir.
* Karşılıklı iki bit 0 ise sonuç sıfırdır.

--------------------------------------------------------------------------------------------------------------------------------------------

```c
 x    = 0110 1101
 y    = 1010 1001
-----------------
x ^ y = 1100 0100
```

* ^ (exor) işleminde;
  * Bitler aynı ise sonuç sıfırdır.
  * Bitler farklı ise sonu 1'dir.

--------------------------------------------------------------------------------------------------------------------------------------------

* Bitsel & operatörünün bir yan etkisi yoktur.

```c
bitprint(x);
bitprint(y);
bitprint(x & y);  --> // x ve y'nin değeri değişmez. Yan etkisi yok.
```

--------------------------------------------------------------------------------------------------------------------------------------------

* **x = x & y;** ile **x &= y;** aynı anlamda.
* Bitsel logic operatörlerin kısa devre davranışı yoktur.
* **exp1 && exp2**
  * ilk önce exp1 yapılır. exp1'in yanlış olması durumunda ep2 yapılmaz.
* **exp1 & exp2**
  * Bu işlemde her iki exp içinde işlem kodu üretilme garantisi vardır.

--------------------------------------------------------------------------------------------------------------------------------------------

* Bitsel exor işleminde;
  * 0 etkisiz eleman
  * 1 ise karşısındaki bitin tersini elde eder.
  * Yani 1 biti karşısındaki bitin toggle edilmesini sağlar.

* Bir sayıyı kendisi ile exor'lar isek sıfır sonucunu elde ederiz.

```c
int x = 10;
printf("%d\n", x);   // 10
bitprint(x ^ x);     // 0000 0000 0000 0000 0000 0000 0000 0000
x = x ^ x;
printf("%d\n", x);   // 0 
```

--------------------------------------------------------------------------------------------------------------------------------------------

* Bir dizi olsun bu dizide her sayıdan iki adet var fakat bir sayıdan sadece bir adet olsun. Bu tek olan sayıyı bulan program.

```c
int ar[] = {2, 5, 7, 8, 9, 1, 3, 2, 7, 5, 8, 9, 1};

int main(int argc, char **argv)
{
    int result = 0;
    for (size_t i = 0; i < asize(ar); ++i) {
        result ^= ar[i];
    }
    // Tüm dizi elemanları sırasıyla exor'lanırsa en son cevap tek olan sayıyı verir. çünkü aynı sayılar birbirleriyle exorlanırsa 0 cevabını verir.
    
    printf("Result = %d\n", result);        // Result = 3
   
}
```
* Çünkü ;

```c
int main(int argc, char **argv)
{
    int x = 0;      // olsun

    x ^= 15;

    printf("%d\n", x);      // 15

    x ^= 15;

    printf("%d\n", x);     // 0
   
}
```
* Tüm çift olan sayıların bitleri 0'lanır.
* Tek bulunan sayının bitleri sonucu verir.

--------------------------------------------------------------------------------------------------------------------------------------------

* **int ar[] = {1, 7, 6, 4, 2, 3, 5, 9};** Bu dizideki eksik sayıyı bulunuz. (yani 8 sayısı)
  * Önce ilk elemandan son elemana kadar olması gereken tüm sayıları birbirleriyle exor'larız.
  * Çıkan sonucu dizinin elemanları ile sırasıyla exor'larsak eksik olan elemanı buluruz.

```c
int ar[] = { 1, 7, 6, 4, 2, 3, 5, 9 };

int main(int argc, char **argv)
{
    int result = 0;

    for (int i = 1; i <= 9; ++i) {
        result ^= i;
    }

    for (size_t i = 0; i < asize(ar); ++i) {
        result ^= ar[i];
    }

    printf("Eksik sayi %d\n", result);    // Eksik sayi 8
   
}
```

--------------------------------------------------------------------------------------------------------------------------------------------

* x ve y iki int sayı olsun.
* x ile y'yi exor'larsak ve çıkan sonucu tekrar y ile exor'larsak x'i elde ederiz.
* x = x ^ y;  // x'in yeni değeri
* x = x ^ y;  // x'in ilk değeri

```c
int main(int argc, char **argv)
{
    int x = 565;
    int y = 789;

    printf("x : %d\n", x);  // x : 565   ilk değer

    x ^= y;

    printf("x : %d\n", x);  // x : 288  elde edilen yeni değer

    x ^= y;

    printf("x : %d\n", x);  // x : 565 son hali ilk değer
   
}
```

--------------------------------------------------------------------------------------------------------------------------------------------

* İki değişkeni takas etmek için üçüncü bir değişken kullanmadan, bitsel exor işlemini kullanarak iki değişkeni takas edebiliriz.

```c
int main(int argc, char **argv)
{
    printf("iki adet sayi giriniz : ");
    int x, y;
    scanf("%d%d", &x, &y);
    
    printf("x : %d  y : %d\n", x, y);

    x ^= y;
    y ^= x;
    x ^= y;

    printf("x : %d  y : %d\n", x, y);

/*  Çıktı :

    iki adet sayi giriniz : 15 30
    x : 15  y : 30
    x : 30  y : 15
*/

}
```

* **Kolay bir örnek adım adım :**

```c
x = 4 olsun   y = 5 olsun

x = 0100 ^ 0101 ---> 0001 = 1  (x ^= y)
y = 0101 ^ 0001 ---> 0100 = 4  (y ^= x)
x = 0001 ^ 0100 ---> 0101 = 5  (x ^= y)
```






















































































































  
