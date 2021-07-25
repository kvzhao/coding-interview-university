
#include <iostream>
#include <vector>

template <typename Seq, typename Num>
Num sum(Seq s, Num v) {
    for (const auto& x : s)
        v += x;
    return v;
}

int main() {

    std::vector<int> s {1, 2, 3, 4, 5};

    int v = 100;

    v = sum(s, v);

    std::cout << v << std::endl;

    return 0;
}
