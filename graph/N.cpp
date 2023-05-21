#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct GRAPH{
    list<int> keys;
    int flag{};
};

//string ListToString(list<int> l){
//    string s;
//    for (int i: l) {
//        s += to_string(i) + " ";
//    }
//    return s;
//}

void dfs_v2( int *c, int i, GRAPH graph[]) {
    graph[i].flag = 1;
    for(int next : graph[i].keys){
        if (graph[next].flag == 0) dfs_v2(c, next, graph);
        else if (graph[next].flag == 1) (*c)++;
    }
    graph[i].flag = 2;
}

int main() {
    int n; cin >> n;

    GRAPH graph[n];
    int key;
    for (int i = 0; i < n; i++) {
        cin >> key;
        graph[--key].keys.push_back(i);
    }

//    for (int i = 0; i < n; i++) {
//        cout << "keys " << ListToString(graph[i].keys) << " id " << graph[i].id << endl;
//    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (graph[i].flag == 0){
            dfs_v2(&c, i,graph);
        }
    }
    cout << c;
    return 0;
}
