#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "utils/span.h"

void RecursiveMultiplication(Span buffer, Span &lhs, Span &rhs);
std::tuple<char, char> MultiplyDigits(char lhs, char rhs);
std::vector<char> CreateInput(std::string text, int numbersLength);
void PrintFormatted(Span &number);
void PrintFormatted(std::vector<char> &number);
void AddTempResult(Span target, Span source);
void AddTrailingZero(Span target, int zeroCount);

// Алгоритм Каратсубы умножения двух чисел
int main()
{
    // ввод чисел пользователем
    std::string lhsText;
    std::string rhsText;

    std::cout << "Recursive algorithm for two numbers multiplication.\n";
    std::cout << "Enter first number: ";
    std::cin >> lhsText;
    std::cout << "Enter second number: ";
    std::cin >> rhsText;

    // Выполняем предусловие, что умножаемые числа одинаковой длинны
    size_t numbersLength = std::max(lhsText.length(), rhsText.length());
    std::vector<char> lhs = CreateInput(lhsText, numbersLength);
    std::vector<char> rhs = CreateInput(rhsText, numbersLength);

    // Что-бы не выделять память в куче при каждом рекурсивном вызове, выделяется один большой
    // буфер на старте алгоритма. Первая половина буфера служит для хранения возвращаемого результата.
    // Вторая половина используется вычислений вычислений.
    //
    // Структура буфера:
    // |--------------|----------------|
    // |  1/2 buffer  |  1/2 buffer    |
    // |--------------|----------------|
    // | final result | inner result   |
    // |--------------|----------------|
    int maxSize = 4 * numbersLength;
    std::vector<char> buffer(maxSize);

    // Выполнить алгоритм
    Span left(0, lhs.size(), lhs);
    Span right(0, rhs.size(), rhs);
    Span data(0, buffer.size(), buffer);
    RecursiveMultiplication(data, left, right);

    // Показать результат
    PrintFormatted(lhs);
    std::cout << " * ";
    PrintFormatted(rhs);
    std::cout << " = ";
    Span result(0, buffer.size() / 2, buffer);
    PrintFormatted(result);
    std::cout << "\n";
}

// Реализация алгоритма
void RecursiveMultiplication(Span buffer, Span &lhs, Span &rhs)
{
    if (lhs.Count == 1)
    {
        char high, low;
        std::tie(high, low) = MultiplyDigits(lhs[0], rhs[0]);
        buffer.Set(low, 0);
        buffer.Set(high, 1);
    }
    else
    {
        if (lhs.Count % 2 != 0)
        {
            lhs.pData->push_back('\0');
            rhs.pData->push_back('\0');
        }
        int bufferMid = buffer.Count / 2;
        Span result(0, bufferMid, buffer);
        Span temp(bufferMid, bufferMid, buffer);

        int numMid = lhs.Count / 2;
        Span a(numMid, numMid, lhs);
        Span b(0, numMid, lhs);
        Span c(numMid, numMid, rhs);
        Span d(0, numMid, rhs);

        // Формула для промежуточного результата:
        // 10^N * ac + 10^(N/2) * (ad + bc) + bd

        // Вычисляем ad и добавляем в result
        RecursiveMultiplication(temp, a, d);
        Span ab(0, temp.Count / 2, temp);
        AddTempResult(result, ab);

        // Вычисляем bc и добавляем в result
        RecursiveMultiplication(temp, b, c);
        Span bc(0, temp.Count / 2, temp);
        AddTempResult(result, bc);

        // Добавляем нули для (ad + bc)
        AddTrailingZero(result, lhs.Count / 2);

        // Вычисляем ac, добавляем нули и добавляем в result
        RecursiveMultiplication(temp, a, c);
        Span ac(0, temp.Count / 2, temp);
        AddTrailingZero(temp, lhs.Count);
        AddTempResult(result, temp);

        // Вычисляем bd и добавляем в result
        RecursiveMultiplication(temp, b, d);
        Span bd(0, temp.Count / 2, temp);
        AddTempResult(result, bd);
    }
}

std::tuple<char, char> MultiplyDigits(char lhs, char rhs)
{
    char mult = lhs * rhs;
    char high = mult / 10;
    char low = mult % 10;
    return std::make_tuple(high, low);
}

// Преобразовать число в массив цифр
std::vector<char> CreateInput(std::string text, int numbersLength)
{
    std::vector<char> result(numbersLength);
    for (int i = 0; i < text.length(); ++i)
    {
        char val = text[text.length() - i - 1];
        result[i] = val - '0';
    }
    return result;
}

void PrintFormatted(std::vector<char> &result)
{
    Span s(0, result.size(), result);
    PrintFormatted(s);
}

void PrintFormatted(Span &span)
{
    bool skipLeadingZero = true;
    for (int i = span.Count; i > 0; --i)
    {
        if (!skipLeadingZero)
        {
            bool printSeparator = (i % 3) == 0;
            if (printSeparator)
                std::cout << ",";
        }

        int val = (int)span[i - 1];
        if (skipLeadingZero)
            skipLeadingZero = val == 0;

        if (skipLeadingZero)
            continue;

        std::cout << val;
    }
}

void AddOneDigit(Span span, int pos, char digit)
{
    char val = span[pos] + digit;
    if (val < 10)
    {
        span.Set(val, pos);
    }
    else
    {
        int high = 1;
        int low = val % 10;
        span.Set(low, pos);
        AddOneDigit(span, pos + 1, 1);
    }
}

void AddTempResult(Span target, Span source)
{
    for (int i = 0; i < source.Count; ++i)
    {
        char val = source[i];
        AddOneDigit(target, i, val);

        source.Set(0, i);
    }
}

void AddTrailingZero(Span target, int zeroCount)
{
    // 1 2 3 4 5
    // 0 0 1 2 3
    for (int i = target.Count - zeroCount - 1; i >= 0; --i)
    {
        char val = target[i];
        target.Set(0, i);
        target.Set(val, zeroCount + i);
    }
}