// Алгоритм подсчета инверсий
// Версия brute-force

var input = new[] { 1, 3, 5, 2, 4, 6 };

Console.ForegroundColor = ConsoleColor.Cyan;
Console.WriteLine("Count inversions. The brute-force version.");
Console.WriteLine($"Input: {string.Join(", ", input)}");
var inversions = CountInversions(input);
Console.WriteLine($"Result: {inversions}");
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
