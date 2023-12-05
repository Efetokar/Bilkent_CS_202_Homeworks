/**
* Title: Algorithm analysis & Sorting
* Author : Efe Tokar
* ID: 22103299
* Section : 1
* Homework : 1
* Description : sorting.h
*/

using namespace std;
#ifndef CS202_HW1_SORTING_H
#define CS202_HW1_SORTING_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <chrono>

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
int largest(int*arr,int size,int &compCount);
void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSortHelper(int *arr, int first, int last, int size, int &compCount, int &moveCount);
void merge(int *arr, int first, int mid, int last, int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSortHelper(int *arr, int first, int last, const int size, int &compCount, int &moveCount);
void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void hybridSort(int *arr, const int size, int &compCount, int &moveCount);
void hybridSortHelper(int *arr, int first, int last, int size, int &compCount, int &moveCount);

#endif //CS202_HW1_SORTING_H
