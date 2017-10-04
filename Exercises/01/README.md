# Упражнение 1 - ООП Преговор

## Задача 1
Да се реализира клас String, който представлява символен низ с произволна дължина. За този клас да се реализира следната функционлност:
* Голямата четворка
```C++
String empty;
String car("Skoda Octavia vRS");
String secondCar(car);
String thirdCar = car;
empty = thirdCar;
```
* Оператор за изход <<
```C++
String newSchoolYear("Welcome back");
std::cout << newSchoolYear;
```
* Оператори за конкатениране + и +=
```C++
String manufacture("VW");
String model("Passat");
String newModel("Arteon");
manufacture += " ";
manufacture += model;
String Arteon = (manufacture + " ") + newModel;
std::cout << manufacture << std::endl; // VW Passat
std::cout << Arteon << std::endl; // VW Arteon
```
* Оператор [ ]
```C++
String Mercedes("C63 AMG");
const String BMW("BMW M3 CSL");
Mercedes[2] = '5';
BMW[5] = '5'; // Error
std::cout << Mercedes << std::endl; // C65 AMG
std::cout << BMW << std::endl; // BMW M3 CSL
```
* Функция, която проверява дали низа е празен
```C++
String noData;
String Jane("The Diary of Jane");
if(noData.empty() == true)
{
    std::cout << "noData is empty\n";
}
noData = "Breaking Benjamin - ";
noData += Jane;
if(noData.empty() == false)
{
    std::cout << "noData is not empty\n";
}
```

## Задача 2
## Задача 3
Да се реализира абстрактен клас `Cipher`, който описва следните операции:
```C++
void encrypt(const String& source, String& destination)
```
   * Криптира source и го записва в destination
```C++
bool decrypt(const String& source, String& destination)
```
   * Ако шифърът може да декриптира подаденият низ source го декриптира, записва в destination и връща като резултат true, в противен случай връща false и не модифицира destination

`Забележка:`

1. Когато даден шифър криптира, той добавя в началото на криптирания низ
   идентификатор с фиксирана дължина (три символа), уникален за всеки вид шифър
   
`Пример:`

##### Съобщение кодирано с шифър 1:
```bash
   RSAjivfubywfvyufdyuf - уникален идентификатор RSA
```
   
##### Съобщение кодирано с шифър 2:
```bash
   DSFjivfubywfvyufdyuf - уникален идентификатор DSF
```

Да се реализарат следните видове шифъри:

Шифър `DSF`, който криптира/декриптира по следният начин:
  - към всяка четна позиция/индекс се добавя 14 към числовата(ASCII) стойност на символа
  - към всяка нечетна позиция/индекс се вади 6 от числовата(ASCII) стойност на символа
  
Шифър `BSF`, който криптира/декриптира по следният начин:
  - всяка буква се подменя с равноотдалечената й буква спрямо последната буква в 
    латинската азбука - a се подменя с z, b се подменя с y, c се подменя с x и т.н
  - всяка цифра се подменя с равноотдалечената й цифра спрямо най голямата цифра от
    десетичната бройна система - 0 се подменя с 9, 1 се подменя с 8  и т.н
  - всички други символи се заместват с &
  
  Да се реализира клас `Enigmа`, представящ машина за криптиране/декриптиране на съобщения със следната функционалност:

```C++
void addCipher(Cipher* newCipher)
```
* добавя нов шифър в списъка на машината

```C++
bool encrypt(const String& source, String& destination)
```
* ако има поне един добавен шифър в машината, криптира съобщението, записва го в destination и връща true, в противен случай връща false

```C++
bool decrypt(const String& source, String& destination)
```
* проверява дали в машината има шифър, който може да декриптира source. Ако има такъв шифър, декриптира съобщението, записва го в destination и връща true, в противен случай връща false

`Забележка:`
1. Извикването на encrypt не всеки път да криптира с различен шифър (ако в възможно)

`Бонус:`
* Машината да подържа вложено криптиране/декриптиране - низ се криптира/декриптира последователно с помощта на повече от един шифър
