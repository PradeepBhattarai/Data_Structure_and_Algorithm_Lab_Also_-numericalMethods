#include<iostream>
using namespace std;


int main()
{
    cout<<"Enter the no of unknown values: ";
    int n;
    cin>>n;
    float a[n][n+1],x[n];
    cout<<"Enter the coffecients of system of equation :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=j)
            {
                float temp=a[i][j]/a[j][j];
                for(int k=0;k<n+1;k++)
                {
                    a[i][k]=a[i][k]-temp*a[j][k];
                }
            }
        }
    }
    cout<<"The solution is:\n";
    for(int i=0;i<n;i++)
    {
        x[i]=a[i][n]/a[i][i];
        cout<<"x"<<i<<" = "<<x[i]<<endl;
    }

    return 0;
}