/*
 * ​Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. Найти количество
таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
n, m ≤ 100000.
Указание. Обходите массив B от конца к началу.
4
­5 0 3 18
5
­10 ­2 4 7 12
7

3
 */

#include <iostream>

using namespace std;

int search_pair(int *array1, int n, int *array2, int m, int k) {

    int res = 0;

    for (int j = m - 1, i = 0; j >= 0 && i < n;) {
        if (array1[i] + array2[j] == k) {
            res++;
            i++;
        } else if (array1[i] + array2[j] > k) {
            j--;
        } else i++;
    }
    return res;
}

int main() {
    int n = 0;
    std::cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int m = 0;
    std::cin >> m;

    int *B = new int[m];
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }

    int k;
    std::cin >> k;

    std::cout << search_pair(A, n, B, m, k) << std::endl;

    delete[] A;
    delete[] B;
    return 0;
}