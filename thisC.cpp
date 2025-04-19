using namespace std;
#include <iostream>
#include <vector>
int main() {

     int n[100];
     fill(n, n + 100, 12);
     
     for(int a: n) {
            cout << a << " ";
     }

    return 0;
}