#include <iostream>
#include <list>
#include <set>
#include <queue>
#include <climits> //не limits.h потому что этот стандартизирован по ISO C


using namespace std;

int main() {

    //параметры задачи и их заполнение
    int n, k, p;
    cin >> n >> k >> p;

    list<int> cars_positions_in_queue[n];
    int c_queue[p];

    //    for (int &car : c_query) {
    //        cin >> car;
    //    }

    for (int i = 0; i < p; i++) {
        cin >> c_queue[i];
        //-- потому что начинается с 0
        cars_positions_in_queue[--c_queue[i]].push_back(i);
    }

    //машинки на полу
    set<int> on_the_floor;

    //на каком шаге машинка была взята, по сути для поиска самой "старой" т.к автосортировка
    priority_queue<pair<int, int>> cars_and_steps;

     //счетчик
    int operations = 0;
    for (int i = 0; i < p; i++){

        //текущий ход
        int curr = c_queue[i];

        //убрать ход машинки из возможных
        cars_positions_in_queue[curr].pop_front();

        //если еще не на полу
        if (on_the_floor.find(curr) == on_the_floor.end()){
//            cout << "car " << curr+1 << " not on the floor yet" << endl<< endl;
            //если на полу максимум - убирается та, что была вынута раньше всех
            if (on_the_floor.size() >= k) {
                on_the_floor.erase(cars_and_steps.top().second);
                cars_and_steps.pop();
//        cout << "too many cars on the floor, oldest car removed" << endl<< endl;
            }

            //новая добавляется в список на полу
            on_the_floor.insert(curr);
            operations++;
        }

        //если конкретная машинка больше не запрашивается - убрать из каталога
        if (cars_positions_in_queue[curr].empty()){
//           cout << "car " << curr+1 << " not requested anymore" << endl<< endl;
            //push в данном случае медленнее из-за копирования
            cars_and_steps.emplace(INT_MAX, curr);
        }

        //если есть на полу - обновляет ход
        else{
//            cout << "updated position of a car: " << curr+1 << endl<< endl;
            cars_and_steps.emplace(cars_positions_in_queue[curr].front(),     curr);
        }
    }

    cout << operations << endl;
    return 0;
}
