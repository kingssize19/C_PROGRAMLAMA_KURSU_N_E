# <time.h> ve <locale.h>

* **calender time :** Takvim zamanı
* **timepoint :** Zaman noktası. Herhangi bir tarih zamanda noktadır. Örneğin : 15 Mayıs 1987
* **epoche orjin :** 01:01:1970 00:00 Unix epoche başlangıç noktası. Epoche orjinine saniyeler ekleyerek veya çıkartarak yeni timepointler elde ederiz.
* **duration (süre) :** İki timepoint'i birbirinden çıkarttığımızda elde ettiğimiz değere duration denir.
* **broken-down time :** Ayrıştırılmış zaman bilgisi.

----------------------------------------------------------------------------------------------------------------

## time.h Başlık Dosyasında Yer Alan struct tm Türü 

* 9 adet int eleman bulundurur.
* Bizim sistemimizde bu yapının sizeof'u 9x4 = 36 byte;

```c
struct tm {
    int tm_year;   // Yıl değeri: 1900 yılından itibaren hesaplanır.
                   // Örneğin, 1993 yılı için tm_year = 93 olur.
                   // Gerçek yıl değerini elde etmek için: 1900 + tm_year

    int tm_mon;    // Ay değeri: 0 ile 11 arasında değişir.
                   // 0 = Ocak, 1 = Şubat, 2 = Mart, ..., 11 = Aralık.

    int tm_mday;   // Ayın gün değeri: 1 ile 31 arasında değişir.
                   // Örneğin, 15. gün için tm_mday = 15.

    int tm_wday;   // Haftanın günü: 0 ile 6 arasında değişir.
                   // 0 = Pazar, 1 = Pazartesi, 2 = Salı, ..., 6 = Cumartesi.

    int tm_yday;   // Yılın gün değeri: 0 ile 365 arasında değişir.
                   // 0 = 1 Ocak, 1 = 2 Ocak, ..., 364 = 31 Aralık (artık yıl değilse).
                   // Artık yıllarda 365. indeks de olabilir.

    int tm_hour;   // Saat değeri: 0 ile 23 arasında değişir.
                   // Örneğin, 14:00 için tm_hour = 14.

    int tm_min;    // Dakika değeri: 0 ile 59 arasında değişir.
                   // Örneğin, 30. dakika için tm_min = 30.

    int tm_sec;    // Saniye değeri: 0 ile 59 arasında değişir.
                   // Örneğin, 45. saniye için tm_sec = 45.

    int tm_isdst;  // Gün ışığı tasarruf modu bilgisi:
                   // - Negatif (-1) ise sistemde gün ışığı tasarruf modu bilgisi tutulmuyor.
                   // - 0 ise gün ışığı tasarruf modu devrede değil.
                   // - Pozitif bir değer (1) ise gün ışığı tasarruf modu aktif.
};
```

----------------------------------------------------------------------------------------------------------------

## <time.h> Kütüphanesinin Fonksiyonları

### time_t time(time_t *p); fonksiyonu :

* Herhangi bir noktada time fonksiyonunu çağırarak epoche'den geçen saniye sayısını elde etmiş oluruz.
* set function.
* calender time değerini elde etmek için time fonksiyonunu çağırırız.
* Ya bu fonksiyona time_t türünde bir nesnenin adresini vereceğiz o adresteki nesneyi set edecek.
* Ya da bu fonksiyona NULL pointer geçip geri dönüş değerini kullanacağız.

#### 1. Yöntem : time_t türünden nesnenin adresini yollamak.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    time_t sec;

    time(&sec);

    printf("saniye : %lld\n", sec); // saniye : 1739796496  epoche'dan yani 01:01:1970 00:00'dan soldaki değer kadar saniye geçmiş.

    return 0;
}
```

#### 2. Yöntem : NULL pointer göndererek geri dönüş değerini kullanmak.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("saniye : %lld\n", time(NULL));

    return 0;
}
```

* **NOT :** Bir pointer değişkenine NULL pointer vermenin bir başka yoluda tamsayı sabiti olarak 0'ı kullanmaktır. Buna NULL pointer conversion denir.

----------------------------------------------------------------------------------------------------------------

### struct tm* localtime(const time_t* p); fonksiyonu :

* calender time'ı broken-down time'a dönüştüren fonksiyon.
* time_t türünden değeri yani calender time'ı, broken-down time'a dönüştürür yani struct tm türüne dönüştürür.
* Fonksiyonun geri dönüş değeri yani struct tm* static ömürlü bir nesnenin adresi. Bu yüzden geri döndürülen nesne hep aynı adres.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t timer = 1750000000;

    for (int i = 0; i < 5; ++i) {
        printf("%p\n", localtime(&timer));
    }

    // 0000020842071440
    // 0000020842071440
    // 0000020842071440
    // 0000020842071440
    // 0000020842071440

    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_current_time(void)
{
    time_t sec;
    time(&sec);

    struct tm* p = localtime(&sec);

    printf("%02d:%02d:%d %02d:%02d:%02d", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec);

}

