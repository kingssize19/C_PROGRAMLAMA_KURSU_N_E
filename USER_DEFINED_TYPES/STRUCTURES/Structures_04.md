* Bir yapının elemanı başka bir yapı türünden değişken olabilir.

```c
struct Nec {
	int x;
};

struct Erg {
	struct Nec n;
};

struct Data {
	struct Erg e;
};


int main(void)
{

	struct Data mydata;

	mydata.e.n.x = 10;

	printf("mydata.e.n.x : %d", mydata.e.n.x);

}
```

```c
struct Nec {
    int x;
};

struct Erg {
    struct Nec* n;
};

struct Data {
    struct Erg* e;
};


int main(void)
{

    struct Data mydata;

    // Bellek tahsisi yap
    mydata.e = (struct Erg*)malloc(sizeof(struct Erg));
    mydata.e->n = (struct Nec*)malloc(sizeof(struct Nec));

    // Bellek başarılı şekilde tahsis edildi mi kontrol et
    if (!mydata.e || !mydata.e->n) {
        printf("Bellek tahsis hatası!\n");
        return 1;  // Hata kodu ile çık
    }

    // Artık bellek tahsis edildi, güvenle erişebiliriz
    mydata.e->n->x = 10;

    printf("mydata.e->n->x : %d\n", mydata.e->n->x);

    // Belleği serbest bırak
    free(mydata.e->n);
    free(mydata.e);
}
```

---------------------------------------------------------------------------------------------------------------------

* Yapının elemanı kendi türünden olamaz.

```c
struct Nec {
  int x, y, z;
  struct Nec nx;    // Sentaks hatası
};
```

---------------------------------------------------------------------------------------------------------------------

## Complete Types - Incomplete Types

* Derleyici eğer bir türün varlığından haberdar ise ancak o türün tanımını henüz görmemiş ise derleyici açısından bu tür incomplete types'tır.

```c
struct Nec;      // incomplete types
```
* Derleyiciyi türün sadece varlığından haberdar ediyor.
* Derleyiciye bu türün elemanlarını göstermiyor.

---------------------------------------------------------------------------------------------------------------------

```c
struct Nec {
    int x, y;      // complete types
};
```

---------------------------------------------------------------------------------------------------------------------

### Incomplete Type ile Neler Yapabiliriz?

* Bir fonksiyonun bildiriminde fonksiyonun parametre değişkeninin türü, geri dönüş değerinin türü incomplete type olabilir. (**Not :** Bildiriminde. Tanımlamada değil!)

```c
struct Nec;     // incomplete types
struct Erg;     // incomplete types

// Aşağıdkai iki bildirim içinde derleyici bir sentaks hatası veya uyarı mesajı vermez.
struct Nec foo(struct Erg);
struct Nec* bar(struct Erg*);
```

---------------------------------------------------------------------------------------------------------------------

* Incomplete type'lar tür eş isim bildirimindede kullanılabilir.

```c
struct Nec;

// Aşağıdaki iki bildirim için derleyici uyarı mesajı veya syntax hatası vermez.
typedef struct Nec Nec;
typedef struct Nec* NecPtr;
```

---------------------------------------------------------------------------------------------------------------------

* Incomplete types türünden bir pointer değişken tanımlayabiliriz.

```c
struct Nec;

int main() {
    
    struct Nec* necptr;     // Derleyici Hata vermez.
    /*
        Derleyici neden hata vermez?
        ****************************
        - Derleyici object pointer storage ihtiyacını bildiği için (örneğin 4 byte) ona göre storage'ı ayarlayabiliyor.
        - Bu yüzden struct Nec'in elemanlarını bilmesine gerek yok.
    */
    
```

```c
struct Nec;
struct Nec* foo(void);
struct Nec* bar(struct Nec*);

int main() {
    
    struct Nec* necptr = NULL;
    necptr = foo();
    bar(necptr);
    
}
```

---------------------------------------------------------------------------------------------------------------------

* Extern bildirimi yapılabilir.

