#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int prices[n];

    for (int i = 0; i < n; i++){
        cin >> prices[i];
    }
    //спасибо разработчикам хоть это писать не надо
    sort(prices, prices + n, greater<>());

    long total = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % k != 0) total += prices[i];
    }

    cout << total << endl;
    return 0;
}
