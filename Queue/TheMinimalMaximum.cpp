//Task: You are given a queue of stacks. Write a program to find the minimal among the maximum elements of the stack
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int maxElement (stack<int> st) //function that finds the maximum element of a stack
{
    int currentMax;            //todo: rename some variables
    currentMax = st.top();
    st.pop();

    while(!st.empty())
    {

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

    while (!queueOfStacks.empty()) //go through every stack
    {
        stack<int> currentStack;
        currentStack = queueOfStacks.front();
        queueOfStacks.pop();

        int currentMaximum; //max element of the current stack
        currentMaximum = maxElement(currentStack);

        if (currentMaximum < minimalMaximum) //find the minimal among the maximum elements
        {
            minimalMaximum = currentMaximum;
        }
    }

    cout << minimalMaximum << endl;

    return 0;
}
