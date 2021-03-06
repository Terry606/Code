// Last Man Standing
// UVa ID: 11351
// Verdict: Accepted
// Submission Date: 2017-12-23
// UVa Run Time: 0.030s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases, n, k;
    
    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cin >> n >> k;
        int last = 0;
        for (int i = 1; i <= n; i++)
            last = (last + k) % i;
        cout << "Case " << c << ": " << (last + 1) << '\n';
    }

    return 0;
}
