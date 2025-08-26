inputA = 5678
inputB = 1234
output = 7006652

def MultiplyNumberByDigit (number, digit):
    total = 0
    shift = 1
    for x in number:
        sub = digit * x
        total = total + sub * shift
        shift = shift * 10
    return total

def SchoolGradeMultiplication (left, right):
    total = 0
    shift = 1
    for x in right:
        row = MultiplyNumberByDigit(left, x)
        total = total + row * shift
        shift = shift * 10
    return total

def NumberToArray(value):
    chars = str(value)
    numbers = list(map(int, chars))
    return list(reversed(numbers))

x = NumberToArray(inputA)
y = NumberToArray(inputB)
z = SchoolGradeMultiplication(x, y)
print (z)