include<iostream>
#include<queue>

using namespace std;

bool read(int n, queue<queue<int> > *q)
{

    int i,numOfElements,j,element,temp;

    for(i=0;i<n;i++)
    {
        queue<int> newq;

        cin>>numOfElements;

        cin>>element;

        newq.push(element);
        temp=element;

        for (j=0;j<numOfElements-1;j++){

            cin>>element;
            if (element>=temp)
                {

                    newq.push(element);

                    temp=element;
                    }

            else return false;

    }

    q->push(newq);
}

return true;
}



int main ()
{

    int n;
    cin>>n;
    queue<queue<int> > q;

    read(n, &q);

    return 0;

}
