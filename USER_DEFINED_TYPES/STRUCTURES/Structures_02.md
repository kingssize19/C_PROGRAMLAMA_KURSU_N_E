## Yapı Nesnelerine İlk Değer Verme

```c
#include <stdio.h>

struct Data {
    int x, y;
    double d;
};



int main() {
    struct Data mydata = {10, 20, 3.4};
    
    // mydata.x = 10;
    // mydata.y = 20;
    // mydata.d = 3.4;
}
```

* Tıpkı dizilerde olduğu gibi, eleman sayısından daha az elemana ilk değer verildiği zaman kalan öğelerin değeri 0 olur.

```c
#include <stdio.h>

struct Data {
    int x, y, z;
    double d1, d2;
};

int main() {
    struct Data mydata = {10, 20, 30};
    // struct Data a = {10, 20, 30, }; sentaks hatası yok. Sondaki , trailing comma (legal).
    
    printf("%d ", mydata.x);    // 10
    printf("%d ", mydata.y);    // 20
    printf("%d ", mydata.z);    // 30
    printf("%.2f ", mydata.d1); // 0.00
    printf("%.2f ", mydata.d2); // 0.00

}
```

-------------------------------------------------------------------------------------------------

```c
#include <stdio.h>

struct Data {
    int x, y;
    int ar[4];
    double d;
};

int main() {
    struct Data mydata = {1, 2, {10, 20}, 3.4};
    print_array(mydata.ar, 4); // 10 20 0 0
}
````

* Küme parantezi kullanılmasada derleyici verilen ilk değerleri sırasıyla dizinin elemanlarına yerleştirir.

```c
#include <stdio.h>

struct Data {
    int x, y;
    int ar[4];
    double d;
};

int main() {
    
    struct Data mydata = {1, 2, 10, 20, 30, 40, 4.5};
    print_array(mydata.ar, 4);  // 10 20 30 40
    printf("mydata.d = %f");    // 4.5
}
```

-------------------------------------------------------------------------------------------------

### Hatırlatma : designated initializer

```c
int main() {
    
    int a[10] = { [3] = 5, [8] = 7, [2] = 4};
    print_array(a, 10); // 0 0 4 5 0 0 0 0 7 0
}
```

* Eğer dizi boyutunu belirtmezsek bu sentaksta en büyük indisli elemanın (indis + 1) değeri dizinin boyutudur.

```c
int main() {
    
    int a[] = { [3] = 5, [8] = 7, [9] = 4};
    printf("Dizi boyutu : %zu", sizeof(a) / sizeof(int)); // Dizinin boyutu : 10
}
```

* Yapı nesnelerinde designated initializer geçerlidir.

```c
struct Data {
    int x, y;
    double d1, d2;
};

int main() {
    
    struct Data mydata = {.x = 4, .y = 10, .d1 = 4.5, .d2 = 4.6};
    
}
```
* Yapılarda designated initializer kullanırken belirli bir sıraya uymak zorunda değiliz.
* İlk değer verilmeyen öğeler 0 değerleri ile başlar.

```c
struct Data {
    int x, y;
    double d1, d2;
};

int main() {
    
    struct Data mydata = {.x = 4, .d1 = 4.5, .y = 10};
    printf("%d ", mydata.x);        // 4
    printf("%d ", mydata.y);        // 10
    printf("%.2f ", mydata.d1);     // 4.50
    printf("%.2f ", mydata.d2);     // 0.00
    
}
```

```c
struct Student {
    int no;
    int age;
    int grades[5];
    char name[20];
    char surname[20];
};

int main() {
    
    struct Student student = {
                  .no = 123,
                  .age = 25,
                  .grades = { [0] = 100, [1] = 100},
                  .name = "eralp",
                  .surname = "tunc",
    };
}
```

-------------------------------------------------------------------------------------------------

### Hatırlatma

* Diziler atama operatörünü sol operandı olamaz. Sentaks Hatası.

```c
int main() {
    
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];
    
    b = a;  // sentaks hatası
}
```

* Dizilerin b = a; şeklinde birbirlerine atanabilmesi için yapı nesneleri kullanılabilir.

```c
struct Arr {
    int arr[5];
};

