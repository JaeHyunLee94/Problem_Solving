//
// Created by 이재현 on 2020/07/27.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int sol = 0;

void dfs(vector<vector<int>> &table, int starty, int startx) {

    int N = table.size();
    int M = table[0].size();

    for (int k = 0; k < 4; k++) {
        int nextx = startx + dx[k];
        int nexty = starty + dy[k];
        if (nextx >= 0 && nextx < M && nexty >= 0 && nexty < N && table[nexty][nextx] == 0) {
            table[nexty][nextx] = 2;
            dfs(table, nexty, nextx);
        }

    }

}

int dfs_all(vector<vector<int>> &table) {


    int N = table.size();
    int M = table[0].size();
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (table[i][j] == 2) {
                dfs(table, i, j);
            }

        }

    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (table[i][j] == 0) {
                count++;
            }

        }

    }

    return count;

}

void find_all(vector<vector<int>> &original_table, int left_wall) {

    int N = original_table.size();
    int M = original_table[0].size();

    if (left_wall == 0) {
        vector<vector<int>> table(original_table);
        sol = max(sol, dfs_all(table));
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (original_table[i][j] == 0) {
                original_table[i][j] = 1;
                find_all(original_table, left_wall - 1);
                original_table[i][j] = 0;
            }


        }
    }

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> table(N, vector<int>(M, 0));

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            int tmp;
            cin >> tmp;
            table[n][m] = tmp;

        }
    }

    find_all(table, 3);

    cout << sol;


}
