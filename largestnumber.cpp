#include <iostream>
using namespace std;

int main(void)
{
int num[5];
int i, maxNum;
maxNum = num[0];

for(i = 0; i < 5; i++)
{
cout << "enter number " << i+1 << " : ";
cin >> num[i];
}

for(i = 1; i < 5; i++)
{
if(maxNum < num[i])
maxNum = num[i];
}

cout << "\nLarge number : " << maxNum;

return 0;
}