#include <bits/stdc++.h>
using namespace std;

void TOH(int n, char source, char auxillary, char destination)
{
  if(n == 1)
  {
    cout << "Move disk 1 from " << source << " to " << destination << endl;
    return;
  }
  TOH(n-1, source, destination, auxillary);
  cout << "Move disk " << n << " from " << source << " to " << destination << endl;
  TOH(n-1, auxillary, source, destination);
}


int main()
{
//   int n = 3;
//   TOH(n, 'A', 'B', 'C');
  
  return 0;
}