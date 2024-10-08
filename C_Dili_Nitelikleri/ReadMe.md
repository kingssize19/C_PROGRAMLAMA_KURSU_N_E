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

* deneme2.c --> Compiler --> deneme2.obj -----|
                                              |----> Linker ----> .exe file 
* deneme.c  --> Compiler --> deneme.obj ------| 


| Source File -> | Compiler -> | Object Code -> | Linker -> | Executable |
|--|--|--|--|--|

* compile time (Derleme Zamanı)
* link time (Object codeların exe koda dönüştürüldüğü süreç)
* run time (Executable kodu işlemcinin fiilen çalıştırdığı süreç)

**Source File (Kaynak Dosya)**
            ]
 **Preprocessor (Önişlemci)**                                                      **(Preprocessing time)** 
            ]
**Translation Unit (Çeviri Birimi)**
            ]
  **Compiler (Derleyici)**  ----> **Assembly Code** ----> **Assembler** ]               **(Compile time)**
            ]                                                           ]
     **Object Code**    <---------------------------------------------- ]
            ]
   **Linker (Bağlayıcı)**                                                               **Linker time**
            ]
    **executable code**











