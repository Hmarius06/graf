#include<fstream>
#include<iostream>
using namespace std;
fstream f("graf.in");
char inf='$';
int a[20][20],x,y,n,c,i,j;
//initializare matrice
void initializare()
{f>>n;
for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
 if(i==j)
   a[i][j]=0;
    else
   a[i][j]=inf;
while(f>>x>>y>>c)
 a[x][y]=c;


f.close();
}

void afisare()
{for(int i=1;i<=n;i++)
  {for(int j=1;j<=n;j++)
      if(a[i][j]==inf)
		 cout<<inf<<"  ";
      else
    cout<<a[i][j]<<"  ";
cout<<endl;
  }
}
void generare()
{for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
  if(a[i][k])
    for(int j=1;j<=n;j++)
     if(a[j][k])
      if(a[i][j]==0)
	a[i][j]=a[i][k]+a[k][j];
	  else
	if(a[i][j]>a[i][k]+a[k][j])
		a[i][j]=a[i][k]+a[k][j];


    }
void verificare(unsigned b, unsigned c)
{if(a[b][c]!='#')
 cout<<"exista drum de la "<<b<<" la "<<c<<" si costul minim : "<<a[b][c];
 else cout<<"nu este drum";
}
void drum(int i,int j)
{int g=0,k=1;
while((k<=n)&&!g)
  {if(i!=k&&j!=k)
     if(a[i][j]==a[i][k]+a[k][j])
      {drum(i,k);
       drum(k,j);
      g=1;
       }
  k++;
  }
if(!g)
cout<<j<<" ";

}
void s_drum(int ni,int nf)
{if(a[ni][nf]<inf)
{cout<<"\ndrumul de la "<<ni<<" la "<<nf<<" are lungimea "<<a[ni][nf];
cout<<endl<<"un drum optim este: "<<endl;
cout<<ni<<" ";
drum(ni,nf);
}
else
cout<<"\nnu exista drum de la "<<ni<<" la "<<nf;
}
int main()
{
unsigned c,b;
initializare();
afisare();
generare();
cout<<"\nMatricea costurilor minime este: "<<endl;
afisare();
cout<<"da doua nr sa vada costul minim"<<endl;

cin>>b>>c;
verificare(b,c);
s_drum(b,c);

}
