# Data Types

#### Basic Types : 
* default
*  built-in
* fundemental
* primitive

#### User - Defined Types : 
* structures
* unions
* enumaration

# Basic Types

* Integer Types (Tam Sayı Türleri)
* Floating Types (Gerçek Sayı Türleri)

----------------------------------------------------------------------------------------------------------------------

### Hatırlatma

* **Undefined Behavior :** Kod derlendiğinde runtime'da herşey olabilir. Kodumuzda asla olmaması gereken bir durum.
* **Unspecified Behavior :** Kodda bir problem yok ama derleyici farklı şekilde kod üretme şansına sahip.
* **Implementation Behavior :** Unspecified Behavior'a benzer. Derleyicinin nasıl kod üreteceğini belgeleme zorunluluğu vardır.

----------------------------------------------------------------------------------------------------------------------

## Integer Types

* Karakter Türleri + Tam Sayı Türleri ---> Tamsayı Türleri

### Karakter Türleri

| Tür | sizeof | Değer Aralığı |
|--|--|--|
| char | 1 byte | |
| unsigned char | 1 byte | 0 - 255 |
| signed char | 1 byte | -128 - 127 |

* char türünün işaretli veya işaretsiz olduğu derleyiciye bağlıdır.

----------------------------------------------------------------------------------------------------------------------

### Tamsayı Türleri

| Tür | sizeof |
|--|--|
| signed short | 2 byte |
| unsigned short | 2 byte |
| signed int | 2 / 4 byte |
| unsigned int | 2 / 4 byte |
| signed long | 4 / 8 byte |
| unsigned long | 4 / 8 byte |
| signed long long (C99) | 8 byte |
| unsigned long long (C99) | 8 byte |
| _Bool (C99) | 1 byte |


* Değişkenlerin sizeof değerleri derleyiciye göre değişiklik gösterse bile aşağıdaki kurala uymalıdır.
  * short <= int <= long <= long long

* **Compiler Extension (Derleyici Eklentisi) :** Derleyicimizin bize kullandırdığı onun yapacağı çeviride anlamlı olan araçlardır. Ama bu araçlar C'de standart değildir.

----------------------------------------------------------------------------------------------------------------------

## Floating Types 

| Tür | sizeof |
|--|--|
| float | 4 byte |
| double | 8 byte |
| long double | 8/10/12/16 byte |

* double türü gerçek sayı türleri içerisinde en çok kullanılan türdür.

----------------------------------------------------------------------------------------------------------------------

* **to define a function :** Bir fonksiyonu tanımlamak.
* **function definition :** Fonksiyon tanımı.
* **to call a function :** Bir fonksiyonu çağırmak.
* **function call :** Fonksiyon çağrısı.
* **to declare a function :** Bir fonksiyonu bildirmek.
* **function declaration :** Fonksiyon bildirimi.

----------------------------------------------------------------------------------------------------------------------

# Değişkenleri Bildirimi / Tanımı

* **Definition :** Tanım
* **Declaration (Bildirim) :** Bir ismin ne olduğunu, ne anlama geldiğini anlatan cümleler.
* **Eğer bir bildirim derleyicinin bildirilen varlık için bir yer (storage) edinmesini sağlıyorsa böyle bildirimlere aynı zamanda definition denir.**


#### Değişken Tanımlama

```c
double dval1;

double dval2 = 3.4;  // initialize : ilk değer verme
```

----------------------------------------------------------------------------------------------------------------------

* Tamsayı türlerinde sadece değişken türünü yazarsak default olarak signed kabul edilir.

```c

signed short x;    // işaretli short
unsigned short y;  // işaretsiz short
short z;           // (default) işaretli short
```

* **Not :** Sadece **signed** kullanmak int kullanıldığı anlamını taşır.

```c
int main() {
    
    signed x;
    x = 10;
    printf("x = %d", x);  // x = 10   
}
```

----------------------------------------------------------------------------------------------------------------------

* float
* double
* long double
* Bu türler signed veya unsigned ile kullanılmaz. (Syntax Error!)

