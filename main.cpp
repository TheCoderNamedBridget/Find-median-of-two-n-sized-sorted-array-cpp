/*
Bridget Naylor
SID:025531413
*/
#include <stdio.h>
#include <iostream>
using namespace std;

//Question 1:
// int returnBinaryBoundaryLine( int size, int list[] )
// {
//     int start = 0;
//     int end = size;
//     int middle = size / 2;
//     bool foundK = false;
//     while ( !foundK )
//     {
//         if ( (size == 1) || (list[ middle ] == 1 && list[ middle - 1 ] == 0) )
//         {
//             foundK = true;
//             return middle;
//         }
//         else if ( list[ middle ] == 0 )
//         {
//             start = middle;
//             middle += end - middle;
//         }
//         else if ( list[ middle ] == 1 )
//         {
//             end = middle;
//             middle = (middle + start) / 2;
//         }
        
//     }

//     return 0;
// }


//Question 2:
int calculateMedian( int n, int list[] )
{
    if ( n % 2 == 0 )
    {
        return (( list[ ( n / 2 ) - 1 ] + list[ n / 2 ] ) / 2);
    }
    else ( n % 2 == 1 );
    {
        return list[ n / 2 ];
    }
    
}

int findAddedListMedian( int n, int list1[], int list2[] )
{
    int start1,start2 = 0;
    int end1, end2 = n;
    
    int middle1 = (start1 + end1) / 2;
    int middle2 = (start2 + end2) / 2;
    
    int median1 = calculateMedian( n, list1 );
    int median2 = calculateMedian( n, list2 );
    
    if ( n <= 0 )
    {
        return -1;//bad list length output
    }
    else if ( n = 1)
    {
        return (list1[0] + list2[0]) / 2;
    }
    else if ( list1[ n - 1 ] < list2[ 0 ])
    {
        int miniList[2] = { list1[ n - 1 ], list2[ 0 ] };
        return calculateMedian( 2, miniList );
    }
    else if ( list2[ n - 1 ] < list2[ 0 ])
    {
        int miniList[2] = { list2[ n - 1 ], list1[ 0 ] };
        return calculateMedian( 2, miniList );
    }
    
    /*
    Cases to handle:
    list1 > list2
    list2 > list1
    list1 and list2 are not clearly < or >
    list1 == list2 if the median of both lists are equal 
    */
    bool medianFound = false;
    while ( !medianFound )
    {
        
        if ( median1 == median2 )//lists have same median
        {
            return median2;
        }
        else if ( median1 < median2 )
        {
            middle1 += middle1 + ( end1 - middle1);
            middle2 = ( middle2 + start2 ) / 2;
            
            median1 = list1[ middle1 ];
            median2 = list2[ middle2 ];
        }
        else if ( median1 > median2 )
        {
            middle2 += middle2 + ( end2 - middle2);
            middle1 = ( middle1 + start1 ) / 2;
            
            median2 = list1[ middle2 ];
            median1 = list2[ middle1 ];
        }
    }

}

int main()
{
    //Question 1:
    // int listSize;
    // cout<<"Enter size of list: "<<endl;
    // cin>>listSize;
    // int listBinary[listSize];
    // cout<<"input: a = ";
    // for ( int i = 0; i < listSize; i++)
    // {
    //     cin>>listBinary[i];
    //     if ( listBinary[i] != 0 && listBinary[i] != 1 )
    //     {
    //         cout<<"Non binary numbers detected. Try again"<<endl;
    //     }
    // }
    
    // cout<<"output: K = "<<returnBinaryBoundaryLine( listSize, listBinary )<<endl;
    
    
    //Question 2:
    int n;
    cout<<"Enter size of arrays: "<<endl;
    cin>>n;
    int array1[n];
    int array2[n];
    
    srand(time(0));
    int randomValue1 = rand() % n;
    int randomValue2 = rand() % n;
    for ( int i = 0; i < n; i++)//setting both arrays to random numbers that are increasing
    {
        array1[i] = randomValue1;
        array2[i] = randomValue2;
        cout<<"Random values1: "<<array1[i]<<endl;
        randomValue1 += rand() % n + 1;
        randomValue2 += rand() % n + 1;
    }
    
    cout<<"Median = "<<findAddedListMedian( n, array1, array2 )<<endl;
    
    return 0;
}


