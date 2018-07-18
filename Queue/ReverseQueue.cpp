/*
task: Give an algorithm for reversing a queue Q. Only following standard operations are allowed on queue.
enqueue(x) : Add an item x to rear of queue.
dequeue() : Remove an item from front of queue.
empty() : Checks if a queue is empty or not.
*/

#include <iostream>
#include<queue>
#include<stack>
using namespace std;


void print(queue<int>& Queue) //function that prints all the elements of a queue
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

void reverseQueue(queue<int>& Queue) //function that reverses a queue
{
    stack<int> Stack;
    while (!Queue.empty())
    {
        Stack.push(Queue.front());
        Queue.pop();
    }

    while (!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }
}


int main()
{
    //test the two functions
    queue<int> Queue;
    Queue.push(5);
    Queue.push(133);
    Queue.push(800);


    reverseQueue(Queue);
    print(Queue);
}

//source: geeksforgeeks.org
