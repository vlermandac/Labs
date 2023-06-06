#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;

void bubbleSort() {
}

int main() {
    srand(time(NULL)); 
    ofstream outfile("results.csv");
    outfile << "n,bubble_sort\n";
    int N, n_1, i, num_experiments;
    for(int n = n_1; n <= N; n += i){
        double bubble_sort_total_time = 0;
        for(){ // Realiza varios experimentos para cada tamaño de vector
            auto start_time = chrono::high_resolution_clock::now();
            bubbleSort();
            auto end_time = chrono::high_resolution_clock::now();
            auto bubble_sort_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
            bubble_sort_total_time += bubble_sort_time;
        }
        double bubble_sort_avg_time = bubble_sort_total_time / num_experiments;
        outfile << n << "," << bubble_sort_avg_time <<endl;
    }
    outfile.close(); 

    return 0;
}
