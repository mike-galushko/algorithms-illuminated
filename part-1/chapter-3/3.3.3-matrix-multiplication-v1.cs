// Алгоритм умножения матриц
// Версия прямолинейная (brute-force)

using System.Runtime.Intrinsics.X86;

var dataFnkList = new[]
{
     GetTestData_1,
     GetTestData_2,
     GetTestData_3,
     GetTestData_4,
     GetTestData_5,
     GetTestData_6,
};

Console.ForegroundColor = ConsoleColor.Cyan;
Console.WriteLine("Matrix multiplication. The brute-force version.");
Console.WriteLine();
foreach (var fnk in dataFnkList)
{
    var (matrixA, matrixB, matrixC) = fnk();
    var result = Multiply(matrixA, matrixB);

    Display(matrixA, matrixB, result, matrixC);
}
Console.ResetColor();
Console.ForegroundColor = ConsoleColor.White;


/// <summary>
/// The brute-force algorithm
/// </summary>
Matrix Multiply(Matrix x, Matrix y)
{
    var z = new Matrix(x.Rows, y.Cols);
    for (int row = 0; row < x.Rows; row++)
    {
        for (int col = 0; col < y.Cols; col++)
        {
            var dot = 0;
            for (int k = 0; k < x.Cols; k++)
            {
                dot += x[row, k] * y[k, col];
            }
            z[row, col] = dot;
        }
    }
    return z;
}

void Display(Matrix a, Matrix b, Matrix result, Matrix expected)
{
    DisplayMatrix(a);
    Console.WriteLine("x");
    DisplayMatrix(b);
    Console.WriteLine("=");
    DisplayMatrix(result);
    Console.WriteLine("Expected:");
    DisplayMatrix(expected);
    Console.WriteLine("----------------------");
}

void DisplayMatrix(Matrix val)
{
    for (int row = 0; row < val.Rows; row++)
    {
        Console.Write("(");
        for (int col = 0; col < val.Cols; col++)
        {
            Console.Write($" {val[row, col]} ");
        }
        Console.Write(")");
        Console.WriteLine();
    }
}

(Matrix, Matrix, Matrix) GetTestData_1() =>
(
    new Matrix([[1, 2, 3], [4, 5, 6]]),
    new Matrix([[7, 8], [9, 10], [11, 12]]),
    new Matrix([[58, 64], [139, 154]])
);

(Matrix, Matrix, Matrix) GetTestData_2() =>
(
    new Matrix([[-2, 3, -1], [0, -4, 5]]),
    new Matrix([[1, -2], [-3, 0], [4, -1]]),
    new Matrix([[-15, 5], [32, -5]])
);

(Matrix, Matrix, Matrix) GetTestData_3() =>
(
    new Matrix([[1, 2], [3, 4]]),
    new Matrix([[1, 0], [0, 1]]),
    new Matrix([[1, 2], [3, 4]])
);

(Matrix, Matrix, Matrix) GetTestData_4() =>
(
    new Matrix([[1, 2], [3, 4]]),
    new Matrix([[0, 0], [0, 0]]),
    new Matrix([[0, 0], [0, 0]])
);

(Matrix, Matrix, Matrix) GetTestData_5() =>
(
    new Matrix([[6]]),
    new Matrix([[-7]]),
    new Matrix([[-42]])
);

(Matrix, Matrix, Matrix) GetTestData_6() =>
(
    new Matrix([[2, 4, 6]]),
    new Matrix([[1], [2], [3]]),
    new Matrix([[28]])
);

/// <summary>
/// Представление матрицы
/// </summary>
class Matrix
{
    private readonly int[] _data;
    public int Rows { get; private set; }
    public int Cols { get; private set; }

    public Matrix(int rows, int cols)
    {
        Rows = rows;
        Cols = cols;
        _data = new int[rows * cols];
    }

    public Matrix(int[][] rows)
    {
        Rows = rows.Length;
        Cols = rows[0].Length;

        _data = new int[Rows * Cols];
        for (int row = 0; row < Rows; row++)
        {
            var columns = rows[row];
            for (int col = 0; col < Cols; col++)
            {
                _data[ToIndex(row, col)] = columns[col];
            }
        }
    }

    public int this[int row, int col]
    {
        get { return _data[ToIndex(row, col)]; }
        set { _data[ToIndex(row, col)] = value; }
    }

    private int ToIndex(int row, int col) => (row * Cols) + col;
}
