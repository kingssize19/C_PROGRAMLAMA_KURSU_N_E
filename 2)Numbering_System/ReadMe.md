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


#### En soldaki bit : most significant bit/digit (LSB). En anlamlı bit (yüksek anlamlı).
#### <--- MSB
#### 1100 1001
####      ---> LSB
#### En sağdaki bit : LSB. En düşük anlamlı bit.



















