#include <iostream>
#include <fstream>
#include <vector>

void merge_sort(std::vector<char> input) noexcept;
const char *get_file_name(int argc, char *argv[], const char *default_file) noexcept;
std::vector<char> read_input(const char *name) noexcept;

int main(int argc, char *argv[])
{
    const char *file = get_file_name(argc, argv, "1.4-merge-sort.txt");
    std::vector<char> input = read_input(file);

    merge_sort(input);
    for (int i = 0; i < input.size(); i++)
        std::cout << input[i];

    return 0;
}

void merge_sort(std::vector<char> input) noexcept
{
}

const char *get_file_name(int argc, char *argv[], const char *default_file) noexcept
{
    if (argc != 2)
        return default_file;

    if (!argv[2])
        return default_file;

    return argv[2];
}

std::vector<char> read_input(const char *file_name) noexcept
{
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    if (!file.good())
    {
        std::cerr << "Cannot find file: " << file_name;
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