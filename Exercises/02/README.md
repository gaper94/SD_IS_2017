# Упражнение 2 - Входни параматери, потоци и текстови файлове

[Примери](InputParametersExamples.cpp)

# Задача 1

Да се напише програма, която приема като входни аргументи списък от текстови файлове и извежда съдържаниетo им ред по ред.
Вашата програма трябва да приема опционално следният аргумент: 

* `-l <брой_редове_които_да_бъдат_изведени>`

Когато има подаден параметър `-l` трябва задължително да бъдат указани и броят редове, които ще бъдат изведени (този параметър важи само за файлът, който следва след него).

При липса на аргументи или неправилно подадени аргументи (параматър -l без брой редове) да се изведе подходящо съобщение, което да поясни на потребителят как се работи с вашата програма.
При грешка с четенето на някой от файловете (не съществува такъв файл, програмата няма права за четене) да се изведе подходящо съобщение за грешка.

`Пример:`

Нека имам следните два текстови файла:

***sort.cpp***
```C++
template<typename T>
void sort(std::vector<T> data, size_t numberOfElements, std::function<bool(const T&,const T&)> comp = nullptr)
{
   ...
}
```
***autoMutex.hpp***
```C++
template<typename T>
class AutoMutex
{
public:
    AutoMutex(T& mutex)
        : m_mut(mutex)
    {
        m_mut.Lock();
    }
    ~AutoMutex()
    {
        m_mut.Unlock();
    }
private:
    T& m_mut;
};
```
Изпълнението на програмата ви със следните аргументи

`printFiles -l 5 autoMutex.hpp sort.cpp`

трябва да има следният изход:
```
### autoMutex.hpp ###
template<typename T>
class AutoMutex
{
public:
    AutoMutex(T& mutex)
### sort.cpp ###
template<typename T>
void sort(std::vector<T> data, size_t numberOfElements, std::function<bool(const T&,const T&)> comp = nullptr)
{
   ...
}
```
# Задача 2
Aвтомобилен класьор/телефонен указател, предефиниране на << и >>
# Задача 3
