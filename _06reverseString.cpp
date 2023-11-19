#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> S;
    string input;
    string output = "";


    cout << "Enter string : ";
    cin >> input;

    for (int i = 0; i < input.length(); ++i)
        S.push(input[i]);

    while (!S.empty())
    {
        output = output + S.top();
        S.pop();
    }
    
    cout << "Reverse string is : " << output << endl;

    return 0;
}