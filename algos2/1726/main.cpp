/*Сортируем координаты по X.
 * Путей из i дома i*(n-i),
 * расстояние до других домов X = |х.i - x.i+1|,
 * общий путь sum = i*(n-i)*Х.
 * Сортируем координаты по У. Аналогично находим общий путь.
 * Складываем общие пути.
 * Находим среднее делением общего пути на количество дорог sum/(n*(n-1)/2).*/

#include <iostream>
using namespace std;

struct Coord {
    long long x;
    long long y;
};

int compareX(const void *coord1, const void *coord2) {
    if ((((struct Coord *)coord1)->x - ((struct Coord *)coord2)->x) < 0){
        return 1;
    }
    if ((((struct Coord *)coord1)->x - ((struct Coord *)coord2)->x) > 0){
        return -1;
    }
    return 0;
}

int compareY(const void *coord1, const void *coord2) {
    if ((((struct Coord *)coord1)->y - ((struct Coord *)coord2)->y) < 0){
        return 1;
    }
    if ((((struct Coord *)coord1)->y - ((struct Coord *)coord2)->y) > 0){
        return -1;
    }
    return 0;
}

int main() {
    long long n, sum = 0;

    cin >> n;

    auto * coordinates = new Coord[n];

    for (int i = 0; i < n; ++i) {
        cin >> coordinates[i].x >> coordinates[i].y;
    }

    qsort(coordinates, n, sizeof(Coord), compareX);
    for (int j = 1; j < n; ++j) {
        sum += j * (n - j) * (coordinates[j-1].x - coordinates[j].x);
    }

    qsort(coordinates, n, sizeof(Coord), compareY);
    for (int k = 1; k < n; ++k) {
        sum += k * (n - k) * (coordinates[k-1].y - coordinates[k].y);
    }
    delete(coordinates);
    sum /= (n * (n-1) / 2);

    cout << sum;
    return 0;
}