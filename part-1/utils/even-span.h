#pragma once

#include <vector>

// Обертка над std::vector. Позволяет работать с частью вектора, без создания копии данных.
// В отличие от обычного Span длинна EventSpan всегда четная. Это достигается за счет
// добавления "виртуального" нуля в конец последовательности, что соответствует добавлению 0 в начало числа.
struct EvenSpan
{
    bool HasZero;
    int Start;
    int Count;
    std::vector<char> *pData;

    EvenSpan(int s, int c, std::vector<char> &d)
    {
        bool addZero = (c == 1) ? false : c % 2;

        HasZero = addZero;
        Start = s;
        Count = addZero ? c + 1 : c;
        pData = &d;
    }

    EvenSpan(int s, int c, EvenSpan parent)
    {
        // Добавляем виртуальный ноль если он уже есть в переданном числе
        if (parent.HasZero && ((s + c) == parent.Count))
        {
            HasZero = true;
            Start = parent.Start + s;
            Count = c;
            pData = parent.pData;
        }
        // Нечетное число. Добавляем виртуальный ноль.
        // Однако, если число состоит из одной цифры, то виртуальный ноль не добавляем.
        // Иначе алгоритм Рекурсивного умножения будет выполнять вечно.
        else if ((c != 1) && ((c % 2) == 1))
        {
            HasZero = true;
            Start = parent.Start + s;
            Count = c + 1;
            pData = parent.pData;
        }
        // Четное число. Виртуальный ноль не добавляем.
        else
        {
            HasZero = false;
            Start = parent.Start + s;
            Count = c;
            pData = parent.pData;
        }
    }

    char operator[](int index)
    {
        if (HasZero && index == (Count - 1))
            return 0;

        return (*pData)[index + Start];
    }

    void Set(char ch, int index)
    {
        // Пропускаем присваивание виртуальному нулю
        if (HasZero && index == (Count - 1))
            return;

        (*pData)[index + Start] = ch;
    }
};
