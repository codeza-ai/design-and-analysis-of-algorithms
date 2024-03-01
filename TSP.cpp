#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define INF INT_MAX

int n;
int dist[10][10];
int dp[16][10];
vector<int> optimal_path;

int tsp(int mask, int pos) {
    if(mask == (1<<n) - 1) {
        return dist[pos][0];
    }
    if(dp[mask][pos] != -1) {
       return dp[mask][pos];
    }

    int ans = INF;

    for(int city=0; city<n; city++) {
        if((mask&(1<<city)) == 0) {
            int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

void find_optimal_path(int mask, int pos) {
    if(mask == (1<<n) - 1) {
        return;
    }

    int ans = INF;
    int next_city;

    for(int city=0; city<n; city++) {
        if((mask&(1<<city)) == 0) {
            int newAns = dist[pos][city] + dp[mask|(1<<city)][city];
            if(newAns < ans) {
                ans = newAns;
                next_city = city;
            }
        }
    }

    optimal_path.push_back(next_city);
    find_optimal_path(mask|(1<<next_city), next_city);
}

int main() {
    
    cin >> n;

    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dist[i][j];
        }
    }

    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            dp[i][j] = -1;
        }
    }

    cout<<tsp(1,0)<<endl;

    optimal_path.push_back(0);
    find_optimal_path(1, 0);

    
    for(int i=0; i<optimal_path.size(); i++) {
        cout<<optimal_path[i]<<" ";
    }
    cout<<endl;
   

    return 0;
}