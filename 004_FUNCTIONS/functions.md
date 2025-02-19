# Functions (Fonksiyonlar)

### C dilinde fonksiyonlar hesapladıkları değer yada değerleri hangi yollarla kendilerini çağıran kodlara iletebilirler ?

**1. Geri Dönüş Değeri Mekanizması (return value)**
**2. Pointer Mantığı/Yöntemi (adres)**
**3. Global Değişkenleri Kullanan Yöntem**

---------------------------------------------------------------------------------------------------------------------------

```c
// int  -> Fonksiyonun geri dönüş değeri
// func -> Fonksiyonun ismi
// int x, double y -> Fonksiyon parametre değişkenleri

int func(int x, double y)
{
    //function code
}
```

* **implicit int kuralı** Günümüzde bu kural kullanılmıyor. Eğer fonksiyonun geri dönüş değeri türünü belirtmezsek int olarak kabul edilir (implicit int).

```c
func(int x, double y)    // implicit int
{
    //...
}
```

---------------------------------------------------------------------------------------------------------------------------

* Bir fonksiyonun geri dönüş değeri yoksa **"void"** ile ifade edilir. Bunlara void function denir.

```c
void func();
```

* Fonksiyon parametre değişken değeri almıyorsa void yazılır.

```c
void func(void);
```

* C ve C++ dilinde bir fonksiyon içinde bir fonksiyon tanımlanamaz. Yani iç içe fonksiyon olmaz.

---------------------------------------------------------------------------------------------------------------------------

## return statement;

* **return;  :** İfadesiz return deyimi. Fonksiyonu sonlandırıyor fakat çağıran koda bir değer iletmiyor.
* **return exp;  :** İfadeli return deyimi. Fonksiyonu sonlandırıyor ve çağıran koda bir değer iletiyor.

* Bir fonksiyonda if deyimi olsun bu koşul sağlandığında if()'ten sonraki statement'lar çalışmasın istiyorsak **return;** deyimini kullanırız.

```c
void foo(int x)
{
    printf("1\n");
    x++;
    printf("2\n");
    x++;
    printf("3\n");
    x++;
    if (x == 3)
        return;
    printf("4\n");
    printf("5\n");
}

int main() {
    foo(0);
    // Çıktı : 
    // 1
    // 2
    // 3
    
}
```

---------------------------------------------------------------------------------------------------------------------------

#### unreachable code (ulaşılamaz kod)

```c
void foo(int x)
{
    // Statement 1
    // Statement 2
    // Statement 3
    return;
    // Statement 4
    // Statement 5
}
```
* Statement 4 ve Statement 5 zaten yürütülmez. Bunlara **unreachable code** denir.

#### redundant code (gereksiz kod)

```c
void foo(int x)
{
    // Statement 1
    // Statement 2
    // Statement 3
    return;
}
```
* Bu kodda yer alan return gereksiz. Kod içerisinde olmasa da olur.

---------------------------------------------------------------------------------------------------------------------------

#### Not :
* Derleyici optimizasyonu çok iyi seviyede olduğu için aşağıdaki iki kod arasında çalışma hızı bakımından fark olmaz. Yani sum1 ile sum2 fonksiyonu arasında çalışma hızı bakımından bir fark yoktur.

```c
int sum1(int x, int y)
{
    int result;
    result = x + y;
    return result;
}

int sum2(int x, int y)
{
    return x + y;
}
```

---------------------------------------------------------------------------------------------------------------------------

### variadic Function

```c
int foo(int x, ...);
```
* ... argümanı ile biten fonksiyonlara variadic function denir.
* foo fonksiyonunun parametre değişkenleri şunu kastediyor. En az 1 argüman yollanmalı 2, 3, 4... daha fazla argüman yollayabiliriz.

```c
int func(int, int, ...);
```
* ... atomuna elipsis token'ı denir.
* func fonksiyonu en az 2 argüman bekliyor. 2'den fazla argüman yollayabiliriz.

---------------------------------------------------------------------------------------------------------------------------

* Bir fonksiyon çağrısı C ve C++ dillerinde bir ifade oluşturur.
* Fonksiyon çağrısı operatör seviyesinde bir işlemdir.
* Fonksiyon çağrı operatörü : ()

#### foo(a, b) olsun :

* Önce argüman olan ifadelerin (a ve b) değerleri hesaplanır. Ondan sonra hesaplanmış değerler fonksiyonun parametre değişkenlerine kopyalanır.
* Eğer çağrılan fonksiyonun bir geri dönüş değeri var ise fonksiyon çağrı ifadesinin değeri fonksiyonun geri dönüş değeridir.

```c
#include <stdio.h>

int foo(int x, int y) {
    return x + y;
}

int main() {
    int a = 5, b = 3;
    int result = foo(a, b); // Önce a ve b hesaplanır, sonra foo çağrılır
    printf("Sonuç: %d\n", result); // Fonksiyonun geri dönüş değeri kullanılır
    return 0;
}
```

---------------------------------------------------------------------------------------------------------------------------

* void bir fonksiyona yapılan çağrı ifadesi void türdendir. Ve C dilinde void türden ifadelerin bir değeri yoktur.

```c
#include <stdio.h>

void printMessage() {
    printf("Merhaba, Dünya!\n");
}

int main() {
    printMessage(); // void fonksiyon çağrısı, bir değer döndürmez
    return 0;
}
```

* Aşağıdaki kod parçası hata verir.

```c
int x = printMessage(); // Hata! Void fonksiyonun bir değeri yoktur.
```

---------------------------------------------------------------------------------------------------------------------------
















