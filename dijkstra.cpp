#include<fstream>
#include<iostream>
using namespace std;
char inf=100;
int i,j,n;
int s[10],t[10],x,d[10],a[10][10];
void citire(char fis[20],int a[][10],int &n)
{int k;
fstream f(fis);
f>>n;
for(i=0;i<=n;i++)
  for(j=1;j<=n;j++)
     if(i==j) a[i][j]=0;
       else a[i][j]=inf;
while(f>>i>>j>>k)
    a[i][j]=k;
f.close();
}
void afisare(int a[10][10],int n)
{for(i=1;i<=n;i++)
   {for(j=1;j<=n;j++)
       if(a[i][j]==inf)
	  cout<<"inf  ";
	  else cout<<a[i][j]<<"  ";

	  cout<<endl;
	  }
     }
void drum(int i)
{
  if(t[i]!=0)  drum(t[i]);
  cout<<i<<"  ";
  }
void afis_vect(int v[],int n)
{for(int i=1;i<=n;i++)
     cout<<v[i]<<"   ";
cout<<endl;
}
void dij(int x)
{int i,j,min,y;
//intializari
s[x]=1;
for(i=1;i<=n;i++)
{  d[i]=a[x][i];
   if(i!=x&&d[i]<inf)  t[i]=x;
}
   afis_vect(d,n);
    afis_vect(t,n);

//se executa alg in n-1 pasi
 for(i=1;i<=n-1;i++)
   {
    for(j=1,min=inf;j<=n;j++)
	if(s[j]==0  && d[j]<min)
	{min=d[j];
	 y=j;
	}
	s[y]=1;
   cout<<"\nNodul selectat "<<y<<endl;
   for(j=1;j<=n;j++)
    if(s[j]==0 && d[j]>d[y]+a[y][j])
	 {d[j]=d[y]+a[y][j];
	 t[j]=y;
	 }

    cout<<"\n_______Forma vect ____________"<<endl;
    afis_vect(d,n);
    afis_vect(t,n);
       }
}
 void afisare(int x)
 { cout<<"\ndrumul de la  "<<x<<"  la:";
   for(int i=1;i<=n;i++)
     if(i!=x)
       if(t[i]!=0)
       {cout<<"\ndrumul cu costul minim de la nodul  "<<x;
       cout<<" la nodul  "<<i<<"  are costul   "<<d[i]<<endl;
       cout<<"\nsi trece prin: ";
       drum(i);
       cout<<endl;
       }
     else cout<<"\nNu exista drum de la "<<x<<" la "<<i<<endl;
    }


 int main()
 {
 cout<<"\nmatricea costurilor  "<<endl;
 citire("graf.in",a,n);
 afisare(a,n);
 cout<<"\de unde pleci? ";
 cin>>x;
 dij(x);
 afisare(x);
 }
