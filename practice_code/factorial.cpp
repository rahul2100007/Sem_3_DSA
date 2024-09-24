#include <iostream>
using namespace std;
void factorial(long long num){
    long long n=1;
    if(num==0){
        cout<<"0";
    }
    else{
    for(int i=1;i<=num;i++)
    {
        n*=i;
    }
    cout<<n;
    }
}
int main()
{
    long long n;
    char ch;
    label:
    do{
    cout<<"\nenter a number";
    cin>>n;
    factorial(n);
    }while(n!=0);
    return 0;
}