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
#include "rpn.h"
#include "utils.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

double long rpn(const std::vector<std::string>& tokens) {
    std::vector<long double> stack;
    for (const auto& token : tokens) {
        if (isNumber(token)) {
            stack.push_back(std::stold(token));
        } else if (isFunction(token)) {
            if (stack.empty()) throw std::runtime_error("Stack underflow on function");
            long double val = stack.back();
            stack.pop_back();
            if (token == "sin") stack.push_back(sinl(val));
            else if (token == "cos") stack.push_back(cosl(val));
            else if (token == "tg") stack.push_back(tanl(val));
            else if (token == "arcsin") stack.push_back(asinl(val));
            else if (token == "arccos") stack.push_back(acosl(val));
            else if (token == "arctg") stack.push_back(atanl(val));
            else if (token == "abs") stack.push_back(fabsl(val));
            else if (token == "sqrt") stack.push_back(sqrtl(val));
            else throw std::runtime_error("Unknown function: " + token);
        } else if (isOperator(token)) {
            if (stack.size() < 2) throw std::runtime_error("Stack underflow on operator");
            long double val2 = stack.back();
            stack.pop_back();
            long double val1 = stack.back();
            stack.pop_back();

            if (token == "+") {
                stack.push_back(val1 + val2);
            } else if (token == "-") {
                stack.push_back(val1 - val2);
            } else if (token == "*") {
                stack.push_back(val1 * val2);
            } else if (token == "/") {
                stack.push_back(val1 / val2);
            } else if (token == "^") {
                stack.push_back(pow(val1, val2));
            }
        } else if (token == "pi") {
            stack.push_back(M_PI);
        } else if (token == "e") {
            stack.push_back(M_E);
        } else {
            throw std::runtime_error("Unknown token: " + token);
        }

        /*std::cout << "stack: [";
        for (auto i : stack) {
            std::cout << i << " ";
        }
        std::cout << "], token: " << token;
        std::cout << std::endl;*/

    }

    if (stack.size() < 1)
        throw std::runtime_error("Invalid RPN expression");
    return stack.back();
}
