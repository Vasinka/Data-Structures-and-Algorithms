//”словие: ƒа се провери дали елементите в дадена опашка образуват монотонна редица
#include<iostream>
#include<queue>
using namespace std;

int main()
{

    queue<int> numbers;

    numbers.push(10);
    numbers.push(2);
    numbers.push(1);
    numbers.push(1);
    numbers.push(1);

    bool isMonotonneus = true;

    int first, second;

    first = numbers.front();

    numbers.pop();

    second = numbers.front();

    if (first > second)
        {
        while (!numbers.empty())
        {
            int current = numbers.front();

            numbers.pop();

            if(!numbers.empty())
                {
                    int next = numbers.front();

                    if (current < next)
                        {
                            isMonotonneus = false;
                            cout << "not monotonneus" << endl;
                            return 0;
                        }


                }

        }

    }


     else
        {
        while (!numbers.empty())
        {
            int current = numbers.front();

            numbers.pop();

            if(!numbers.empty())
            {
                int next = numbers.front();

                if (current > next)
                {
                    isMonotonneus = false;
                    cout << "not monotonneus" << endl;
                    return 0;
                }

            }

        }

    }


    if (isMonotonneus == true)
        cout << "monotonneus" << endl;

return 0;
}
