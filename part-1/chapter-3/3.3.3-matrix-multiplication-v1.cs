// Алгоритм умножения матриц
// Версия прямолинейная (brute-force)

Console.ForegroundColor = ConsoleColor.Cyan;
Console.WriteLine("Matrix multiplication. The brute-force version.");

var matrixA = new Matrix(5);
var matrixB = new Matrix(5);
for (int i = 0; i < matrixA.Dimension; i++)
{
    for (int j = 0; j < matrixB.Dimension; j++)
    {
        matrixA[i, j] = (i + 1) + (j + 1);
        matrixB[i, j] = (i + 1) * (j + 1);
    }
}
var result = Multiply(matrixA, matrixB);

DisplayMatrix(matrixA);
Console.WriteLine("x");
DisplayMatrix(matrixB);
Console.WriteLine("=");
DisplayMatrix(result);

Console.ResetColor();
Console.ForegroundColor = ConsoleColor.White;

Matrix Multiply(Matrix x, Matrix y)
{
    var z = new Matrix(x.Dimension);
    for (int i = 0; i < x.Dimension; i++)
    {
        for (int j = 0; j < y.Dimension; j++)
        {
            var dot = 0;
            for (int k = 0; k < x.Dimension; k++)
            {
                dot += x[i, k] + y[k, j];
            }
            z[i, j] = dot;
        }
    }
    return z;
}

void DisplayMatrix(Matrix val)
{
    for (int i = 0; i < val.Dimension; i++)
    {
        Console.Write("(");
        for (int j = 0; j < val.Dimension; j++)
        {
            Console.Write($" {val[i, j]} ");
        }
        Console.WriteLine(")");
    }
}

/// <summary>
/// Представление матрицы
/// </summary>
class Matrix
{
    private readonly int[] _data;
    private readonly int _dimension;

    public Matrix(int dimension)
    {
        _dimension = dimension;
        _data = new int[dimension * dimension];
    }

    public int this[int row, int col]
    {
        get { return _data[ToIndex(row, col)]; }
        set { _data[ToIndex(row, col)] = value; }
    }

    public int Dimension => _dimension;

    private int ToIndex(int row, int col) => (row * _dimension) + col;
}