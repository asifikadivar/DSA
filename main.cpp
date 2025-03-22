//
//  main.cpp
//  T1
//
//  Created by Asif Kadivar on 05/10/24.
//

#include <iostream>
using namespace std;

class Stack
{
private:
#define STACK_SIZE 5
    
    int nTop;
    int Arr[STACK_SIZE] ;
    
public:
    Stack();
    //~Stack();
    bool IsEmpty();
    bool IsFull();
    int Count();
    
    int Pop();
    void Push(int nValue);
    
    void Change(int nPos, int nValue);
    void Display(int nPos);
};

Stack::Stack()
{
    nTop = -1;
    for (int i = 0; i < STACK_SIZE; i++)
    {
        Arr[i] = 0;
    }
}

bool Stack::IsEmpty()
{
    if(nTop == -1)
        return true;
    else
        return false;
}
bool Stack::IsFull()
{
    if(nTop == STACK_SIZE -1)
        return true;
    else
        return false;
    
}
int Stack::Count()
{
    return nTop + 1;
}

void Stack::Push(int nValue)
{
    if(IsFull())
    {
        cout<<"Stack is overflow" << endl;
    }
    else
    {
        nTop++;
        Arr[nTop] = nValue;
    }
}
int Stack::Pop()
{
    if(IsEmpty())
    {
        cout<<"Stack is underflow " << endl;
        return 0;
    }
    else
    {
        int nValue = Arr[nTop];
        nTop--;
        return nValue;
    }
}

void Stack::Change(int nPos, int nValue)
{
    if(nPos > (STACK_SIZE -1) || nPos < 0)
    {
        cout<<"Provided postion of change is out of scope" << endl;
        return;
    }
    Arr[nPos] = nValue;
}
void Stack::Display(int nPos)
{
    if(nPos > (STACK_SIZE -1) || nPos < 0)
    {
        cout<<"Provided postion of change is out of scope" << endl;
        return;
    }
    cout<<"Data on " <<  nPos << " is " << Arr[nPos] <<endl;
    return;
}

int main()
{
    Stack obj;
    int nOperation = -1;
    int nPosition = -1;
    int nValue = -1;
    
    do
    {
        cout<<"Enter the value 0 to 7 for following Stack Function, Press 0 For Exit"<<endl;
        cout<<"1 for IsEmpty()" << endl << "2 for IsFull()" << endl << "3 for Stack Count()" << endl;
        cout<<"4 for Pop()" << endl << "5 for Push(int nValue)" << endl;
        cout<<"6 for Change(int nPos, int nValue)" << endl << "7 for Display(int nPos)" << endl;
        cout<<"8 Clear Screen" << endl;
        
        cin>>nOperation;
        
        switch(nOperation)
        {
            case 0:
                break;
            case 1:
                if(obj.IsEmpty())
                    cout<<"Stack is Empty" << endl;
                else
                    cout<<"Stack is not Empty" << endl;
                break;
            case 2:
                if(obj.IsFull())
                    cout<<"Stack is Full" << endl;
                else
                    cout<<"Stack is not Full" << endl;
                break;
            case 3:
                cout<< "Stack count is : "<< obj.Count() << endl;
                break;
            case 4:
                cout<< "Pop Value is : "<< obj.Pop() << endl ;
                break;
            case 5:
                cout<<"Enter the Push Value : ";
                cin>>nValue;
                cout<<endl;
                obj.Push(nValue);
                break;
            case 6:
                cout<<"Enter the change value : ";
                cin>>nValue;
                cout << endl;
                cout<<"Enter the Postion of value : ";
                cin>> nPosition;
                cout << endl;
                obj.Change(nPosition, nValue);
                break;
            case 7:
                cout<<"Enter the Display Position : ";
                cin>>nPosition;
                cout << endl;
                obj.Display(nPosition);
                break;
            case 8:
                system("cls");
                break;
            default:
                break;
        }
        
        cout<<"************ End of one Operation ************" << endl << endl;
    } while (nOperation != 0);
    
    
    return 0;
}
