#include <iostream>
#include <vector>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int test_case = 0;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        int n = 0;
        cin >> n;

        vector<int> a3(n, 0);
        vector<int> a2(n, 0);
        vector<int> a1(n, 0);


        vector<vector<int>> table(2, vector<int>(n, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                int tmp;
                cin >> tmp;
                table[i][j] = tmp;
            }
        }

        a3[0] = max(table[0][0], table[1][0]);
        a2[0] = table[1][0];
        a1[0] = table[0][0];

        for (int k = 1; k < n; k++) {
            a3[k] = max(a3[k - 1], max(table[0][k] + a2[k - 1], table[1][k] + a1[k - 1]));
            a2[k] = max(table[1][k]+a1[k-1],a3[k-1]);
            a1[k] = max(table[0][k]+a2[k-1],a3[k-1]);

        }

        cout<< a3[n-1]<<'\n';



    }

    return 0;


}