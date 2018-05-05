/* Отсортируем знаки по убыванию их количества.
 * В цикле работаем на каждой итерации с первыми двумя элементами отсортированного массива.
 * Храним сумму всех элементов, пока она больше нуля, действуем следующим образом:
 * Выводим значение скорости на самом частом знаке
 * После каждого вывода уменьшаем счетчик и пересортировываем, если необходимо
 * Если сумма == количеству знаков в первом элементе массива,
 * то в массиве остался только первый элемент. Выводим его оставшееся число раз.*/

#include <iostream>
using namespace std;
struct Sign{
    int speed;
    int count;
};
int compare(const void* x1, const void* x2){
    return -((Sign*)x1)->count + ((Sign*)x2)->count;
}

int main() {
    size_t k;
    Sign signs[10000];
    int sum = 0;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        cin >> signs[i].count;
        sum += signs[i].count;
        signs[i].speed = i + 1;
    }

    qsort(signs, k, sizeof(Sign), compare);

    while (sum > 0) {
        cout << signs[0].speed << " ";
        signs[0].count--;
        sum--;

        if(signs[0].count < signs[1].count) {
            qsort(signs, k, sizeof(Sign), compare);
            continue;
        }

        if (sum == signs[0].count) {
            break;
        }

        cout << signs[1].speed << " ";
        signs[1].count--;
        sum --;

        qsort(signs, k, sizeof(Sign), compare);
    }

    while(signs[0].count > 0) {
        cout << signs[0].speed << " ";
        signs[0].count--;
    }

    return 0;
}