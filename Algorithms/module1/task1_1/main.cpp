//Найти, на сколько нулей оканчивается n! = 1 * 2 * 3 * ... * n.

#include <iostream>

int search_five(int n) {
    int num = 0;
    while (n % 5 == 0) {
        n = n / 5;
        num++;
    }
    return num;
}

int num_of_zero(int n) {
    int num = 0;
    for (int i = 1; i <= n; i++) {
        num += search_five(i);
    }
    return num;
}

int main() {
    int n = 0;

    std::cin >> n;

    std::cout << num_of_zero(n) << std::endl;
    return 0;
}
