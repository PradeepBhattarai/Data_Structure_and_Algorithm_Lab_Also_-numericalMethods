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
    //Elimination
    for(int i=0;i<n;i++)
    {
        if(a[i][i]<0.00005)
        {
            cout<<"Mathematical Error!"<<endl;
            return 0;
        }
        for(int j=i+1;j<n+1;j++)
        {
            float ratio=a[j][i]/a[i][i];
            for(int k=0;k<n+1;k++)
            {
                a[j][k]=a[j][k]-ratio*a[i][k];
            }
        }
    }
    //Backward Substitution
    x[n-1]=a[n-1][n]/a[n-1][n-1];

    for(int i=n-2;i>=0;i--)
    {
        x[i]=a[i][n];
        for(int j=i+1;j<n+1;j++)
        {
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }

    cout<<"The solution is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"x"<<i<<" = "<<x[i]<<endl;
    }

    return 0;
}