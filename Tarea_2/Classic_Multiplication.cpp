// Blocked Matrix Multiplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <chrono>
#include <time.h>
#include <stdlib.h>

void classic(int** A, int** B, int** C, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}


void blocked(int** A, int** B, int** C, int n, int bsize) {
    int i, j, k, kk, jj;
    int sum;
    int en = bsize * (n / bsize); 

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = 0.0;

    for (kk = 0; kk < en; kk += bsize) {
        for (jj = 0; jj < en; jj += bsize) {
            for (i = 0; i < n; i++) {
                for (j = jj; j < jj + bsize; j++) {
                    sum = C[i][j];
                    for (k = kk; k < kk + bsize; k++) {
                        sum += A[i][k] * B[k][j];
                    }
                    C[i][j] = sum;

                }

            }
        }
    }
}


void Ini(int**& A, int**& B, int**& C, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int va = (int)rand() / (int)RAND_MAX;
            int vb = (int)rand() / (int)RAND_MAX;
            A[row][col] = va;
            B[row][col] = vb;
        }
    }
}


int main()
{
    int size = 1000;
    int** A = new int* [size];
    int** B = new int* [size];
    int** C = new int* [size];
    for (int i = 0; i < size; ++i) {
        A[i] = new int[size];
        B[i] = new int[size];
        C[i] = new int[size];
    }

    Ini(A, B, C, size);
    auto started = std::chrono::high_resolution_clock::now();
    classic(A, B, C, size);
//    blocked(A, B, C, size, 50);
    auto done = std::chrono::high_resolution_clock::now();
    std::cout << "Time : " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << std::endl;


    for (int i = 0; i < size; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;
}

