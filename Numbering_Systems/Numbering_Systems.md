## NUMBERING SYSTEM
* decimal     (onluk)
* hexadecimal (on altılık)
* octal       (sekizlik)
* binary      (ikilik)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Binary System
* 0 ve 1'lerden oluşur.

| Signed (İşaretli) | Unsigned (İşaretsiz) |
|--|--|
| Hem negatif hem pozitif tamsayılar var. | Negatif sayılar yok. 0 ve pozitif tamsayılar var. |

* Her basamak ---> binary digit ---> bunlara bit denir.
* 1 byte = 8 bit    (0000 1111 => 1 byte = 8 bit)
* 1 KB = 2^10 = 1024 byte
* 1 MB = 2^20

* 1 byte'ın yarısına nibble denir. (4 bit = nibble)
* 1 word = 2 byte'lık alan.
* double word = 4 byte'lık alan.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Unsigned Binary (0, ................... , pozitif number)

* **0101**
  * En sağdaki bit (1) sayının 0. biti
  * En soldaki bit (0) sayının 3. biti

* **1 Byte'ın tutabileceği en küçük değer :** 0000 0000 = 0
* **1 Byte'ın tutabileceği en büyük değer :** 1111 1111 = 255

* **2 Byte :**
  * min = 0
  * max = 65.535

* **4 Byte :**
  * min = 0
  * max = 4.294.967.295


![image](https://github.com/user-attachments/assets/56fbc822-82f8-4986-bbfb-4294df673cb6)

* En soldaki bit (MSB) : En yüksek anlamlı bit.
* En sağdaki bit (LSB) : En düşük anlamlı bit.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Decimal convert to Binary

* İkiye böl kalanı en sağ digit'ten itibaren yazmaya başla. Kalan bitlere 0 yaz.

![image](https://github.com/user-attachments/assets/5e70f796-9326-4939-a3a8-472affa8adc1)


## one's complement (bire tümleyen)

* Bir sayının bire tümleyeni alınırsa o sayının bitlerinin tersi alınır.
* 0101 1101 sayısının bire tümleyeni 1010 0010

## two's complement (ikiye tümleyen)

* İkiye tümleyen = bire tümleyen + 1 formülü ile hesaplanır. Yani sayının 1'e tümleyeni alınır ardından o sayıya 1 eklenir.
* 0101 1000 sayısının 2'ye tümleyenini bulalım.
  * 0101 1000 sayısının bire tümleyeni 1010 0111
  * 1010 0111 + 1 = 1010 1000
  * 0101 1000 syaısının ikiye tümleyeni 1010 1000 'dır.

* **İkiye tümleyen için pratik yöntem :** Sağdan başlanır ilk 1 bitini görene kadar bitlerin aynısı yazılır. Ondan sonraki bitler için bitlerin tersi yazılır.
  * 0101 1010 ---ikiye tümleyeni---> 1010 0110 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Signed Binary

* Aynı tamsayı değerindeki pozitif tamsayılar ile negatif tamsayılar birbirlerinin ikiye tümleyenidir.
* 56 ile -56 birbirinin ikiye tümleyenidir.

## sign bit (işaret biti)

* İşaret biti : en yüksek anlamlı bit işaret bitidir.
* İşaret biti 1 ise sayı negatif'tir. 1001 0101  (En yüksek anlamlı biti 1)
* İşaret biti 0 ise sayı pozitif'tir. 0110 0000  (En yüksek anlamlı biti 0)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## İşaretli sistemde sayı değeri nasıl bulunur?

* Sayının ikiye tümleyeni alınır. Çıkan sonuç ne ise gerçek sonuç onun (-)'lisidir.
* 1110 0101 sayısının işaretli sistemdeki değeri?
  * 1110 0101 sayısının ikiye tümleyeni 0001 1011
  * 0001 1011 : 27  gerçek sonuç -27'dir.

* -91 sayısının binary sistem değeri nedir?
  * 0101 1011 : 91
  * 0101 1011 sayısı neyin ikiye tümleyeni? 1010 0101 : -91

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* **1 byte'lık yazılabilecek en büyük değer :** 0111 1111 = 127
* **1 byte'lık yazılabilecek en küçük değer :** 1000 0001 = -128

| min | max | byte |
|--|--|--|
| -128 | 127 | 1 byte |
| -32'768 | 32'767 | 2 byte |
| -2'147'483'648 | 2'147'483'647 | 4 byte | 

* İşaretli olarak bir sayının tüm bitleri 1 ise o sayı -1 'dir.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Hexadecimal System

* 16 tabanlı sayı sistemi.
* 0 1 2 3 4 5 6 7 8 9 A B C D E F

## Hex convert Binary

* 1ACF
* 1 : 0001    A : 1010    C : 1100    F : 1111
* 1ACF = 0001 1010 1100 1111

## Decimal convert Hex

* Sayıyı 16 ya böl sürekli kalanı en sağdaki bitten itibaren yaz.

* 2 byte'lık alanda yazılabilecek en büyük işaretli tam sayıyı hex olarak yazalım.
  * 0111 1111 1111 1111 = 7FFF

* 2 byte'lık alanda yazılabilecek en küçük işaretli tam sayıyı hex olarak yazalım.
  * 1000 0000 0000 0000 = 8000

* 2 byte'lık alanda yazılan -1 değerini hex olarak yazalım.
  * 1111 1111 1111 1111 = FFFF

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* Gerçek bir sayı 4 byte, 8 byte'lık alanlarda kodlanmış şekilde tutulabilir.
  * 4 byte (single precision)
  * 8 byte (double precision)




































