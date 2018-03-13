#include <vector>
#include <array>
#include <list>

template <class T, class C>
struct is_container {
    static constexpr bool value{false};
};

template <class T, std::size_t N>
struct is_container<T, std::array<T, N>> {
static constexpr bool value{true};
};

template <class T, class A>
struct is_container<T, std::vector<T, A>> {
static constexpr bool value{true};
};

template <class C, class = std::enable_if_t<is_container<int, C>::value>>
int sum(const C &container)
{
    int s{0};
    for (auto &x : container)
        s += x;
    return s;
}

int main()
{
    sum(std::array<int, 2>{{0, 1}}); // OK
    sum(std::vector<int>{0, 1});     // OK

    sum(0);                        // NG
    sum(std::vector<float>{0, 1}); // NG
    sum(std::list<int>{0, 1});     // NG
}