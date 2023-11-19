#include <iostream>
#include <string>
#include <stack>

using namespace std;

string convert2binary(int n)
{
    stack<int> S;
    int bit;
    string result = "";

    while (n>0)
    {
        bit = n % 2;
        S.push(bit);
        n = n / 2;
    }

    int num;

    while (!S.empty())
    {
        result = result + to_string(S.top());
        S.pop();
    }

    return result;
}

string convert2oct(int n)
{
    stack<int> S;
    int oct;
    string result = "";

    while (n>0)
    {
        oct = n % 8;
        S.push(oct);
        n = n / 8;
    }

    while (!S.empty())
    {
        result = result + to_string(S.top());
        S.pop();
    }

    return result;
}

string convert2hex(int n)
{
    stack<int> S;
    int hex;
    string result = "";
    char table[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    while (n>0)
    {
        hex = n % 16;
        S.push(hex);
        n = n / 16;
    }

    while (!S.empty())
    {
        if(S.top()<10)
            result = result + to_string(S.top());
        else
            result = result + table[S.top() - 10];

        S.pop();
    }

    return result;
}

int main()
{
    int n;
    string s;

    cout << "Enter bumber to convert : ";
    cin >> n;
    cout << "Number in binary is : "<< convert2binary(n) << endl;
    cout << "Number in oct is : "<< convert2oct(n) << endl;
    cout << "Number in hex is : "<< convert2hex(n) << endl;

    return 0;
}