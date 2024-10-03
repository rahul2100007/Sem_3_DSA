#include <iostream>
using namespace std;
void sumprdt(int arr[], int size)
{
    int sum = 0, prdt = 1;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        prdt *= arr[i];
    }

    cout << "SUM OF ARRAY = " << sum << endl;
    cout << "PRODUCT OF ARRAY = " << prdt << endl;
}
void lw_hi(int arr[], int size)
{
    int smallest = INT_FAST32_MAX;
    int largest = INT_FAST32_MIN;
    for (int i = 0; i < size; i++)
    {
        if (smallest > arr[i])
        {
            smallest = arr[i];
        }
        else
        {
            continue;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
        else
        {
            continue;
        }
    }
    cout << "LARGEST VALUE OF ARRAY = " << largest << endl;
    cout << "SMALLEST VALUE OF ARRAY = " << smallest << endl;
}
void unique(int arr[], int size)
{
    int count;
    cout<<"Unique values = ";
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << arr[i] << " ";
        }
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
    cout<<endl;
    sumprdt(array, size);
    cout<<endl;
    lw_hi(array, size);
    cout<<endl;
    unique(array, size);
    return 0;
}