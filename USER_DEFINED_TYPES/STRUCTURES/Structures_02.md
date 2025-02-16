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



























