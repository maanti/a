#include <iostream>

int main() {
    int     fighters,
            teams,
            testsNum,
            team_size,
            remainder,
            result = 0;
    std::cin >> testsNum;
    for (int i = 0; i < testsNum ; ++i) {
        std::cin >> fighters >> teams;
        team_size = fighters / teams;
        remainder = fighters % teams;

        for (int j = 0; j < remainder; ++j) {
            fighters -= team_size + 1;
            result += (team_size + 1) * fighters;
        }

        for (int l = 0; l < (teams - remainder) ; ++l) {
            fighters -= team_size;
            result += team_size * fighters;
        }
        std::cout << result << std::endl;
        result = 0;
    }
    return 0;
}