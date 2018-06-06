// Tiling Dominoes
// UVa ID: 11270
// Verdict: Accepted
// Submission Date: 2018-06-03
// UVa Run Time: 0.000s
//
// 版权所有（C）2018，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    long long r[482][3] = {
        {1, 1, 0}, {1, 2, 1}, {1, 3, 0}, {1, 4, 1}, {1, 5, 0}, {1, 6, 1}, {1, 7, 0}, {1, 8, 1}, {1, 9, 0}, {1, 10, 1}, 
        {1, 11, 0}, {1, 12, 1}, {1, 13, 0}, {1, 14, 1}, {1, 15, 0}, {1, 16, 1}, {1, 17, 0}, {1, 18, 1}, {1, 19, 0}, {1, 20, 1}, 
        {1, 21, 0}, {1, 22, 1}, {1, 23, 0}, {1, 24, 1}, {1, 25, 0}, {1, 26, 1}, {1, 27, 0}, {1, 28, 1}, {1, 29, 0}, {1, 30, 1}, 
        {1, 31, 0}, {1, 32, 1}, {1, 33, 0}, {1, 34, 1}, {1, 35, 0}, {1, 36, 1}, {1, 37, 0}, {1, 38, 1}, {1, 39, 0}, {1, 40, 1}, 
        {1, 41, 0}, {1, 42, 1}, {1, 43, 0}, {1, 44, 1}, {1, 45, 0}, {1, 46, 1}, {1, 47, 0}, {1, 48, 1}, {1, 49, 0}, {1, 50, 1}, 
        {1, 51, 0}, {1, 52, 1}, {1, 53, 0}, {1, 54, 1}, {1, 55, 0}, {1, 56, 1}, {1, 57, 0}, {1, 58, 1}, {1, 59, 0}, {1, 60, 1}, 
        {1, 61, 0}, {1, 62, 1}, {1, 63, 0}, {1, 64, 1}, {1, 65, 0}, {1, 66, 1}, {1, 67, 0}, {1, 68, 1}, {1, 69, 0}, {1, 70, 1}, 
        {1, 71, 0}, {1, 72, 1}, {1, 73, 0}, {1, 74, 1}, {1, 75, 0}, {1, 76, 1}, {1, 77, 0}, {1, 78, 1}, {1, 79, 0}, {1, 80, 1}, 
        {1, 81, 0}, {1, 82, 1}, {1, 83, 0}, {1, 84, 1}, {1, 85, 0}, {1, 86, 1}, {1, 87, 0}, {1, 88, 1}, {1, 89, 0}, {1, 90, 1}, 
        {1, 91, 0}, {1, 92, 1}, {1, 93, 0}, {1, 94, 1}, {1, 95, 0}, {1, 96, 1}, {1, 97, 0}, {1, 98, 1}, {1, 99, 0}, {1, 100, 1}, 
        {2, 1, 1}, {2, 2, 2}, {2, 3, 3}, {2, 4, 5}, {2, 5, 8}, {2, 6, 13}, {2, 7, 21}, {2, 8, 34}, {2, 9, 55}, {2, 10, 89}, 
        {2, 11, 144}, {2, 12, 233}, {2, 13, 377}, {2, 14, 610}, {2, 15, 987}, {2, 16, 1597}, {2, 17, 2584}, {2, 18, 4181}, {2, 19, 6765}, {2, 20, 10946}, 
        {2, 21, 17711}, {2, 22, 28657}, {2, 23, 46368}, {2, 24, 75025}, {2, 25, 121393}, {2, 26, 196418}, {2, 27, 317811}, {2, 28, 514229}, {2, 29, 832040}, {2, 30, 1346269}, 
        {2, 31, 2178309}, {2, 32, 3524578}, {2, 33, 5702887}, {2, 34, 9227465}, {2, 35, 14930352}, {2, 36, 24157817}, {2, 37, 39088169}, {2, 38, 63245986}, {2, 39, 102334155}, {2, 40, 165580141}, 
        {2, 41, 267914296}, {2, 42, 433494437}, {2, 43, 701408733}, {2, 44, 1134903170}, {2, 45, 1836311903}, {2, 46, 2971215073}, {2, 47, 4807526976}, {2, 48, 7778742049}, {2, 49, 12586269025}, {2, 50, 20365011074}, 
        {3, 1, 0}, {3, 2, 3}, {3, 3, 0}, {3, 4, 11}, {3, 5, 0}, {3, 6, 41}, {3, 7, 0}, {3, 8, 153}, {3, 9, 0}, {3, 10, 571}, 
        {3, 11, 0}, {3, 12, 2131}, {3, 13, 0}, {3, 14, 7953}, {3, 15, 0}, {3, 16, 29681}, {3, 17, 0}, {3, 18, 110771}, {3, 19, 0}, {3, 20, 413403}, 
        {3, 21, 0}, {3, 22, 1542841}, {3, 23, 0}, {3, 24, 5757961}, {3, 25, 0}, {3, 26, 21489003}, {3, 27, 0}, {3, 28, 80198051}, {3, 29, 0}, {3, 30, 299303201}, 
        {3, 31, 0}, {3, 32, 1117014753}, {3, 33, 0}, {4, 1, 1}, {4, 2, 5}, {4, 3, 11}, {4, 4, 36}, {4, 5, 95}, {4, 6, 281}, {4, 7, 781}, 
        {4, 8, 2245}, {4, 9, 6336}, {4, 10, 18061}, {4, 11, 51205}, {4, 12, 145601}, {4, 13, 413351}, {4, 14, 1174500}, {4, 15, 3335651}, {4, 16, 9475901}, {4, 17, 26915305}, 
        {4, 18, 76455961}, {4, 19, 217172736}, {4, 20, 616891945}, {4, 21, 1752296281}, {4, 22, 4977472781}, {4, 23, 14138673395}, {4, 24, 40161441636}, {4, 25, 114079985111}, {5, 1, 0}, {5, 2, 8}, 
        {5, 3, 0}, {5, 4, 95}, {5, 5, 0}, {5, 6, 1183}, {5, 7, 0}, {5, 8, 14824}, {5, 9, 0}, {5, 10, 185921}, {5, 11, 0}, {5, 12, 2332097}, 
        {5, 13, 0}, {5, 14, 29253160}, {5, 15, 0}, {5, 16, 366944287}, {5, 17, 0}, {5, 18, 4602858719}, {5, 19, 0}, {5, 20, 57737128904}, {6, 1, 1}, {6, 2, 13}, 
        {6, 3, 41}, {6, 4, 281}, {6, 5, 1183}, {6, 6, 6728}, {6, 7, 31529}, {6, 8, 167089}, {6, 9, 817991}, {6, 10, 4213133}, {6, 11, 21001799}, {6, 12, 106912793}, 
        {6, 13, 536948224}, {6, 14, 2720246633}, {6, 15, 13704300553}, {6, 16, 69289288909}, {7, 1, 0}, {7, 2, 21}, {7, 3, 0}, {7, 4, 781}, {7, 5, 0}, {7, 6, 31529}, 
        {7, 7, 0}, {7, 8, 1292697}, {7, 9, 0}, {7, 10, 53175517}, {7, 11, 0}, {7, 12, 2188978117}, {7, 13, 0}, {7, 14, 90124167441}, {8, 1, 1}, {8, 2, 34}, 
        {8, 3, 153}, {8, 4, 2245}, {8, 5, 14824}, {8, 6, 167089}, {8, 7, 1292697}, {8, 8, 12988816}, {8, 9, 108435745}, {8, 10, 1031151241}, {8, 11, 8940739824}, {8, 12, 82741005829}, 
        {9, 1, 0}, {9, 2, 55}, {9, 3, 0}, {9, 4, 6336}, {9, 5, 0}, {9, 6, 817991}, {9, 7, 0}, {9, 8, 108435745}, {9, 9, 0}, {9, 10, 14479521761}, 
        {9, 11, 0}, {10, 1, 1}, {10, 2, 89}, {10, 3, 571}, {10, 4, 18061}, {10, 5, 185921}, {10, 6, 4213133}, {10, 7, 53175517}, {10, 8, 1031151241}, {10, 9, 14479521761}, 
        {10, 10, 258584046368}, {11, 1, 0}, {11, 2, 144}, {11, 3, 0}, {11, 4, 51205}, {11, 5, 0}, {11, 6, 21001799}, {11, 7, 0}, {11, 8, 8940739824}, {11, 9, 0}, 
        {12, 1, 1}, {12, 2, 233}, {12, 3, 2131}, {12, 4, 145601}, {12, 5, 2332097}, {12, 6, 106912793}, {12, 7, 2188978117}, {12, 8, 82741005829}, {13, 1, 0}, {13, 2, 377}, 
        {13, 3, 0}, {13, 4, 413351}, {13, 5, 0}, {13, 6, 536948224}, {13, 7, 0}, {14, 1, 1}, {14, 2, 610}, {14, 3, 7953}, {14, 4, 1174500}, {14, 5, 29253160}, 
        {14, 6, 2720246633}, {14, 7, 90124167441}, {15, 1, 0}, {15, 2, 987}, {15, 3, 0}, {15, 4, 3335651}, {15, 5, 0}, {15, 6, 13704300553}, {16, 1, 1}, {16, 2, 1597}, 
        {16, 3, 29681}, {16, 4, 9475901}, {16, 5, 366944287}, {16, 6, 69289288909}, {17, 1, 0}, {17, 2, 2584}, {17, 3, 0}, {17, 4, 26915305}, {17, 5, 0}, {18, 1, 1}, 
        {18, 2, 4181}, {18, 3, 110771}, {18, 4, 76455961}, {18, 5, 4602858719}, {19, 1, 0}, {19, 2, 6765}, {19, 3, 0}, {19, 4, 217172736}, {19, 5, 0}, {20, 1, 1}, 
        {20, 2, 10946}, {20, 3, 413403}, {20, 4, 616891945}, {20, 5, 57737128904}, {21, 1, 0}, {21, 2, 17711}, {21, 3, 0}, {21, 4, 1752296281}, {22, 1, 1}, {22, 2, 28657}, 
        {22, 3, 1542841}, {22, 4, 4977472781}, {23, 1, 0}, {23, 2, 46368}, {23, 3, 0}, {23, 4, 14138673395}, {24, 1, 1}, {24, 2, 75025}, {24, 3, 5757961}, {24, 4, 40161441636}, 
        {25, 1, 0}, {25, 2, 121393}, {25, 3, 0}, {25, 4, 114079985111}, {26, 1, 1}, {26, 2, 196418}, {26, 3, 21489003}, {27, 1, 0}, {27, 2, 317811}, {27, 3, 0}, 
        {28, 1, 1}, {28, 2, 514229}, {28, 3, 80198051}, {29, 1, 0}, {29, 2, 832040}, {29, 3, 0}, {30, 1, 1}, {30, 2, 1346269}, {30, 3, 299303201}, {31, 1, 0}, 
        {31, 2, 2178309}, {31, 3, 0}, {32, 1, 1}, {32, 2, 3524578}, {32, 3, 1117014753}, {33, 1, 0}, {33, 2, 5702887}, {33, 3, 0}, {34, 1, 1}, {34, 2, 9227465}, 
        {35, 1, 0}, {35, 2, 14930352}, {36, 1, 1}, {36, 2, 24157817}, {37, 1, 0}, {37, 2, 39088169}, {38, 1, 1}, {38, 2, 63245986}, {39, 1, 0}, {39, 2, 102334155}, 
        {40, 1, 1}, {40, 2, 165580141}, {41, 1, 0}, {41, 2, 267914296}, {42, 1, 1}, {42, 2, 433494437}, {43, 1, 0}, {43, 2, 701408733}, {44, 1, 1}, {44, 2, 1134903170}, 
        {45, 1, 0}, {45, 2, 1836311903}, {46, 1, 1}, {46, 2, 2971215073}, {47, 1, 0}, {47, 2, 4807526976}, {48, 1, 1}, {48, 2, 7778742049}, {49, 1, 0}, {49, 2, 12586269025}, 
        {50, 1, 1}, {50, 2, 20365011074}, {51, 1, 0}, {52, 1, 1}, {53, 1, 0}, {54, 1, 1}, {55, 1, 0}, {56, 1, 1}, {57, 1, 0}, {58, 1, 1}, 
        {59, 1, 0}, {60, 1, 1}, {61, 1, 0}, {62, 1, 1}, {63, 1, 0}, {64, 1, 1}, {65, 1, 0}, {66, 1, 1}, {67, 1, 0}, {68, 1, 1}, 
        {69, 1, 0}, {70, 1, 1}, {71, 1, 0}, {72, 1, 1}, {73, 1, 0}, {74, 1, 1}, {75, 1, 0}, {76, 1, 1}, {77, 1, 0}, {78, 1, 1}, 
        {79, 1, 0}, {80, 1, 1}, {81, 1, 0}, {82, 1, 1}, {83, 1, 0}, {84, 1, 1}, {85, 1, 0}, {86, 1, 1}, {87, 1, 0}, {88, 1, 1}, 
        {89, 1, 0}, {90, 1, 1}, {91, 1, 0}, {92, 1, 1}, {93, 1, 0}, {94, 1, 1}, {95, 1, 0}, {96, 1, 1}, {97, 1, 0}, {98, 1, 1}, 
        {99, 1, 0}, {100, 1, 1}
    };
    
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < 482; i++)
            if (r[i][0] == n && r[i][1] == m)
            {
                cout << r[i][2] << '\n';
                break;
            }
    }

    return 0;
}