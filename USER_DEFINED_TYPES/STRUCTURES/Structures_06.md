## Alignment (Hizalama)

* İşlemciler belirli işlemleri yapabilmek için belleğe erişirler.
* Fakat bu işlemcinin yapısına bağlı olarak, işlemcilerin belleğe erişip bellekte tutulan nesneleri alıp onları kullanabilmeleri için bu nesnelerin bellekte 2'nin 4'ün 8'in katları olan adreslere yerleştirmesi gerekir.
* İşlemcinin yapısının ne olduğuna bağlı olarak verilerin kolay ulaşılabilmesi için 2'nin, 4'ün, 8'in katları olan adreslere yerleştirilmesine alignment requirement denir.
* Mesela bizim derleyicimizde int türünden değişkenlerin kolay ulaşılabilmeleri için 4'ün katları olan adreslere yerleştirilmeleri lazım.
* Double türden değişkenlere kolay erişilebilmesi için 8'in katları olan adreslere yerleştirilmeleri lazım.

-------------------------------------------------------------------------------------------------------------------------------------------

* Her türün align of değeri vardır. Bu değere _Alignof() operatörü ile ulaşırız. Bu operatör size_t türünden bir değer döner.

```c
#include <stdio.h>

int main() {
    
    printf("_Alingof(char) : %zu\n", _Alignof(char));        // _Alingof(char) : 1
    printf("_Alingof(int) : %zu\n", _Alignof(int));          // _Alingof(int) : 4
    printf("_Alingof(double) : %zu\n", _Alignof(double));    // _Alingof(double) : 8
}
```

* Yapı türlerininde alignof değeri vardır. Bu değer yapı elemanlarından en yüksek alignof değerine sahip türün değeridir.

```c
struct Nec {
    char s1;
    int ival;
    double dval;
};

int main() {
    
    printf("_Alignof(struct Nec) : %zu\n", _Alignof(struct Nec));        // _Alignof(struct Nec) : 8

}
```

-------------------------------------------------------------------------------------------------------------------------------------------

* stdalign.h başlık dosyasını include ederek _Alignof() operatörünü bu başlık dosyasındaki makrolar sayesinde alignof(char), alignof(int) şeklinde kullanabiliriz.

```c
#include <stdio.h>
#include <stdalign.h>

int main() {
    
    printf("alignof(char) : %zu\n", alignof(char));              // alignof(char) : 1
    printf("alignof(int) : %zu\n", alignof(int));                // alignof(int) : 4
    printf("alignof(double) : %zu\n", alignof(double));          // alignof(double) : 8

}
```

* Değişkenleri alignof değerlerinin dışında daha farklı alignof değeri katlarına yerleştir talimatı verebiliriz. (16'nın katları, 32'nin katları)
* Yani derleyiciye şunu deriz;
  * Sen onun alignof değerine bakma benim istediğim alignof değerini kullan.
  * Bu işlem için kullanılan operatör : **alignas operatörü**
  * _Alignas() şeklindede kullanabiliriz veya stdalign.h dosyasını include ederek alignas şeklinde kullanırız.
  * alignas(32) -> 32 byte'ın katlarına yerleştir demek.

```c
#include <stdio.h>
#include <stdalign.h>

struct Nec{
  int a;
  double b;
};

int main() {
    
    struct Nec nec1;
    
    printf("alignof(nec1) : %zu\n", alignof(nec1));     // alignof(nec1) : 8
    
    alignas(16) struct Nec nec2;
    
    printf("alignof(nec2) : %zu\n", alignof(nec2));    // alignof(nec2) : 16
    

}
```

-------------------------------------------------------------------------------------------------------------------------------------------

## Padding Bytes : Kullanılmayan Byte'lar

```c
#include <stdio.h>
#include <stdalign.h>

struct Nec{
  char c1;
  int x;
  char c2;
};

/*

Address Byte
------------
1000        c1
1001        padding byte
1002        padding byte
1003        padding byte

1004        x'in 1. byte'ı
1005        x'in 2. byte'ı
1006        x'in 3. byte'ı
1007        x'int 4. byte'ı

1008        c2
1009        padding byte
1010        padding byte
1011        padding byte

*/
```
* Yukarıdaki örnekte :
  * struct Nec türünün align of değeri 4 yani değikenler bellekte 4'ün katı olan adreslere yerleştirilecektir.
  * x'e erişim 4'ün katına yerleştirildiği için verimli şekilde olacaktır.
  * Bu yapı nesnesi sizeof(int) : 4, sizeof(char) : 1 olmasına karşın. struct Nec türünün sizeof'u 6 olmayacak 12 olacaktır.

