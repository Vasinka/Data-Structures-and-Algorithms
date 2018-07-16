//условие: Да се състави програма, която приема от стандартния вход положително число n и извежда n-тото число на Фибоначи. 
//         За целта да се използва стек.

#include<iostream>
#include<stack>
using namespace std;

int main ()
{

    unsigned int n;
    cin>>n;

    if (n<1)
    {


        cout << "Invalid input" << endl;
        return 0;
    }

    stack<int> st;

    st.push(0);
    st.push(1);

    for(int i=2; i<=n; i++)
    {

        int second = st.top();

        st.pop();

        int first = st.top();

        st.push(second);

        st.push(first + second);
    }


    cout << st.top() << endl;
    return 0;
}
