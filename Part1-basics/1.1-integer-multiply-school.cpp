#include <iostream>
#include <string>
#include <vector>

std::vector<char> CreateInput(std::string text);
std::vector<char> SchoolAlgorithm(std::vector<char> &lhs, std::vector<char> &rhs);

// Школьный алгоритм умножения двух чисел
int main()
{
    // Read input from console
    std::string lhsText;
    std::string rhsText;

    std::cout << "Multiply to numbers. The school algorithm.\n";
    std::cout << "Enter first number: ";
    std::cin >> lhsText;
    std::cout << "Enter second number: ";
    std::cin >> rhsText;

    // Run algorithm
    std::vector<char> lhs = CreateInput(lhsText);
    std::vector<char> rhs = CreateInput(rhsText);
    std::vector<char> result = SchoolAlgorithm(lhs, rhs);

    // Write output to console
    std::cout << lhsText << " * " << rhsText << " = ";
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << (int)result[i];
    }
    std::cout << "\n";
}

std::vector<char> SchoolAlgorithm(std::vector<char> &lhs, std::vector<char> &rhs)
{
    // Allocate memory for the resulting value
    int maxSize = (lhs.size() + 1) + (rhs.size() - 1);
    std::vector<char> result(maxSize);

    // For each digit in RHS
    for (int digitPos = 0; digitPos < rhs.size(); ++digitPos)
    {
        char digit = rhs[digitPos];
    }

    return result;
}

// Convert input text to numbers array
std::vector<char> CreateInput(std::string text)
{
    std::vector<char> result(text.length());
    for (int i = 0; i < text.length(); ++i)
    {
        char val = text[i];
        result[i] = val - '0';
    }
    return result;
}
