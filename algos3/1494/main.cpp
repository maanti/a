#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n, max_ball = 0, this_ball = NULL;
    stack<int> my_stack;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> this_ball;
        if (this_ball > max_ball) {
            for (int j = max_ball + 1; j < this_ball; ++j) {
                my_stack.push(j);
            }
        } else if (this_ball < max_ball) {
            if (my_stack.top() == this_ball) {
                my_stack.pop();
            } else {
                cout << "Cheater";
                return 0;
            }
        } else if (this_ball == max_ball) {
            cout << "Cheater";
            return 0;
        }
        if (this_ball > max_ball) {
            max_ball = this_ball;
        }
    }
    cout << "Not a proof";
}