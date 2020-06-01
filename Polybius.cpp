#include <iostream>
#include <string>
using namespace std;

class polybius
{
  public:
  string alfabeto;
  string tabla;
  int tamtabla;
  polybius();
  string cifrado(string msj);
  string decifrado(string msjcif);
};
polybius::polybius()
{
  alfabeto="ABCDEFGHIKLMNOPQRSTUVWXYZ";
  tabla="ABCDE";
  tamtabla=tabla.length();
}
string polybius::cifrado(string msj)
{
  int aux,aux2,aux3;
  string msjcif;
  for(int i=0;i<msj.length();i++)
  {
    aux=alfabeto.find(msj[i]);
    aux2=aux%tamtabla;
    aux3=aux/tamtabla;
    msjcif+=tabla[aux3];
    msjcif+=tabla[aux2];
  }
  return msjcif;
}
string polybius::decifrado(string msjcif)
{
  int aux,aux2,aux3,aux4;
  string msjdes;
  for(int i=0;i<msjcif.length();i=i+2)
  {
    aux=tabla.find(msjcif[i]);
    aux2=tabla.find(msjcif[i+1]);
    msjdes+=alfabeto[aux*tamtabla+aux2];
  }
  return msjdes;
}

int main()
{
  polybius polybios;
  string msj1,msj2;
  msj1=polybios.cifrado("ABSTRACTA");
  msj2=polybios.decifrado(msj1);
  cout<<msj1<<endl;
  cout<<msj2<<endl;
}