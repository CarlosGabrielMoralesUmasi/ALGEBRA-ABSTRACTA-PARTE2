#include <iostream>
#include <math.h>
using namespace std;

void crib_era(int x)
{
  bool num_prim[x];
  for(int i=0;i<x;i++)
  {
    num_prim[i]=false;
  }

  for(int j=2;j*j<=x;j++)
  {
    if(!(num_prim[j]))
    {
      for(int n=j*j;n<=x;n+=j)
      {
        num_prim[n]=true;
      }
    }
  }

  for(int l=2;l<=x;l++)
  {
    if(!num_prim[l])
    {
      cout<<l<<" ";
    }
  }
}
int main() 
{ 
  int x; 
  cout<<"Escriba el numero: ";
  cin>>x;
  crib_era(x);
}