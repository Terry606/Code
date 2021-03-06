#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    vector < int > numbers;
    for (int i = 1; i <= 10; i++)
        numbers.push_back(i);
        
    auto it = upper_bound(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end())
    {
        for (int i = it - numbers.begin(); i < numbers.size(); i++)
            cout << numbers[i] << " ";
        cout << endl;
    }
    
    it = upper_bound(numbers.begin(), numbers.end(), 20);
    if (it == numbers.end())
        cout << "I have searched to the end but found none." << endl;
    
    return 0;
}
