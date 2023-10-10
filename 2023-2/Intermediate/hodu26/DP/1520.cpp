#include <bits/stdc++.h>

using namespace std;

int mapp[503][503];
int sub_paths[503][503];  // count paths start in idx

int dx[4] = {0, 0, 1,-1};
int dy[4] = {1,-1, 0, 0};

int find_path(int M, int N, pair<int,int> cur){
    if (cur.first == M-1 && cur.second == N-1) return 1;

    sub_paths[cur.first][cur.second]++;

    pair<int,int> nxt;

    for (int i=0;i<4;i++){
        nxt = make_pair(cur.first+dx[i],cur.second+dy[i]);

        if (nxt.first<0 || nxt.first>=M || nxt.second<0 || nxt.second>=N) continue;

        if (mapp[nxt.first][nxt.second] >= mapp[cur.first][cur.second]) continue;

        if (sub_paths[nxt.first][nxt.second] >= 0){
            sub_paths[cur.first][cur.second] += sub_paths[nxt.first][nxt.second];
            continue;
        }

        sub_paths[cur.first][cur.second] += find_path(M,N,nxt);
    }

    return sub_paths[cur.first][cur.second];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int M,N;

    cin >> M >> N;

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cin >> mapp[i][j];
        }
    }

    for (int i=0;i<M;i++){
        fill(sub_paths[i], sub_paths[i]+N, -1);
    }

    cout << find_path(M,N,{0,0});

    return 0;
}
