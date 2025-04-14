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
#include "shunting_yard.h"
#include "utils.h"

std::string shuntingYard(const std::vector<std::string>& tokens) {
    const std::string space = " ";
    std::vector<std::string> stack;
    std::string output;

    for (const auto& token : tokens) {
        //std::cout << "[" + token + "]";
        if (isNumber(token)) {
            output += token + space;
        }
        else if (isFunction(token)) {
            stack.push_back(token);
        }
        else if (isOperator(token)) {
            while (!stack.empty() && (
                       (isOperator(stack.back()) && (
                            (token != "^" && getPrecedence(token) <= getPrecedence(stack.back())) ||
                            (token != "^" && getPrecedence(token) < getPrecedence(stack.back()))
                            )) || isFunction(stack.back()))) {
                output += stack.back() + space;
                stack.pop_back();
            }
            stack.push_back(token);
        }
        else if (token == "(") {
            stack.push_back(token);
        }
        else if (token == ")") {
            while (!stack.empty() && stack.back() != "(") {
                output += stack.back() + space;
                stack.pop_back();
            }
            if (stack.empty()) return "Error: Mismatched parentheses!";
            stack.pop_back();
            if (!stack.empty() && isFunction(stack.back())) {
                output += stack.back() + space;
                stack.pop_back();
            }
        } else if (token == "pi" || token == "e" || token == "x") {
            output += token + space;
        }
        else {
            return "Error: Invalid token: " + token;
        }
    }

    while (!stack.empty()) {
        if (stack.back() == "(" || stack.back() == ")") {
            return "Error: Mismatched parentheses!";
        }
        output += stack.back() + space;
        stack.pop_back();
    }

    return output;
}
