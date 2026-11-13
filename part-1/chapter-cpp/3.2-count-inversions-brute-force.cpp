#include <iostream>
#include <vector>
#include "utils/numbers-file.h"

int count_inversions(std::vector<char> &input) noexcept;

int main(int argc, char *argv[])
{
    std::cout << "Calculate number of inversions. " << "The Brute-force method." << std::endl;

    std::vector<char> input = read_numbers(argc, argv, "3.2-count-inversions.txt");
    if (input.size() > 0)
    {
        int inversions = count_inversions(input);
        std::cout << "Inversions count: " << inversions << std::endl;
    }

    return 0;
}

int count_inversions(std::vector<char> &input) noexcept
{
    int result = 0;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = i + 1; j < input.size(); j++)
        {
            if (input[i] > input[j])
                ++result;
        }
    }
    return result;
}
