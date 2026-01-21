#include <iostream>
#include <string>
#include <vector>
#include <tuple>

std::vector<char> SchoolAlgorithm(std::vector<char> &lhs, std::vector<char> &rhs);
void MultiplyRow(std::vector<char> &result, std::vector<char> &lhs, char digit, int digitPos);
std::tuple<char, char> MultiplyDigits(char lhs, char rhs);
void AddDigit(std::vector<char> &result, char digit, int digitPos);
std::vector<char> CreateInput(std::string text);
void PrintFormatted(std::vector<char> &number);

// Школьный алгоритм умножения двух чисел
int main()
{
    // ввод чисел пользователем
    std::string lhsText;
    std::string rhsText;

    std::cout << "Multiply to numbers. The school algorithm.\n";
    std::cout << "Enter first number: ";
    std::cin >> lhsText;
    std::cout << "Enter second number: ";
    std::cin >> rhsText;

    // Выполнить алгоритм
    std::vector<char> lhs = CreateInput(lhsText);
    std::vector<char> rhs = CreateInput(rhsText);
    std::vector<char> result = SchoolAlgorithm(lhs, rhs);

    // Показать результат
    PrintFormatted(lhs);
    std::cout << " * ";
    PrintFormatted(rhs);
    std::cout << " = ";
    PrintFormatted(result);
    std::cout << "\n";
}

// Реализация алгоритма
std::vector<char> SchoolAlgorithm(std::vector<char> &lhs, std::vector<char> &rhs)
{
    // Выделяем память для максимального результата
    int maxSize = (lhs.size() + 1) + (rhs.size() - 1);
    std::vector<char> result(maxSize);

    // Для каждой цифры из правого числа
    for (int digitPos = 0; digitPos < rhs.size(); ++digitPos)
    {
        char digit = rhs[digitPos];
        MultiplyRow(result, lhs, digit, digitPos);
    }

    return result;
}

// Умножаем первое число на одну цифру из второго числе
void MultiplyRow(std::vector<char> &result, std::vector<char> &lhs, char digit, int digitPos)
{
    // 1234
    //   3
    // ----
    // 369

    for (int lhsPos = 0; lhsPos < lhs.size(); ++lhsPos)
    {
        // Перемножаем две цифры
        char high, low;
        char lhsDigit = lhs[lhsPos];
        std::tie(high, low) = MultiplyDigits(lhsDigit, digit);

        // Складываем первую цифру после умножения
        AddDigit(result, low, lhsPos + digitPos);

        // Складываем вторую цифру после умножения
        AddDigit(result, high, lhsPos + digitPos + 1);
    }
}

std::tuple<char, char> MultiplyDigits(char lhs, char rhs)
{
    char mult = lhs * rhs;
    char high = mult / 10;
    char low = mult % 10;
    return std::make_tuple(high, low);
}

void AddDigit(std::vector<char> &result, char digit, int digitPos)
{
    if (digit == 0)
        return;

    char sum = result[digitPos] + digit;
    char high = 0;
    char low = sum;

    if (sum > 9)
    {
        high = 1;
        low = sum - 10;
    }

    result[digitPos] = low;
    AddDigit(result, high, digitPos + 1);
}

// Преобразовать число в массив цифр
std::vector<char> CreateInput(std::string text)
{
    std::vector<char> result(text.length());
    for (int i = 0; i < text.length(); ++i)
    {
        char val = text[text.length() - i - 1];
        result[i] = val - '0';
    }
    return result;
}

void PrintFormatted(std::vector<char> &result)
{
    bool skipLeadingZero = true;
    for (int i = result.size(); i > 0; --i)
    {
        if (!skipLeadingZero)
        {
            bool printSeparator = (i % 3) == 0;
            if (printSeparator)
                std::cout << ",";
        }

        int val = (int)result[i - 1];
        if (skipLeadingZero)
            skipLeadingZero = val == 0;

        if (skipLeadingZero)
            continue;

        std::cout << val;
    }
}