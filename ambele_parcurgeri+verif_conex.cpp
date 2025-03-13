#include <iostream>
#include <fstream>

using namespace std;

int n, a[10][10], v[10];

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


void bfs(int start)
{
    int i, k, st, dr, x[10];
    // Adaug varful initial in coada
    st = dr = 1;
    x[1] = start;
    // Vizitez varful
    v[start] = 1;

    // Cat timp coada != goala
    while(st<=dr) {
        // Extragem un element din coada
        k = x[st];
        // Afisam elementul
        cout << k << " ";

        // Determin vecinii
        for(int i = 1; i <= n; i++)
        {
            // Daca nu e vizitat si i este vecin
            if(v[i] == 0 && a[k][i] == 1) {
                // Vizitez varful si il adaug in coada
                v[i] = 1;
                x[++dr] = i;
            }
        }
        // "Sterg" din coada
        st++;
    }
}

void dfs(int k)
{
    v[k] = 1;
    cout << k << " ";

    for (int i = 1; i <= n; i++)
    {
        if (a[k][i] && v[i] == 0)
        {
            dfs(i);
        }
    }
}

int verif_conex()
{
    for(int i=1;i<=n;i++)
        if(v[i]==0)return 0;
    return  1;
}


int main()
{
    int m;
    creare_matrice_adiacenta();
    afisare_adiacenta();
    cout << "Ce metoda de parcurgere vrei sa folosesti?"<<endl<<"1.BFS"<<endl<<"2.DFS"<<endl;
    cin>>m;
    if(m==1)
    {
        cout<<"Ai ales metoda BFS(parcurgere in latime):"<<endl;
        bfs(1);
        cout<<endl;
    }
    else if(m==2)
    {
        cout<<"Ai ales metoda DFS(parcurgere in adancime):"<<endl;
        dfs(1);
        cout<<endl;
    }
    if(verif_conex() == 0)cout<<"Graful nu este conex."<<endl;
    else cout<<"Graful este conex."<<endl;
}
