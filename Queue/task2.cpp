#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int findAverage(stack<int> st)
{
    int sum=0, numOfElements=0;


    while(!st.empty())
    {
        numOfElements++;
        int current;
        current = st.top();
        sum += current;
        st.pop();
    }

    int average = sum/numOfElements;
    return average;

}

int main()
{
    queue<stack<int> > myQueue;

    stack<int> stack1;
    stack1.push(3);
    stack1.push(2);
    stack1.push(1);

    stack<int> stack2;
    stack2.push(2);
    stack2.push(2);
    stack2.push(2);

    stack<int> stack3;
    stack3.push(1);
    stack3.push(6);
    stack3.push(2);

    myQueue.push(stack1);
    myQueue.push(stack2);
    myQueue.push(stack3);

    bool glupost = true;
    int currentAverage;
    currentAverage = findAverage(myQueue.front());
    myQueue.pop();

    while(!myQueue.empty())
    {
        stack<int>currentStack;
        currentStack = myQueue.front();

        if(currentStack.top()!= currentAverage)
        {
            glupost = false;
            cout <<"no" <<endl;

            return 0;
        }

        currentAverage = findAverage(currentStack);
        myQueue.pop();

    }

    cout << "yes" << endl;

    return 0;
}
