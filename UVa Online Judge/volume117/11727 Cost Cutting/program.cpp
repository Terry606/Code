// Cost Cutting
// UVa ID: 11727
// Verdict: Accepted
// Submission Date: 2017-10-05
// UVa Run Time: 0.000s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases = 0, salary[3];

    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cin >> salary[0] >> salary[1] >> salary[2];
        sort(salary, salary + 3);
        cout << "Case " << c << ": " << salary[1] << '\n';
    }
    
    return 0;
}