```c
typedef struct Nec {
	char c1;
	int x;
	char c2;
}Nec;

int main(void)
{
	printf("sizeof(Nec) = %zu\n", sizeof(Nec));		// sizeof(Nec) = 12

}
```

-------------------------------------------------------------------------------------------------------------------------------------------

* Yapı türlerinin elemanlarının yerleşim sırası bu yapı türünün sizeof değerini değiştirir.

```c
typedef struct Nec {
	char c1;
	int x;
	char c2;
}Nec;

typedef struct Erg {

	int x;
	char c1;
	char c2;
}Erg;

typedef struct Foo {

	char c1;
	char c2;
	int x;
}Foo;


int main(void)
{
	printf("sizeof(Nec) = %zu\n", sizeof(Nec));		// sizeof(Nec) = 12
	printf("sizeof(Erg) = %zu\n", sizeof(Erg));		// sizeof(Erg) = 8
	printf("sizeof(Foo) = %zu\n", sizeof(Foo));		// sizeof(Foo) = 8
}
```

-------------------------------------------------------------------------------------------------------------------------------------------

* Yapı nesnesinin sonunda padding byte olabilir. Fakat yapı nesnesinin başında hiçbir zaman padding byte olamaz.

```c
typedef struct Nec {
	char c1;
	int x;
	char c2;
}Nec;




int main(void)
{
	Nec mynec;

	// &mynec adresi ile &mynec.c1 aynı adres olmak zorundadır.
	// Bu şekildede ifade edilir. Yapının başında padding byte olmaz.
}
```

-------------------------------------------------------------------------------------------------------------------------------------------

* Padding byte'ların eklenmesi işlemlerin daha düşük maliyet ile yapılmasını sağlıyor.

-------------------------------------------------------------------------------------------------------------------------------------------

### Paddin byte'lar bizi neden ilgilendiriyor.

#### 1. Sonuç : 

* Yapı nesnesinin elemanlarının dizilim sırasına göre yapının storage ihtiyacı artabilir yada artmayabilir. Tamamen padding byte'ların olup olmadığına ve ne kadar olduğuna bağlı. Dolayısıyla bir yapı türünün storage ihtiyacı için her zaman sizeof() operatörünü kullanmalıyız.

```c
typedef struct Nec {
	char c1;
	int x;
	char c2;
}Nec;

// sizeof Nec : 12


int main(void)
{
	int n = 10;

	malloc(n * 6);  // n * sizeof Nec yerine bu şekilde bir allocate yapmaya çalışsaydık gereken bellek alanının yarısı kadar allocate yapardık.
			//Bu yüzden storage ihtiyacı için herzaman sizeof operatörü kullanılmalı.
}
```

-------------------------------------------------------------------------------------------------------------------------------------------

#### Önemli! Embedded'da bu hata çok yapılıyor.
#### 2. Sonuç : 

* Yapı nesnesinin elemanlarının adreslerinden hareketle, yapı nesnesinin diğer elemanlarının adresine doğrudan pointer aritmetiği ile erişmeye çalışmayın. Çünkü pointer aritmetiği padding byte'ları dikkate almaz.

```c
typedef struct Nec {
	char c1;
	int x;
	char c2;
}Nec;


int main(void)
{
	Nec mynec = { 12, 345876, 45 };

	char* p = &mynec.c1;

	printf("%d\n", *(int*)(p + 1));  // x'in adresini tutması için (int *) ile cast etti.
					 //Fakat atlanılan nokta padding bytes... Tanımsız davranış var.
}
```

* Aşağıddaki kodda bu hatanın önüne geçmiş oluruz.

```c
typedef struct Nec{
  char c1;
  int x;
  char c2;
}Nec;

int main(void)
{
  Nec mynec = { 12, 345876, 45 };
  char* p = &mynec.c1;

  printf("%d\n", *(int*)(p + _Alignof(Nec)));

}
```

-------------------------------------------------------------------------------------------------------------------------------------------

### offsetof makrosu 	// 2. sonuç ile ilgili hatalara düşmemek için bu makro kullanılır.

* Bir yapı nesnesinin kendi adresinden hareketle veya ilk nesnesinin adresinden hareketle diğer elemanların adresine ilişkin bir offset değeri elde etmek için stddef.h başlık dosyasındaki offsetof makrosu kullanılır.

