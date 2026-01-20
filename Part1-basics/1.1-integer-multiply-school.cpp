#include <iostream>

int SchoolAlgorithm(int lhs, int rhs);

// Школьный алгоритм умножения двух чисел
int main()
{
    int lhs, rhs = 0;

    std::cout << "Multiply to numbers. The school algorithm.\n";
    std::cout << "Enter first number: ";
    std::cin >> lhs;
    std::cout << "Enter second number: ";
    std::cin >> rhs;

    int result = SchoolAlgorithm(lhs, rhs);
    std::cout << lhs << " * " << rhs << " = " << result;
}

int SchoolAlgorithm(int lhs, int rhs)
{
    return 10;
}