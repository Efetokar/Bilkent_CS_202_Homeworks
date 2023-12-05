/**
* Title: Algorithm analysis & Sorting
* Author : Efe Tokar
* ID: 22103299
* Section : 1
* Homework : 1
* Description : main.cpp
*/

using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include "sorting.h"
#include <cmath>

int compCountIS;
int moveCountIS;
int compCountSS;
int moveCountSS;
int compCountMS;
int moveCountMS;
int compCountQS;
int moveCountQS;
int compCountHS;
int moveCountHS;

void createRandomArr(int *&arr1, int *&arr2, int *&arr3,int *&arr4, int *&arr5, int size){
    int *arr= new int[size];
    for(int i=0; i<size; i++){
        arr[i]= rand() % 100;
    }
    arr1= new int[size];
    arr2= new int[size];
    arr3= new int[size];
    arr4= new int[size];
    arr5= new int[size];

    for(int i=0; i<size; i++){
        arr1[i]= arr[i];
        arr2[i]= arr[i];
        arr3[i]= arr[i];
        arr4[i]= arr[i];
        arr5[i]= arr[i];
    }
    delete[] arr;
}

 void createAscendingArr(int *&arr1, int *&arr2, int *&arr3,int *&arr4, int *&arr5, int size){
    int *arr= new int[size];
    //first we create a random array
     for(int i=0; i<size; i++){
         arr[i]= rand() % 100;
     }

     //The we sort it so it becomes an ascending array
     quickSort(arr,size,compCountQS,moveCountQS);

    int logN= log2(size);                //Number of elements each mini-array holds
    int times= size/logN;                   //Number of mini-arrays, except what's left
    int whatsLeft= size - (times*logN);     //Number of elements of what's left of the array

    for(int i=0; i<=times; i++){
        if(i==times){
            int* tempArr= new int[whatsLeft];
            //Filling the tempArr
            for(int j=0; j<whatsLeft;j++){
                tempArr[j]= arr[(i*logN)+j];
            }

            //Shuffle the tempArr
            std::random_device rg;
            std::mt19937 rng(rg());
            std::shuffle(tempArr, tempArr+whatsLeft, rng);

            //Putting the shuffled elements back to the original array
            for(int j=0; j<whatsLeft;j++){
                arr[(i*logN)+j]= tempArr[j];
            }

            delete[] tempArr;
        }

        else{                               //Except the last time loop goes here
            int* tempArr= new int[logN];
            //Filling the tempArr
            for(int j=0; j<logN;j++){
                tempArr[j]= arr[(i*logN)+j];
            }

            //Shuffle the tempArr
            std::random_device rg;
            std::mt19937 rng(rg());
            std::shuffle(tempArr, tempArr+logN, rng);

            //Putting the shuffled elements back to the original array
            for(int j=0; j<logN;j++){
                arr[(i*logN)+j]= tempArr[j];
            }



            delete[] tempArr;
        }

    }
     arr1= new int[size];
     arr2= new int[size];
     arr3= new int[size];
     arr4= new int[size];
     arr5= new int[size];

     for(int i=0; i<size; i++){
         arr1[i]= arr[i];
         arr2[i]= arr[i];
         arr3[i]= arr[i];
         arr4[i]= arr[i];
         arr5[i]= arr[i];
     }
     delete[] arr;

    }

