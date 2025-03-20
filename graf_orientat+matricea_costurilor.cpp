#include <iostream>
#include <fstream>

using namespace std;

int n, a[10][10], dp[10], dm[10], c[10][10];
int inf=50000;

void citeste()
{
    fstream f("graf.in");
    int i,x,y;
    f>>n;
    while(f >> x >> y) a[x][y] = 1;
    f.close();
}
void afisare(int a[10][10])
{
    cout << "\nMatricea:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout<<endl;
}
void vect_grade()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[j][i]==1)dm[i]++;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==1)dp[i]++;
}
void afis_vect(int v[10])
{
    int i;
    cout<<"Vectorul: "<<endl;
    for(i=1;i<=n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void matr_cost()
{
    fstream f("cost.txt");
    int i,j,x,y,z;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)c[i][j]=0;
            else c[i][j]=inf;
    while(f>>i>>j>>z)
        c[i][j]=z;
    f.close();
}

int main()
{
    citeste();
    afisare(a);
    vect_grade();
    afis_vect(dm);
    afis_vect(dp);
    matr_cost();
    afisare(c);


}