int main() {
    
    struct Arr a = {1, 2, 3, 4, 5};
    struct Arr b;
    
    b = a;  // legal
    
    printf("a.arr[4] = %d\n", a.arr[4]);    // 5
    printf("b.arr[4] = %d\n", b.arr[4]);    // 5
}
```

```c
struct Student {
    int no;
    char name[20];
    char surname[20];
    int grades[5];
};

int main() {
    
    struct Student s1 = {35, "Ali", "Tan", {98, 99, 100, 100}};
    struct Student s2;
    
    s2 = s1; // memcpy(&s2, &s1, sizeof s1); ile aynı anlamda
}
```

-------------------------------------------------------------------------------------------------

```c
#include <stdio.h>

struct Data {
  int a, b, c;  
};

struct Data g;  // struct Data türünden global değişken.

int main() {

}
```

* Yapı bildirimi ile o yapı türünden nesne ya da nesneler tanımlamayı aşağıdaki örnekteki gibi gerçekleştirebiliriz.
* Aşağıdaki gibi bir ya da birden fazla nesne tanımlayabiliriz.

```c
struct Data {
  int a, b, c;  
}g1, g2, g3;
```

* Aynı zamanda bu nesneleri tanımlarken ilk değerde verebiliriz.

```c
struct Data {
  int x, y, z;  
}g1 = {2, 3, 4}, g2 = {.y = 5}, g3 = {.x = 7, . z = 8};

int main() {
    
    printf("g1.x = %d\n", g1.x);    // g1.x = 2
    printf("g2.y = %d\n", g2.y);    // g2.y = 5
    printf("g3.z = %d\n", g3.z);    // g3.z = 8
    
}
```

* Aşağıdaki iki yapı kullanımıda aynı anlamı ifade etmektedir.

```c
struct Data {
  int x, y, z;  
}g = {2, 3, 4}, *ptr = &g;

/***********************************************/

struct Data {
    int x, y, z;
};

struct Data g = {2, 3, 4}, *ptr = &g;
```

-------------------------------------------------------------------------------------------------

* structure tag olmadan bir yapı tanımlanabilir.
* a, b ve c tür ismi olmayan ama aynı yapı türünden nesnelerdir.

```c
struct {
  int x, y, z;  
}a, b, c;
```

-------------------------------------------------------------------------------------------------

* Aşağıdaki kodda a = b ataması geçersiz bir atamadır. a ve b'nin türleri farklı.
* Gerçekleştirilen yapı tanımlamalarında hiçbir hata yoktur. İki bildirimde legal.

```c
struct {
  int x, y, z;  
}a;

struct {
    int x, y, z;
}b;

int main() {
   a = b; 
}
```

-------------------------------------------------------------------------------------------------

* Aşağıdaki örnekte olduğu gibi dizilerin türleri yapı türünden olabilir.
* Designated initializer kullanıldığında ilk değer verilmeyen elemanlar 0 değeri alır. Aynı durum normal değer atama yapılırkende görülür.

```c
struct Point {
  int x, y;  
};

int main() {
   
   struct Point a[4] = {{2, 3}, {4, 5}, {6, 7}};
   struct Point b[] = {[1] = {10, 11}};
   
   printf("a[0].x = %d\n", a[0].x);     // 2
   printf("a[0].y = %d\n", a[0].y);     // 3
   
   printf("a[1].x = %d\n", a[1].x);     // 4
   printf("a[1].y = %d\n", a[1].y);     // 5
   
   printf("a[2].x = %d\n", a[2].x);     // 6
   printf("a[2].y = %d\n", a[2].y);     // 7
   
   printf("a[3].x = %d\n", a[3].x);     // 0
   printf("a[3].y = %d\n", a[3].y);     // 0
   
   printf("b[0].x = %d\n", b[0].x);     // 0
   printf("b[0].y = %d\n", b[0].y);     // 0
   
   printf("b[1].x = %d\n", b[1].x);     // 10
   printf("b[1].y = %d\n", b[1].y);     // 11
   
}
```

-------------------------------------------------------------------------------------------------

## Yapıların Pointer'ı ve Arrow Operator

```c
struct Data {
    