void createDescendingArr(int *&arr1, int *&arr2, int *&arr3,int *&arr4, int *&arr5, int size){
    int *arr= new int[size];
    //first we create a random array
    for(int i=0; i<size; i++){
        arr[i]= rand() % 100;
    }

    //The we sort it so it becomes an ascending array
    quickSort(arr,size,compCountQS,moveCountQS);

    int *temp= new int[size];
    int tempIndex=size-1;
    for(int i=0; i<size; i++){
        temp[i]=arr[tempIndex];
        tempIndex--;
    }

    for(int i=0; i<size; i++){
        arr[i]=temp[i];
    }

    delete[] temp;

    int logN= log2(size);                //Number of elements each mini-array holds
    int times= size/logN;                   //Number of mini-arrays, except what's left
    int whatsLeft= size - (times*logN);     //Number of elements of what's left of the array

    for(int i=0; i<=times; i++){
        if(i==times){
            int* tempArr= new int[whatsLeft];
            //Filling the tempArr
            for(int j=0; j<whatsLeft;j++){
                tempArr[j]= arr[(i*logN)+j];
            }

            //Shuffle the tempArr
            std::random_device rg;
            std::mt19937 rng(rg());
            std::shuffle(tempArr, tempArr+whatsLeft, rng);

            //Putting the shuffled elements back to the original array
            for(int j=0; j<whatsLeft;j++){
                arr[(i*logN)+j]= tempArr[j];
            }

            delete[] tempArr;
        }

        else{                               //Except the last time loop goes here
            int* tempArr= new int[logN];
            //Filling the tempArr
            for(int j=0; j<logN;j++){
                tempArr[j]= arr[(i*logN)+j];
            }

            //Shuffle the tempArr
            std::random_device rg;
            std::mt19937 rng(rg());
            std::shuffle(tempArr, tempArr+logN, rng);

            //Putting the shuffled elements back to the original array
            for(int j=0; j<logN;j++){
                arr[(i*logN)+j]= tempArr[j];
            }



            delete[] tempArr;
        }

    }
    arr1= new int[size];
    arr2= new int[size];
    arr3= new int[size];
    arr4= new int[size];
    arr5= new int[size];

    for(int i=0; i<size; i++){
        arr1[i]= arr[i];
        arr2[i]= arr[i];
        arr3[i]= arr[i];
        arr4[i]= arr[i];
        arr5[i]= arr[i];
    }
    delete[] arr;

}

