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

* deneme2.c --> Compiler --> deneme2.obj
                                          * ----> Linker ----> .exe file 
* deneme.c  --> Compiler --> deneme.obj


| Source File -> | Compiler -> | Object Code -> | Linker -> | Executable |
|--|--|--|--|--|

* compile time (Derleme Zamanı)
* link time (Object codeların exe koda dönüştürüldüğü süreç)
* run time (Executable kodu işlemcinin fiilen çalıştırdığı süreç)

**Source File** --> **Preprocessor** --> **Translation Unit** --> **Compiler** --> **Object Code** --> **Linker** --> **executable code**

**(Preprocessing time)**
**(Compile time)**
**Link time**

#### IDE (Integrated Development Environment)
* Geliştirme Platformları (Tümleşik Geliştirme Ortamı)

#### ill formed   : Dilin kurallarını çiğneyen bir durumu bildirir. Geçerli olmayan bir program. zıttı -> well formed
#### syntax error : sentaks/söz dizimi hatası
#### invalid code : Geçersiz kod. Kodun dilin kurallarını çiğnemesi demek. zıttı -> valid code
#### illegal code : Kodun dilin kurallarına aykırı olduğunu anlatır. zıttı -> legal code

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#### observable behavior : Gözlenebilir davranış. (optimizer modüle)

#### Derleyici, programın gözlemlenebilir davranışı değişmediği sürece kodu bizim yazdığımızdan farklı şekilde düzenleyebilir.

#### Derleyicinin en önemli modülü, kodun etkin bir şekilde makine kodlarına dönüştürülmesini sağlayan modül olan optimizer modülüdür.

x = 5;                                                                         a = b;
y = 3;        -------------------> Compiler Optimization ------------------->  y = 3;
a = b;                                                                         x = 5;






