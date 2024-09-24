#include <iostream>
using namespace std;
void function(int array[], int size)
{
    int hi_Num, lw_num, hi_idx, lw_idx;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[i] > array[j] || array[i] == array[j])
            {
                count++;
            }
            else
            {
                continue;
            }
            if (count == size)
            {
                hi_Num = array[i];
                hi_idx = i;
            }
            else if (count == size - 1)
            {
                lw_num = array[i];
                lw_idx = i;
            }
        }
    }
    if (lw_idx > hi_idx)
    {
        int sum = 0;
        for (int i = hi_idx + 1; i < lw_idx; i++)
        {
            sum = sum + (lw_num - array[i]);
            if(i!=hi_idx+1){
                cout<<"+";
            }
            cout<<lw_num - array[i];
        }
        cout<<"="<<sum<<endl;
        //cout << sum;
    }
    
    else
    {
        int sum = 0;
        for (int i = hi_idx - 1; i > lw_idx; i--)
        {
            sum = sum + (lw_num - array[i]);
            if(i!=hi_idx+1){
                cout<<"+";
            }
            cout<<lw_num - array[i];
        }
        cout<<"="<<sum<<endl;
        //cout << sum;
    }
}
int main()
{
    int size;
    cout << "Enter array size:";
    cin >> size;
    int array[size];
    cout << "\nenter elements:";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    function(array, size);
}