* offset teriminden kastedilen yapı nesnesinin elemanının, yapı nesnesinin başından itibaren kaçıncı byte'ta olduğudur.

```c
typedef struct Nec {
	char c1;		// offsetof değeri 0
	int x;			// offsetof değeri 4
	char c2;		// offsetof değeri 8
}Nec;
```

```c
typedef struct Nec {
	char c1;
	int x;
	char c2;
}Nec;




int main(void)
{
	Nec mynec = { 12, 123456, 45 };

	//offsetof(Nec, c1);   // c1 in offsetini elde etmek için
	//offsetof(Nec, x);	   // x in offsetini elde etmek için
	//offsetof(Nec, c2);   // c2 in offsetini elde etmek için

	printf("%zu\n", offsetof(Nec, c1));		// 0
	printf("%zu\n", offsetof(Nec, x));		// 4
	printf("%zu\n", offsetof(Nec, c2));		// 8

}
```

-------------------------------------------------------------------------------------------------------------------------------------------

#### offsetof makrosunun implementasyonu

```c
typedef struct Nec {
	char c1;
	char c2;
	int x;
}Nec;

// Offsetof makrosunun implementasyonu
#define Offsetof(s, m)			(size_t)(&(((s *)0)->m))

int main(void)
{
	//offsetof(Nec, c1);   // c1 in offsetini elde etmek için
	//offsetof(Nec, x);    // x in offsetini elde etmek için
	//offsetof(Nec, c2);   // c2 in offsetini elde etmek için

	printf("%zu\n", Offsetof(Nec, c1));		// 0
	printf("%zu\n", Offsetof(Nec, c2));		// 1
	printf("%zu\n", Offsetof(Nec, x));		// 4

}
```

-------------------------------------------------------------------------------------------------------------------------------------------

#### 3. Sonuç :

* İki yapının eşitlik sınaması.

```c
typedef struct Nec {
	char c1;
	int x;
	char c2;

}Nec;

int main(void)
{
	Nec n1 = { 12, 123456, 45 };
	Nec n2 = { 12, 123456, 45 };

	if (n1.c1 == n2.c1 && n1.c2 == n2.c2 && n1.x == n2.x)
	{
		// Bu şekilde eşitlik kontrol edilebilir fakat yapı elemanları çok fazla olduğunda okunma zorluğu yaşatır.
	}

}
```

-------------------------------------------------------------------------------------------------------------------------------------------

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct Nec {
	char c1;
	int x;
	char c2;

}Nec;

int main(void)
{
	Nec n1 = { 12, 123456, 45 };
	Nec n2 = { 12, 123456, 45 };

	if (!memcmp(&n1, &n2, sizeof(Nec))) {
		printf("esit\n");
	}
	else {
		printf("esit degil\n");
	}

	// çıktı : esit degil

}
```

* Yukarıdaki kodda **esit degil** sonucunun çıkma sebebi padding byte'lardan dolayıdır.
* memcmp fonksiyonu elemanların eşitliklerini kontrol etmez bellek bloklarının eşitliklerini kontrol eder.
* n1 ve n2'ye ilk değer verdiğimizde padding byte'lar garbage değer alır.
* Dolayısıyla n1 içindeki padding byte'lardaki değerler ile n2'deki padding byte'ların değerlerinin aynı olma garantisi yoktur. Bu yüzden iki yapı birbirine eşit çıkmaz.
* Eğer gerçekten iki yapı nesnesinin bu şekilde memcmp fonksiyonuyla karşılaştırılabilir olmasını istiyorsak padding byte'ları 0 yapmalıyız.
* Bunun için memset fonksiyonunu çağırırız.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define clear_struct(x) memset(&x, 0, sizeof(x))

typedef struct Nec {
	char c1;
	int x;
	char c2;

}Nec;

int main(void)
{
	Nec n1;
	Nec n2;

	clear_struct(n1);
	clear_struct(n2);

	n1.c1 = 45;
	n1.c2 = 89;
	n1.x = 246;

	n2.c1 = 45;
	n2.c2 = 89;
	n2.x = 246;

	if (!memcmp(&n1, &n2, sizeof(Nec))) {
		printf("esit\n");
	}
	else {
		printf("esit degil\n");
	}

	// Çıktı : esit (garanti altında, çünkü padding byte'ları sıfırladık.)

}
```

--------------------------------------------------------------------------------------------------------

### #pragma pack(1)

* **byte alignment :** Der