  int x, y;
  double d;
  
};

int main() {
   
   struct Data mydata = {3, 5, 1.2};
   struct Data dx = {13, 35, 1.2};
   struct Data* p = &mydata;
   
   *p = dx;
   dx = *px;
}
```

* *p.x ifadesi \*(p.x) anlamındadır.
* (*p).x = 56;   Bu kod geçerlidir.
* -> operatörünün sol operandı bir yapı türünden adres olmak zorunda yoksa sentaks hatası olur. Sağ operandı olan isimde sol operand hangi yapı türünden adres ise o yapı türünün elemanlarından birisi olacak.
* (*p).x ile p->x aynı anlamdadır.
* struct Data a\[5\]; olsun.
  * a->x = 5; ile a\[0\].x = 5; aynı anlamdadır.
* (a + 3)->y = 2; ifadesi legaldir. (a + 3) array decay ile dizinin 3 indisli elemanının adresidir.
  * (a + 3)->y = 2 ile a\[3\].y = 2 ifadesi aynı anlamdadır.
* struct Data mydata; olsun.
  * (&mydata)->x = 5 ifadesi ile mydata.x = 5 ifadesi aynı anlamdadır.

-------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>

struct Data {
    
  int x, y;
  double d;
  
};

struct Data* foo(void) {
    
    struct Data* ptr = (struct Data*)malloc(sizeof(struct Data));

    if (!ptr) {
        printf("Memory can not allocated!!\n");
        return NULL;
    }    

    ptr->x = 10;
    ptr->y = 20;
    ptr->d = 6.5;

    return ptr;

}

int main() {
   
   struct Data* p = foo();
   
   p->x++;
   printf("p->x = %d", p->x);
   free(p);
}
```

-------------------------------------------------------------------------------------------------

```c
struct Data {
    int x, y;
    double d;
};

struct Data g;

int main() {
    
    struct Data a = {2, 5, 3.4};
    
    const struct Data* p = &a;
    /*

     **Yukarıdaki const kullanımı için geçersiz ifadeler.**
     
     -> *p = ; ataması yapılamaz.
     -> (*p).x++; gibi işlemler yapılamaz. *p salt okuma amaçlı.
     -> p->x = 4; sentaks hatası.
     
     **Yukarıdaki const için geçerli ifade**
     p = &g;
     
    */
    
    struct Data* const p1 = &g;
    
    /*
     *  p1 = &g; sentaks hatası. Yani p1 pointer'ı değiştirilemez. Fakat pointer ile erişebildiğimiz yapı değişkenlerini değiştirebiliriz.
    */
   
   
}
```

-------------------------------------------------------------------------------------------------

```c
struct Data {

    int a[20];
    double b[40];
    
};

struct Data x;
struct Data* p = &x;

int main() {
    
    printf("sizeof(x) = %d\n", sizeof x);   // sizeof(x) = 400
    printf("sizeof(p) = %d\n", sizeof p);   // sizeof(p) = 8
   
}
```

* sizeof(x) : Yapı türünün sizeof'u.
* sizeof(p) : Yapı türünden adres türünün sizeof'u. Derleyiciden derleyiciye göre  değişir. Yapı türünden pointer sizeof'u.

-------------------------------------------------------------------------------------------------

```c
struct Data* p1 = NULL;        // legal kullanım.
struct Data* p2 = 0;           // 0 sabitinin NULL pointer'a dönüşmesinden faydalanır. Legal kullanım.
```

```c
// Aşağıdaki kullanım şekilleri legaldir.
struct Data mydata;
struct Data* p = &mydata;
struct Data** pp = &p
```

-------------------------------------------------------------------------------------------------

















