

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m=1024;
    int tileSize = 16;
    // int a[1024][1024];
    // int b[1024][1024];
    // int c[1024][1024];
    // for (int m=0;m<3;m++) {
            // Initialize matrices A, B, and C
            int** a = new int*[m];
            int** b = new int*[m];
            int** c = new int*[m];
            for (int i = 0; i < m; ++i) {
                a[i] = new int[m];
                b[i] = new int[m];
                c[i] = new int[m];
            }
    for(int i=0;i<m;i++)
    {
        for(int j=0; j<m; j++)
        {
            a[i][j]= rand() % 100;
            b[i][j] = rand() % 100;
           // c[i][j] = 0;
        }
        
    }
    
    clock_t start, end;
    
    start = clock();

//logic for matrix multiplicatioj using loop tiling

 for (int i = 0; i < m; i += tileSize) {
        for (int j = 0; j < m; j += tileSize) {
            for (int k = 0; k < m; k += tileSize) {
                for (int ii = i; ii < min(i + tileSize, m); ++ii) {
                    for (int jj = j; jj < min(j + tileSize, m); ++jj) {
                        for (int kk = k; kk < min(k + tileSize, m); ++kk) {
                            c[ii][jj] += a[ii][kk] * b[kk][jj];
                        }
                    }
                }
            }
        }
    }
    
    end = clock();
    
    double ti = double(end - start)/double(CLOCKS_PER_SEC);
    cout << "time for size of 1024, block size of 16: " << ti<<" sec";
    //cout << "time for size of 4096, block size of 256:" << ti<<" sec";
    
    // Deallocate memory
            for (int i = 0; i < m; ++i) {
                delete[] a[i];
                delete[] b[i];
                delete[] c[i];
            }
            delete[] a;
            delete[] b;
            delete[] c;
    return 0;
}
