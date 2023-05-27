#include <iostream>
#include <list>
#include <iterator>

using namespace std;

bool cmp(string& n_1, string& n_2){
    return n_1 + n_2 > n_2 + n_1;
}

int main() {
    list<string> numbers;
    string number;
    char count = 0;

    while (cin >> number) {
        count++;
        numbers.push_back(number);

        if(count == 100){
            break;
        }
    }

    numbers.sort(cmp);
    for(string& n: numbers) {
        cout << n;
    }

    return 0;
}
