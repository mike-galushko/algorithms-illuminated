#include <iostream>
#include <fstream>
#include <vector>

std::vector<char> read_input(const char *name) noexcept;

int main()
{
    std::vector<char> input = read_input("1.4-merge-sort.txt");

    for (int i = 0; i < input.size(); i++)
        std::cout << input[i];

    return 0;
}

std::vector<char> read_input(const char *name) noexcept
{
    std::ifstream file(name, std::ios::binary | std::ios::ate);
    if (!file)
    {
        std::cerr << "Error opening input file " << name;
        return std::vector<char>(0);
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    file.read(buffer.data(), size);
    file.close();

    // Should be optimized by RVO
    return buffer;
}