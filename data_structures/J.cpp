#include <iostream>
#include <list>

using namespace std;

list<int> queue_first_half;
list<int> queue_second_half;

void rearrange_queue(){
    if (queue_first_half.size() < queue_second_half.size()){
        queue_first_half.push_back(queue_second_half.front());
        queue_second_half.pop_front();
    }
    else if (queue_first_half.size() > queue_second_half.size() + 1){
        queue_second_half.push_front(queue_first_half.back());
        queue_first_half.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    int position;

    char sign;


    for (int i = 0; i < n; i++) {
        cin >> sign;
        switch (sign) {

            case '+':
                cin >> position;
                queue_second_half.push_back(position);
                break;
            case '*':
                cin >> position;
                queue_first_half.push_back(position);
                break;
            case '-':
                if(!queue_first_half.empty()) {
                    cout << queue_first_half.front() << endl;
                    queue_first_half.pop_front();
                }
                break;
        }

        rearrange_queue();

    }

    return 0;
}
