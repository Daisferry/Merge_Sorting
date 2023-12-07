#include <iostream>

using namespace std;


//prototypes
void mergeSort(int* unsArr, int sizeArr);
void merge(int* unsArr, int* subArr_1, int subArrSize_1, int* subArr_2, int subArrSize_2);



//merging function -> needs closer inspection ; status: unimplemented
void merge(int* unsArr, int* subArr_1, int subArrSize_1, int* subArr_2, int subArrSize_2) {
    int i = 0, j = 0, k = 0;

    while (i < subArrSize_1 && j < subArrSize_2) {
        if (subArr_1[i] <= subArr_2[j]) {
            unsArr[k] = subArr_1[i];
            i++;
        } else {
            unsArr[k] = subArr_2[j];
            j++;
        }
        k++;
    }

    while (i < subArrSize_1) {
        unsArr[k] = subArr_1[i];
        i++;
        k++;
    }

    while (j < subArrSize_2) {
        unsArr[k] = subArr_2[j];
        j++;
        k++;
    }
}



//will need to be int*() style, but used as void() for simplicity ; status: complete
void mergeSort(int* unsArr, int sizeArr)
{
    if (sizeArr <= 1)
    {
        return;
    }

    //initializing sizes for arrays
    int subArrSize_1 = (sizeArr/2);
    int subArrSize_2 = sizeArr - (sizeArr/2);

    //initializing 2 sub-arrays
    int* subArr_1 = new int [subArrSize_1];
    int* subArr_2 = new int [subArrSize_2];

    //inserting numbers in array 1
    for(int i = 0 ; i < subArrSize_1 ; i++ )
    {
        subArr_1[i] = unsArr[i];
        cout<< subArr_1[i]<<" ";
    }

    cout<<'\n';

    //inserting numbers in array 2
    for(int i = subArrSize_1 ; i < sizeArr ; i++ )
    {
        subArr_2[i - (subArrSize_1)] = unsArr[i];
        cout<<subArr_2[i - (subArrSize_1)]<<" ";
    }

    cout<<'\n';

    mergeSort(subArr_1, subArrSize_1);
    mergeSort(subArr_2, subArrSize_2);    

    //declaring iteration counters
    int subArrCount_1 = 0;
    int subArrCount_2 = 0;

    //comparing and merging arrays
    for(int i=0; i<sizeArr; i++)
    {
        if (subArrCount_1 < subArrSize_1 && (subArrCount_2 >= subArrSize_2 || subArr_1[subArrCount_1] <= subArr_2[subArrCount_2]))
        {
            unsArr[i] = subArr_1[subArrCount_1];
            subArrCount_1++;
        }
        else
        {
            unsArr[i] = subArr_2[subArrCount_2];
            subArrCount_2++;
        }
    }

    //allocating space by deleting unused heap mamory
    delete[] subArr_1;
    delete[] subArr_2;
}



int main()
{
    int numberofElements = 11;
    int* numberList = new int[numberofElements] { 10 , 9 , 5 , 4 , 11 , 6 , 1 , 8 , 3 , 2 , 7}; 

    for(int i=0; i<numberofElements; i++)
    {
        cout<<numberList[i]<<" ";
    }

    cout<<'\n';

    mergeSort(numberList, numberofElements);

    for(int i=0; i<numberofElements; i++)
    {
        cout<<numberList[i]<<" ";
    }

    delete[] numberList;

    return 0;
}