#include<fstream>
#include<iostream>
#include<string>
using namespace std;

struct nod
{
    int nr, ap;
    nod *st,*dr;
};
nod *c;

void inserare(nod*&c, int k)
{
    if(c)
        {if(c->nr==k)
        {
            c->ap++;
        }
        else
            {
                if(c->nr<k) inserare(c->dr,k);
                else inserare(c->st,k);
            }
        }
    else
    {
        c=new nod;
        c->nr=k;c->ap=1;
        c->dr=c->st=0;
    }
}

void SRD(nod* c)
{
    if(c)
    {
        SRD(c->st);
        cout << c->nr << " aparente: "<<c->ap<<endl;
        SRD(c->dr);
    }
}

 int main()
 {
    int k;
    ifstream f("inser.in");
    while(f>>k)
        inserare(c,k);
    SRD(c);

    return 0;
 }

