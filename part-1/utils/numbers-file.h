#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

std::vector<char> read_file(const char *relative_path) noexcept
{
    std::string work_dir = std::filesystem::current_path().string();
    std::string full_path = work_dir + "/" + relative_path;

    std::ifstream file(full_path, std::ios::binary | std::ios::ate);
    if (!file.good())
    {
        std::cerr << "Cannot find file: " << full_path;
        return std::vector<char>(0);
    }

    file.seekg(0, std::ios::beg);

    std::vector<char> result;
    int number;
    while (!file.eof())
    {
        file >> number;
        if (number > 0)
        {
            result.push_back(number);
        }
    }
    file.close();

    // Should be optimized by RVO
    return result;
}

const char *get_file_name(int argc, char *argv[], const char *default_file) noexcept
{
    if (argc <= 2)
        return default_file;

    if (!argv[2])
        return default_file;

    return argv[2];
}

std::vector<char> read_numbers(int argc, char *argv[], const char *default_file) noexcept
{
    const char *file = get_file_name(argc, argv, default_file);
    return read_file(file);
}