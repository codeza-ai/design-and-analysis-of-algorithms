#include <limits.h>
#include <iostream>
#include <stdbool.h>

using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

int max(int a, int b, int c){
    return max(a, max(b, c));
}

int maxCrossingSum(int arr[], int l, int m, int h){
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = m;i>= 0;i--){
        sum+= arr[i];
        if(sum > left_sum)left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for(int i = m;i <= h;i++){
        sum+= arr[i];
        if(sum > right_sum)right_sum = sum;
    }

    return max(left_sum + right_sum - arr[m], right_sum, left_sum);
}

int maxSubarraySum(int arr[], int l, int h){
    if(l > h )return INT_MIN;
    if(l == h)return arr[l];

    int m = (l+h)/2;

    return max(
        maxCrossingSum(arr, l, m, h),
        maxSubarraySum(arr, l, m - 1),
        maxSubarraySum(arr, m + 1, h)
    );
}

int main(){
    int arr[] = {2,3,4,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<maxSubarraySum(arr, 0, n-1);
}
