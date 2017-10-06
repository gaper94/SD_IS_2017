# Упражнение 1 - ООП Преговор

## Задача 1
Да се реализира клас `String`, който представлява символен низ с произволна дължина. За този клас да се реализира следната функционлност:
* Голямата четворка
```C++
String empty;
String car("Skoda Octavia vRS");
String secondCar(car);
String thirdCar = car;
empty = thirdCar;
```
* Необходимите set и get функции
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
* Функция, която изчиства вътрешните данни на низа
```C++
String GTR("Nissan GTR");
GTR.clear();
std::cout << GTR << std::endl; // "" 
```
`Бонус:`

Изправени сте пред следната ситуация: във вашият проект се ползват много низове и заделянето и освобождаването на динамична памет е скъпа операция. Знаете също че низовете, които се ползват, в 80% от случаите не надвишават 15 символа и в 90% не надвишават 10 символа. Опитайте се да направите оптимизация с която да намалите заделянето/освобождаването на динамична памет

## Задача 2
Да се реализира шаблонен клас `Vector`, който представлява динамичен масив от произволен тип. За този клас да се реализира следната функционлност:
* Голямата четворка
```C++
Vector<int> emptyNumbers;
int data[5] = {1, 2, 3, 4, 5};
Vector<int> numbers(data, 5);
Vector<int> copyNumbers(numbers);
Vector<int> otherCopy = numbers;
emptyNumbers = otherCopy;
```
* Необходимите set и get функции
* Функция за добавяне на елемент в краят на масива
```C++
int data[3] = {1, 2, 3};
Vector<int> numbers(data, 3);
numbers.push_back(4); // {1, 2, 3, 4}
numbers.push_back(5); // {1, 2, 3, 4, 5}
```
* Функция, която проверява дали динамичният масив е празен
```C++
Vector<int> noData;
if(noData.empty() == true)
{
    std::cout << "noData is empty\n";
}
noData.push_back(10); // {10}
noData.push_back(12); // {10, 12}
if(noData.empty() == false)
{
    std::cout << "noData is not empty\n";
}
```
* Оператор [ ]
```C++
Vector<int> numbers;
for(size_t i = 0; i < 10; i++)
{
    numbers.push_back(i);
}
const Vector<int> constNumbers(numbers);
for(size_t i = 0; i < numbers.size(); i++)
{
    numbers[i] *= 2;
    std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    constNumbers[i] *= 2; // Error
    std::cout << "constNumbers[" << i << "] = " << constNumbers[i] << std::endl;
}
```
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
