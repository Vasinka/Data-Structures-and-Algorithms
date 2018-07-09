#include<iostream>
using namespace std;

template<typename T>
class Stack {
            public:
                Stack() {
                                count = 0;
                                last = NULL;
                        }

                void Push(T value, T maxValue);

                T Pop();

                int GetMax();

            private:
                struct Node {
                T value;
                int maxValue;
                Node* next;
                            };
                Node* last;
                size_t count;
                };

        template<typename T>
        void Stack<T>::Push(T value, T maxValue) {
            Node* node = new Node;

            node->value = value;
            node->maxValue = maxValue;

            if (count == 0) {
                node->next = NULL;
                last = node;
                count++;
                            }
            else {
                node->next = last;
                last = node;
                count++;
                 }
                                                 }

            template<typename T> T Stack<T>::Pop() {
                if (count == 0) {
                    return (T)0;
                                }
                    else {
                        Node* node = last;
                        T popped = node->value;
                        last = node->next;
                        count--;
                        return popped;
                                }
                                                  }

                template<typename T>
                int Stack<T>::GetMax()
                {
                    if (count == 0) {
                        return 0;
                                    }
                    else {
                        return last->maxValue;
                        }
                }

int main()
{
    int N;
    int q;
    Stack<int> stack;
    int max = 0;
    int stackMax = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        {
        cin >> q;
        switch (q)
            {
            case 1:
                cin >> q;
                max = max > q ? max : q;
                stack.Push(q, max);
                break;
            case 2:
                stack.Pop();
                max = stack.GetMax();
                break;
            case 3:
                cout << max << endl;
                break;
            default:
                break;
            }
        }

    return 0;
}
