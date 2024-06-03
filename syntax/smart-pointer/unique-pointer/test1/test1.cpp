#include <iostream>

// clang++ -std=c++17 test1.cpp
// Test passing unique pointers to functions

using namespace std;

class Product {
    public:
        Product(string name) {
            this->name = name;
        }
        string GetName() {
            return name;
        }
        ~Product() {
            cout<< "Product object " << name << " is released" << endl;
        }
    private:
        string name;
};

void pass1(unique_ptr<Product> up) {
    cout << "In pass(): " << up->GetName() << endl;
}

void pass2(unique_ptr<Product> &up) {
    cout << "In pass(): " << up->GetName() << endl;
}

int main() {
    auto up1 = make_unique<Product>("tv");
    auto up2 = make_unique<Product>("pc");
    
    pass1(move(up1));
    // pass1(up1); This will result in an error
    if (up1 == nullptr) {
        cout << "up1 is moved." << endl;
    }

    pass2(up2);
    if (up2 == nullptr) {
        cout << "up2 is moved." << endl;
    }
    return 0;
}
