#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>

using namespace std;

int main() {

    int n ;
    int k;
    cin >> n >> k;

    size_t c[n];

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    size_t l = 0, r = c[n-1]-c[0] + 1, mid, last,count;
    while (l < r){
        mid = (l+r) /2;
        last  = c[0];
        count = 1;
        for (int i = 0; i < n; i++) {
            if(c[i] - last > mid){
                last = c[i];
                count++;
            }
        }

        if(k <= count){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }

    cout << l;

    return 0;
}
