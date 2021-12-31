#include <bits/stdc++.h>
#include <string>
using namespace std;
void keypad(int, string, vector<string>);

void printKeypad(int num)
{
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    vector<string> temp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string output;

    keypad(num, output, temp);
}
void keypad(int num, string output, vector<string> temp)
{

    if (num == 0)
    {
        cout << output << endl;
    }

    int last = num % 10;

    for (int i = 0; i < temp[last].size(); i++)
    {

        keypad(num / 10, temp[last][i] + output, temp);
    }
}