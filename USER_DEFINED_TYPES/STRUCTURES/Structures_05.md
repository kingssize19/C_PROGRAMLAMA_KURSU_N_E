# Linked List (Bağlı Liste)

![image](https://github.com/user-attachments/assets/a84e8d66-5658-44a9-8569-800205d9dd27)


* **Solda yer alan dinamik dizi yapısı için :** Index ile elemana erişmek için karmaşıklık O(1) constant time'dır.
* **Sağda bulunan bağlı liste yapısı için :** Index ile elemana erişmek için karmaşıklık O(n).

* Değerle erişme her ikisindede aynıdır.
* Ekleme ve silme işlemlerinde :
  * Dinamik dizi sadece sondan ekleme veya sondan silme işlemleri yapıldığında constant time'da. Son olmayan bir noktadan ekleme veya silme yapıldığında lineer complexity.
  * Fakat bağlı listede eklenilecek konuma ilişkin pointerlar elimizde ise nerden ekleme yaparsak yapalım constant time'da gerçekleşir.
* Bağlı listede harcanan bellek alanı dinamik diziden fazladır.

-----------------------------------------------------------------------------------------------------------------------------------------------------

| **Özellik**          | **Dinamik Dizi (Array)** | **Bağlı Liste (Linked List)** |
|----------------------|------------------------|------------------------------|
| **Eleman Erişimi**   | **O(1)** – İndeksleme ile doğrudan erişim yapılabilir. | **O(n)** – Bağlı listede belirli bir elemana ulaşmak için baştan itibaren taramak gerekir. |
| **Ekleme/Silme İşlemleri** | **O(n)** – Ortadan veya baştan ekleme/silme yapmak zordur. Yalnızca sona ekleme/silme O(1) olabilir. | **O(1)** – Eğer ilgili düğümün adresi biliniyorsa, baştan veya ortadan ekleme/silme işlemi hızlıdır. |
| **Bellek Kullanımı** | Daha az bellek kullanır, çünkü yalnızca veri saklanır. | Daha fazla bellek kullanır, çünkü her düğüm bir gösterici (pointer) saklamak zorundadır. |
| **Büyüme/Küçülme** | Statik boyut artışı gerekir, genellikle 2 katına çıkartılır. | Esnek boyutlandırma mümkündür, ihtiyaç duyuldukça düğüm eklenebilir. |
| **Sıralı Okuma** | Önbellek dostudur, ardışık bellek bloklarında saklandığı için hızlı erişim sağlar. | Rastgele adreslerde saklandığı için erişim hızı düşebilir. |
| **Kullanım Alanları** | Elemanlara sık erişim gereken durumlar (dizi tabanlı aramalar, indeks bazlı işlemler, matris işlemleri vb.). | Dinamik ekleme/silme gereken durumlar (kuyruklar, yığınlar, graf yapıları vb.). |

### Hangi Durumda Hangisi Seçilmelidir ?

* **Eğer verilere sık sık indeksleme yaparak erişmek gerekiyorsa**, dinamik diziler daha avantajlıdır. Örneğin, bir öğrenci kayıt sisteminde her öğrenciye bir numara verilmişse ve bu numaraya doğrudan erişmek gerekirse, diziler daha verimli olacaktır.
* **Eğer veriler üzerinde sıkça ekleme ve silme işlemi yapılıyorsa**, bağlı listeler daha avantajlıdır. Örneğin, işlem geçmişi tutan bir sistemde (geri alma işlemleri gibi) veya dinamik veri yapıları (yığın, kuyruk gibi) için bağlı liste daha iyi bir seçimdir.
* **Bellek kullanımının minimize edilmesi isteniyorsa**, dinamik diziler daha iyi bir seçimdir çünkü ek göstericilere ihtiyaç duymaz.
* **Eğer veri boyutu önceden bilinmiyor ve sürekli değişiyorsa**, bağlı liste kullanmak daha uygundur çünkü bellekte dinamik olarak büyüyüp küçülebilir.  


























