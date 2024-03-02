#include <bits/stdc++.h>

using namespace std;

struct activity{
    int start;
    int finish;
};

bool compare(activity a1, activity a2){
    return (a1.finish < a2. finish);
}

void activity_selection(activity arr[], int n){
    sort(arr, arr+ n, compare);

    int i = 0;
    cout<<"("<<arr[i].start<<","<<arr[i].finish<<") ";

    for(int j = 1;j< n;j++){
        if(arr[j].start >= arr[i].finish){
            i = j;
            cout<<"("<<arr[i].start<<","<<arr[i].finish<<") ";
        }
    }


}

int main()
{
    activity arr[] = { { 5, 9 }, { 1, 2 }, { 3, 4 },
                        { 0, 6 }, { 5, 7 }, { 8, 9 } };
        int n = sizeof(arr) / sizeof(arr[0]);

    activity_selection(arr, n);
    return 0;
}