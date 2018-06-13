#include <cstdio>
#include <vector>
#include <queue>

const int inf = -500*10000;

struct node
{
    std::vector<std::pair<int, int>> e;
    int d;
    int in;

    node() : in(0), d(inf) {}
};

node nodes[501];

int main()
{
    int N, M, S, F;
    scanf("%d %d", &N, &M);
    std::queue<node*> q;

    for(int i = 0; i < M; i++)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        nodes[x].e.emplace_back(y, c);
        nodes[y].in++;
    }
    scanf("%d %d", &S, &F);
    nodes[S].d = 0;

    for(int i = 1; i <= N; i++)
        if(nodes[i].in == 0)
            q.push(nodes + i);
    while(!q.empty())
    {
        auto nod = q.front();
        q.pop();
        for(auto it = nod->e.begin(); it < nod->e.end(); it++)
        {
            nodes[it->first].d = std::max(nodes[it->first].d, nod->d + it->second); // Relaxation
            nodes[it->first].in--;
            if(nodes[it->first].in == 0)
                q.push(nodes + it->first);
        }
    }
    if(nodes[F].d >= 0)
        printf("%d\n", nodes[F].d);
    else
        printf("No solution\n");
    return 0;
}