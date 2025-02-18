## Dinamik Bellek Yönetimi ile Yapı Nesnesi Kullanım Örneği

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Student {

    int no;
    char name[20];
    char surname[20];
    int grades[5];
    
};

struct Student* make_random_student(void)
{
    struct Student* p = (struct Student*)malloc(sizeof(*p));
    p->no = rand() % 1001;
    strcpy(p->name, "Hayati");
    strcpy(p->surname, "Kilic");
    for (int i = 0; i < 5; ++i) {
        p->grades[i] = rand() % 101;
    }
    
    return p;
}


int main() {
    
    srand(time(NULL));
    struct Student* ptr = make_random_student();
    
    
    
    printf("ptr->no        : %d\n", ptr->no);
    printf("ptr->name      : %s\n", ptr->name);
    printf("ptr->surname   : %s\n", ptr->surname);
    printf("ptr->grades[0] : %d\n", ptr->grades[0]);
    printf("ptr->grades[4] : %d\n", ptr->grades[4]);
    
    free(ptr);
   
}

/*
Örnek Çıktı :

***********************
ptr->no        : 972
ptr->name      : Hayati
ptr->surname   : Kilic
ptr->grades[0] : 98
ptr->grades[4] : 30
***********************
*/

```

--------------------------------------------------------------------------------------------------------

### Not : Aşağıdaki kullanımda isim arama açısından hiçbir sentaks hatası yoktur.

```c
struct nec {
    int nec;
};

int main() {
    
    struct nec nec;
    nec.nec = 4;
    
}
```

--------------------------------------------------------------------------------------------------------

## Yapı Türleri ve Typedef Bildirimleri (Tür Eş İsim Bildirimleri)


```c
struct Student {
    int no;
    char name[20];
    char surname[20];
    int grades[5];
};

typedef struct Student Student;

int main() {
    
    Student student;
    
}
```
* **Student** ismi **struct Student** türünün eş ismi oldu.

```c
struct Student {
    int no;
    char name[20];
}Student;
/* |--> Buradaki Student struct Student türünden global bir değişken ismidir */

int main() {
    
    Student.no = 998;
    printf("%d", Student.no);
    
}
```

--------------------------------------------------------------------------------------------------------

* Fakat yukarıdaki kullanım şekli typedef ile birleşirse Student struct Student türünün eş ismi olur ve aşağıdaki kodda main içerisindeki iki kullanımda legal'dir.

```c
typedef struct Student {
    int no;
    char name[20];
}Student;
/* |--> Buradaki Student struct Student türünün eş ismi. */

int main() {
    
    struct Student s1 = {456, "Ali"};
    Student s2 = {456, "Ali"};
    
}
```

--------------------------------------------------------------------------------------------------------

* Aşağıdaki kodda :
  * Student tür eş ismi struct Student türünün eş ismi.
  * StudentPtr eş ismi struct Student* türünün eş ismidir.

```c
typedef struct Student {
    int no;
    char name[20];
}Student, *StudentPtr;


int main() {
    
    Student s = {345, "Yelda"};
    StudentPtr p = &s;
    
    printf("s.no = %d\n", s.no);        // s.no = 345
    printf("p->no = %d\n", p->no);      // p->no = 345
    
}
```

--------------------------------------------------------------------------------------------------------

```c
typedef struct {
    int x;
}Data;


int main() {
    
    Data d1 = { 123 }; // legal kullanım.
    
    struct Data d2 = { 123 }; // Sentaks hatası : Data etiket ismi değil.
}
```

--------------------------------------------------------------------------------------------------------

```c
typedef struct {
    int no;
    char name[20];
}*StudentPtr;


int main() {
    
    StudentPtr pd = (StudentPtr)malloc(sizeof(*pd));
    pd->no = 356; // gibi pointer yardımıyla bu nesneyi istediğimiz gibi kullanabiliriz.
    
}
```

* Bu türden otomatik veya statik ömürlü nesne kullanamayız, oluşturamayız.
* Bu tarz tanımlanan bir yapıyı ancak yukarıdaki gibi dinamik ömürlü nesne oluşturarak kullanabiliriz.

--------------------------------------------------------------------------------------------------------

### Local Structure
* Bir yapı türünün global isim alanı haricinde, bir fonksiyon içinde yani block scope'da yapılan yapı bildirimine denir.

```c
void foo(void) 
{
    struct Data {
      int x, y;  
    };
}
```

--------------------------------------------------------------------------------------------------------

* **C dilinde yapıların elemanları fonksiyon olamaz.**
* **Fakat C++ dilinde yapıların elemanları fonksiyon olabilir. (member function)**
* **Hem C hem de C++'da yapının elemanı function pointer olabilir.**
  * ```c
    struct Data {
  
      void (*foo)(void);  // legal
      void bar();         // illegal
    };
    ```
















