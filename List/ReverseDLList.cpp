//task: https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem
#include<iostream>

using namespace std;

struct DoublyLinkedListNode
{
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head)
{


    if (head == NULL) return head;
    
    if (head->next == NULL)
    {
        head->next = head->prev;
        head->prev = NULL;
        return head;
    }

    DoublyLinkedListNode *nextPtr = head->next;
    DoublyLinkedListNode *prevPtr = head->prev;
    head->next = prevPtr;
    head->prev = nextPtr;

    return reverse(nextPtr);
}

/*int main ()
{
    return 0;
}
*/
