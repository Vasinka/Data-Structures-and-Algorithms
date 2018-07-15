#include<iostream>
#include<stack>
using namespace std;
int main ()
{
    int number;

    cin >> number;

    stack <int> st;

    while (number)    // ����� number ����������� �� 2 � ��������� �������� �� ��������� � �����
    {
        st.push(number%2);

        number /= 2;
    }

    while (!st.empty()) // ��������� ���������� �� ����� ���� �� ����
    {                   //���� ���������� ����� �� ����������� ����� number � �������� �� �����
        cout << st.top();

        st.pop();
    }

    cout << endl;

    return 0;
}
