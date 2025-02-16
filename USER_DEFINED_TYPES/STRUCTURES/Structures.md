# Structures (Yapılar)

```c
struct Data {      // Data : Struct Tag

};
```

* C dilinde yapıların en az bir elemana sahip olması gerekmektedir.
* Yukarıdaki yapı struct'ların yapısına, oluşturulmasına bir örnektir.
* Fakat elemana sahip olmadığı için sentaks hatası.
* C++ dilinde yukarıdaki bildirim geçerlidir.

-------------------------------------------------------------------------------------------------------------------

```c
struct Data {
    int x, y;    
    double d;
}

int main(void)
{
    // int x;  -> Değişken türü : int      Değişkenin ismi : x
    struct Data mydata;    // Değişkenin türü : struct Data      Değişkenin ismi : mydata
}
```
* Yukarıdaki yapı içerisinde yer alan x, y, d değişkenleri structure members olarak isimlendirilir.
* struct Data türünden
  * x member'ı
  * y member'ı
  * d member'ı

-------------------------------------------------------------------------------------------------------------------

```c

struct Data {
    int x, y;
    double d;
}

int main(void)
{
    struct Data mydata;    // C++'da legal.  C'de legal.
    Data mydata;           // C++'da legal.  C'de illegal (sentaks hatası).
}
```
* struct Data tanımlaması derleyiciye bilgi veren bir deyim.
* Bu türün ne olduğu, bu tür hakkında bilgi veren deyim.
* Derleyici bu bildirimi görüp bellekte yer ayırmaz.
* Bu türden bir değişken tanımlandığında (main içerisindeki gibi) derleyici bellekte yer ayırır.

-------------------------------------------------------------------------------------------------------------------

```c
struct Data {
    int x, y;
    double d;
}

int main(void) {
    struct Data mydata;
}
```
* mydata nesnesinin kendi adresi ile mydata'nın ilk elemanının adresi aynı adrestir. Aşağıdaki örnek C kodunda bu bilgiye yer verilmiştir.
```c
struct Data {
	int x, y;
	double z;
	
};


int main(int argc, char *argv[]) {
	
	
	struct Data mydata;
	
	printf("%p %p", &mydata, &mydata.x);		//000000000062FE10 000000000062FE10
	

	return 0;
}
```
* Bellek sıralamasının **x'in adresi < y'nin adresi < d'nin adresi** şeklinde olması garanti altındadır. Bu sıralamaya uyacaktır.
* struct Data türünden bir nesnenin storage ihtiyacı = int türü storage * 2 + double türü storage şeklindedir.

-------------------------------------------------------------------------------------------------------------------

* Yapı elemanı her türden olabilir.

```c
struct Nec {
	int x, y;
	int* ptr;
	int (*fp)(int);
	int a[5];
	char str[10];
};
```

* Bir yapının bir yada birden fazla elemanlarının yine bir yapı türünden olması en sık karşılaştığımız kullanış biçimidir.

```c
struct Point {
     double x, y;
};

struct Rectangle {
     struct Point p1, p2;
};
```

-------------------------------------------------------------------------------------------------------------------

### Dikkat

* Yapı elemanları fonksiyon olamaz. Fakat C++ dilinde yapıların elemanları fonksiyon olabilir. Böyle fonksiyonlara C++ dilinde **"member function"** denir.

```c
struct Nec {
     int foo(int, int);		// C dili için illegal. Fakat C++ dilinde legal. member function.
};
```
-------------------------------------------------------------------------------------------------------------------

* Yapı elemanlarını salt okuma amaçlı kullanmak için const anahtar sözcüğü ile niteleriz.

```c
struct Data {
     int x, y, z;
};

int main (void)
{
     const struct Data data = {3, 6, 7};	// Salt okuma amaçlı.
}
```

-------------------------------------------------------------------------------------------------------------------

```c
struct Data {
	int x, y, z;
};

struct Data g;			// Global struct Data türünden ismi g olan değişken. Derleyici bu değişken için yer ayıracak.
extern struct Data g;		/* Derleyici bu yapı türünden nesne için yer ayırmayacak. 
				   Bunun başka bir modülde tanımlanan, o kaynak dosyada yeri derleyici tarafından ayrılmış olan bir değişken olduğunu düşünür. */
```

