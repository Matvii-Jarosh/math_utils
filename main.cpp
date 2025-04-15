#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
    long double x1, x2, y1, y2;

    std::cin >> x1;
    std::cin >> y1;

    std::cin >> x2;
    std::cin >> y2;

    std::cout << (x1 + x2) / 2;
    std::cout << (y1 + y2) / 2;

    return 0;
}
