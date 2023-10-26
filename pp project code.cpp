#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& n, double p) : name(n), price(p) {}

    virtual void display() {
        cout << "Product Name: " << name << endl;
        cout << "Price: " << price << endl;
    }

    double get_price() {
        return price;
    }
};

class Laptop : public Product {
public:
    Laptop(const string& n, double p) : Product(n, p) {}

    void display() override {
        cout << "Laptop Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};

class Smartphone : public Product {
public:
    Smartphone(const string& n, double p) : Product(n, p) {}

    void display() override {
        cout << "Smartphone Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    Laptop laptop("Intel ABC", 83455.15);
    Smartphone smartphone("Samsung XYZ", 40000.0);

    Product* products[] = {&laptop, &smartphone};

    cout << "Product Information:\n";
    for (int i = 0; i < 2; i++) {
        products[i]->display();
    }

    if (laptop.get_price() < smartphone.get_price()) {
        cout << "Laptop is cheaper than Smartphone.\n";
    } else if (laptop.get_price() > smartphone.get_price()) {
        cout << "Smartphone is cheaper than Laptop.\n";
    } else {
        cout << "Laptop and Smartphone have the same price.\n";
    }

    return 0;
}
