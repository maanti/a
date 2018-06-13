//

#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

struct Dir {
    map<string, Dir *> subDirs;
} dirs[40000];
int counter = 1;

Dir *addDir(Dir *dir, const string &str) {
    auto &d = dir->subDirs[str];
    if (!d) {
        d = &dirs[counter++];
    }
    return d;
}

void print(Dir *dir, int depth = 0) {
    for (auto s : dir->subDirs) {
        for (int i = 0; i < depth; i++) {
            cout << " ";
        }
        cout << s.first << "\n";
        print(s.second, depth + 1);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str, pathStr;
        cin >> str;
        stringstream ss(str);
        Dir *dir = &dirs[0];
        while (getline(ss, pathStr, '\\'))
            dir = addDir(dir, pathStr);
    }
    print(&dirs[0]);
}