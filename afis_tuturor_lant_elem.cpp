#include <iostream>
#include <fstream>
using namespace std;

typedef int stiva[100];
int a[20][20],n,k,as,ev,x,y,este;
stiva st;
fstream f("graf.in");
void citeste()
{
    f>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f>>a[i][j];


}
void init()
{
    st[k]=0;
}

int succesor()
{
    if (st[k]<n)
    {
        st[k]=st[k]+1;
        return 1;
    }
    else return 0;
}
int valid()
{ int i;
    if (k>1)
    {
        if (a[st[k-1]][st[k]]==0) return 0;
    }
    for (i=1;i<k;i++)
        if (st[i]==st[k]) return 0;
    return 1;
}

int solutie()
{
     return st[k]==y;
}

void tipar()
{
    este++;
    for (int i=1;i<=k;i++)
        cout<<st[i]<<" ";
    cout<<endl;
}

void bt()
{
    k=2;
    st[k]=0;
    while(k>1)
    {
        as=1;
        ev=0;
        while (as&&!ev)
    {
        as=succesor();
        if(as) ev=valid();
    }
    if(as)
    {
        if (solutie()) tipar();
        else {k++; init();}
    }
    else
        k--;
    }
}
int main()
{
    citeste();
    for (x=1;x<=n;x++)
      for(y=1;y<=n;y++)
        if (x!=y)
        {
            st[1]=x;
            bt();
        }
    if(este<0)cout<<"NU exista lanturi elementare. ";
    else cout<<"sunt "<<este<<" lanturi";
    return 0;
}

8
0 1 1 1 0 0 0 0
1 0 0 0 1 0 0 0
1 0 0 1 1 0 0 0
1 0 1 0 0 0 0 0
0 1 1 0 0 0 0 0
0 0 0 0 0 0 1 1
0 0 0 0 0 1 0 0
0 0 0 0 0 1 0 0

