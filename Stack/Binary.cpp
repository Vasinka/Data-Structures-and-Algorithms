#include<iostream>
#include<stack>
using namespace std;
int main ()
{
    int number;

    cin >> number;

    stack <int> st;

    while (number)    // äåëèì number öåëî÷èñëåíî íà 2 è çàïèñâàìå îñòàòúêà îò äåëåíèåòî â ñòåêà
    {
        st.push(number%2);

        number /= 2;
    }

    while (!st.empty()) // èçâåæäàìå åëåìåíòèòå íà ñòåêà åäèí ïî åäèí
    {                   //òàêà íàïðàêòèêà èìàìå íà ñòàíäàðòíèÿ èçõîä number â äâîè÷íèÿ ìó çàïèñ
        cout << st.top();

        st.pop();
    }

    cout << endl;

    return 0;
}
 