----------------------------------------------------------------------------------------------------------------------

# Life Span

## Storage Class

* **automatic storage :** Örneğin yerel değişkenler, fonksiyonlar vs. Bunlar hayata gelirler işleri bittiğinde hayattan giderler.
* **static storage :** Global değişkenler veya statik anahtar sözcüğü ile tanımlanan yerel değişkenler. Bellekte bunlara ayrılan yeri programın sonuna kadar korurlar.
* **dynamic storage**
* **thread - local storage**


* Global değişkenler default olarak statik ömürlüdür. Bellekteki yerlerini program sonuna kadar korurlar, program bitene kadar o yerler bu değişkenlerin olur.
* Global değişkenlerin yani statik ömürlü değişkenlerin ilk değerleri belirlenmediği zaman default değerleri 0 olarak hayata başlarlar.


**Dikkat :** C dilinde statik ömürlü değişkenlere ilk değer veren ifadeler "sabit ifadesi" olmak zorundadır.

```c
#include <stdio.h>

int gx = 7;      // constant expression
int gy = gx;     // syntax error (initializer is not a constant)
```

----------------------------------------------------------------------------------------------------------------------

* Fonksiyonların ana bloklarının içinde tanımlanan değişkenler "local variable" 'dır. (Yerel değişkenlerdir.)
* Yerel Değişkenler :
  * Otomatik veya static ömürlü olabilir.
  * Yerel değişkenler default olarak otomatik ömürlüdür.
  * Yerel değişkenleri static ömürlü yapmak için static keyword'ü ile tanımlamalıyız.
  * Otomatik ömürlü yerel değişkenlere ilk değer atanmaz ise çöp değer ile hayata gelirler bu çöp değeri kullanmak tanımsız davranıştır.

```c
int main() {
    
    int x;        // Garbage value. Otomatik ömürlü yerel değişken.
    static int y; // Static ömürlü yerel değişken. 0 değeri ile hayat gelir.
        
}
```

```c
int main()
{
    int x;       // Çöp değer kullanıyor. Fakat tanımsız davranış yok. Çünkü bu çöp değeri kullanmıyoruz.

    int y = x;   // Fakat bu aşamada x'in çöp değerini kullandığımız için tanımsız davranış var.
}
```

* Aşağıdaki kullanım biçiminde tanımsız davranış yok.

```c
int x;
x = 4;
```

* Aşağıdaki kullanım biçiminde tanımsız davranış var.

```c
int x;
x = x + 5;
```

#### Dikkat

* Statik ömürlü değişkenlere ilk değer veren ifadelerin constant expression olma zorunluluğu varken.
* Otomatik ömürlü değişkenlere ilk değer veren ifadelerin constant expression olma zorunluluğu yoktur

```c
int main()
{
    int x = 5;
    int y = x + 6;      // İçinde değişken ismi olduğu için constant expression değil. Fakat syntax hatası yok. Otomatik ömürlü değişken.

}
```

----------------------------------------------------------------------------------------------------------------------

# Scope

## Name Lookup (İsim Arama)

* C dilinde, kodda bildirilen bütün isimlerin bir **scope**'u (kapsamı) vardır.
* Bir ismin **scope**'u demek o ismin kullanılabileceği kod alanı demektir.
* **name lookup :** Kodda kullanılan isimlerin hangi varlıklara ilişkin olduğunun anlaşılması / belirlenmesi süreci.
  * İsim arama bir sıra dahilinde yapılır :
    * Yani önce şuraya bak.
      * Orada bulamazsan buraya bak.
* İsim arama süreci aranan isim bulunduğunda sona erer. Bir daha başlamaz.


#### Scoping Rules

* File Scope
* Block Scope
* Function Prototype Scope
* Function Scope

**1. File Scope (Dosya Kapsamı) :**
* İsmin tüm dosya içinde kullanılabilir olması demektir.
* Bir ismi global isim alanında bildirdiysek o isim file scope'tadır.
* Yani tanımlandığı noktadan dosya sonuna kadar her yerde kullanılabilir.





































