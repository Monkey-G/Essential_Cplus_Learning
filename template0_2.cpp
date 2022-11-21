#include <iostream>
#include <algorithm>

using namespace std;
#define len 7

int main()
{
    int a[7] = { 11, 4, 51, 41, 91, 98, 10 };
    int min_idx = min_element(a, a + len) - a;
    int max = max_element(a, a + len);
    cout << min_idx << " " << a[min_idx] << endl;
    cout << max << endl;
    cout << *max_element(a, a + 7);

    return 0;
}
