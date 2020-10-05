/*
Bridget Naylor
SID:025531413
*/
#include <stdio.h>
#include <iostream>
using namespace std;

//Question 1:
int returnBinaryBoundaryLine( int size, int list[] )
{
    int start = 0;
    int end = size;
    int middle = size / 2;
    bool foundK = false;
    while ( !foundK )
    {
        //cout<<"list[ middle ] "<<list[ middle ]<<" middle "<<middle<<endl;
        if ( (size == 1) || (list[ middle ] == 1 && list[ middle - 1 ] == 0) )
        {
            foundK = true;
            return middle;
        }
        else if ( list[ middle ] == 0 )
        {
            start = middle;
            middle += end - middle - 1;
            
        }
        else if ( list[ middle ] == 1 )
        {
            end = middle;
            middle = (middle + start) / 2;
            // if ( end == middle )
            // {
            //     return middle;
            // }
        }
        
    }

    return 0;
}


// //Question 2:
// int calculateMedian( int n, int list[] )
// {
//     if ( n % 2 == 0 )
//     {
//         return (( list[ ( n / 2 ) - 1 ] + list[ n / 2 ] ) / 2);
//     }
//     else ( n % 2 == 1 );
//     {
//         return list[ n / 2 ];
//     }
    
// }

// int findAddedListMedian( int n, int list1[], int list2[] )
// {
//     cout<<"in function "<<endl;
//     int start1 = 0;
//     int start2 = 0;
//     int end1 = n;
//     int end2 = n;
    
//     int middle1 = (start1 + end1) / 2;
//     int middle2 = (start2 + end2) / 2;
    
//     int median1 = calculateMedian( n, list1 );
//     int median2 = calculateMedian( n, list2 );
    
//     if ( n == 1)
//     {
//         cout<<"n = 1"<<endl;
//         return (list1[0] + list2[0]) / 2;
//     }
//     else if ( list1[ n - 1 ] < list2[ 0 ])
//     {
//         cout<<"list1 < list2 "<<list1[ n - 1 ]<<" "<<list2[ 0 ]<<endl;
//         int miniList[2] = { list1[ n - 1 ], list2[ 0 ] };
//         return calculateMedian( 2, miniList );
//     }
//     else if ( list2[ n - 1 ] < list2[ 0 ])
//     {
//         cout<<"list1 > list2 "<<list1[ n - 1 ]<<" "<<list2[ 0 ]<<endl;
//         int miniList[2] = { list2[ n - 1 ], list1[ 0 ] };
//         return calculateMedian( 2, miniList );
//     }
//     // else if ( n == 2)
//     // {
//     //     if ( list1[1] > list2[1] )
//     //     {
//     //         cout<<"here1"<<endl;
//     //         return (list1[0] + list1[1]) / 2;
//     //     }
//     //     cout<<"here2"<<endl;
//     //     return (list1[1] + list1[0]) / 2;
//     // }
    
//     /*
//     Cases to handle:
//     list1 > list2
//     list2 > list1
//     list1 and list2 are not clearly < or >
//     list1 == list2 if the median of both lists are equal 
//     */
//     bool medianFound = false;
//     while ( !medianFound )
//     {
//         cout<<"in N "<<n<<endl;
//         if ( median1 == median2 )//lists have same median
//         {
//             cout<<"med = med"<<endl;
//             return median2;
//         }
//         else if ( median1 < median2 )
//         {
//             cout<<"median1 "<<median1<<" < "<< "median2 "<<median2<<endl;
//             middle1 += ( n - middle1) -1;
//             middle2 = ( middle2 + start2 ) / 2;
//             cout<<"Core dump here? start1 "<<start1<<" middle1 "<<middle1<<endl;
//             cout<<"Core dump here? middle1 "<<middle1<<" middle2 "<<middle2<<endl;
//             cout<<"print "<<list1[ middle1 ]<<endl;
//             median1 = list1[ middle1 ];
//             cout<<"Core dump here?"<<endl;
//             median2 = list2[ middle2 ];
//             cout<<"guess not"<<endl;
//         }
//         else if ( median1 > median2 )
//         {
//             cout<<"median1 "<<median1<<" > "<< "median2 "<<median2<<endl;
//             middle2 += ( n - middle2) - 1;
//             middle1 = ( middle1 + start1 ) / 2;
//             cout<<"Core dump here? start1 "<<start1<<" middle1 "<<middle1<<endl;
//             cout<<"Core dump here? middle1 "<<middle1<<" middle2 "<<middle2<<endl;
//             median2 = list2[ middle2 ];
//             cout<<"Core dump here?"<<endl;
//             cout<<"print "<<list1[ middle1 ]<<endl;
//             median1 = list1[ middle1 ];
//             cout<<"guess not"<<endl;
//         }
//     }

// }

int main()
{
    //Question 1:
    int listSize;
    cout<<"Enter size of list: ";
    cin>>listSize;
    int listBinary[listSize];
    cout<<"input: a = ";
    for ( int i = 0; i < listSize; i++)
    {
        cin>>listBinary[i];
        if ( listBinary[i] != 0 && listBinary[i] != 1 )
        {
            cout<<"Non binary numbers detected. Try again"<<endl;
        }
    }
    
    cout<<"output: K = "<<returnBinaryBoundaryLine( listSize, listBinary )<<endl;
    
    
    //Question 2:
    // int n;
    // cout<<"Enter size of arrays: "<<endl;
    // cin>>n;
    // int array1[n];
    // int array2[n];
    // if ( n == 0)
    // {
    //     cout<<"invalid n value"<<endl;
    //     exit( 0 );
    // }
    // srand(time(0));
    // int randomValue1 = rand() % 100;
    // int randomValue2 = rand() % 100;
    // for ( int i = 0; i < n; i++)//setting both arrays to random numbers that are increasing
    // {
    //     array1[i] = randomValue1;
    //     array2[i] = randomValue2;
    //     cout<<"Random values1: "<<array1[i]<<endl;
    //     cout<<"Random values2: "<<array2[i]<<endl;
    //     randomValue1 += rand() % 100 + 1;
    //     randomValue2 += rand() % 100 + 1;
    // }
    // cout<<"N "<<n<<endl;
    // cout<<"Median = "<<findAddedListMedian( n, array1, array2 )<<endl;
    
    return 0;
}



