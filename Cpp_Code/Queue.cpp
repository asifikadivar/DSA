
#include <iostream>
using namespace std;

class Queue
{
private:
#define STACK_SIZE 5
    
    int nFront;
    int nRear;
    int Arr[STACK_SIZE] ;
    
public:
    Queue();
    //~Queue();
    bool IsEmpty();
    bool IsFull();
    
    void  EnQueue(int nValue);
    int   DeQueue();
    
    void Display();
    void Count();
};

Queue::Queue()
{
    nFront = -1;
    nRear  = -1;
    for (int i = 0; i < STACK_SIZE; i++)
    {
        Arr[i] = 0;
    }
}

bool Queue::IsEmpty()
{
    if(nFront == -1 && nRear == -1)
        return true;
    else
        return false;
}
bool Queue::IsFull()
{
    if(nRear == size(Arr) -1)
        return true;
    else
        return false;
    
}

void Queue::EnQueue(int nValue)
{
    if(IsFull())
    {
        cout<<"Queue is Full, cannot enter new value" << endl;
    }
    if(IsEmpty())
    {
        nFront = 0;
        nRear  = 0;
    }
    else
    {
        nRear++;
    }
    Arr[nRear] = nValue;
}
int Queue::DeQueue()
{
    if(IsEmpty())
    {
        cout<<"Queue is empty " << endl;
        return -1;
    }
    int nTemp = -1;
    nTemp = Arr[nFront];
    Arr[nFront] = 0;
    
    if(nRear == nFront)
    {
        nRear = -1;
        nFront = -1;
    }
    else
        nFront++;
    
    return nTemp;
    
}

void Queue::Display()
{
    for(int i = 0; i < 5; i++)
    {
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
    return;
}
void Queue::Count()
{
    if( nFront == -1 && nRear == -1)
        cout<<"Count : 0" << endl;
    else
        cout<<"Count : " << 1 + nRear - nFront;
}

int main(int argc, const char * argv[])
{
    Queue obj;
    int nOperation = -1;
    int nValue = -1;
    
    do
    {
        cout<<"Enter the value 0 to 7 for following Queue Function, Press 0 For Exit"<<endl;
        cout<<"1 for EnQueue()" << endl;
        cout<<"2 for DeQueue()" << endl ;
        cout<<"3 for Empty()" << endl;
        cout<<"4 for Full()" << endl ;
        cout<<"5 for Count" << endl;
        cout<<"6 for Display" << endl;
        cout<<"7 Clear Screen" << endl;
        
        cin>>nOperation;
        
        switch(nOperation)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter the Value : ";
                cin>>nValue;
                obj.EnQueue(nValue);
                break;
            case 2:
                cout<<"DeQueue value is : "<<obj.DeQueue()<<endl;;
                break;
            case 3:
                if(obj.IsEmpty())
                    cout<<"Queue is Empty" << endl;
                else
                    cout<<"Queue is not Empty" << endl;
                break;
            case 4:
                if(obj.IsFull())
                    cout<<"Queue is Full" << endl;
                else
                    cout<<"Queue is not Full" << endl;
                break;
            case 5:
                obj.Count();
                break;
            case 6:
                obj.Display();
                break;
            case 7:
                system("cls");
                break;
            default:
                break;
        }
        
        cout<<"************ End of one Operation ************" << endl << endl;
    } while (nOperation != 0);
    
    
    return 0;
}
