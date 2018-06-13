#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
int n,k;

void update_tree(int i, int count, int tree[], int size){
    for (i += size; i > 0; i /= 2)
        tree[i] += count;
}

int find_element(int x, int skip, int tree[], int size){
    while(x < size){
        x *= 2;
        if(skip > tree[x]){
            skip -= tree[x];
            x++;
        }
    }
    update_tree(x-size, -1, tree, size);
    return x-size;
}

int main(){
    cin >> n >> k;
    int size = (1b << static_cast<int>(log2(n - 1) + 1));
    int solders[2*size] = {};
    for (int i = 0; i < n; ++i)
        update_tree(i, 1, solders, size);
    int pos = k - 1;
    for (int i = 0; i <n; ++i)
    {
        cout << find_element(1, pos + 1, solders, size)  + 1 << " ";
        if (i < n - 1)
            pos = (pos + (k - 1)) % (n - 1 - i); //k-1
    }

}