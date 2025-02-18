* Fonksiyonun geri dönüş değeri türü bir yapı türü olabilir.

```c
struct Data f1(void);
```

* Fakat kopyalama maliyeti olduğu için bu tarz fonksiyonların kullanımı tercih edilmez.
* Aşağıdaki örnekte return edilen değerler bir bellek alanına kopyalanır. Ardından x değişkenine kopyalanır. 2 adet kopyalama işlemi gerçekleşir.

```c
struct Data f1(void);

struct Data x;

x = f1(); 
```

----------------------------------------------------------------------------------------------------------

* Fonksiyonun geri dönüş değeri bir yapı nesnesinin adresi olabilir.

```c
struct Data* f2(void);
```

* **Dikkat :** Otomatik ömürlü nesnenin adresini döndürmesi tanımsız davranışa yol açar. (dangling pointer.)

```c
typedef struct {
    int row;
    int col;
    int arr[20][20];
    double d1, d2;
}Data;

struct Data* foo(void)
{
    Data dx;
    //set dx
    return &dx;     // !!ub
}
```

----------------------------------------------------------------------------------------------------------

* Statik ömürlü nesnenin adresini döndürebilir. Bunda herhangi bir sıkıntı yoktur.

```c
typedef struct {
    int row;
    int col;
    int arr[20][20];
    double d1, d2;
}Data;

Data dx;  // global dx değişkeni. statik ömürlü.

struct Data* foo(void)
{
    //set dx
    return &dx;
}
```

* Static yerel bir nesnenin adresini döndürebilir. Bunda hiçbir sıkıntı yoktur.

```c
typedef struct {
    int row;
    int col;
    int arr[20][20];
    double d1, d2;
}Data;

struct Data* foo(void)
{
    static Data dx;
    //set dx
    return &dx;
}
```

----------------------------------------------------------------------------------------------------------

* Dinamik ömürlü bir nesne adresi döndürüyor olabilir.

```c
typedef struct {
    int row;
    int col;
    int arr[20][20];
    double d1, d2;
}Data;

struct Data* foo(void)
{
    Data* p = (Data*)malloc(sizeof(Data));
    //....
    //set *p, p-> şeklinde
    return p;
}
```

* Son olarak fonksiyonun argümanı yapı nesnesinin adresi olabilir.

```c
typedef struct {
    int row;
    int col;
    int arr[20][20];
    double d1, d2;
}Data;

struct Data* foo(Data *p)
{
    //...set *p

    return p;
}
```

* Fonksiyon const nesne adresi döndürebilir. Fonksiyon döndürdüğü adresi salt okuma amaçlı yazılımcıya sunar. Adresteki nesneyi değiştiremeyiz.

```c
typedef struct {
    int row;
    int col;
    int arr[20][20];
    double d1, d2;
}Data;

const struct Data* foo(void);
```





