```c
struct Nec;
extern struct Nec x; 
```
* Extern anahtar sözcüğü ile yapılan bildirim **non-defining declaration** yani derleyici x nesnesi için bir yer ayırmayacak.
* x nesnesinin başka bir modülde tanımlanmış global değişken olduğunu varsayacaktır.

```c
extern struct Nec ar[];
```
* Derleyici ar için bellekte yer ayırmayacak. Bu kod legal.

---------------------------------------------------------------------------------------------------------------------

* Yapının bir elemanı incomplete type türden pointer olabilir.

```c
struct Nec;     // incomplete type

struct Erg {
    struct Nec* NecPtr;
};
```

---------------------------------------------------------------------------------------------------------------------

### Incomplete Type Türünü Nerelerde Kullanamayız?

* Bir incomplete type türden nesne tanımlayamayız.

```c
struct Nec;     // incomplete type

int main() {

    struct Nec mynec;   // sentaks hatası
    
}
```

---------------------------------------------------------------------------------------------------------------------

* Incomplete type türü sizeof operatörünün operandı olamaz.

```c
struct Nec;     // incomplete type

struct Erg {    // complete type
    int x, y, z;
};

int main() {

    printf("sizeof(struct Nec) : %zu\n", sizeof(struct Nec));     // illegal kod. sentaks hatası.
    printf("sizeof(struct Erg) : %zu\n", sizeof(struct Erg));     // legal kod.  Çıktı : 12
    
}
```

---------------------------------------------------------------------------------------------------------------------

* Pointer'ın dereference edildiği ifadeyide kullanamayız.

```c
struct Nec;    

extern struct Nec gnec;

int main() {

    struct Nec* p = &gnec;
    // *p kullanımı sentaks hatası.
    // p[] kullanımı sentaks hatası
    // p->x kullanımı sentaks hatası
}
```

---------------------------------------------------------------------------------------------------------------------

* Yapının bir elemanı incomplete type türünden olamaz.

```c
struct Nec;     // incomplete type

struct Erg {
    struct Nec nec;  // Error : Sentaks Hatası.
};
```

---------------------------------------------------------------------------------------------------------------------

#### Dikkat : Bir yapının elemanı kendi türünden olamaz.

```c
struct Nec {
    struct Nec x;       // sentaks hatası. Bu aşamada struct Nec halen incomplete type yani tanımsız struct Nec.
};
```

#### Ama yapının elemanı kendi türünden pointer olabilir.

```c
struct Nec {
    struct Nec* necptr;    // Node (düğüm)
};
```

* Bu kullanıma kendi kendine atıfta bulunan yapılarda denir. (**self - referential structures**)

---------------------------------------------------------------------------------------------------------------------

#### Bir başlık dosyasında (header file) asla gereksiz bir şekilde başka başlık dosyalarını #include etme! (Sadece mecbur isek include ederiz.)
#### O kullanacağımız gereksinimleri incomplete type olarak tanımlarsak gereksiz include işlemlerinden kaçınmış oluruz.

---------------------------------------------------------------------------------------------------------------------

#### nested type struct :

* Elemanın ilişkin olduğu türü doğrudan elemana sahip yapının içinde bildirimi.

```c
struct Erg {
    int a, b, c;

    struct Nec {
        int x, y, z;
    }nec;
};
```

* struct Erg'in scope'u neyse struct Nec'inde sope'u o dur.

```c
struct Erg {
    int a, b, c;

    struct Nec {
        int x, y, z;
    }nec;
};

int main() {

    struct Nec mynec;		// C dilinde geçerli. C++ dilinde geçerli değildir.
    
}
```

* Erg içinde bulunan struct Nec yapı türüne isim vermesekte geçerli olur.

```c
struct Erg {
    int a, b, c;

    struct {
        int x, y, z;
    }nec;
};


int main() {

    struct Erg e;

    e.nec.x = 10;	// Geçerli kullanım
    e.nec.y = 20;	// Geçerli kullanım
    e.nec.z = 30;	// Geçerli kullanım
}
```






















