// Pig-Latin
// UVa ID: 492
// Verdict: 
// Submission Date: 
// UVa Run Time: s
//
// 版权所有（C）2016，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);

    cin.unsetf(ios::skipws);
    char input;
    string block;
    
    while (cin >> input)
    {
        if (isalpha(input))
            block += input;
        else
        {
            if (block.length() > 0)
            {
                char vowel = tolower(block.front());
                if (vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u')
                    cout << block << "ay";
                else
                {
                    char front = block.front();
                    block.erase(block.begin());
                    cout << block << front << "ay";
                }
            }
            cout << input;
            block.clear();
        }
    }
    
	return 0;
}
