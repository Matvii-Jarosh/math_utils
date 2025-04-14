/*
 * Copyright (C)2025 Matvii Jarosh
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#include <iostream>
#include <cmath>

// програма для знаходження дліни 3д лінії
int main(int argc, char *argv[])
{
    long double x1, x2, y1, y2, z1, z2;

    std::cin >> x1;
    std::cin >> y1;
    std::cin >> z1;

    std::cin >> x2;
    std::cin >> y2;
    std::cin >> z2;

    long double len_pow2 = pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2);

    long double result = sqrt(len_pow2);
    if (result == (long double)(int)result) // якщо вонр цілоє
        std::cout << result;
    else
        std::cout << "sqrt(" << len_pow2 <<")";
    return 0;
}
