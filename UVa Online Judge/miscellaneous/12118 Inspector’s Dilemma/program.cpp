// Inspector’s Dilemma
// UVa ID: 12118
// Verdict: 
// Submission Date: 
// UVa Run Time: s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> edges[1010];
int V, E, T, visited[1010];

int dfs(int u)
{
    visited[u] = 1;
    int oddDegreeVertices = (edges[u].size() & 1 ? 1 : 0);
    for (auto v : edges[u])
        if (edges[v].size() && !visited[v])
            oddDegreeVertices += dfs(v);
    return oddDegreeVertices;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases = 0;
    while (cin >> V >> E >> T)
    {
        if (V == 0) break;

        for (int i = 1; i <= V; i++)
            edges[i].clear();

        int a, b;
        for (int i = 1; i <= E; i++)
        {
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        
        memset(visited, 0, sizeof(visited));

        int additional = 0, components = 0;
        for (int i = 1; i <= V; i++)
            if (edges[i].size() && !visited[i])
            {
                components++;
                int oddDegreeVertices = dfs(i);
                additional += max(oddDegreeVertices - 2, 0) / 2;
            }

        cout << "Case " << ++cases << ": ";
        cout << T * ((components - 1) + E + additional) << '\n';
    }

    return 0;
}
