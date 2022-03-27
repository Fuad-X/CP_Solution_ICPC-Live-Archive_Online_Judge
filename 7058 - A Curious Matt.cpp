#include <iostream>

using namespace std;

int arr[2][1000000];

void marge(int l, int m, int r)
{
    int size1 = m-l+1;
    int size2 = r-m;
    
    int arr1[2][size1];
    int arr2[2][size2];
    
    for(int i=0; i<size1; i++)
    {
        arr1[0][i]=arr[0][i+l];
        arr1[1][i]=arr[1][i+l]; 
    }
    
    for(int i=0; i<size2; i++)
    {
        arr2[0][i]=arr[0][i+m+1];
        arr2[1][i]=arr[1][i+m+1]; 
    }
    
    int i=0, j=0, k=l;
    
    while(i<size1 && j<size2)
    {
        if(arr1[0][i] <= arr2[0][j])
        {
            arr[0][k] = arr1[0][i];
            arr[1][k] = arr1[1][i];
            i++;
        }
        else
        {
            arr[0][k] = arr2[0][j];
            arr[1][k] = arr2[1][j];
            j++;
        }
        k++;
    }
    
    while(i<size1)
    {
        arr[0][k] = arr1[0][i];
        arr[1][k] = arr1[1][i];
        i++;
        k++;
    }
    
    while(j<size2)
    {
        arr[0][k] = arr2[0][j];
        arr[1][k] = arr2[1][j];
        j++;
        k++;
    }
}

void margeSort(int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        margeSort(l, m);
        margeSort(m+1, r);
        marge(l, m, r);
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        int size;
        cin >>size;
        for(int j=0; j<size; j++)
        {
            cin >> arr[0][j] >> arr[1][j];
        }
        
        margeSort(0, size-1);
        
        double max = 0;
        for(int j=0; j<size-1; j++)
        {
            double comp = (double)abs(arr[1][j]-arr[1][j+1])/(double)abs(arr[0][j]-arr[0][j+1]);
            if( comp> max) 
                max = comp;
        }
        
        printf("Case #%d: %.2lf\n", i, max);
    }
   
   return 0;
}
