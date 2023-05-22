#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
//struct GRAPH{
//    list<int_fast32_t> graph;
//    int flag{};
//};
//
//int_fast32_t getVal(const list<int_fast32_t>& _list, int _i){
//    short c = 0;
//    for (int_fast32_t it :_list) {
//        if(c == _i)
//            return it;
//    }
//    return 0;
//}

void dfs_v2(int i, int_fast32_t* gr, int* flags, int n, int* c, int_fast32_t average, int mod) {
    flags[i] += 1;

    int_fast32_t uid;
    for(int j = 0; j < n; j++){
        if (mod){
            uid = j * n + i;
        }
        else{
            uid = i * n + j;
        }
//        cout << "uid " << uid << endl;
        if (j != i && flags[j] == mod && gr[uid] <= average) {
            dfs_v2(j, gr, flags, n, c, average, mod);
        }
    }
    (*c)++;
}

int main() {
    int n; cin >> n;

    int_fast32_t min = INT_FAST32_MAX;
    int_fast32_t max = 0;
    int_fast32_t buff;
    int_fast32_t gr[n][n];


    //Да извращение, да не стыдно
    short c = 0;
    while (c < n){
        for (int i = 0; i < n; ++i) {
            cin >> buff;
            gr[c][i] = buff;

            if(c != i){
                if (buff > max){
                    max = buff;
                }
                if (buff < min){
                    min = buff;
                }
            }
        }
        c++;
    }

//    cout << "min " << min << " max " << max << endl;
    int flags[n];
    int_fast32_t average;
    int fc = 0;
    do {
//        cout << "==================" << endl;
        average = (min + max)/2;
        for (int i = 0; i < n; i++) {
            flags[i] = 0;
        }
        fc = 0;
        if (n == 1) {
            break;
        }
        dfs_v2(0, &gr[0][0], flags, n, &fc, average, 0);
        dfs_v2(0, &gr[0][0], flags, n, &fc, average, 1);
        if (min >= max){
            break;
        }
        if (fc == 2*n){
            max = average;
        }
        else {
            min = average +1;
        }


//        cout << "avg " << average << endl;
//        cout << "==================" << endl;
    } while (1);

    if (fc != 2*n){
        min = 0;
    }
    cout << min;

    return 0;
}
