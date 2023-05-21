#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct GRAPH{
    list<int> graph;
    int flag{};
};

bool dfs_v2(int v, GRAPH graph[], int flag){
    graph[v].flag = flag;
    bool buff_res;
    for(int next : graph[v].graph){

        if (graph[next].flag == 0){

            if(flag == 2){
                buff_res = dfs_v2(next, graph, 1);
            }else
            {
                buff_res = dfs_v2(next, graph, 2);
            }

            if (!buff_res) {
                return false;
            }
        } else if (graph[next].flag == flag) {
            return false;
        }
    }
    return true;
}

int main() {
    int n; cin >> n;
    int m; cin >> m;

    GRAPH gr[n];

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        gr[a].graph.push_back(b);
        gr[b].graph.push_back(a);
    }

    bool possible = true;
    for (int i = 0; i < n; i++){
        if (!possible){
            break;
        }
        if(gr[i].flag == 0){
            possible = dfs_v2(i, gr, 1);
        }
    }

    if (possible) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
