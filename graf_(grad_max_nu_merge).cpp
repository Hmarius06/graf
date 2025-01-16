#include <iostream>
#include <fstream>
using namespace std;

int a[10][10],n,m;


void citeste()
{
    int i,j;
    cout<<"Cate noduri sunt?";
    cin>>n;
    for(i=2;i<=n;i++)
        for(j=1;j<i;j++)
    {
        cout<<"["<<j<<","<<i<<"]=";
        cin>>a[i][j];
        a[j][i]=a[i][j];
    }
}

void afisare_v()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        cout<<"Vecinii nodului "<<i<<" sunt: "<<endl;
            for(j=1;j<=n;j++)
                {
                    if(a[i][j]==1)cout<<j<<";";
                }
        cout<<endl;
    }
    cout<<endl;
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
void grad_m()
{
    int i,j,m[10],max=0;
    cout<<"Nodurile cu grad maxim sunt:"<<endl;
    for(i=1;i<=n;i++)
        {m[i]=0;
        for(j=1;j<=n;j++)
        {
                if(a[i][j]=1)m[i]++;
                if(max<m[i])max=m[i];
        }
        }
    for(i=1;i<=n;i++)
        if(max==m[i])cout<<i<<" are gradul maxim de "<<m[i]<<endl;

}
void izolate()
{
    int i,j,x,y=0;
     for(i=2;i<=n;i++)
     {
        x=0;
        for(j=1;j<i;j++)
    {
        if(a[i][j]=1)x=1;
    }
        if(x==0)
        {
            cout<<"nodul "<<i<<" este izolat "<<endl;
            y++;
        }
     }
     if(y!=0)cout<<"nr minim de muchii pentru ca graful sa nu aiba noduri izolate este "<<(n+1)/2<<endl;
}
void U_m()
{
    int i,j;
    cout<<"u={ ";
    for(i=2;i<=n;i++)
        for(j=1;j<i;j++)
    {
        if(a[i][j]==1)cout<<"["<<j<<","<<i<<"] ";
    }
    cout<<"}"<<endl;
}


int main()
{
    citeste();
    afisare_m();
    afisare_v();
    grad_m();
    izolate();
    U_m();


 return 0;
}
