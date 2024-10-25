#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int Size)
    {
        size = Size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow";
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow";
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty";
            return -1;
        }
    }
    void showEmpty(){
        if(top==-1){
            cout<<"Stack is empty";
        }
        else{
            cout<<"Stack is not empty";
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Stack st(5);
    st.push(22);
    st.push(45);
    st.push(29);
    cout << st.peek() << endl;
    st.showEmpty(); 
    cout<< endl;
    st.pop();
    cout << st.peek();
}