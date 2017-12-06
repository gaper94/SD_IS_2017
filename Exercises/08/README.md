# Упражнение 8 - Алгоритми - Сортировки и бинарно търсене

## Задача 1
Да се реализира алгоритъм за сортиране чрез вмъкване (Insertion sort).
Анализирайте сложността на алгоритъма.

## Задача 2
Да се реализира алгоритъм за сортиране чрез метода на мехурчето (Bubble sort)
Анализирайте сложността на алгоритъма. Опитайте се оптимизирате алгоритъма до колкото позволява. 

## Задача 3
Да се реализира алгоритъм за сортиране чрез метода на пряката селекция (Selection sort)
Анализирайте сложността на алгоритъма.

`Забележка:`

Опитайте се да реализирате задача 1, 2 & 3 като направите функцията за сортиране да
приема итератори и тези функции да работят за всички видове контейнери до сега (масив, вектор, опашка, списък и т.н)

`Пример:`
```C++
template<typename T>
void selection_sort(iter<T> begin, iter<T> end, bool (*predicate)(const T&, const T&) = nullptr); // If predicate is nullptr
                                                                                                  // try to use operator '<'
template<typename T>                                                                                 
void print(iter<T> begin, iter<T> end);

bool descending(const int& a, const int& b)
{
    return a > b;
}

Vector<int> numbers;
numbers.push_back(20);
numbers.push_back(1);
numbers.push_back(32);
numbers.push_back(-32);

linked_list<int> list_numbers;
for(size_t i = 0; i < numbers.size(); i++)
{
    if(i % 2 == 0)
        list_numbers.push_front(numbers[i]);
    else
        list_numbers.push_back(numbers[i]);
}

sort(numbers.begin(), numbers.end());
sort(list_numbers.begin(), list_numbers.end());
print(numbers);
print(list_numbers, descending);
```

## Задача 4
Да се реализира алгоритъм за двоично търсене (binary search)
Анализирайте сложността на алгоритъма.
Сравненете как алгоритъма се представя (брой сравнения и сложност за достъпване на елемент на произволна позиция) върху различни
структури от данни : линейно разполжен контейнер и свързан списък
Кога линейното търсене би се представило по-добре спрямо двоичното търсене ?
