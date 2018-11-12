#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class List
{
private:
    node *head, *tail;
public:
    List()
    {
        head = NULL;

        tail = NULL;
    }
void createNode (int value)
{
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }

    else
    {
        tail -> next = temp;
        tail = temp;
    }
}

    void insertAtStart (int value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insertAtPosition (int pos, int value)
    {
        node * pre = new node;
        node * cur = new node;
        node * temp = new node;
        cur = head;

        for (int i = 1; i<pos; i++)
        {
            pre = cur;
            cur = cur -> next;
        }

        temp -> data = value;
        pre -> next = temp;
        temp -> next = cur;
    }

    void deleteFirst()
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast()
    {
        node * current = new node;
        node * previous = new node;
        current = head;

        while (current->next!=NULL)
        {
            previous = current;
            current = current->next;
        }

        tail = previous;
        previous -> next = NULL;
        delete current;
    }

    void deletePosition (int pos)
    {
        node *current = new node;
        node * previous = new node;
        current = head;

        for (int i=1; i<pos; i++)
        {
            previous = current;
            current = current -> next;
        }

        previous -> next = current->next;
    }

    void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}

			cout << endl;
		}

};

int main ()
{
    List myList;

    myList.createNode(10);
    myList.createNode(210);
    myList.createNode(1);
    myList.createNode(512);

    myList.display();
    myList.createNode(2);
    myList.display();
    myList.insertAtStart(11);
    myList.display();
    myList.insertAtPosition(2,12);
    myList.display();
    myList.deleteFirst();
    myList.display();
    myList.deleteLast();
    myList.display();
}
