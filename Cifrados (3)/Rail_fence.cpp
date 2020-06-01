int main()
{
    int i,len,j=0,k=0;
    char texto[15],cif[15],str1[10],str2[10];
    cout<<"Enter texto Text:";
    cin>>texto;
    cout<<endl;
    len=strlen(texto);
    for(i=0;i<len;i++)
    {
        if(i%2==0)
        {
            str1[j]=texto[i];
            j++;
        }
        else
            {
                str2[k]=texto[i];
                k++;
            }
        }
    j=0;

    cout<<"Str1:"<<str1<<endl<<"Str2:"<<str2;
}