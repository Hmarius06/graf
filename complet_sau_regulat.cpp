#include <iostream>
#include <fstream>
using namespace std;

int a[10][10],n,x[100];
fstream f("graf.in");
void citeste()
{
    f>>n;
    int x,y;
    while(f>>x>>y)
        a[x][y]=a[y][x]=1;
    f.close();
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

void grade_v()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==1)x[i]++;
}

int verif_c()
{
    int i;
    for(i=1;i<=n;i++)
        if(x[i]!= n-1)return 0;
    return 1;
}
int verif_r()
{
    int i;
    for(i=1;i<n;i++)
        if(x[i]!= x[i+1])return 0;
    return 1;
}


int main()
{
   citeste();
   cout<<"Matricea de adiacenta: "<<endl;
   afisare(a);
   grade_v();
   cout<<"Vector grade: "<<endl;
   for(int i=1;i<=n;i++)cout<<x[i]<<" ";
   cout<<endl;
   if(verif_c()==1)cout<<"Graful este complet."<<endl;
   else cout<<"Graful nu este complet."<<endl;
   if(verif_r()==1)cout<<"Graful este regulat."<<endl;
   else cout<<"Graful nu este regulat."<<endl;


    return 0;
}
