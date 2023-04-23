#include <iostream>
#include <map>
#include <list>



using namespace std;

int main(){
    int n,m;
    cin >>n >>m;

    map<int,pair<int,int>> requests;

    bool memory_cells[n];
    fill_n(memory_cells, n, false);

    size_t size_of_array = sizeof(memory_cells)/sizeof(memory_cells[0]);

    int task,c,suggested_start,remove_start, to_remove;
    bool place_found;
    for (int i = 0; i < m; i++) {
        cin >> task;
        c = 0;
        suggested_start = 0;
        place_found = false;

        if(task > 0){

            for( int j = 0; j < size_of_array; j++ ){
                if (memory_cells[j]){
                    suggested_start = j+1;
                }
                if (!memory_cells[j]) {
                    c++;
                }
                if (c == task){
                    for (int k = suggested_start; k < suggested_start+task; k++) {
                        memory_cells[k] = true;
                    }
                    place_found = true;
                    break;
                }
            }
            if (place_found)
                requests.insert_or_assign(i+1, make_pair(suggested_start,task));
            if(suggested_start >= 0)
//                    cout<< suggested_start+1 << "==" << endl;
                cout<< suggested_start+1 << endl;
//               else if(suggested_start > 0)
//                   cout<< suggested_start+2 << "==" << endl;
        }
        else{
            auto at = requests.find(task*-1);
            remove_start = at->second.first;
            to_remove = at->second.second;

            for (int j = remove_start; j < remove_start+to_remove; j++) {
                memory_cells[j] = false;
            }
        }
    }
    return 0;
}
