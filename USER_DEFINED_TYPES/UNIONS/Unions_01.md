# UNIONS (Birlikler)

```c
union Data {
  double dval;
  int a, b, c;
};

int main(void)
{
    union Data mydata;
    union Data* dataptr = &mydata;

}
```

* **Türün ismi :** union Data
* **union tag  :** Data

---------------------------------------------------------------------------------------------------------------------------

* Bir yapı nesnesinin sizeof'u elemanlarının sizeoflarının toplamıdır. (+ varsa padding byte)
* union türünün sizeof'u, union'un sizeof'ça en büyük elemanının sizeof'udur.

```c
struct SData {
    double dval;
    int a, b, c;
};

union UData {
  double dval;
  int a, b, c;
};

int main(void)
{
    struct SData sdata;
    union UData udata;
    
    printf("sizeof(sdata) : %zu\n", sizeof(sdata));    // sizeof(sdata) : 24  --> sizeof(double) + 3 x sizeof(int) + padding byte = 24
    printf("sizeof(udata) : %zu\n", sizeof(udata));    // sizeof(udata) : 8   --> 8 (double'ın sizeof'u)

}
```

```c
typedef struct{
    int x, y, z;
}SData;

typedef union {
  int x, y, z;
  double d1, d2;
  char str[12];
}UData;

int main(void)
{
    SData sdata;
    UData udata;
    
    printf("sizeof(sdata) : %zu\n", sizeof(sdata));        // sizeof(sdata) : 12   --> 3 x sizeof(int)
    printf("sizeof(udata) : %zu\n", sizeof(udata));        // sizeof(udata) : 16   --> sizeof(str)'den 12 byte + padding byte

}
```

* Bu durumun sebebi ; Birliklerin elemanlarının adreslerinin aynı olmasıdır.

```c
typedef union {
  int x, y, z;
  double d1, d2;
  char str[12];
}UData;

int main(void)
{
    UData mydata;
    
    printf("%p\n", &mydata);        // 0x7ffc14d2dcc0
    printf("%p\n", &mydata.x);      // 0x7ffc14d2dcc0
    printf("%p\n", &mydata.y);      // 0x7ffc14d2dcc0
    printf("%p\n", &mydata.z);      // 0x7ffc14d2dcc0
    printf("%p\n", &mydata.d1);     // 0x7ffc14d2dcc0
    printf("%p\n", &mydata.d2);     // 0x7ffc14d2dcc0
    printf("%p\n", &mydata.str);    // 0x7ffc14d2dcc0
    

}
```

* Aynı bellek alanını paylaştıkları için birinin değeri değiştiğinde diğerlerinin değerleride değişir.

---------------------------------------------------------------------------------------------------------------------------

* Birliklerde sadece tek bir elemana ilk değer verilebilir.

```c
typedef union {
  int x, y, z;
  double d1, d2;
  char str[12];
}UData;

int main(void)
{
    UData mydata = {12};
    
    printf("mydata.x : %d\n", mydata.x);  // mydata.x : 12
    printf("mydata.y : %d\n", mydata.y);  // mydata.y : 12
    printf("mydata.z : %d\n", mydata.z);  // mydata.z : 12
    
}
```

* İlk elemana verilmiş ilk değer.
* mydata'nın x'i 12 oldu.
* y ve z'de aynı bellek alanını paylaştığı için mydata'nın y'si ve z'si de 12 değerinde olacak.

---------------------------------------------------------------------------------------------------------------------------

## Birliklerin En Çok Kullanıldığı Tema

* Bir verinin farklı biçimlerde temsil edilmesi.

```c
union Pack{
  
    uint32_t uval;
    uint8_t ar[4];
    
};

/*
---------------------------------
|            uval               |
---------------------------------
| ar[0] | ar[1] | ar[2] | ar[3] |
---------------------------------
*/

int main(void)
{
    union Pack x = { .uval = 7623435u };   // Bunu 4 byte'lık tamsayı olarak kullanabiliriz.
                                          // x.arr[0] -> istersekte ar isimli dizi elemanıyla 1. 2. 3. 4. byte'larını ayrı ayrı nesneler olarak kullanabiliriz
    
}

```

* **sizeof(union pack) :** 4 

---------------------------------------------------------------------------------------------------------------------------

#### Çok sık kullanılan teknik :

```c
typedef struct {
    int type;
    union {
        unsigned char Byte;
        unsigned int Uval;
        double dval;
        char str[16];
    };
}Json;
```

* Yapı içerisinde bu şekilde bulunan union yapısına **Anonymous union** denir.

