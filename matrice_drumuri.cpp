#include <iostream>
#include <fstream>
using namespace std;

int a[10][10],n,m,d[10][10];
fstream f("graf.in");
void citeste()
{
    f>>n;
    int x,y;
    while(f>>x>>y)
        a[x][y]=a[y][x]=d[x][y]=d[y][x]=1;
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
void ray_warshall()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            if(d[k][i])
                {for(j=1;j<=n;j++)
                    {
                        if(d[k][j])d[i][j]=1;
                        afisare(d);
                    }
                }
}
int verificare()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!d[i][j]) return 0;
    return 1;
}

int main()
{
   citeste();
   cout<<"Matricea de adiacenta: "<<endl;
   afisare(a);
    cout<<"Matricea drumurilor: "<<endl;
   afisare(d);
   ray_warshall();
   cout<<"Matricea drumurilor: "<<endl;
   afisare(d);
   if(verificare())cout<<"Graful este conex."<<endl;
   else cout<<"Graful nu este conex."<<endl;

    return 0;
}

