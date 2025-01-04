// You are using GCC
#include <iostream>
using namespace std;

#define MAX_SIZE 100

void traverseInventory(int arr[], int size)
{
    // Type your code here
    cout << "Inventory List: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertItem(int arr[], int &size, int item)
{
    cout << "Inserting Item: " << item << endl;
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            arr[i + 1] = item;
        }
    }
    size += 1;
    traverseInventory(arr, size);
}

void removeItem(int arr[], int &size, int item)
{
    // Type your code here
    cout << "Removing Item: " << item << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            for (int j = i; j < size; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
    traverseInventory(arr, size);
}

int main()
{
    int inventory[MAX_SIZE];
    int size, n, m;
    int newItems[MAX_SIZE];
    int deleteItems[MAX_SIZE];

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> inventory[i];
    }

    traverseInventory(inventory, size);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> newItems[i];
    }
    for (int i = 0; i < n; i++)
    {
        insertItem(inventory, size, newItems[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> deleteItems[i];
    }
    for (int i = 0; i < m; i++)
    {
        removeItem(inventory, size, deleteItems[i]);
    }

    return 0;
}