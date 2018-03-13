#include <iostream>
#include <vector>
#include <cstdlib>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

int main() {
    int N;
    cin >> N;
    vector<unsigned int> t(N + 1), x(N + 1), y(N + 1);
    t[0] = x[0] = y[0] = 0;
    for (int i : irange(0, N)) {
        cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
    }
    int t_diff;
    int x_diff;
    int y_diff;
    int l1;
    for (int i : irange(0, N)) {
        t_diff = abs((int) (t[i + 1] - t[i]));
        x_diff = abs((int) (x[i + 1] - x[i]));
        y_diff = abs((int) (y[i + 1] - y[i]));
        l1 = x_diff + y_diff;
        if (t_diff < l1) {
            cout << "No" << endl;
            return 0;
        }
        if (t_diff % 2 != l1 % 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}