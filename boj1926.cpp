// 1926번 그림
#include <bits/stdc++.h>
using namespace std;;
#define X first
#define Y second 
int board[502][502];    // 입력 받을 칸
bool vis[502][502];     // 해당 칸 방문 여부 표시
int n, m;               // n : 행의 수, m : 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    queue<pair<int,int> > Q;
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int pic_count=0, max_area = 0;

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if (board[i][j] == 1 && !vis[i][j]) {
                pic_count++;
                vis[i][j] = 1;
                Q.push({i, j});
                int area = 0;

                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    area++;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                if(max_area < area)
                    max_area = area;
            }
        }
    }

    cout << pic_count << '\n' << max_area;
}