#include <iostream>
using std::cout;
using std::endl;

template<typename T, int m>
class Foo {
public:
    Foo(T foo) : _foo(foo){
        if (m == 1) {
            cout << "m is " << m << endl;
        }
        cout << "data is " << _foo << endl;
    }
    Foo(Foo& ) = delete;
    ~Foo() {  }
private:
    T _foo;
};

int main() {
    Foo<float, 0> f(1.314);
}
