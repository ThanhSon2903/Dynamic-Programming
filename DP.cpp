/*
Bai 1
Tim tong duong di lon nhat trong ma tran

5 5
1 0 31 5 25 
28 26 32 46 7 
26 40 36 13 16 
7 26 14 6 11 
42 45 11 10 21 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    int a[n+5][m+5],b[n+5][m+5];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1){
                b[i][j] = a[i][j];
            }
            else if(i==1){
                b[i][j] = a[i][j] + b[i][j-1];
            }
            else if(j==1){
                b[i][j] = a[i][j] + b[i-1][j];
            }
            else{
                b[i][j] = a[i][j] + max(b[i-1][j-1],max(b[i][j-1],b[i-1][j]));
            }
        }
    }

    cout << b[n][m] << endl;
    return 0;
}


/*
Bai2
Bài Toán Dãy Con Tăng Dài Nhất (LIS)
2 3 4 1 5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<int>a(n),L(n,1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i] > a[j]){
                L[i] = max(L[i],L[j]+1);
            }
        }
    }
    cout << *max_element(L.begin(),L.end()) << endl;
}


/*
Bai3
Xâu Con Chung Dài Nhất Quy Hoạch Động | LCS Problem
string x: acbaed
string y: abcade
Lap bang phuong an
dp[i][j]: Luu do dai xau con chung dai nhat co duoc boi lay i ky tu dau tien cua xau X va j ky tu dau tien cua Y
cout << dp[x.size()][y.size()] << end;
*/
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string x,y;cin>>x>>y;
    int n=x.size(),m=y.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }
            else{
                if(x[i-1]==y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}

/*
Bai4
01 Knapsack
*/
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
    
    return 0;
}

/*
Bai5
Fibonacci Numbers
*/
#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[100] ;
unsigned long long solve(int n){
    if(n<=1){//Truong hop co so
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = solve(n-1) + solve(n-2);
    return dp[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;cin>>tc;
    memset(dp,-1,sizeof(dp));
    while(tc--){
        int n;cin>>n;
        cout << solve(n) << endl;
    }
    return 0;
}

/*
Bai6: 
Xuc sac
*/
//Vi du n=4: F[4] = F[3] + F[2] + F[1] + F[0];
//Do phuc tap: O(n*i);
/*
Cach buoc de giai 1 bai DP
1.Vi du Bai 6

        | 1 neu i = 0(Bai toan co so)
F[i] =  |
        |Sum+=(F[i-j]) voi i>0va j = 1--->6
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define maxn 1000006
#define FastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr);
ll dp[maxn];
int main(){
    FastIO();
    int n;cin>>n;
    dp[0] = 1;//Truong hop co so
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i>=j){
                (dp[i]+=dp[i-j])%=MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
/*
Bai7:Tim duong di tren luoi tu (1,1) --> (n,n)
o o o o
o x o x
o o o x
x o o o
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define maxn 1003
int n;
int dp[maxn][maxn];char a[maxn][maxn];
//dp[i][j]: so cach tu o thu i den o thu j
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
                if(i==1&&j==1){
                    dp[i][j] = 1;//Truong hop co so khi i=1&&j=1
                }
            }
        }
    }
    cout << dp[n][n];
    return 0;
}


// 1 dp[0][0]
// 1 1 dp[0][1]
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
// 1 6 15 20 15 6 1
// 1 7 21 35 35 21 7 1
// 1 8 28 56 70 56 28 8 1
// 1 9 36 85 126 126 75 36 9 1
//Bai8: To hop hay tam giac pascal
#include<bits/stdc++.h>
using namespace std;
#define maxn 1001
#define endl "\n"
#define MOD 1000000007
int dp[maxn][maxn];
int n,k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<=1000;i++){
        dp[i][0] = dp[i][i] = 1;
    }
    for(int i=2;i<=1000;i++){
        for(int j=1;j<i;j++){
            dp[i][j] += (dp[i-1][j] + dp[i-1][j-1])%MOD; 
        }
    }
    int tc;cin>>tc;
    while(tc--){
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}


/*
Bai9: Tong doan tu l->r
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000000
#define endl "\n"
#define MOD 1000000007
/*
3
1 2 3
3
1 3
1 2
2 3
*/
ll Prev[maxn] = {0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin >> a[i];
        Prev[i] = Prev[i-1] + a[i];
    }
    int tc;cin>>tc;
    while(tc--){
        int l,r;cin>>l>>r;
        cout << Prev[r] - Prev[l-1]<< endl;
    }
    return 0;
}

/*
Bai10: Doan con co tong Max
*/
