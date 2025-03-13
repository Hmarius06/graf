#include <iostream>
#include <fstream>

using namespace std;

int n, a[10][10], v[10], x[10];

void creare_matrice_adiacenta()
{
    fstream f("graf.in");
    int i,x,y;
    f>>n;
    while(f >> x >> y) a[x][y] = a[y][x] = 1;
    f.close();
}
void afisare_adiacenta()
{
    cout << "\nMatricea de adiacenta:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout<<endl;
}

int verif_conex()
{
    for(int i=1;i<=n;i++)
        if(v[i]==0)return 0;
    return  1;
}

void dfs(int k)
{
    v[k] = 1;
    cout << k << " ";
    for (int i = k; i <= n; i++)
    {
        if (a[k][i] && v[i] == 0)
        {
            dfs(i);
        }
    }

}
void grade()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==1)x[i]=1;
}
int terminal()
{
    for(int i=1;i<=n;i++)
        if(x[i]==1)return 1;
    return 0;
}
int complet()
{
    for(int i=1;i<=n;i++)
        if(x[i]!=n-1)return 1;
    return 0;
}
int terminal()
{
    for(int i=1;i<=n;i++)
        if(x[i]==1)return 1;
    return 0;
}

int main()
{
    creare_matrice_adiacenta();
    afisare_adiacenta();
    grade();
    if(terminal()==1)cout<<"In grupul de persoane, fiecare are minim un prieten."<<endl;
    else cout<<"In grupul de persoane, nu toti au minim un prieten."<<endl;
    if(complet()==1)cout<<"Fiecare persoana este prietena cu oricare alta din grup."<<endl;
    else cout<<"Fiecare persoana nu este prietena cu oricare alta din grup."<<endl;
    if(terminal()==1)cout<<"Fiecare persoana are macar un prieten."<<endl;
    else cout<<"Exista persoana fara macar un prieten."<<endl;
    
    
}
