#include <iostream>
#include <fstream>
#include <vector>
#include "utils/span.h"

void merge_sort(Span input, Span buffer) noexcept;
const char *get_file_name(int argc, char *argv[], const char *default_file) noexcept;
std::vector<char> read_input(const char *name) noexcept;

int main(int argc, char *argv[])
{
    const char *file = get_file_name(argc, argv, "1.4-merge-sort2.txt");
    std::vector<char> input = read_input(file);
    std::vector<char> buffer(input.size());

    Span s_input(0, input.size(), input);
    Span s_buffer(0, input.size(), buffer);
    merge_sort(s_input, s_buffer);
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input[i];
    }

    return 0;
}

void merge_sort(Span input, Span buffer) noexcept
{
    if (input.Count == 1)
    {
        // Do nothing if only 1 element
    }

    if (input.Count == 2)
    {
        // Sort 2 elements
        if (input[0] > input[1])
        {
            char temp = input[0];
            input.Set(input[1], 0);
            input.Set(temp, 1);
        }
    }
    else
    {
        // Divide and conquer

        // Split data into 2 partitions
        int left_count = input.Count / 2;
        int right_count = input.Count - left_count;

        Span left(0, left_count, input);
        Span right(left_count, right_count, input);
        Span left_buffer(0, left_count, buffer);
        Span right_buffer(left_count, right_count, buffer);

        // Calculate each partition recursively
        merge_sort(left, left_buffer);
        merge_sort(right, right_buffer);

        //  Merge calculated results into the buffer
        int i = 0;
        int j = 0;
        while (i + j < input.Count)
        {

            if (i >= left.Count)
            {
                // Only right elements left
                buffer.Set(right[j], i + j);
                j++;
            }
            else if (j >= right.Count)
            {
                // Only left elements left
                buffer.Set(left[i], i + j);
                i++;
            }
            else if (left[i] < right[j])
            {
                // Apply left element
                buffer.Set(left[i], i + j);
                i++;
            }
            else
            {
                // Apply right element
                buffer.Set(right[j], i + j);
                j++;
            }
        }

        // Copy result from the buffer
        for (int i = 0; i < input.Count; i++)
        {
            input.Set(buffer[i], i);
        }
    }
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