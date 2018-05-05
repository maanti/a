#include <iostream>
int findMinDiffRec(int a[], int n, int sumCalculated, int sum) {
    // Если достигли последнего элемента, вернуть абсолютную разность
    // первой суммы (sumCalculated) и второй суммы (sum - sumCalculated)
    if (n == 0) {
        return abs((sum - sumCalculated) - sumCalculated);
    }
    // для каждого элемента массива нужно сделать выбор:
    // включить его в первую группу или во вторую.
    // Возвращаем мимальное из двух решений
    return std::min(findMinDiffRec(a, n - 1, sumCalculated + a[n - 1], sum),
                    findMinDiffRec(a, n - 1, sumCalculated, sum));
}

int main() {
    int n, sum = 0;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }
    std::cout << findMinDiffRec(a, n, 0, sum);
}