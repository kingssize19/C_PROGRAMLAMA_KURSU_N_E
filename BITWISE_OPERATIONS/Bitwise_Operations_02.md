# Bitwise Manipulations (2. Bölüm)

* **Bir tamsayının belirli bir bitini birlemek &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to set the bit)**
* **Bir tamsayının belirli bir bitini sıfırlamak &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to reset the bit)**
* **Bir tamsayının belirli bir bitini değiştirmek &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to flip the bit / to toggle the bit)**
* **Bir tamsayının belirli bir bitinin değerini elde etmek &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (to get the bit)**


------------------------------------------------------------------------------------------------------------------------------------------------------------------

## to set the bit

* 1000 1000 0?11 0101 &nbsp;&nbsp;&nbsp;&nbsp; ? bitini 1 yapalım.
* 0000 0000 0100 0000 &nbsp;&nbsp;&nbsp;&nbsp; (Bit mask)
* x biti set edilecek tam sayı, n ise set edilecek bitin indeksi olsun.
* x |= (1 << n); &nbsp;&nbsp;&nbsp;&nbsp; x'in n. biti set edilmiş (yani birlenmiş) olur.




