#include <iostream>
using namespace std;
class Singleton {
private:
    static Singleton* s;
    int k;
    Singleton(int i) : k(i) {}
public:
    static Singleton* getReference() {
        if (s == nullptr) {
            s = new Singleton(3);
        }
        return s;
    }
    static void destroyInstance() {
        if (s != nullptr) {
            delete s;
            s = nullptr;
        }
    }
    int getValue() {
        return k;
    }
    void setValue(int i) {
        k = i;
    }
    void attack() {
        cout << "Boss attacks with power " << k << "!\n";
    }
    void defend() {
        cout << "Boss defends with resilience " << k << "!\n";
    }
    void specialMove() {
        cout << "Boss performs a special move with strength " << k << "!\n";
    }
    ~Singleton() {
        cout << "Boss has been defeated!\n";
    }
};
Singleton* Singleton::s = nullptr;
int main() {
    Singleton* p = Singleton::getReference();
    cout << "Initial value: " << p->getValue() << "\n\n";
    p->setValue(p->getValue() + 5);
    cout << "Updated value: " << p->getValue() << "\n\n";
 
    p->attack();
    p->defend();
    p->specialMove();

    Singleton::destroyInstance();

    p = Singleton::getReference();
    cout << "Value after re-initialization: " << p->getValue() << "\n\n";

    p->attack();
    p->defend();
    p->specialMove();

    Singleton::destroyInstance();

    return 0;
}


