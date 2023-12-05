/**
* Title: Algorithm analysis & Sorting
* Author : Efe Tokar
* ID: 22103299
* Section : 1
* Homework : 1
* Description : sorting.cpp
*/

using namespace std;
#include <algorithm>
#include "sorting.h"

void insertionSort(int *arr, const int size, int &compCount, int &moveCount){
    compCount=0;
    moveCount=0;
    for(int i=1; i<size; i++){
        int next= arr[i];
        int j= i;

        for(j=i; j>0 && (arr[j-1]> next); j--){
            arr[j]= arr[j-1];
            moveCount++;
            compCount++;
        }

        arr[j]= next;
        moveCount += 3;
    }
}

int largest(int*arr,int size, int &compCount){
    int i=0;
    for(int j=1; j<size; j++){
        compCount++;
        if(arr[j]>arr[i]){
            i=j;
        }
    }
    return i;
}

void selectionSort(int *arr, const int size, int &compCount, int &moveCount){
    compCount=0;
    moveCount=0;
    for(int i= size-1; i>=1; i--){
        int l= largest(arr,i+1, compCount);
        std::swap(arr[l],arr[i]);
        moveCount +=3;
    }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    compCount=0;
    moveCount=0;
    mergeSortHelper(arr, 0, (size-1), size, compCount, moveCount);
}

void mergeSortHelper(int *arr, int first, int last, int size, int &compCount, int &moveCount){
    if(first<last){
        int mid= first + (last-first)/2;
        mergeSortHelper(arr,first,mid,size, compCount, moveCount);
        mergeSortHelper(arr, mid+1, last, size, compCount, moveCount);
        merge(arr, first, mid, last, size, compCount, moveCount);
    }
}

void merge(int *arr, int first, int mid, int last, int size, int &compCount, int &moveCount){
    int temp[size];
    int f1= first;
    int l1= mid;
    int f2= mid+1;
    int l2= last;
    int i=f1;

    for(; (f1 <= l1) && (f2 <= l2); i++){
        compCount++;
        if(arr[f1] <= arr[f2]){
            temp[i]=arr[f1];
            f1++;
            moveCount++;
        }
        else{
            temp[i]=arr[f2];
            f2++;
            moveCount++;
        }
    }

    for(; (f1 <= l1); i++){
        temp[i]= arr[f1];
        moveCount++;
        f1++;
    }

    for(; (f2 <= l2); i++){
        temp[i]= arr[f2];
        moveCount++;
        f2++;
    }

    for( i=first; i<=last; i++){
        arr[i]= temp[i];
        moveCount++;
    }

}

void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    compCount=0;
    moveCount=0;
    quickSortHelper(arr,0,(size-1),size,compCount, moveCount);
}

void quickSortHelper(int *arr, int first, int last, const int size, int &compCount, int &moveCount){
    int pivotIndex;
    if(first<last){
        partition(arr,first,last,pivotIndex,compCount,moveCount);
        quickSortHelper(arr,first,pivotIndex-1,size,compCount,moveCount);
        quickSortHelper(arr,pivotIndex+1,last,size,compCount,moveCount);
    }
}

void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount){
    int pivot = arr[first];
    int lastS1 = first;
    int firstUnknown = first + 1;
    for (  ; firstUnknown <= last; ++firstUnknown) {
        compCount++;
        if (arr[firstUnknown] < pivot) {
            ++lastS1;
            std::swap(arr[firstUnknown], arr[lastS1]);
            moveCount+=3;
        }
    }
    std::swap(arr[first], arr[lastS1]);
    moveCount+=3;
    pivotIndex = lastS1;
}

void hybridSort(int *arr, const int size, int &compCount, int &moveCount){
    compCount=0;
    moveCount=0;
    hybridSortHelper(arr,0,(size-1), size,compCount, moveCount);
}

void hybridSortHelper(int *arr, int first, int last, int size, int &compCount, int &moveCount){
    if(first<last){
        if((last-first) <= 20){
            //bubble sort algorithm
            int sorted=0;
            for(int i=first+1; (i<=last && sorted==0 ); i++){
                sorted=1;
                for(int j=first; j<last-+1; j++){
                    int next= j+1;
                    compCount++;
                    if( arr[j] > arr[next]){
                        std::swap(arr[j], arr[next]);
                        moveCount +=3;
                        sorted=0;
                    }
                }
            }
        }
        else{
            int mid= first + (last-first)/2;
            hybridSortHelper(arr,first,mid,size, compCount, moveCount);
            hybridSortHelper(arr, mid+1, last,size, compCount, moveCount);
            merge(arr, first, mid, last, size, compCount, moveCount);
        }
    }
}


