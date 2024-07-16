1) Önceden belirlenmiş bir sentaksı vardır.
2) En az bir anahtar sözcük içeriyorlar.
3) Programın akış yönünü belirliyor, değiştirebiliyorlar.

if
while
do-while
for
switch
goto
break
continue 
return

------------------
### if statement
------------------
-> if parantezi içinde türü void olmayan bir ifade olacak.

*if (expr)
   statement;

Aşağıda yan yana bulunan örnek kullanımlar aynı anlamı ifade etmektedir.

1) if (x != 0)        if (x)
     ++a;               ++a;

2) if (y == 0)        if (!y)
     ++a;               ++a;

--------------------
### null statement
--------------------
-> Bir if statement var fakat gövdesi boş yani bir işlem gerçekleştirilmiyorsa bunlara null statement denir.

if (x > 20);  --> null statement

//Null statement
if (x > 10)
  ; 

//Null statement
if (x > 10)
{}

//Aşağıdaki örnekte a 'nın değerinin artması if'e bağlı değil çünkü if null statement.
if (x > 2);
  ++a;

--> Fonksiyon ismi if () içerisinde kullanılırsa geri dönen değer lojik yoruma tabi tutulur.
foo(); fonksiyonu return 0; geri dönsün.

if (foo())
  printf("Doğru");
--> if kısmında bulunun printf fonksiyonu çalışmaz.

----------------
### else kısmı
----------------
if (expr)
  true_path;  //Doğru kısım
else
  false_path;  //Yanlış kısım

Örnek : 

if (expr)
  ;
else
  ++a;

Yukarıdaki kod ile aynı anlamda daha clean hali aşağıda yer almaktadır.

if (!expr)
  ++a;

### Mülakat Sorusu : Noktalı virgül kullanmadan ekrana "Merhaba Dünya" yaz.
Not : printf(); fonksiyonu int türünden bir fonksiyondur ve geri dönüş değeri karakter sayısıdır. Bu sebeple;

if (printf("Merhaba Dünya"))
  {}
Bu şekilde noktalı virgül kullanmadan ekrana Merhaba Dünya yazdırırız.






