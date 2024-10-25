#include <iostream>

class PQueue
{
public:
    int data[100];
    int priority[100];
    int size;

    PQueue()
    {
        size = 0;
    }

    void push(int value, int p)
    {
        if (size == 100)
        {
            return;
        }
        data[size] = value;
        priority[size] = p;
        size++;
        std::cout << "Pushed " << value << " with priority " << p << std::endl;
    }

    int getHighestPriority()
    {
        int max = 0;
        for (int i = 1; i < size; i++)
        {
            if (priority[i] > priority[max])
            {
                max = i;
            }
        }
        std::cout << "Highest priority is " << priority[max] << std::endl;
        return data[max];
    }

    void popHighestPriority()
    {
        int max = 0;
        for (int i = 1; i < size; i++)
        {
            if (priority[i] > priority[max])
            {
                max = i;
            }
        }
        for (int i = max; i < size - 1; i++)
        {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }
        size--;
        std::cout << "Popped " << data[max] << " with priority " << priority[max] << std::endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << "Printed" << std::endl;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    PQueue pq;
    pq.push(1, 3);
    pq.push(2, 1);
    pq.push(3, 2);
    pq.print();
    std::cout << pq.getHighestPriority() << std::endl;
    pq.popHighestPriority();
    pq.print();
    std::cout << pq.getHighestPriority() << std::endl;
    return 0;
}