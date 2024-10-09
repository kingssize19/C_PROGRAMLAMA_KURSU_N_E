## C PROGRAMLAMA KURSU

### C DİLİNİN NİTELİKLERİ

* **imperative :** Buyurgan
* **procedural :** Prosedürel
* **non-proprietary :** Mülkiyeti yok (Komite tarafından)
* **middle level :** Orta seviyeli
* **static typing :** Statik tür kavramı (Durağan değişmez.) (Tanımlanan değişkenlerin değerleri değişebilir fakat typeları değiştirilemez.)
* **general-purpose :** Genel amaçlı
* **efficient :** Verimli
* **artificial :** Yapay
* **standart :** Standart
* **portable :** Taşınabilir
* **expressive :** İfade gücü yüksek
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
### 1969
* traditional C
* classic C
* C89/90 ilk standart [ANSI/ISO C]

### 1995 
* C99 standartı

### 2011
* C11 standartı 

ALGOL -> CPL -> BCPL -> B -> C    [Typeless]

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### Daha yüksek seviyeli bir dilden daha düşük seviyeli bir dile çeviri yapan programlara "compiler" denir.


| Source Code | -> Compiler -> | Object Code |
|--|--|--|
| Human Readable Program | Compile |Executable Machine Code |

| Front End | Back End |
|--|--|
| Lexical Analysis -> Syntax Analysis | Code Generation and Optimisation |

* **Lexical Analysis :** Kaynak kodu en küçük birimlerine ayırır.
* **Syntax Analysis :** Dilin kurallarına uygunluğun kontrol edildiği süreç.

| Source File | -> Compiler -> | Object Code/Object File |
|--|--|--|


### Object kodun çalıştırılabilir bir kod haline getirilmesi için bir süreç daha gerçekleştirilmeli. Bu sürece Linking (Bağlama) denir.

* Link (Bağlama)
* Linker (Bağlayıcı)

* deneme2.c --> Compiler --> deneme2.obj }
*                                            } ----> Linker ----> .exe file 
* deneme.c  --> Compiler --> deneme.obj  }  


| Source File -> | Compiler -> | Object Code -> | Linker -> | Executable |
|--|--|--|--|--|

* compile time (Derleme Zamanı)
* link time (Object codeların exe koda dönüştürüldüğü süreç)
* run time (Executable kodu işlemcinin fiilen çalıştırdığı süreç)

**Source File** --> **Preprocessor** --> **Translation Unit** --> **Compiler** --> **Object Code** --> **Linker** --> **executable code**

**Preprocessing time**
* Bu aşama, kaynak dosyadaki #include, #define, #ifdef gibi önişlemci komutlarının işlendiği aşamadır.
  * Dosyadaki makrolar (#define) genişletilir.
  * Diğer dosyalar (#include) eklenir.
  * Koşullu derlemeler (#ifdef, #ifndef) değerlendirilir.
  * Sonuç olarak, derleyiciye iletilmeden önce tüm kod işlenmiş bir dosya oluşturulur.
* Bu aşama tamamlandığında, dosya "preprocessed source code" haline gelir.

**Compile time**
* Ön işleme aşamasından çıkan kaynak kod, makine diline çevrilir veya assembly diline dönüştürülür.
  * C kaynak kodu sentezlenir, yani yazılan C kodunun sözdizimi ve dil kuralları doğrulanır.
  * Hatalar ve uyarılar bu aşamada tespit edilir.
  * Derleyici, C kodunu nesne koduna (object file) veya assembly koduna çevirir.
  * Bu aşamanın sonunda her C dosyası için birer nesne dosyası (.o ya da .obj) üretilir.
  
**Link time**
* Derleme aşamasından çıkan nesne dosyaları, programın çalışabilmesi için gerekli kütüphaneler ve diğer modüllerle birleştirilir.
  * Tüm nesne dosyaları bir araya getirilir.
  * Harici kütüphanelerle ve sistem işlevleriyle bağlantılar yapılır (örn. printf, malloc gibi işlevlerin adreslerinin bulunup bağlanması).
  * Bu aşamanın sonunda çalıştırılabilir dosya (örneğin, .exe ya da .out) oluşturulur.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#### IDE (Integrated Development Environment)
* Geliştirme Platformları (Tümleşik Geliştirme Ortamı)

* **ill formed   :** Dilin kurallarını çiğneyen bir durumu bildirir. Geçerli olmayan bir program. zıttı -> well formed
* **syntax error :** sentaks/söz dizimi hatası
* **invalid code :** Geçersiz kod. Kodun dilin kurallarını çiğnemesi demek. zıttı -> valid code
* **illegal code :** Kodun dilin kurallarına aykırı olduğunu anlatır. zıttı -> legal code

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* **observable behavior : Gözlenebilir davranış. (optimizer modüle)**

* **Derleyici, programın gözlemlenebilir davranışı değişmediği sürece kodu bizim yazdığımızdan farklı şekilde düzenleyebilir.**

* **Derleyicinin en önemli modülü, kodun etkin bir şekilde makine kodlarına dönüştürülmesini sağlayan modül olan optimizer modülüdür.**

* **Derleyicinin daha etkin makine kodu üretmek için yaptığı düzenlemelere "compiler optimization" denir.**

* **Yazdığımız kod farklı derleyicilerle derlendiğinde derleyicilerin ürettikleri makine kodu farklı hızlarda çalışabilir.**

* **Derleyici işlemci mimarisini göz önünde bulundurarak optimizasyon yapar.**

* **simd : İşlemcinin 1 cycle'ında birden fazla işlemin yapılması.**

* **Derleyiciyi derleyici yapan optimizer modülüdür.**

* **Derleyici kodumuzu bizim yazdığımız biçimde derlerse kodumuz yavaş çalışır.**

* **Debugger : Sağladığı birtakım olanaklarla, kontrollü bir ortamda programı çalıştırarak koddaki hataları bulmamıza yardımcı olur.**

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Undefined Behavior (Tanımsız Davranış)

**Örnek :**
```c
a = b / c;
if (c == 0) {
//code
}
```
* c = 0 olamayacağı için compiler burayı görmezden gelebilir. Çünkü tamsayı 0'a bölünemez.
* Bu yüzden **undefined behavior** durumlarında runtime'da her zaman sağlıklı çalışma işlemi gerçekleşmeyebilir. Bu yüzden bu durumlardan kaçınmalıyız.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* **Preprocessor (Önişlemci)**
* **Preprocessor Directive (Önişlemci Talimatı)**
  * **#include <string.h>**
  * **#define SIZE 100**
 
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* **token (atom)**
* **tokenizing (atomlarına ayırma)**

* **Bir C derleyicisi Lexical Analysis sürecinde önce tokenizing yapar. Kaynak kodu kendisi için anlamlı en küçük birimlerine ayırır.**
* **token :** Kaynak kodun derleyici tarafından anlam taşıyan en küçük birimi.

| TOKEN |
|--|
  * Keyword (Anahtar sözcük)
  * Identifier (İsim)
  * Constant (Sabit)
  * Operator (İşleç)
  * String Literal (Yazı sabiti)
  * Delimiter (Ayıraç)  olabilir.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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



















