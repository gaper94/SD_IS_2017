# Упражнение 8 - Алгоритми - Сортировки и бинарно търсене

## Задача 1
Да се реализира алгоритъм за сортиране чрез вмъкване (Insertion sort)

## Задача 2
Да се реализира алгоритъм за сортиране чрез метода на мехурчето (Bubble sort)

## Задача 3
Да се реализира алгоритъм за сортиране чрез метода на пряката селекция (Selection sort)

`Забележка:`

Опитайте се да реализирате задача 1, 2 & 3 като направите функцията за сортиране да
приема итератори и тези функции да работят за всички видове контейнери до сега (масив, вектор, опашка, списък и т.н)

`Пример:`
```C++
template<typename T>
void selection_sort(iter<T> begin, iter<T> end, bool (*predicate)(const T&, const T&) = nullptr); // If predicate is nullptr
                                                                                                  // try to use operator '<'

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
```

## Задача 4
Binary search
Анализ на алгоритъма
Сравнение на алгоритъма - върху линейно разполжен контейнер и свързан списък
Кое е по-добре - линейно или бинарно търсене ?
