#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int maxElement (stack<int> st) //function that returns the maximum element of a stack
{
    int currentMax;
    currentMax = st.top();
    st.pop();

    while(!st.empty())
    {
        //st.pop();

        int currentElement;
        currentElement = st.top();
        st.pop();

        if (currentElement > currentMax)
        {
            currentMax = currentElement;
        }

    }

    return currentMax;
}

int main ()
{
    int minimalMaximum; // :)
    queue<stack<int> > queueOfStacks;

    stack<int> stack1;
    stack1.push(1);
    stack1.push(10);
    stack1.push(1);

    stack<int> stack2;
    stack2.push(2);
    stack2.push(200);
    stack2.push(3);

    stack<int> stack3;
    stack3.push(-1);
    stack3.push(-15);
    stack3.push(-1);


    queueOfStacks.push(stack1);
    queueOfStacks.push(stack2);
    queueOfStacks.push(stack3);



    stack<int> firstStack;
    firstStack = queueOfStacks.front();
    queueOfStacks.pop();

    minimalMaximum = maxElement(firstStack);

    while (!queueOfStacks.empty())
    {
        stack<int> currentStack;
        currentStack = queueOfStacks.front();
        queueOfStacks.pop();

        int currentMaximum; //max element of the current stack
        currentMaximum = maxElement(currentStack);

        if (currentMaximum < minimalMaximum)
        {
            minimalMaximum = currentMaximum;
        }
    }

    cout << minimalMaximum << endl;

    return 0;
}
