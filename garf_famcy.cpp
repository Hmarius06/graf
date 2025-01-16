#include <iostream>
#include <fstream>
using namespace std;

int a[10][10],n,x[10],m;
ifstream f("graf.in");

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
void grade()
{
    int i,j;
    for (i = 1; i <=n; i++)
        for ( j = 1; j <= n; j++)
        if(a[i][j]==1) x[i]++;
}

void afisare_m()
{
    int i,j;
    cout<<"Matricea:"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<endl;
        for(j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}

void afis_g()
{
    int i;
    cout<<"Vect grade: ";
    for(i=1;i<=n;i++)
     cout<<x[i]<<" ";
     cout<<endl;
}

void grad_min()
{
    int i,mi=0;
    for(i=1;i<=n;i++)
        if(x[i]<mi)mi=x[i];
    for(i=1;i<=n;i++)
        if(mi==x[i])cout<<"Varful "<<i<<" are grad min: "<<x[i]<<endl;
}

void nod_term()
{
    int i;
    for(i=1;i<=n;i++)
        if(x[i]==1)cout<<"Nodul "<<i<<" este nod terminal."<<endl;
}

void nod_iz()
{
    int i,r=0;
    for(i=1;i<=n;i++)
        if(x[i]==0){r++;}
    if(r!=0)cout<<"Sunt "<<r<<"noduri izolate."<<endl;
    else cout<<"Nu sunt noduri izolate"<<endl;
}

int main()
{
    citire();
    afisare_m();
    grade();
    afis_g();
    grad_min();
    nod_term();
    nod_iz();

 return 0;
}
