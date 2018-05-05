#include <iostream>

int main() {
    int n, maxFinal = 0, maxCurrent = 0;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        maxCurrent = std::max(0, maxCurrent + a[i]);
        if (maxCurrent != 0) {
            maxFinal = std::max(maxFinal, maxCurrent);
        }
    }
    std::cout << maxFinal;
    return 0;
}

