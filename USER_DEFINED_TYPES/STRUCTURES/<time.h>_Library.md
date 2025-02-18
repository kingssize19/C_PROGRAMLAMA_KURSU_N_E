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



















