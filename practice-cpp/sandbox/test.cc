
#include <assert.h>

template<typename T>
class array {
public:

array(int len) : length(len) {
    a = new T[length];
}

T& operator[] (int i) {
    assert(i >= 0 && i < length);
    return a[i];
}

array<T>& operator=(array<T> &b) {
    if (a != nullptr) {
        delete[] a;
    }
    a = b.a;
    b.a = nullptr;
    b.length = 0;
    length = b.length;
    return *this;
}


private:
T *a;
int length = 0;

};



int main() {
    array<int> a(10);

    return 0;
}
