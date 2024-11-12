## C Dilinin Nitelikleri

* **imperative :** buyurgan
* **procedural :** prosedürel
* **non-proprietary :** mülkiyeti yok
  *  Komite tarafından yönetiliyor.
* **middle level :** orta seviyeli
* **static typing :** statik tür kavramı
  * Durağan değişmez.
  * Tanımlanan değişkenlerin değerleri değişebilir fakat type'ları değiştirilemez.
* **general-purpose :** genel amaçlı
* **efficient :** verimli
* **artificial :** yapay
* **standard :** standart
* **portable :** taşınabilir
* **expressive :** ifade gücü yüksek

------------------------------------------------------------------------------------------------------------------------------------------------------------

### 1969
* traditional C
* classic C
* C89/90 ilk standart (ANSI/ISO C)

### 1995 
* C99 standartı

### 2011
* C11 standartı

------------------------------------------------------------------------------------------------------------------------------------------------------------

![image](https://github.com/user-attachments/assets/5b63e339-372d-4453-aa74-b7f424ebe1fa)

------------------------------------------------------------------------------------------------------------------------------------------------------------

### Compiler

* Daha yüksek seviyeli bir dilden daha düşük seviyeli bir dile çeviri yapan programlara **"compiler"** denir.

![image](https://github.com/user-attachments/assets/ac32a295-90a4-49a3-ab47-d28d379589e9)

------------------------------------------------------------------------------------------------------------------------------------------------------------

![image](https://github.com/user-attachments/assets/9b737ad9-dac7-4170-bfef-46ca23c931ef)

* **Lexical Analysis :** Kaynak kodu en küçük birimlerine ayırır.
* **Syntax Analysis :** Dilin kurallarına uygunluğun kontrol edildiği süreç.

------------------------------------------------------------------------------------------------------------------------------------------------------------

![image](https://github.com/user-attachments/assets/7e1ede93-28f2-4206-8a29-dd65f5440d7a)

### Link/Linker

* Object kodun çalıştırılabilir bir kod haline getirilmesi için bir süreç daha gerçekleştirilmeli. Bu sürece **Linking** (Bağlama) denir.
* Link   (Bağlama)
* Linker (Bağlayıcı)

* **Compile time :** Derleme zamanı.
* **Link time :** Object code'ların exe koda dönüştürüldüğü süreç.
* **Run time :** Executable kodu işlemcinin fiilen çalıştırdığı süreç.

------------------------------------------------------------------------------------------------------------------------------------------------------------

### IDE (Integrated Development Environment)

* Tümleşik Geliştirme Ortamı

### ill formed

* Dilin kurallarını çiğneyen bir durumu bildirir. Geçerli olmayan bir program.
* Zıttı : well formed

### Syntax Error

* Sentaks / Sözdizim hatası

### Invalid Code

* Geçersiz kod. Kodun dilin kurallarını çiğnemesi demek.

### illegal Code

* Kod'un dilin kurallarına aykırı olduğu anlatılır.
* Zıttı : legal code

### Observable Behavior

* Gözlenebilir davranış.
* Optimizer modül.

------------------------------------------------------------------------------------------------------------------------------------------------------------

* Derleyici, programın gözlemlenebilir davranışı değişmediği sürece kodu bizim yazdığımızdan farklı şekilde düzenleyebilir.

* Derleyicinin en önemli modülü, kodun etkin bir şekilde makine kodlarına dönüştürülmesini sağlayan modül olan optimizer modülüdür.

![image](https://github.com/user-attachments/assets/c355d1cb-bffe-456c-bfae-2291806fdcc6)

* Yazdığımız kod farklı derleyicilerle derlendiğinde derleyicilerin ürettikleri "machine code" farklı hızlarda çalışabilir.
* Derleyici işlemci mimarisini göz önünde bulundurarak optimizasyon yapar.  

### simd 

* İşlemcinin 1 cycle'ında birden fazla işlemin yapılması.

* Derleyiciyi derleyici yapan optimizer modülüdür.
* Derleyici kodumuzu bizim yazdığımız biçimde derlerse kodumuz yavaş çalışır.

### debugger

* Sağladığı birtakım olanaklarla, kontrollü bir ortamda programı çalıştırarak koddaki hataları bulmamıza yardımcı olur.
   
------------------------------------------------------------------------------------------------------------------------------------------------------------

### Undefined Behavior (Tanımsız Davranış)

```c
a = b / c;
if (c == 0)
{
   //code
}
```
* c = 0 olamayacağı için compiler burayı görmezden gelebilir. Çünkü tamsayı 0'a bölünemez.
* Bu yüzden undefined behavior durumlarında runtime'da her zaman sağlıklı çalışma işlemi gerçekleşmeyebilir. Bu yüzden bu durumlardan kaçınmalıyız.

------------------------------------------------------------------------------------------------------------------------------------------------------------

### Preprocessor (Ön işlemci)  / Preprocessor Directive (Ön işlemci talimatı)

```c
#include <string.h>

#define SIZE 100
```
* Yukarıdaki preprocessor directive örnekleri verilmiştir.

------------------------------------------------------------------------------------------------------------------------------------------------------------

### token (atom)   /   tokenizing (atomlarına ayırma)

* Bir C derleyicisi Lexical Analysis sürecinde önce tokenizing yapar. Kaynak kodu kendisi için anlamlı en küçük birimlerine ayırır.
* **Token :** Kaynak kodun derleyici tarafından anlam taşıyan en küçük birimine denir.

![image](https://github.com/user-attachments/assets/2d0d75b9-222a-4984-96d8-084be6db2c95)

------------------------------------------------------------------------------------------------------------------------------------------------------------

* **latin-roman karakter seti : A....Z, a.....z**
* **0 - 9 : Arabic Numerals**
* **_ underscore**
* **İsimler rakam karakteri ile başlamaz.**
* **Anahtar sözcükler isim olarak seçilmez.**

| CASE-SENSITIVE | CASE-INSENSITIVE |
|--|--|
| Büyük/küçük harfe duyarlı. | Büyük/küçük harfe duyarlı değil. |

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

```c
x = 345;

// x = identifier
// 345 = constant
```
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

| Decimal System | Octal System | Hexadecimal System |
|--|--|--|
| 561 | 0561 (Başa 0 ön eki gelir.) | 0x561 (Başa 0x ön eki gelir.) |

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## OPERATORS

| Logical AND | Logical OR | Logical NOT | increment (plus plus) | decrement (minus minus) | String Literal |
|--|--|--|--|--|--|
| && | \|\| | ! | ++ | -- | "MUSTAFA" |

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* **GLOBAL NAMESPACE :** Herşeyi içine alan, bütün kodların, fonksiyonların bulunduğu yer.
* **LOCAL NAMESPACE  :** Fonksiyonların içi.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* **Statement :** Belirli bir işi gerçekleştirmek için yazdığımız c cümlelerine "statement" denir.
*  **: -> colon**
*  **; -> semi-colon, terminator**
* **declaration (Bildirim):** Bir ismin hangi anlama geldiğini, ne olduğunu anlatan cümleler.
* **name lookup (isim arama):** Kod içinde kullanılan bir ismin hangi varlığa ilişkin olduğunun derleyici anlaşılması süreci.

```c
int main(void)
{
  int x;   // declaration statement : x'in ne olduğunu bildiren satır.
  x = 5;   // Name lookup : Derleyici x'in ne olduğunu öğrenmek için onu bildiren satırı arar.
}
```

* **name lookup hatası :**
  * Önce isim aranacak
  * Aranan isim bulunamaz ise sentaks hatası

* **context control hatası :**
  * Aranan isim bulunursa
  * Bulunan ismin kullanım şekli hatalı ise

* **Global namespace'de sadece declaration statement olur. Executable statement yer almaz.

* **expression (ifade) :** Değişkenlerin, sabitlerin, operatörlerin bir arada bulundukları yapıya expression denir.
  * x\*x + y\*y > 10
  * x
  * 10
  * x + 10
  * Yukarıdakilerin hepsi **expression**'dur.

* **expression'ların data type, value, value category gibi özellikleri vardır.**

* **L value expression :** Bazı ifadeler bir nesneye karşılık geliyor, bir değişkene karşılık geliyor, erişebileceğimiz bellekte yeri ayrılmış bir varlığa karşılık geliyorsa buna **L value expression** denir.

* **R value expression :** Bazı ifadeler bellekte doğrudan erişebileceğimiz bellek alanına, değişkene karşılık gelmiyor bir hesaplamayı ifade ediyor ise **R value expression** denir.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### Statement Niteleyicileri;
* **expression statement (ifade deyimi)**
  * Eğer ifade (expression) geçerli ise sonuna ; koyarak geçerli bir deyim elde ederiz. Bu şekilde oluşturulan deyimlere ifade deyimi (expression statement) denir.

* **null statement**
  * Tek başına noktali virgül'ün (;) oluşturduğu statement'a null statement denir.

* **compound statement**
  * ```c
    {
       x++;
       --y;
       a = x + y;
    ```
  * Yukarıdaki örnek compound statement'a örnektir. 

* **control statement**
  * Önceden belirlenmiş bir sentaksı var.
  * En az bir anahtar sözcük var.
  * ```c
    if statement
    while statement
    do while statement
    for statement
    switch statement
    goto statement
    return statement
    break statement
    continue statement
    ```

* **block**
  * { } ikisinin oluşturduğu birime block denir.

* curly brace
  * { left brace (opening)
  * } right brace (closing)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* **object-nesne :** Değişken anlamını taşır.

* **Data Type :**
  1. Değişkenleri niteleyen terim
  2. Sabitleri niteleyen terim
  3. İfadeleri niteleyen terim
 
* **Programın çalışma zamanında o değişken (o nesne) bellekte kaç byte yer kaplayacak bunu belirleyen o değişkenin türüdür.**
* **storage :** Bir nesnenin bellekte yerinden bahsederken, o nesneye ait bellek bloğundan bahsederken kullandığımız terim **storage** terimidir.
 
* object/variable
* data type
* value
* storage (nesnenin bellekteki yeri)
* address

| DATA | TYPE |
|--|--|
| Basic Types | User-Defined Types |
| * Fundemental types | * Structures |
| * Built-in types | * unions |
| * Default types | * enumerations |

* **Basic Types :** Öyle türler ki bu türlerden değişkenlerin değerleri tam sayı ve gerçek sayı değerleri hazır olarak bulunur.
  * float, int, double vs.

* **constant expression (sabit ifadesi)**
```c
int main (void)
{
  int arr[10 + 20];       
}
```
* Yukarıdaki kod hata vermez.

```c
int main (void)
{
  int x = 10;
  int y = 20;
  int arr[x + y];
}
```
* Yukarıdaki kod hata verir. **Expected constant expression.**






