* Öyle bir veri türü olsunki o veri türünden bir değişken
  * char türden bir karakter tutabilsin,
  * int türden tamsayı değeri tutabilsin,
  * gerçek sayı değeri tutabilsin,
  * tarih bilgisi tutabilsin.

```c
#define CHAR    0
#define INT     1
#define DOUBLE  2
#define DATE    3

typedef struct {
    int type;
    union {
        char c;
        int i;
        double d;
        Date dt;
    };
}Data;


int main(void)
{
    Data mydata;
    
    mydata.type = CHAR;
    mydata.c = 'F';
    
    mydata.type = DOUBLE;
    mydata.d = 4.596;
    
}
```

---------------------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdint.h>

typedef union {
    
    uint32_t uval;
    
    struct {
        uint16_t low_bytes;
        uint16_t high_bytes;
    };
    
    struct {
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
        uint8_t byte4;
    };
    
}Data;


int main(void)
{
    printf("sizeof(Data) : %zu\n", sizeof(Data)); // sizeof(Data) : 4
    
    Data mydata;
    
    mydata.byte1 = 45u;
    mydata.byte2 = 95u;
    mydata.byte3 = 2u;
    mydata.byte4 = 22u;
    
    // mydata.uval = şeklindede erişebiliriz.

}
```

* En yaygın kullanım şekli yukarıdaki kodda kullanıldığı gibidir. (Sistem programlama tarafında)

---------------------------------------------------------------------------------------------------------------------------

### tagged union, discriminated union

* Öyle bir değişken olsunki önceden belirlenmiş farklı türlerden değerler alabilsin. (C++ dilinde hazır kütüphane ile bu kullanım sunulur. Variant)
* C'de hazır olarak sunulmadığı için kendimiz kod yazmak zorundayız.

```c
typedef struct{
    int type;   // Data'nın char, int, double, Date hangisini tuttuğu bilgisini taşıyan eleman.
    
    union {
        char c;
        int i;
        double d;
        Date dt;
    };
}Data;
```

* Data türünden bir değişkenin 2 tane elemanı var.
  * Biri type diğeri anonymous union.
 
---------------------------------------------------------------------------------------------------------------------------

#### Aşağıdaki Kod Örneği Tagged Union Kullanımına Örnektir

```c
#define CHAR_TYPE       0
#define INT_TYPE        1
#define DOUBLE_TYPE     2
#define DATE_TYPE       3

typedef struct {
    int type;
    union {
        char c;
        int i;
        double d;
        Date dt;
    };
}Data;

double drand(void)
{
    return (double)rand() / RAND_MAX + rand();
}

void set_random_value(Data* p)
{
    switch(rand() % 4) {
        case CHAR_TYPE : p->type = CHAR_TYPE; p->c = rand % 26 + 'A'; break;
        case INT_TYPE : p->type = INT_TYPE; p->i = rand(); break;
        case DOUBLE_TYPE : p->type = DOUBLE_TYPE; p->d = drand(); break;
        case DATE_TYPE : p->type = DATE_TYPE; set_random_date(&p->dt); break;
    }
}

void print_data_value(const Data* p)
{
    switch(p->type) {
        case CHAR_TYPE : printf("%c", p->c); break;
        case INT_TYPE : printf("%d", p->i); break;
        case DOUBLE_TYPE : printf("%f", p->d); break;
        case DATE_TYPE : print_date(&p->dt); break;
    }
}
```

---------------------------------------------------------------------------------------------------------------------------

#### Bir diğer union kullanım fikri :

* Bellek ihtiyacını azaltmak.
* Aynı verileri daha az bellek alanı kullanarak ifade etmek.
* Öyle durumlar var ki;
  * Siz birden fazla veriyi işleyeceksiniz fakat bazı verilerin bir arada bulunma şansı yok.
  * Bunları ayrı ayrı bellek alanlarında tutmak yerine, tek bir bellek alanını ikisi içinde kullanırız. (Nasıl olsa ikisi birlikte var olamaz.)
  * Böylece toplam bellek kullanımını azaltmış oluruz.

```c
typedef struct {
    int id;
    char name[40];
    char address[40];
    int gender;
    
    union {
        struct { // cinsiyet erkek ise askerlik bilgileri
            char place[24];
            int status;            
        }
        char maiden_name[30];  // cinsiyet kız ise kızlık soy adı
    };
    
    
}Employee;
```

* Bu iki veri aynı anda olamayacağı için bu kullanım ile sizeof(Employee) düşer. 






















