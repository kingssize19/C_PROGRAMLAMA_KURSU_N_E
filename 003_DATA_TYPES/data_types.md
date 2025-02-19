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

-----------------------------------------------------------------------------------------------------------------

### Hatırlatma

* **Undefined Behavior :** Kod derlendiğinde runtime'da herşey olabilir. Kodumuzda asla olmaması gereken bir durum.
* **Unspecified Behavior :** Kodda bir problem yok ama derleyici farklı şekilde kod üretme şansına sahip.
* **Implementation Behavior :** Unspecified Behavior'a benzer. Derleyicinin nasıl kod üreteceğini belgeleme zorunluluğu vardır.

-----------------------------------------------------------------------------------------------------------------

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
























