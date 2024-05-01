#include <vector>
#include <iostream>
#include <stdbool.h>
using namespace std;

int matrixChainMultiplication(int dim[], int n){
    int m[n][n];

    for(int i = 0;i< n;i++){
        m[i][i] = 0;
    }

    int i, j, k, L, q;

    for(L = 2;L < n;L++){
        for(i = 0; i < n - L + 1;i++){
            j = i + L - 1;

            m[i][j] = INT_MAX;
            for(k = i;k <= j- 1;k++){
                q = m[i][k] + m[k + 1][j] + dim[i-1]*dim[k]*dim[j];

                if(q < m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n-1];
}

int main(){
    int dim[] = {1,2,3,4};
    int n = sizeof(dim)/sizeof(dim[0]);

    cout<<matrixChainMultiplication(dim, n);
}