int main()
{
    print_current_time(); // 17:02:2025 16:14:30

    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_current_time(void)
{
    static const char* const pmons[] = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran",
                                       "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};

    static const char* const pdays[] = {"Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi"}; // tm_wday 0. index pazar gününden başlar.

    time_t sec;
    time(&sec);

    struct tm* p = localtime(&sec);

    printf("%02d %s %d %s %02d:%02d:%02d", p->tm_mday, pmons[p->tm_mon], p->tm_year + 1900, pdays[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);

}

int main()
{
    print_current_time(); // 17 Subat 2025 Pazartesi 19:43:57

    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t sec;

    time(&sec);
    struct tm* p = localtime(&sec);

    if (p->tm_isdst < 0)
        printf("Sistemde gun isigi tasarruf bayragi tutulmuyor.\n");
    else if (p->tm_isdst)
        printf("Gun isigi tasarruf modundayiz.\n");
    else
        printf("Gun isigi tasarruf modunda degiliz.\n");

    // Çıktı : Gun isigi tasarruf modunda degiliz.

    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

### struct tm* gmtime(const time_t* p); fonksiyonu :

* localtime() fonksiyonu sistemimizdeki local zaman bilgilerini verir.
* gmtime() fonksiyonu aynı localtime gibi greenwich zaman bilgilerini verir.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_current_time(void)
{
    static const char* const pmons[] = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran",
                                       "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};

    static const char* const pdays[] = {"Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi"}; // tm_wday 0. index pazar gününden başlar.

    time_t sec;
    time(&sec);

    struct tm* p = localtime(&sec);

    printf("%02d %s %d %s %02d:%02d:%02d", p->tm_mday, pmons[p->tm_mon], p->tm_year + 1900, pdays[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);

}

void print_current_time2(void)
{
    static const char* const pmons[] = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran",
                                       "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};

    static const char* const pdays[] = {"Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi"}; // tm_wday 0. index pazar gününden başlar.

    time_t sec;
    time(&sec);

    struct tm* p = gmtime(&sec);

    printf("%02d %s %d %s %02d:%02d:%02d", p->tm_mday, pmons[p->tm_mon], p->tm_year + 1900, pdays[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);

}


int main()
{
    print_current_time();   // 17 Subat 2025 Pazartesi 19:58:33
    printf("\n");
    print_current_time2();  // 17 Subat 2025 Pazartesi 16:58:33
    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

### char* ctime(char time_t* p); ve char* asctime(const struct tm* p); fonksiyonları :

* Her iki fonksiyonda statik ömürlü dizinin adresini döndürür.
* Aradaki fark parametre değişkenlerinin türleri.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t sec;
    time(&sec);

    char *p = ctime(&sec);  // p'yi kullandığımızda timepoint'i betimleyen, \n dahil 26 eleman uzunluğundaki diziyi kullanmış oluruz.
                            // Ve bu yazının formatı standart.

    printf("%sHayati Kilic", p);  // Mon Feb 17 20:06:54 2025
                                  // Hayati Kilic



    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t sec;
    time(&sec);

    char *p = ctime(&sec);
    printf("%s", p);
    sec -= 100000;
    p = ctime(&sec);
    printf("100.000 saniye öncesi : %s", p);

    // Mon Feb 17 20:09:50 2025
    // 100.000 saniye öncesi : Sun Feb 16 16:23:10 2025

    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t sec;
    time(&sec);

    struct tm* tp = localtime(&sec);

    char* p1 = ctime(&sec);
    char* p2 = asctime(tp);

    printf("%p %p", p1, p2);  //0000024a217d1470 0000024a217d1470   ikisinin geri döndürdükleri adres aynı dizi adresleri.

    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

## <locale.h> ve setlocale() fonksiyonu

* Hem printf fonksiyonu hem de scanf fonksiyonu locale'e bağlı fonksiyonlardır.

#### char* setlocale(int cat, const char* locale); fonksiyonu

```c
setlocale(LC_ALL, "turkish");
```

* **Fonksiyonun geri dönüş değeri :** Eğer locale değişikliği başarılı değilse NULL pointer. Başarılı ise locale'in resmi ismi.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    char *p = setlocale(LC_ALL, "Turkish");

    if (!p) {
        printf("Locale değişikliği yapılamadı.\n");
    }
    else {
        printf("Locale değişikliği yapıldı.\n");
        printf("%s\n", p);      // Turkish_Türkiye.1254
    }

    return 0;
}
```

----------------------------------------------------------------------------------------------------------------

#### strftime() fonksiyonu : 

```c
size_t strftime(char* p, size_t size, const char* pfm, const struct tm* ptm);
```
* Bu fonksiyon, verilen tarih ve saat bilgisini belirtilen format (pfm) doğrultusunda bir karakter dizisine (p) yazmak için kullanılır.

| Parametre | Türü | Açıklama |
|-----------|------|----------|
| p         | char* | Formatlanmış tarih ve saat bilgisinin yazılacağı karakter dizisinin adresi. |
| size      | size_t | Maksimum karakter kapasitesi (null karakter dahil) – Eğer formatlanmış çıktı size değerinden büyükse, fonksiyon 0 döndürür. |
| pfm       | const char* | Format dizgesi – Tarih ve saat çıktısının nasıl olması gerektiğini belirleyen karakter dizisi. |
| ptm       | const struct tm* | Zaman bilgilerini içeren `tm` yapısının adresi. `struct tm`, yıl, ay, gün, saat, dakika, saniye gibi bilgileri içerir. |


#### Desteklenen Format Dizgeleri (`pfm`)

| Format Dizgesi | Açıklama | Örnek Çıktı |
|---------------|---------|-------------|
| `%a` | Kısa gün adı | `Sal` |
| `%A` | Uzun gün adı | `Salı` |
| `%b` | Kısa ay adı | `Eyl` |
| `%B` | Uzun ay adı | `Eylül` |
| `%c` | Yerel tarih ve saat gösterimi | `18 Şub 2025 14:30:15` |
| `%C` | Yüzyıl (yıl / 100) | `20` (2025 için) |
| `%d` | Ayın günü (01-31) | `05` |
| `%D` | Kısa tarih formatı (MM/DD/YY) | `02/18/25` |
| `%e` | Ayın günü (1-31, tek haneli günlerde boşluk içerir) | ` 5` |
| `%F` | ISO 8601 tarih formatı (YYYY-MM-DD) | `2025-02-18` |
| `%g` | ISO 8601 yılın son iki hanesi | `25` |
| `%G` | ISO 8601 yılın tamamı | `2025` |
| `%H` | Saat (00-23) | `14` |
| `%I` | Saat (01-12) | `02` |
| `%j` | Yılın kaçıncı günü (001-366) | `049` (18 Şubat için) |
| `%m` | Ay numarası (01-12) | `02` |

----------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{

    time_t sec;

    time(&sec);

    struct tm* p = localtime(&sec);

    char buf[100];

    size_t n = strftime(buf, 100, "%A %B %Y", p);

    printf("(%s)\n", buf);          // (Monday February 2025)
    printf("n = %zu\n", n);         // n = 15
}
```

----------------------------------------------------------------------------------------------------------------

* strftime() fonksiyonu locale'e bağlıdır.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Turkish");

    time_t sec;

    time(&sec);

    struct tm* p = localtime(&sec);

    char buf[100];

    size_t n = strftime(buf, 100, "%A %B %Y", p);

    printf("(%s)\n", buf);      // (Pazartesi Şubat 2025)
    printf("n = %zu\n", n);     // n = 20
}

```

----------------------------------------------------------------------------------------------------------------

#### clock_t clock(void) fonksiyonu :

* mainden bu fonksiyonun çağrıldığı yere kadar yapılan işlemlerin clock tick sayısını geri döndürür. Bu clock tick sayısını (Hassas zaman olması açısından) double ile cast ederiz. Ardından CLOCK_PER_SEC macrosuna bölerek saniye cinsinden geçen süreyi buluruz.

* **clock() fonksiyonunun geri dönüş değeri :** main'in başından clock fonksiyonunun çağrıldığı yere kadarki clock tick sayısı. clock_t türünden.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{

    printf("kac tam sayi : ");
    size_t n;
    scanf("%zu", &n);

    int *p = (int *)malloc(n * sizeof(int));

    if (!p) {
        fprintf(stderr, "bellek yetersiz.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        p[i] = i;

    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", p[i]);
    }
    printf("\n");
    printf("Islem bitti...\n");
    printf("sure : %lf saniye\n", (double)clock() / CLOCKS_PER_SEC);
    free(p);

    // Çıktı : kac tam sayi : 5
    //         0 1 2 3 4
    //         Islem bitti...
    //         sure : 2.024000 saniye

}
```

----------------------------------------------------------------------------------------------------------------

* Herhangi bir event'in süresini hesaplayabiliriz. Hesaplamak istediğimiz event başlamadan önce clock fonksiyonunu çağırırız ardından bu event'in bitiminde clock fonksiyonunu tekrar çağırırız aradaki farkı clock tick olarak buluruz. Dilersek bu clock tick değerini CLOCK_PER_SEC macrosuna bölerek saniye cinsinden o eventin harcadığı zamanı bulabiliriz.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{

    printf("kac tam sayi : ");
    size_t n;
    scanf("%zu", &n);

    int *p = (int *)malloc(n * sizeof(int));

    if (!p) {
        fprintf(stderr, "bellek yetersiz.\n");
        return 1;
    }


    for (int i = 0; i < n; ++i) {
        p[i] = rand();

    }

    clock_t start = clock();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t k = 0; k < n - 1 - i; ++k) {
            if (p[k] < p[k + 1]) {
                int temp = p[k];
                p[k] = p[k + 1];
                p[k + 1] = temp;
            }
        }
    }
    clock_t finish = clock();



    printf("\n");
    printf("Islem bitti...\n");
    printf("sure : %lf saniye\n", (double)(finish - start) / CLOCKS_PER_SEC);
    free(p);

}
```

















