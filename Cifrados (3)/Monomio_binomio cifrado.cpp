#include <iostream>
#include <string>

using namespace std;

class monomio_binomio
{
  public:
  string alfabeto;
  monomio_binomio();
  string cypher(string msj);
  string decypher(string msjcif);
};
monomio_binomio::monomio_binomio()
{
  alfabeto="D-ENAR-IOSBCFGHJKLMÑPQTUVWXYZ.";
}
string monomio_binomio::cypher(string msj)
{
  string msjcif;
  int aux;
  for(int i=0;i<msj.length();i++)
  {
    aux=alfabeto.find(msj[i]);
    aux++;
    if(aux>20)
      msjcif+="7";
    if(aux>10 && aux<21)
      msjcif+="2"; 
    msjcif+=to_string(aux%10);  
  }
  return msjcif;
}
string monomio_binomio::decypher(string msjcif)
{
  string msjdes;
  string aux;
  int aux2;
  int lalf=alfabeto.length();
  for(int i=0;i<msjcif.length();i++)
  {
    if(msjcif[i]=='7')
    {
      aux=msjcif[i+1];
      aux2=stoi(aux);
      msjdes+=alfabeto[(aux2+20%lalf)-1];
      i++;
    }
    else if(msjcif[i]=='2')
    {
      aux=msjcif[i+1];
      aux2=stoi(aux);
      msjdes+=alfabeto[(aux2+10%lalf)-1];
      i++;
    }
    else
    {
      aux=msjcif[i];
      aux2=stoi(aux);
      msjdes+=alfabeto[(aux2%lalf)-1];
    }
  }
  return msjdes;
}

int main()
{
  monomio_binomio monomio_binomio;
  string msj1,msj2;
  msj1=monomio_binomio.cypher("PQTUV");
  msj2=monomio_binomio.decypher(msj1);
  cout<<msj1<<endl;
  cout<<msj2;
}}