#include <iostream>
#include <fstream>
using namespace std;

int a[10][10],n,x[10][10];
fstream f("graf.in");
fstream f2("graf2.in");
void citeste()
{
    f>>n;
    int x,y;
    while(f>>x>>y)
        a[x][y]=a[y][x]=1;
    f.close();
}
void citeste2()
{
    f2>>n;
    int b,y;
    while(f2>>b>>y)
        x[b][y]=x[y][b]=1;
    f2.close();
}

void afisare(int mot[10][10])
{
    cout<<endl;
    for(int i=1;i<=n;i++)
        {
        for(int j=1;j<=n;j++)
            cout<<mot[i][j]<<" ";
        cout<<endl;
        }
    cout<<endl;
}
int complementar()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==x[i][j] && a[i][j]==1)return 0;
    return 1;
}


int main()
{
   citeste();
   citeste2();
   cout<<"Matricea de adiacenta graf 1: "<<endl;
   afisare(a);
   cout<<"Matricea de adiacenta graf 2: "<<endl;
   afisare(x);
   if(complementar()==0)cout<<"Grafurile nu sunt complementare. "<<endl;
   else cout<<"Grafurile sunt complementare. "<<endl;



    return 0;
}
