// Алгоритм подсчета инверсий
// Версия divide-and-conquer
using Buffer = System.Memory<int>;

var str = "foo";
var strA = System.Text.Encoding.UTF8.GetBytes(str);

//var input = new[] { 1, 3, 5, 2, 4, 6 };
var input = new[] { 5, 4, 3, 2, 1 };
var (sorted, inversions) = SortAndCountInv(input);
DisplayInversions(input, inversions);

(Buffer, int) SortAndCountInv(Buffer input)
{
    if (input.Length == 0 || input.Length == 1)
    {
        return new(input, 0);
    }

    var mid = input.Length / 2;
    var left = input.Slice(0, mid);
    var right = input.Slice(mid, input.Length - mid);

    var (leftSorted, leftInv) = SortAndCountInv(left);
    var (rightSorted, rightInv) = SortAndCountInv(right);
    var merged = MergeAndCountSplitInv(leftSorted, rightSorted);
    var totalInv = leftInv + rightInv + merged.Item2;

    return (merged.Item1, totalInv);
}

(Buffer, int) MergeAndCountSplitInv(Buffer leftBuffer, Buffer rightBuffer)
{
    int i = 0, j = 0, k = 0, splitInv = 0;
    var left = leftBuffer.Span;
    var right = rightBuffer.Span;
    var temp = new int[left.Length + right.Length];
    var sorted = new Span<int>(temp);

    while (k < left.Length + right.Length)
    {
        if (i >= left.Length)
        {
            sorted[k] = right[j];
            j++;
        }
        else if (j >= right.Length)
        {
            sorted[k] = left[j];
            i++;
        }
        else if (left[i] < right[j])
        {
            sorted[k] = left[i];
            i++;
        }
        else
        {
            sorted[k] = right[j];
            j++;
            splitInv += left.Length - i;
        }
        k++;
    }

    return (new Memory<int>(temp), splitInv);
}

void DisplayInversions(int[] input, int inversions)
{
    Console.ForegroundColor = ConsoleColor.Cyan;
    Console.WriteLine("Count inversions. The brute-force version.");
    Console.WriteLine($"Input: {string.Join(", ", input)}");
    Console.WriteLine($"Result: {inversions}");
    Console.ResetColor();
}
