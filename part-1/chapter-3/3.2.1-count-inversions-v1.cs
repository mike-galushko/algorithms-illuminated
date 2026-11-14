// Алгоритм подсчета инверсий
// Версия brute-force

Console.ForegroundColor = ConsoleColor.Cyan;
Console.WriteLine("Count inversions. The brute-force version.");
DisplayInversions(new[] { 1, 3, 5, 2, 4, 6 });
DisplayInversions(new[] { 5, 4, 3, 2, 1 });
DisplayInversions(new[] { 1, 2, 3, 4 });
Console.ResetColor();

int CountInversions(int[] input)
{
    int count = 0;
    for (int i = 0; i < input.Length - 1; i++)
    {
        for (int j = i + 1; j < input.Length; j++)
        {
            if (input[i] > input[j])
            {
                count++;
            }
        }
    }
    return count;
}

void DisplayInversions(int[] input)
{
    var inversions = CountInversions(input);
    var seq = string.Join(", ", input);
    Console.WriteLine($"Sequence [{seq}] contains {inversions} inversions");
}