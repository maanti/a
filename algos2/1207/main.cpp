/*
 * Находим точку с минимальной абсциссой,
 * принимаем её за центр координат в полярной системе.
 * В полярной системе координат точка однозначно определяется полярным углом
 * и полярным радиусом.
 * В контексте данной задачи нас интересуют только углы.
 * Найдем тангенсы углов для каждой точки относительно нового начала координат.
 * Сортируем тангенсы. Выбираем средний. */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
struct Point {
    int id;
    long x;
    long y;
    double angle;
};

int compare(const void* x1, const void* x2){
    double result = ((Point*)x1)->angle - ((Point*)x2)->angle;
    if (result < 0){
        return -1;
    } else if (result == 0){
        return 0;
    } else {
        return 1;
    }
}

int main() {
    size_t n;
    long yMin, xMin;
    int indexMin;
    std::cin >> n;

    Point points[10000];

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
        points[i].id = i;
        if(i == 0){
            yMin = points[i].y;
            xMin = points[i].x;
            indexMin = i;
        }
        if (points[i].x < xMin){
            indexMin = i;
            yMin = points[i].y;
            xMin = points[i].x;
        }
    }

    for (int j = 0; j < n; ++j) {
        if(points[j].x != xMin) {
            points[j].angle = (double)(points[j].y - yMin) / (double)(points[j].x - xMin);
        } else if (points[j].y != yMin) {
            if(points[j].y > 0)
                points[j].angle = INFINITY;
            else
                points[j].angle = -INFINITY;
        }
    }

    for(int k = indexMin; k < n-1; k++){
        points[k] = points[k+1];
    }

    std::qsort(points, n-1, sizeof(Point), compare);
    if(indexMin > points[(n-1)/2].id){
        std::cout << points[(n-1)/2].id + 1 << " " << indexMin + 1;
    } else {
        std::cout << indexMin + 1 << " " << points[(n) / 2 - 1].id + 1;
    }
    return 0;
}