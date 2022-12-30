#include<iostream>
using namespace std;

void towerOfHanoi(int n,char from_rod,char aux_rod,char to_rod)
{
    if(n==0)
        return;
    towerOfHanoi(n-1,from_rod,to_rod,aux_rod);
    cout<<"Move disk "<<n<<" from rod "<<from_rod<<" to_rod "<<to_rod<<endl;
    towerOfHanoi(n-1,aux_rod,from_rod,to_rod);
}
int main()
{
    int n;
    cout<<"Enter the number of disks:";
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    return 0;
}