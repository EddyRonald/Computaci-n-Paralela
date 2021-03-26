#include <iostream>
#include <chrono>
#include <time.h>
#include <stdlib.h>



int main() {
    const int max = 15000;
    int x[max], y[max];
    int** A = new int* [max];
    for (int i = 0; i < max; ++i)
        A[i] = new int[max];

    /* array initialization */
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            A[i][j] = rand() % 10000;
        }
    }

    for (int i = 0; i < max; i++) {
        x[i] = rand() % 10000;
        y[i] = 0;
    }


    auto started = std::chrono::high_resolution_clock::now();
    /* first pair of loops */
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto done = std::chrono::high_resolution_clock::now();
    std::cout<< "Time of first bucle : " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count()<<std::endl;





    /* assing y = 0 */
    for (int i = 0; i < max; i++) {
        y[i] = 0;
    }


    auto started_ = std::chrono::high_resolution_clock::now();
    /* second pair of loops */
    for (int j = 0; j < max; j++) {
        for (int i = 0; i < max; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto done_ = std::chrono::high_resolution_clock::now();
    std::cout << "Time of second bucle : " << std::chrono::duration_cast<std::chrono::milliseconds>(done_ - started_).count();

    return 0;
}
