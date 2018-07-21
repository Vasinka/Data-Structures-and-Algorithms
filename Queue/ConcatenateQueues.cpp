/*Условие:Напишете външна функция, която слива две опашки, чиито елементи са подредени в нарастващ ред,
 и връща опашка с всички елементи отново подредени в нарастващ ред. */

#include<iostream>
#include<queue>
using namespace std;

queue<int> concatenate(queue<int> queue1, queue<int> queue2) //todo: да го сменя на merge, вместо concatenate
{
    queue<int> newQueue;

    while (!queue1.empty() && !queue2.empty())
    {
        int current1 = queue1.front();
        int current2 = queue2.front();

        if (current1 < current2)
        {
            newQueue.push(current1);
            queue1.pop();
        }

        else
        {
            newQueue.push(current2);
            queue2.pop();
        }


    }

    while (!queue1.empty())
    {
        int current = queue1.front();
        newQueue.push(current);
        queue1.pop();
    }

    while (!queue2.empty())
    {
        int current = queue2.front();
        newQueue.push(current);
        queue2.pop();
    }

return newQueue;
}

int main ()
{
    queue<int> mnOpashka, gotinaOpashka, ludaOpashka;

    mnOpashka.push(20);
    mnOpashka.push(1000);
    mnOpashka.push(5100);
    mnOpashka.push(5100);

    gotinaOpashka.push(20);
    gotinaOpashka.push(40);

    ludaOpashka = concatenate (mnOpashka, gotinaOpashka);

    while(!ludaOpashka.empty())
    {
        int momentnaLudost = ludaOpashka.front();
        cout << momentnaLudost << endl;
        ludaOpashka.pop();
    }

return 0;
}
