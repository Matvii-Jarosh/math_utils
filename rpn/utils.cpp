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
#include "utils.h"
#include <sstream>
#include <unordered_set>
#include <regex>

std::vector<std::string> tokenize(const std::string& input) {
    std::regex re(R"(([+\-*/^()]))");
    std::string spaced = std::regex_replace(input, re, " $1 ");

    std::vector<std::string> tokens;
    std::istringstream iss(spaced);
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

bool isNumber(std::string str) {
    std::regex number_regex(R"(^[0-9.]+$)");
    return std::regex_match(str, number_regex);
}

bool isFunction(const std::string& token) {
    static const std::unordered_set<std::string> functions = {
        "sin", "cos", "tg",
        "sqrt", "abs",
        "arcsin", "arccos", "arctg"
    };

    return functions.count(token) > 0;
}

bool isOperator(const std::string& token) {
    static const std::unordered_set<std::string> operators = {
        "+", "-", "*", "/", "^"
    };

    return operators.count(token) > 0;
}

int getPrecedence(const std::string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

bool isLeftAssociative(const std::string& op) {
    return op != "^";
}
