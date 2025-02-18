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
* C dilinde yapının elemanlarına yapı bildirimi içinde bir değer atamak sentaks hatası.
* C++ dilinde bu kullanım sentaks hatası değildir.
  * ```c
    struct Data {
  
      int x = 5;
      int y = 10;
  
    };
    ```
    
--------------------------------------------------------------------------------------------------------

### void foo(struct Data);

* call by value
* kopyalama maliyeti var
* struct Data size'ı arttıkça maliyet artar.
* Kullanımı çok tercih edilmez.

### void bar(struct Data*);

* call by reference
* Fonksiyona gönderilen argüman struct Data türünden nesne adresi.
* Pointer kadar kopyalama yapar. (Benim derleyicimde 4 byte)
* struct Data size'ı ne olursa olsun kopya maliyeti pointer kadar.

--------------------------------------------------------------------------------------------------------

### void bar(struct Data*);

* Aldığı adresteki nesneyi değiştirme amaçlı.
* mutator
* set function

### void baz(const struct Data*);

* Salt okuma amaçlı
* accessor
* get function

--------------------------------------------------------------------------------------------------------

### void bar(struct Data*);

* Bu fonksiyon, çalıştırıldığı kodun dışına bir değer aktarmak için yapı nesnesini işaretçiyle alır.
  * **Parametre :** struct Data* → Çıktı (out) parametresi
  * **Amaç :** Fonksiyonun içinde değiştirilen değerlerin, fonksiyonu çağıran kod tarafından kullanılmasını sağlamak.
  * **Özellik :** İşaretçi kullanıldığı için orjinal bellek adresine erişim vardır. Bu sayede fonksiyon içinde yapılan değişiklikler, fonksiyonu çağıran koda da yansır.
  * ```c
    #include <stdio.h>

    struct Data {
        int x, y;
    };

    void bar(struct Data* d) {
        d->x = 10;
        d->y = 20;  // d'nin içindeki değerleri değiştiriyoruz
    }

    int main() {
        struct Data myData = {0, 0};  // Başlangıçta x ve y sıfır
        bar(&myData);  // Fonksiyona adres gönderiyoruz
        printf("x = %d, y = %d\n", myData.x, myData.y);  // Değişiklikler main'de görülebilir
        return 0;
    }
    ```
  * Bu fonksiyon orijinal veriyi değiştirir. Böyle parametrelere out parametre (çıktı parametresi) denir.


### void baz(const struct Data*);

* Bu fonksiyon, yalnızca mevcut bir yapı nesnesinin değerlerini okumak için çağrılır. Veri değiştirilmez.
  * **Parametre :** const struct Data* → Girdi (input) parametresi
  * **Amaç :** Fonksiyonun, veriyi değiştirmeden kullanmasını sağlamak.
  * **Özellik :** const anahtar kelimesi, fonksiyonun yapı içeriğini değiştirmesini engeller.
  * ```c
    #include <stdio.h>

    struct Data {
        int x, y;
    };

    void baz(const struct Data* d) {
        printf("x = %d, y = %d\n", d->x, d->y);
        // d->x = 100;  // HATA! const olduğu için değiştirmek yasak
    }

    int main() {
        struct Data myData = {5, 15};
        baz(&myData);  // Veriyi sadece okuyoruz
        return 0;
    }
    ```
  * Burada const, fonksiyonun veriyi değiştirmemesini sağlar. Bu tür parametrelere input parametre (girdi parametresi) denir. Eğer baz() içinde d->x = 100; gibi bir değişiklik yapmaya çalışırsan derleme hatası alırız.

--------------------------------------------------------------------------------------------------------

```c
typedef struct {
	
	int no;
	char name[20];
	char surname[20];
	double mean;
	
	
}Student;


/* Aşağıdaki fonksiyon kullanımı call by value. Kopyalama maliyeti fazla. Kulanımı önerilmez! */
/*
void print_student(Student s) 
{
	printf("*********************************\n");
	printf("No	: %d\n", s.no);
	printf("Name 	: %s\n", s.name);
	printf("Surname : %s\n", s.surname);
	printf("Mean 	: %.2f\n", s.mean);
	printf("*********************************\n");	
}
*/

// Aşağıdaki fonksiyon call by reference. Kopyalama maliyeti pointer kadar. 
void print_student(const Student* s) 
{
	printf("*********************************\n");
	printf("No	: %d\n", s->no);
	printf("Name 	: %s\n", s->name);
	printf("Surname : %s\n", s->surname);
	printf("Mean 	: %.2f\n", s->mean);
	printf("*********************************\n");
}

// Set function
void set_student(Student* ptr)
{
	ptr->no += 100;
	strcat(ptr->name, "can");
	strcat(ptr->surname, "oglu");
}


int main(int argc, char *argv[]) {
	
	Student s1 = {123, "Hayati", "Kilic", 98.80};
	Student s2 = {234, "Irem", "Ince", 100.00};

	//printf("sizeof (&s1) for call by reference : %zu\n", sizeof(&s1));			// 8   call by reference kopyalama maliyet büyüklüğü
	//printf("sizeof (s1) for call by reference  : %zu\n", sizeof(s1));			// 56  call by value kopyalama maliyet büyüklüğü

	
	print_student(&s1);
	set_student(&s1);
	print_student(&s1);
	s2 = s1;
	print_student(&s2);

	return 0;
}
```







































