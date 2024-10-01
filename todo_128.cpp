// Example program
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdint.h>
#include <bits/stdc++.h>
#include <immintrin.h>
#define M 144

using namespace std;


void transpose(const uint64_t a[M][M], uint64_t b[M][M]) {
    //===================only modify it this region=================================


    const int tileSize = 1024; // Size of the tiles
    const int unrollFactor = 12; // Number of loop iterations to process per iteration
    for (int ii = 0; ii < M; ii += tileSize) {
        for (int jj = 0; jj < M; jj += tileSize) {
            for (int i = ii; i < min(ii + tileSize, M); i += unrollFactor) {
                for (int j = jj; j < min(jj + tileSize, M); j++) {
                    for (int k = 0; k < unrollFactor; k++) {
                        if (i + k < M) {
                            b[j][i + k] = a[i + k][j];
                        }
                    }
                }
            }
        }
    }





    //==============================================================================
}