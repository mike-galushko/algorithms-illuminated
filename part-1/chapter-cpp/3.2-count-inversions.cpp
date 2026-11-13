#include <iostream>
#include <vector>
#include "utils/numbers-file.h"
#include "utils/span.h"

int calculate(std::vector<char> &input) noexcept;
int count_inversions(Span &input, Span &buffer) noexcept;
void print_vector(std::vector<char> &data) noexcept;

int main(int argc, char *argv[])
{
    std::cout << "Calculate number of inversions by sort merge algorithm. " << std::endl;

    std::vector<char> input = read_numbers(argc, argv, "3.2-count-inversions.txt");
    if (input.size() > 0)
    {
        std::cout << "Original input: ";
        print_vector(input);

        int inversions = calculate(input);

        std::cout << std::endl
                  << "Sorted input: ";
        print_vector(input);
        std::cout << std::endl
                  << "Inversions count: "
                  << inversions
                  << std::endl;
    }

    return 0;
}

int calculate(std::vector<char> &input) noexcept
{
    std::vector<char> buffer(input.size());
    Span s_input(0, input.size(), input);
    Span s_buffer(0, buffer.size(), buffer);

    return count_inversions(s_input, s_buffer);
}

int count_inversions(Span &input, Span &buffer) noexcept
{
    int inversions = 0;
    if (input.Count == 1)
    {
        // Do nothing
    }
    else if (input.Count == 2)
    {
        // Only 2 elements
        if (input[0] > input[1])
        {
            char tmp = input[0];
            input.Set(input[1], 0);
            input.Set(tmp, 1);
            inversions = 1;
        }
    }
    else
    {
        // Split input into 2 halfs
        int left_count = input.Count / 2;
        int right_count = input.Count - left_count;
        Span left = Span(0, left_count, input);
        Span right = Span(left_count, right_count, input);
        Span left_buffer = Span(0, left_count, buffer);
        Span right_buffer = Span(left_count, right_count, buffer);

        // Calculate inversions for the halfs
        int inv_left = count_inversions(left, left_buffer);
        int inv_right = count_inversions(right, right_buffer);

        // Merge sort two subranges into the buffer
        // Calculate split inversions at the same time
        int split_inversions = 0;
        for (int i = 0, j = 0, k = 0; k < input.Count; k++)
        {
            if (i == left.Count)
            {
                buffer.Set(right[j], k);
                j++;
            }
            else if (j == right.Count)
            {
                buffer.Set(left[i], k);
                i++;
            }
            else if (left[i] <= right[j])
            {
                buffer.Set(left[i], k);
                i++;
            }
            else
            {
                buffer.Set(right[j], k);
                j++;
                split_inversions += left.Count - i;
            }
        }

        // Copy sorted buffer back to the input
        for (int i = 0; i < input.Count; i++)
        {
            input.Set(buffer[i], i);
        }

        // The final inversions count
        inversions = inv_left + inv_right + split_inversions;
    }

    return inversions;
}

void print_vector(std::vector<char> &data) noexcept
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << (int)data[i] << " ";
    }
}
