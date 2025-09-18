#include <iostream>
using namespace std;

void reverse(string &str, int i, int j)
{
    if (i > j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;

    reverse(str, i, j);
}

int main()
{
    string name = "Dameto_Pacita";
    cout << "Name before: " << name << endl;
    reverse(name, 0, name.length()-1);
    cout << "Name after: " << name;

    return 0;
}