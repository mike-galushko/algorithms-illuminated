#include <iostream>
#include <string>
#include <vector>

std::vector<char> CreateInput(std::string text);
int SchoolAlgorithm(std::vector<char> &lhs, std::vector<char> &rhs);

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
    int result = SchoolAlgorithm(lhs, rhs);

    // Write output to console
    std::cout << lhsText << " * " << rhsText << " = " << result << "\n";
}

int SchoolAlgorithm(std::vector<char> &lhs, std::vector<char> &rhs)
{
    return 10;
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
