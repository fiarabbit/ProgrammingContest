#include <iostream>
#include <vector>
#include <deque>

using namespace std;

using uint = unsigned int;


int main() {
    uint N;
    cin >> N;
    vector<uint> as(N, 0);
    for (unsigned int i = 0; i < N; ++i) {
        cin >> as.at(i);
    }

    uint count_2{0};
    for (unsigned int j = 0; j < N; ++j) {
        if (as.at(j) == 2) {
            count_2 += 1;
        }
    }

    // splitterの位置をa[k]の手前にしたときの，splitterより左にある1の数とsplitterより右にある2の数を数える
    // 数え方は，a[k] == 1ならfs[k+1] = fs[k] + 1，a[k] == 2ならfs[k+1] = fs[k] - 1とすると尺取りができる
    vector<int> fs(N+1, count_2);
    for (unsigned int k = 0; k < N; ++k) {
        if (as.at(k) == 1){
            fs.at(k+1) = fs.at(k) + 1;
        } else if (as.at(k) == 2){
            fs.at(k+1) = fs.at(k) - 1;
        }
    }

    /*
     * 考察
     * 区間反転は，fsを点対称回転させるのと一緒
     * 従って，[l, r)の区間反転をすると，fsは元の最大値またはfs[l] + fs[r] - min(fs[k])が最大になる
     * このことから，kはfsの極小値で，lはkより左のfsの最大値，rはkより右のfsの最大値しかありえないことがわかる．
     * 以下ではkについてそれに対応するfs[k], fs[l], fs[r]を全列挙することで最大を得る
     */

    int maximum_value{0}; // 後で使う
    // local_maximumを取る
    // maximumについては，Wの字になっている時は，左右の末端も取る
    vector<uint> local_maximum_index{};
    if (as.front() == 2){
        local_maximum_index.push_back(0);
        maximum_value = max(maximum_value, fs.at(local_maximum_index.back())); // 初期状態の最大を取っておく
    }
    for (unsigned int l = 1; l < N; ++l) {
        if (as.at(l) == 2 && as.at(l-1) == 1){
            local_maximum_index.push_back(l);
            maximum_value = max(maximum_value, fs.at(local_maximum_index.back())); // 初期状態の最大を取っておく
        }
    }
    if(as.back() == 1){
        local_maximum_index.push_back(N);
        maximum_value = max(maximum_value, fs.at(local_maximum_index.back())); // 初期状態の最大を取っておく
    }

    // local_minimumを取る
    // minimumについては，Mの字になっていても，左右の末端を取らない
    // この操作によってlocal_max.size() == local_min.size() + 1が保証される
    vector<uint> local_minimum_index{};
    for (unsigned int m = 1; m < N; ++m) {
        if (as.at(m) == 1 && as.at(m-1) == 2){
            local_minimum_index.push_back(m);
        }
    }

    // 全てのlocal_minimumについて，それより左の領域で最も大きいfsの値を計算する
    deque<int> left_maximum{};
    for (auto it = local_maximum_index.begin();it != local_maximum_index.end(); it++) {
        if (it == local_maximum_index.begin()) {
            left_maximum.push_back(fs.at(*it));
        } else {
            left_maximum.push_back(max(left_maximum.back(), fs.at(*it)));
        }
    }
    left_maximum.pop_back();

    // 全てのlocal_minimumについて，それより右の領域で最も大きいfsの値を計算する
    deque<int> right_maximum{};
    for (auto it = local_maximum_index.rbegin();it != local_maximum_index.rend(); it++) {
        if (it == local_maximum_index.rbegin()) {
            right_maximum.push_front(fs.at(*it));
        } else {
            right_maximum.push_front(max(right_maximum.front(), fs.at(*it)));
        }
    }
    right_maximum.pop_front();

    // 全てのlocal_minimumについて，(左最大) + (右最大) - (極小) を計算する
    vector<int> values(local_minimum_index.size(), 0);
    for (unsigned int n = 0; n < local_minimum_index.size(); ++n) {
        values.at(n) = left_maximum.at(n) + right_maximum.at(n) - fs.at(local_minimum_index.at(n));
    }

    // 以上の中から最も値の大きいものを選択する
    for (int &value : values) {
        maximum_value = max(maximum_value, value);
    }
    cout << maximum_value << endl;

    return 0;
}