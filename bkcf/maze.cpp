#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

bool visited[MAX][MAX];
int  N,M,r,c;
int a[MAX][MAX];

void input(){
    cin >> N >> M >> r >> c;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> a[i][j];
}
bool check(int r, int c){
    return r >= 1 && r <= N && c >= 1 && c <= M && a[r][c] == 0 && ! visited[r][c];
}
void solve(){
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
        visited[i][j] = false;

    map<pair<int,int>, int> d;// khoang cach tu vi tri xuat phat den vi tri hien tai
    queue<pair<int,int> > Q;

    map<pair<int,int>, pair<int,int> > pred;
    stack<pair<int,int> > path;
    pair<int,int> start = pair<int,int>(r,c);
    pair<int,int> finish;
    Q.push(start);
    visited[r][c] = true;
    d[start] = 0;
    bool found = false;
    while(!Q.empty()){
        pair<int,int> p = Q.front(); Q.pop();


        for (int k = 0; k < 4; k++){
            int nr = p.first + dr[k];
            int nc = p.second + dc[k];
            if(nr < 1 || nr > N || nc < 1 || nc > M){
                cout << d[p] + 1 << endl;
                finish = pair<int,int>(nr,nc);
                pred[finish] = p;
                found = true;break;
            }
            if(check(nr,nc)){
                pair<int,int> np = pair<int,int>(nr,nc);
                Q.push(np);
                visited[nr][nc] = true;
                d[np] = d[p] + 1;
                pred[np] = p;
            }

        }
        if(found) break;
    }

    if(found){
        pair<int,int> p = finish;
        while(p != start){
            path.push(p);
            p = pred[p];
        }
        cout << "(" << start.first << "," << start.second << ") ";
        while(!path.empty()){
            p = path.top(); path.pop();
            cout << "(" << p.first << "," << p.second << ") ";
        }
    }
}
int main(){
    input();
    solve();
}
