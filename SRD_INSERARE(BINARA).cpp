#include<fstream>
#include<iostream>
#include<string>
using namespace std;

struct nod
{
    int nr;
    nod *st,*dr;
};
nod *c;

void inserare(nod*&c, int k)
{
    if(c)
        {if(c->nr==k)
            cout<<"Nod deja inserat"<<endl;
        else
            {
                if(c->nr<k) inserare(c->dr,k);
                else inserare(c->st,k);
            }
        }
    else
    {
        c=new nod;
        c->nr=k;
        c->dr=c->st=0;
    }
}

void SRD(nod* c)
{
    if(c)
    {
        SRD(c->st);
        cout << c->nr << " ";
        SRD(c->dr);
    }
}

 int main()
 {
     int n;
     cout<<"Cate noduri ai?"<<endl;cin>>n;
    for(int i=1;i<=n;i++)
        inserare(c,i);
    SRD(c);

    return 0;
 }
