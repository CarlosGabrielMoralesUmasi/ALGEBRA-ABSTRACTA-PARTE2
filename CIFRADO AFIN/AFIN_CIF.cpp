#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Cif_Afin
{
  public:
  string alfabeto;
  int c,zn,c2;

  Cif_Afin(int _c);
  int mod(int x,int y);
  int mcd(int x, int y);
  int euclidesext(int x,int y);
  int inversa(int x,int y);
  string cifrar(string msj);
  string decifrar(string cmsj);
};

Cif_Afin::Cif_Afin(int _c)
{
  alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
  c=_c;
  zn=alfabeto.length();
  c2=mod(rand() % 100,zn);
}
int Cif_Afin::mod(int x,int y)
{int r;
  r=x-((x/y)*y);
  if(r<0)
    r=x-(((x/y)-1)*y);
  return r; 
}
int Cif_Afin::mcd(int x,int y)
{int r;
  r=mod(x,y);
  while (r > 0)
  { x=y;
    y=r;
    r = mod(x,y);
  }
return y;
}
int Cif_Afin::euclidesext(int x,int y)
{int q,s,t,r;
  int r1=x,r2=y,s1=1,s2=0,t1=0,t2=1;
  while(r2>0)
  {
    q=r1/r2;
    r=r1-q*r2;
    r1=r2;
    r2=r;

    s=s1-q*s2;
    s1=s2;
    s2=s;

    t=t1-q*t2;
    t1=t2;
    t2=t;
  }
  s=s1;
  t=t1;
return s;
}
int Cif_Afin::inversa(int x,int y)
{
  if(mcd(x,y)==1)
  {
    int inv=euclidesext(x,y);
    if(mod((inv*x),y)==1)
    {
      if (inv<0)
        inv=mod(inv,y);
      return inv;
    }
  }else
    return 0;
return 0;
}
string Cif_Afin::cifrar(string msj)
{int aux,aux2;
  string cmsj;
  for(int i=0;i<msj.length();i++)
  {
    aux=alfabeto.find(msj[i]);
    aux2=mod(((c*aux)+c2),zn);
    cmsj+=alfabeto[aux2];
  }
return cmsj;
}

string Cif_Afin::decifrar(string cmsj)
{int aux,aux2,aux3;
  string dmsj;
  aux=inversa(c,zn);
  if(!aux)
    return 0;
  for(int i=0;i<cmsj.length();i++)
  {
    aux2=alfabeto.find(cmsj[i]);
    aux3=mod(aux*(aux2-c2),zn);
    dmsj+=alfabeto[aux3];
  }
return dmsj;
}
int main()
{
  Cif_Afin Cif_Afin(23);
  string msj;
  cout<<"ESCRIBE MENSAJE: "<<endl;
  getline(cin,msj);
  //string cmsg=Cif_Afin.cifrar(msj);
  string dmsg=Cif_Afin.decifrar("BAMC");
  cout<<Cif_Afin.c2<<endl;
 // cout<<cmsg<<endl;
  cout<<dmsg<<endl;
}
