#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <vector>
#include<list>

using namespace std;

vector<int> A, B;
int del = 1;

/// <summary>
/// Вычисление НОД 3 чисел, если он равен 1, то общий делитель едиснтвенный 1
/// </summary>
/// <param name="one">число массива A</param>
/// <param name="two">число массива B</param>
/// <param name="three">индекс</param>
/// <returns>НОД</returns>
int Nod(int one, int two, int three) {
    for (int i = 1; i <= one; i++) {
        if (one % i == 0 && two % i == 0 && three % i == 0) {
            del = i;
        }
    }
    return del;
}

int main() {
    int threadsCount;
    int n = 1000 + rand();
    cin >> threadsCount;

    //Заполнение массивов
    for (size_t i = 0; i < n; i++) {

        A.push_back(1 + rand() % 1000000);
        B.push_back(1 + rand() % 1000000);
    }

    vector<char> flag(n, 0);

#pragma omp parallel for num_threads(threadsCount)
    for (int i = 0; i < n; i++) {
        if (Nod(A[i], B[i], i) == 1)
            flag[i] = i;
    }

    //Выведем результат
    for (int i = 0; i < flag.size(); i++) {
        if (flag[i])
            cout << i << " ";
    }

    return 0;
}