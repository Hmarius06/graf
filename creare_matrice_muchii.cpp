#include <iostream>
#include <fstream>
using namespace std;

int a[10][10],n,m,k=1;
ifstream f("graf.in");

struct muchie
{
    int x,y;
} u[100];

void citire()
{   int i,j;
        f>>n>>m;
    for (i = 1; i <=n; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            f>>a[i][j];
        }
    }
}


void afisare_m ()
{
    cout<<"\nMatricea este: "<<endl;
    for (int i=1; i<=n; i++)
        {for (int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
         cout<<endl;
        }
}

void muchii_vect()
{
    int i,j;
    for (i = 1; i <n; i++)
        for(j = i+1;j<=n;j++)
            if(a[i][j]==1)
            {
                u[k].x=i;
                u[k].y=j;
                k++;
            }
k--;
}

void afis_muchii()
{
    int i;
    cout<<"Vect muchii: "<<endl;
    for(i=1;i<=k;i++)
    {
        cout<<"["<<u[i].x<<","<<u[i].y<<"]; ";
    }
    cout<<endl;
}

void afisare_vecin()
{
    int i,p;
    cout<<"Ce nod vrei sa stii vecinii?";
    cin>>p;
    cout<<"Vecini lui "<<p<<" sunt: "<<endl;
    for(i=1;i<=k;i++)
    {
        if(u[i].x == p )cout<<u[i].y<<" ";
        else if(u[i].y == p)cout<<u[i].x<<" ";
    }
    cout<<endl;
}



int main()
{
    citire();
    afisare_m();
    muchii_vect();
    afis_muchii();
    afisare_vecin();

 return 0;
}
9 8
0 1 1 0 0 1 0 0 0
1 0 0 1 1 0 0 0 0
1 0 0 0 0 1 1 0 0
0 1 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0 0
1 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0
https://tetr.io/#GNKX

