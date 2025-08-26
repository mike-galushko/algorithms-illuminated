# Reading the book "Algorithms Illuminated"

Code examples are written on Python. To run an example:

```text
python <example-name>.py
```

## 1.2 Integers multiplication

An algorithm example: multiply to numbers.
You have:

- *input* - two numbers
- *output* - calculated number
- *algorithm* - a set of transformation rules

Distinguish two different things:

- problem being solved - input and output
- method of solution - algorithm

*Performance* - number of *primitive operations* as function of digit N in each input number.

School grade algorithm:

```text
    5678
  x 1234
--------
   22712
  17034
 11356
 5678
--------
 7006652
```

Performance:
One row performance is 2N. Number or rows is N. All rows performance is 2N^2. Add all rows is 2N^2. algorithm performance is 2N^2 + 2N^2 = 4N^2.

## 1.3 Karatsuba multiplication
