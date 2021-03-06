// Prim, Prim
// UVa ID: 10807
// Verdict: Accepted
// Submission Date: 2018-04-25
// UVa Run Time: 1.100s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 12, MAXE = 32, INF = 0x3f3f3f3f;

struct edge {
    int from, to, weight, used;
    edge (int from = 0, int to = 0, int weight = 0, int used = 0): from(from), to(to), weight(weight), used(used) {}
    bool operator<(const edge& x) const { return weight < x.weight; }
};

edge edges[MAXE];
int parent[MAXV], ranks[MAXV], parent1[MAXV], ranks1[MAXV], n, m;
int minimumCost;

void makeSet()
{
    for (int i = 0; i <= n; i++) parent[i] = i, ranks[i] = 0;
}

int findSet(int x)
{
    return (parent[x] == x ? x : parent[x] = findSet(parent[x]));
}

bool isConnected(int x, int y)
{
    return findSet(x) == findSet(y);
}

bool unionSet(int x, int y)
{
    x = findSet(x), y = findSet(y);
    if (x != y) {
        if (ranks[x] > ranks[y]) parent[y] = x;
        else {
            parent[x] = y;
            if (ranks[x] == ranks[y]) ranks[y]++;
        }
        return true;
    }
    return false;
}

int kruskal()
{
    int weight = 0, merged = 0;
    // Backup.
    for (int i = 0; i <= n; i++) parent1[i] = parent[i], ranks1[i] = ranks[i];
    makeSet();
    for (int i = 0; i < m; i++)
        if (!edges[i].used && unionSet(edges[i].from, edges[i].to))
        {
            weight += edges[i].weight;
            merged++;
        }
    // Restore.
    for (int i = 0; i <= n; i++) parent[i] = parent1[i], ranks[i] = ranks1[i];
    if (merged == n - 1) return weight;
    else return INF;
}

void dfs(int idx, int depth, int weight)
{
    if (idx == m) return;
    if (weight > minimumCost) return;
    if (depth == n - 1)
    {
        int A = kruskal();
        if (A != INF) minimumCost = min(minimumCost, weight + A);
        return;
    }

    if (!isConnected(edges[idx].from, edges[idx].to))
    {  
        // Backup.
        edges[idx].used = 1;
        int tParent[MAXV], tRanks[MAXV];
        memcpy(tParent, parent, sizeof(parent));
        memcpy(tRanks, ranks, sizeof(ranks));

        // Change.
        unionSet(edges[idx].from, edges[idx].to);
        dfs(idx + 1, depth + 1, weight + edges[idx].weight);

        // Restore.
        memcpy(parent, tParent, sizeof(tParent));
        memcpy(ranks, tRanks, sizeof(tRanks));
        edges[idx].used = 0;
    }
    dfs(idx + 1, depth, weight);
}

int main(int argc, char *argv[])
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    int from, to, weight;
    while (cin >> n, n)
    {
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> from >> to >> weight;
            edges[i] = edge(from, to, weight, 0);
        }

        sort(edges, edges + m);
        minimumCost = INF;
        makeSet();
        dfs(0, 0, 0);
        
        if (minimumCost == INF) cout << "No way!\n";
        else cout << minimumCost << '\n';
    }
    
    return 0;
}
