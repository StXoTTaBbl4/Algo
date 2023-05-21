#include <iostream>
#include <queue>
#include <set>
#include <list>
using namespace std;

struct node{
    int value;
    int id;
};
bool operator < (const node &node_1, const node &node_2){return node_1.value > node_2.value;}

node get_top_and_remove(priority_queue<node>& frontier){
    node a = frontier.top();
    frontier.pop();
    return a;
}

void generate_answer(node already_visited[], int end, int begin,int columns){
    cout << already_visited[end].value << endl;
    if (already_visited[end].value != -1){
        list<char> fastest_path;

        int curr = end;
        while (curr != begin){
            int diff = curr - already_visited[curr].id;
            if (diff == 1) fastest_path.push_front('E');
            else if (diff == -1) fastest_path.push_front('W');
            else if (diff == columns) fastest_path.push_front('S');
            else if (diff == -columns) fastest_path.push_front('N');
            curr = already_visited[curr].id;
        }

        for (char step: fastest_path) {
            cout << step;
        }
    }
}

int main() {
    int rows; cin >> rows;
    int columns; cin >> columns;
    int beginX; cin >> beginX;
    int beginY; cin >> beginY;
    int endX; cin >> endX;
    int endY; cin >> endY;

    int begin = (beginX - 1) * columns + (beginY - 1);
    int end = (endX - 1) * columns + (endY - 1);

    string field[rows];
    for (int i = 0; i < rows; i++){
        cin >> field[i];
    }

    node already_visited[rows*columns];
    for (int i = 0; i < rows*columns;i++){
        already_visited[i] = {-1,-1};
    }

    priority_queue<node> frontier;

    frontier.push({0, begin});
    node current_node{};
    multiset<node> nodes;
    int buff_val;

    while (!frontier.empty()){
        current_node = get_top_and_remove(frontier);
        if (current_node.id == end){
            break;
        }

        nodes.clear();
        int buff_x = current_node.id / columns;
        int buff_y = current_node.id % columns;

        if(field[buff_x][buff_y] != '#'){
            if (buff_y + 1 < columns && field[buff_x][buff_y + 1] != '#') {
                if(field[buff_x][buff_y + 1] == 'W'){
                    nodes.insert({2, current_node.id + 1});
                }else {
                    nodes.insert({1, current_node.id + 1});
                }
            }
            if (buff_y - 1 >= 0 && field[buff_x][buff_y - 1] != '#') {
                if(field[buff_x][buff_y - 1] == 'W'){
                    nodes.insert({2, current_node.id - 1});
                }else {
                    nodes.insert({1, current_node.id - 1});
                }
            }
            if (buff_x + 1 < rows && field[buff_x + 1][buff_y] != '#') {
                if(field[buff_x + 1][buff_y] == 'W'){

                    nodes.insert({2, current_node.id + columns});
                }else {
                    nodes.insert({1, current_node.id + columns});
                }
            }
            if (buff_x - 1 >= 0 && field[buff_x - 1][buff_y] != '#') {
                if(field[buff_x - 1][buff_y] == 'W'){
                    nodes.insert({2, current_node.id - columns});
                }else {
                    nodes.insert({1, current_node.id - columns});
                }
            }
        }
        else{
            continue;
        }

        for (node node:nodes){
            buff_val = current_node.value + node.value;
            if (already_visited[node.id].value > buff_val || already_visited[node.id].value == -1){
                frontier.push({buff_val, node.id});
                already_visited[node.id].value = buff_val;
                already_visited[node.id].id = current_node.id;
            }
        }
    }
    generate_answer(already_visited, end, begin, columns);
    return 0;
}
