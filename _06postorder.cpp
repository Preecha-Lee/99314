#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool isOperator(char c)
{
    char oper[7] = {'+','-','*','/','^'};

    for (int i = 0; i < 5; ++i)
    {
        if(c==oper[i])
            return true;
    }

    return false;
}

int ordOperator(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return 0;
}


string postOrder(string s)
{
    stack<char> S;
    string result = "";

    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i]=='(')
            S.push(s[i]);
        else if(isOperator(s[i]))
        {
            if(S.empty() || ordOperator(s[i])>ordOperator(S.top()))
                S.push(s[i]);
            else
            {
                while (!S.empty() && ordOperator(s[i])<=ordOperator(S.top()))
                {
                    result = result + S.top();
                    S.pop();
                }

                S.push(s[i]);
            }
        }
        else if(s[i]==')')
        {
            while (S.top() != '(')
            {
                result = result + S.top();
                S.pop();
            }

            S.pop();
        }
        else
            result = result + s[i];
    }

    while (!S.empty())
    {
        result = result + S.top();
        S.pop();
    }

    return result;
}

int main()
{
    string s;

    do
    {
        cout << "Enter expression : ";
        cin >> s;

        if ( s!= "n")
            cout << "Convert to post order : "<< postOrder(s) << endl;
        
    } while (s != "n");
    

    return 0;
}