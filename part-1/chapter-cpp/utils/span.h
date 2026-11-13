#pragma once

#include <vector>

// Обертка над std::vector
// Позволяет работать с частью вектора, без создания копии данных
struct Span
{
    int Start;
    int Count;
    std::vector<char> *pData;

    Span(int s, int c, std::vector<char> &d)
    {
        Start = s;
        Count = c;
        pData = &d;
    }

    Span(int s, int c, Span parent)
    {
        Start = parent.Start + s;
        Count = c;
        pData = parent.pData;
    }

    char operator[](int index)
    {
        return (*pData)[index + Start];
    }

    void Set(char ch, int index)
    {
        (*pData)[index + Start] = ch;
    }
};
