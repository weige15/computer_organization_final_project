// Example program
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdint.h>
#include <bits/stdc++.h>
#include <immintrin.h>
#define M 136


using namespace std;




void transpose(const uint64_t a[M][M], uint64_t b[M][M]) {
	//===================only modify in here===============================================





	int tileSize = 256; // Size of the tiles
	const int unrollFactor = 8; // Number of loop iterations to process per iteration

	for (int ii = 0; ii < M; ii += tileSize) {
        for (int jj = 0; jj < M; jj += tileSize) {
            for (int j = jj; j < min(jj + tileSize, M); j += unrollFactor) {
                // Prefetch the next tile of matrix a
                _mm_prefetch((char*)&a[ii + tileSize][j], _MM_HINT_T0);

                for (int i = ii; i < min(ii + tileSize, M); i++) {
                    for (int k = 0; k < unrollFactor; k++) {
                        if (j + k < M) {
                            b[j + k][i] = a[i][j + k];
                        }
                    }
                }

                // Prefetch the next set of elements from matrix a
                _mm_prefetch((char*)&a[ii][j + unrollFactor], _MM_HINT_T0);
            }
        }
    }




    // =======================================================================================
}