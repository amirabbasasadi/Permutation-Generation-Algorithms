// Comparison of Permutation Generation Algorithms
// Implemented by : Amirabbas Asadi
#include<iostream>
#include<vector>
#include<string>
#include <chrono>
#include "includes/Algorithm1.h"
using namespace std;

int main(){
    // repeat times
    const int repeats = 10;
    // Test Array Allocation
    const int size = 10;
    char* elements = new char[size];
    if(!elements)
        throw runtime_error("can not allocate memory");
    elements[0] = 'A';
    elements[1] = 'B';
    elements[2] = 'C';
    elements[3] = 'D';
    elements[4] = 'E';
    elements[5] = 'F';
    elements[6] = 'G';
    elements[7] = 'H';
    elements[8] = 'I';
    elements[9] = 'J';
    // Test Algortihms
    vector<PermutationGenerator<char>*> algorithms;
    // consumed time for each algorithm
    algorithms.push_back(new Algorithm1<char>);
    vector<double> times;
    times.resize(algorithms.size());
    for(int i=0; i<algorithms.size(); i++){
        // show algortihm results and calculate time
        cout << "Algorithm " << i+1 << " :" << endl;
        long double sumOfElapsedTime = 0;
        for(int j=0; j<repeats; j++){
            algorithms[i]->setArray(elements, 5);
            algorithms[i]->shuffleArray();
            // start clock
            auto t_start = std::chrono::high_resolution_clock::now();
            algorithms[i]->generatePermutation();
            // end clock
            auto t_end = std::chrono::high_resolution_clock::now();
            double elaspedTimeMs = std::chrono::duration<double, std::milli>(t_end-t_start).count();
            sumOfElapsedTime += elaspedTimeMs;
        }
        times[i] = sumOfElapsedTime/repeats;
        cout << string(20, '-') << endl;
    }
    // show consumed time by each algortihm
    cout << "Time Table (in milliseconds) : " << endl;
    cout << "Repeat Times : " << repeats << endl;
    for(int i=0; i<algorithms.size(); i++)
        cout << "Algorithm " << i+1 << " Time : " << times[i] << endl;
    return 0;
}