-------------------------------------------------------------------------------------------------------------------

* Yapı türleri büyük bir çoğunlukla başlık dosyalarında bildirilir.  (data.h)

```c
struct A {
	int x, y, z;
};

int main(void) 
{
	struct A ax;
	printf("%zu\n", sizeof(struct A));	// 12
	printf("%zu\n", sizeof ax);		// 12
}
```

* sizeof (struct A) için :
  * Geçerli bir ifade
  * Bir sabit ifadesi
  * Bu ifadenin türü size_t türü
  * Bu ifadenin değeri nedir?
    * Bu ifadenin değeri struct A türünden bir nesne için bellekte ne kadar yere ihtiyaç var? sorusunun cevabıdır.

-------------------------------------------------------------------------------------------------------------------

```c
struct Nec {
	int x, y, z;
};

int main(void) 
{
	struct Nec nec;
	
}
```
* nec için :
  * Bu bir ifadedir. İfadenin türü "Struct Nec"
  * nec ifadesi l value expression.
  * l value expression olduğu için &nec; ifadesi sentaks hatası oluşturmaz.
  * nec.x; bir ifade, türü int, l value.

-------------------------------------------------------------------------------------------------------------------

## member selection operators (eleman seçme operatörü) (En yüksek öcnelik seviyesi)

* **. dot operator :** Yapı nesnesinin kendisi yoluyla elemanına erişmek için kullanılır. 
* **-> arrow operator :** Yapı nesnesinin adresini kullanarak o adresteki yapı nesnesinin elemanına erişmek için kullanılır.

```c
struct Nec {
     int x, y;
     int a[5];
     double d;
};

int main (void)
{
    struct Nec mynec;
    struct Nec* p = &mynec;
}
```
* **(\*p).x :** mynec nesnesinin x elemanına erişir.
* **p->x :** Bu şekildede x'e erişilebilir. Bu operatör ile adresini aldığımız nesnenin elemanına erişiriz.

-------------------------------------------------------------------------------------------------------------------

### Dikkat

* Bir yapı nesnesi anlamına gelen bir ifade C dilinde sadece 4 tane operatörün operandı olabilir.
* **struct Nec mynec;** olsun.
  * mynec : sizeof, adres (&), nokta (.), atama (=) operatörlerinin operandı olabilir.


```c
struct Nec {
	int x, y;
	int a[5];
	double d;
};

struct Erg {
	struct Nec n;
};

int main(void) 
{
	struct Erg e;
	
	e.n.x;  // Legal (e.n).x;
	
}
```

* sizeof (struct Nec) için :
  * size_t türünden bir ifade
  * constant expression. Yani char buf\[sizeof(struct Nec)\]; tanımında sentaks hatası olmaz.

-------------------------------------------------------------------------------------------------------------------

```c
struct Nec {
	int x, y;
	int a[5];
	double d;
};


int main(void) 
{
	struct Nec  mynec;
	
	&mynec  // struct Nec* türünden ifade.
	
	
	struct Nec* ptr = &mynec;
	
	// *ptr ile mynec aynı anlamı ifade eder.
	
}
```

* Bir yapı nesnesine (ancak ve ancak) aynı türden bir başka yapı nesne atanabilir. İki farklı yapı nesnesi arasında tür dönüşümü olmaz.

```c
#include <stdio.h>

struct Data {
    int x;
};

struct Nec {
    int y;
};

int main() {
    struct Data d = {2};
    struct Data a;
    struct Nec n;
    
    a = d;  // legal
    n = d;  /* /tmp/IT1r74p3Kj/main.c: In function 'main':
		ERROR!
		/tmp/IT1r74p3Kj/main.c:18:9: error: incompatible types when assigning to type 'struct Nec' from type 'struct Data'
		18 |     n = d;
		   |         ^


		=== Code Exited With Errors === */


    return 0;
}
```





















