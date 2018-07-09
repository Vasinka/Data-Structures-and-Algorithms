#include <iostream>

using namespace std;

template<typename T> class Stack {
public:
                Stack() {
                                count = 0;
                                last = NULL;
                }

                void Push(T value) {
                                Node* node = new Node;

                                node->value = value;

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

                T Pop() {
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

                T GetTop() {
                                if (count == 0) {
                                                return T(2147483647);
                                }
                                return last->value;
                }

                int Count() {
                                return count;
                }

private:
                struct Node {
                                T value;
                                Node* next;
                };
                Node* last;
                int count;
};

int main() {
                int g;
                cin >> g;

                while (g > 0) {
                                Stack<int> A;
                                Stack<int> B;
                                Stack<int> C;
                                g--;
                                int n, m, x, q;
                                cin >> n >> m >> x;

                                int a[100000];
                                int b[100000];
                                for (int i = 0; i < n; i++)
                                {
                                                cin >> a[i];
                                }
                                for (int i = 0; i < m; i++)
                                {
                                                cin >> b[i];
                                }

                                for (int i = n - 1; i >= 0; i--)
                                {
                                                A.Push(a[i]);
                                }
                                for (int i = m - 1; i >= 0; i--)
                                {
                                                B.Push(b[i]);
                                }

                                int sum = 0;
                                int countAll = 0;
                                int countA = 0;
                                int countB = 0;
                                int ta, tb, tc;

                                ta = A.GetTop();

                                while (sum + ta <= x && A.Count() > 0)
                                {
                                                sum += ta;
                                                countA++;
                                                A.Pop();
                                                C.Push(ta);

                                                ta = A.GetTop();
                                }
                                countAll = countA;

                                while (B.Count() > 0)
                                {
                                                tb = B.GetTop();
                                                sum += tb;
                                                countB++;
                                                B.Pop();
                                                while (sum > x && C.Count() > 0)
                                                {
                                                                countA--;
                                                                tc = C.GetTop();
                                                                C.Pop();
                                                                sum -= tc;
                                                }
                                                if (sum <= x && countA + countB > countAll)
                                                {
                                                                countAll = countA + countB;
                                                }
                                }
                                cout << countAll << endl;
                }
                return 0;
}
