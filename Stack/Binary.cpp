#include<iostream>
#include<iostream>
#include<stack>
using namespace std;
int main ()
{
    int number;

    cin >> number;

    stack <int> st;

    while (number)    // делим number целочислено на 2 и записваме остатъка от делението в стека
    {
        st.push(number%2);

        number /= 2;
    }

    while (!st.empty()) // извеждаме елементите на стека един по един
    {                   //така напрактика имаме на стандартния изход number в двоичния му запис
        cout << st.top();

        st.pop();
    }

    cout << endl;

    return 0;
}

 
