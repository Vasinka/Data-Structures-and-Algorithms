#include<iostream>
#include<stack>
#include<cstring>

using namespace std;
int main ()
{
    int i;
    char expression[100];
    stack<char> st;

    cin.getline(expression,100);

    for (i = 0; i < strlen(expression); i++)

    {
        if (expression[i]!= '(' && expression[i]!= ')' && expression[i]!= ' ')
        {
            cout << "Invalid input" << endl;
            return 0;
        }

        if (expression[i] == '(')
                st.push(expression[i]);
        else
        {
            if (!st.empty())
                st.pop();

            else

            {
                cout << "NO" << endl;
                return 0;

            }
        }
    }

    if (st.empty())

        cout << "YES" << endl;
    else

        cout << "NO" << endl;

    return 0;
}
