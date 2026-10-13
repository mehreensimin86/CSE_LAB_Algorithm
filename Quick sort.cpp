
#include<iostream>
using namespace std;
int Partition(int arr[], int low,int high)
{
    int pivot = arr[high];
    int i = low-1;
    for (int j=low;j<high;j++)
    {
        if(arr[j]<= pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);

    return i+1;
}

void quicksort(int arr[], int low, int high)
{
    int pivot;
    if (low < high){
   pivot = Partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot + 1, high);
}
}
int main()
{
    int n,pivot;
    cout << "Enter number of elements ";
    cin >> n;
    int arr[n];
    cout << "Enter elements ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}
