#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using std::string;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

// Get the pivot for array, with 
int partition(float *arr, int left, int right) {
    float pivot = arr[left];

    // find middle value
    int middle = 0;
    for(int i=left+1;i<=right;i++) {
        if(arr[i] <= pivot)
            middle++;
    }

    int pivotIndex = left+middle;
    std::swap(arr[pivotIndex], arr[left]);

    int i = left, j = right;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

// Implemented Quick Sort Algo, using array and beginning and end index
void quickSort(float *arr, int left, int right) {
    if(left < right) {
        int p = partition(arr, left, right);
        // Sort left side
        quickSort(arr, left, p-1);
        // Sort right side
        quickSort(arr, p+1, right);
    } else
        return;
    
}

// Read file and get array
vector<float> readInputFile(const string& inputFile) {
    ifstream fileIn;
    fileIn.open(inputFile);
    string in;
    vector<float> vec;
    while(fileIn.good()) {
        fileIn >> in;
        vec.push_back(std::stof(in));
    }
    return vec;
}

// Output sorted array to file
void printQuickSort(float *a, int n,const string& outputFile) {
    std::ofstream fileOut(outputFile);
    for(int i=0;i<n;i++) {
        fileOut << a[i] << " ";
    }
    fileOut.close();
}

// Ouput to Execution Time file
void writeOutputFile(const string& size, float exTime, const string& outputFile) {
    std::ofstream fileOut(outputFile, ofstream::app); //append to file, don't overwrite
    fileOut << size << "\t" << exTime << endl;
    fileOut.close();
}

int main(int argc, char *argv[]) {
    string inputFile = argv[1], outputFile = argv[2];
    string size = inputFile.substr(6,inputFile.find_last_of('_')-6);

    vector<float> vec = readInputFile(inputFile);
    int n = vec.size()-1;
    float a[n];
    for(int i=0;i<n;i++) {
        a[i] = vec[i];
    }

    // Sort the array and time it
    float start=clock();
    quickSort(a,0,n-1);
    float stop=clock();

    // execution time in microseconds
    float exTime = (stop-start)/float(CLOCKS_PER_SEC)/1000;

    if(outputFile.find("output") == 0)
        printQuickSort(a,n,"output.txt");
    else
        writeOutputFile(size,exTime,outputFile);

    return 0;
}