void printPerformance(){
    int size1=1000;
    int size2=5000;
    int size3=10000;
    int size4=20000;
    cout<< "Part 2-b-1: Performance analysis of random integers array" <<endl;
    cout<< "----------------------------------------------------------"<<endl;
    int* arr1;
    int* arr2;
    int* arr3;
    int* arr4;
    int* arr5;
    cout<< "Elapsed time Comp. count Move count" <<endl;

    cout<< "Array Size: 1000" <<endl;
    createRandomArr(arr1,arr2,arr3,arr4,arr5,size1);

    clock_t start= clock();
    insertionSort(arr1,size1,compCountIS, moveCountIS);
    clock_t end= clock();
    double time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr2,size1,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr3,size1,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr4,size1,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr5,size1,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 5000" <<endl;
    createRandomArr(arr1,arr2,arr3,arr4,arr5,size2);

    start= clock();
    insertionSort(arr1,size2,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr2,size2,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr3,size2,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr4,size2,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr5,size2,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 10000" <<endl;
    createRandomArr(arr1,arr2,arr3,arr4,arr5,size3);

    start= clock();
    insertionSort(arr1,size3,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr2,size3,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr3,size3,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr4,size3,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr5,size3,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 20000" <<endl;
    createRandomArr(arr1,arr2,arr3,arr4,arr5,size4);

    start= clock();
    insertionSort(arr1,size4,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr2,size4,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr3,size4,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr4,size4,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr5,size4,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<< "----------------------------------------------------------"<<endl;

    cout<< "Part 2-b-2: Performance analysis of partially ascending integers array" <<endl;
    cout<< "----------------------------------------------------------"<<endl;
    int* arr6;
    int* arr7;
    int* arr8;
    int* arr9;
    int* arr10;
    cout<< "Elapsed time Comp. count Move count" <<endl;

    cout<< "Array Size: 1000" <<endl;
    createAscendingArr(arr6,arr7,arr8,arr9,arr10,size1);

    start= clock();
    insertionSort(arr6,size1,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr7,size1,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr8,size1,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr9,size1,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr10,size1,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 5000" <<endl;
    createAscendingArr(arr6,arr7,arr8,arr9,arr10,size2);

    start= clock();
    insertionSort(arr6,size2,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr7,size2,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr8,size2,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr9,size2,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr10,size2,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 10000" <<endl;
    createAscendingArr(arr6,arr7,arr8,arr9,arr10,size3);

    start= clock();
    insertionSort(arr6,size3,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr7,size3,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr8,size3,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr9,size3,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr10,size3,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 20000" <<endl;
    createAscendingArr(arr6,arr7,arr8,arr9,arr10,size4);

    start= clock();
    insertionSort(arr6,size4,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr7,size4,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr8,size4,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr9,size4,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr10,size4,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    cout<< "----------------------------------------------------------"<<endl;

    cout<< "Part 2-b-3: Performance analysis of partially descending integers array" <<endl;
    cout<< "----------------------------------------------------------"<<endl;
    int* arr11;
    int* arr12;
    int* arr13;
    int* arr14;
    int* arr15;
    cout<< "Elapsed time Comp. count Move count" <<endl;

    cout<< "Array Size: 1000" <<endl;
    createDescendingArr(arr11,arr12,arr13,arr14,arr15,size1);

    start= clock();
    insertionSort(arr11,size1,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr12,size1,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr13,size1,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr14,size1,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr15,size1,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr11;
    delete[] arr12;
    delete[] arr13;
    delete[] arr14;
    delete[] arr15;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 5000" <<endl;
    createDescendingArr(arr11,arr12,arr13,arr14,arr15,size2);

    start= clock();
    insertionSort(arr11,size2,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr12,size2,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr13,size2,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr14,size2,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr15,size2,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr11;
    delete[] arr12;
    delete[] arr13;
    delete[] arr14;
    delete[] arr15;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 10000" <<endl;
    createDescendingArr(arr11,arr12,arr13,arr14,arr15,size3);

    start= clock();
    insertionSort(arr11,size3,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr12,size3,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr13,size3,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr14,size3,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr15,size3,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr11;
    delete[] arr12;
    delete[] arr13;
    delete[] arr14;
    delete[] arr15;

    cout<< "----------------------------------------------------------"<<endl;

    //------------------------------------------------------------------------------------------------------------------
    cout<< "Elapsed time Comp. count Move count" <<endl;
    cout<< "Array Size: 20000" <<endl;
    createDescendingArr(arr11,arr12,arr13,arr14,arr15,size4);

    start= clock();
    insertionSort(arr11,size4,compCountIS, moveCountIS);
    end= clock();
    time = static_cast<double>(end- start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Insertion Sort " << time << " ms " << compCountIS << " " << moveCountIS << endl;

    start = clock();
    selectionSort(arr12,size4,compCountSS, moveCountSS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Selection Sort " << time << " ms " << compCountSS << " " << moveCountSS << endl;

    start = clock();
    mergeSort(arr13,size4,compCountMS, moveCountMS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Merge Sort " << time << " ms " << compCountMS << " " << moveCountMS << endl;

    start = clock();
    quickSort(arr14,size4,compCountQS, moveCountQS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Quick Sort " << time << " ms " << compCountQS << " " << moveCountQS << endl;

    start = clock();
    hybridSort(arr15,size4,compCountHS, moveCountHS);
    end= clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout<< "Hybrid Sort " << time << " ms " << compCountHS << " " << moveCountHS << endl;

    delete[] arr11;
    delete[] arr12;
    delete[] arr13;
    delete[] arr14;
    delete[] arr15;

    cout<< "----------------------------------------------------------"<<endl;
}

int main() {
   /* int* arr1;
    int* arr2;
    int* arr3;
    int* arr4;
    int* arr5;
    int a;
    int b;
    createRandomArr(arr1,arr2,arr3,arr4,arr5,120);

    for(int i=0; i<120;i++){
        cout<< arr1[i] << " " ;
    }
    cout<< "" << endl;
    hybridSort(arr1,120,a,b);
    for(int i=0; i<120;i++){
        cout<< arr1[i] << " ";
    }
    cout<< "" << endl;*/
    printPerformance();
    return 0;
}