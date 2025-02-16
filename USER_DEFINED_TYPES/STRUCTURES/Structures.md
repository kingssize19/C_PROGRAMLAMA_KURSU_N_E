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







































