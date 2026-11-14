// Алгоритм подсчета инверсий
// Версия divide-and-conquer
using Buffer = System.Memory<int>;

Console.ForegroundColor = ConsoleColor.Cyan;
Console.WriteLine("Count inversions. The divide-and-conquer version.");
DisplayInversions(new[] { 1, 3, 5, 2, 4, 6 });
DisplayInversions(new[] { 5, 4, 3, 2, 1 });
DisplayInversions(new[] { 1, 2, 3, 4 });
Console.ResetColor();

Result SortAndCountInv(Buffer input)
{
    if (input.Length == 0 || input.Length == 1)
    {
        return new(input, 0);
    }

    var mid = input.Length / 2;
    var left = input.Slice(0, mid);
    var right = input.Slice(mid, input.Length - mid);

    var leftSorted = SortAndCountInv(left);
    var rightSorted = SortAndCountInv(right);
    var merged = MergeAndCountSplitInv(leftSorted.Buffer, rightSorted.Buffer);
    var totalInv = leftSorted.Inversions + rightSorted.Inversions + merged.Inversions;

    return new Result(merged.Buffer, totalInv);
}

Result MergeAndCountSplitInv(Buffer leftBuffer, Buffer rightBuffer)
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
            sorted[k] = left[i];
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

    return new Result(temp, splitInv);
}

void DisplayInversions(int[] input)
{
    var (sorted, inversions) = SortAndCountInv(input);
    var seq = string.Join(", ", input);
    Console.WriteLine($"Sequence [{seq}] contains {inversions} inversions");
}

record Result(Buffer Buffer, int Inversions);