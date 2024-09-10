#include <iostream>
using namespace std;
class base
{
    public:
        double a=10.5;
};
class child
{
    public:
        base obj;
        double *b=&obj.a;
};
int main(){
    child c;
    base obj; 
    int x[2][4]={1,0,3,4,5,6,7,8};
   // cout<<&c.b<<endl;
   for(int i=0;i<2;i++)
   {
        for(int j=0;j<2;j++)
        {
                cout<<x[i][j]<<" ";
        }
        cout<<endl;
   }
    int *ptr=x[0]+1;
    cout<<*(ptr)+1<<" ";
    int *B=(int*)malloc(sizeof(B)*3);
    cout<<B<<endl;
    
    //cout<<*ptr<<endl;
    //ptr++;
    //cout<<ptr<<endl;
    //ptr++;
    //cout<<ptr;
   // cout<<(int) c.b<<endl;
   // cout<<sizeof(*c.b)<<endl;
   // cout<<sizeof(obj.a);
}