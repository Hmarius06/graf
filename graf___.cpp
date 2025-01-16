#include <iostream>
#include <fstream>
using namespace std;
int a[10] [10], n;
ifstream fin("fisier.txt");
void citire()
{
    int i, j;
    fin>>n;
    for ( i = 1; i <=n; i++)
    {
        for ( j = 1; j <=n; j++)
        {
            fin>>a[i][j];
        }   
    }
}
void afisare()
{
    int i, j;
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            if (a[i][j])
            {
                cout<<"["<<i<<"],["<<j<<"] ";
            }
        }
    }
}
int verifica()
{
    int i, j;
    for ( i = 1; i < n; i++)
    {
        for ( j = i+1; j <= n; j++)
        {
            if (a[i][j] !=0 && a[i][j] !=1)
            return 0;
        }
    }
    return 1;
}
int main()
{
   citire();
   afisare();
   if (verifica())
   cout<<"\nmatricea este binara";
   else cout<<"\nmatricea nu este binara";

   return 0;
}
/*fisier.txt
8
0 1 0 0 1 0 0 0
1 0 1 0 1 0 0 0
0 1 0 1 1 0 0 0
0 0 1 0 1 1 1 0
1 1 1 1 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0*/
