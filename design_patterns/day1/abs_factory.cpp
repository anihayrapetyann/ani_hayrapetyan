#include <iostream>

using namespace std;

class Chair {
public:
    virtual ~Chair(){};
    virtual string UsefulFunctionA() const = 0;
};

class VictorianChair : public Chair {
public:
    string UsefulFunctionA() const override {
        return "The result of the product victorian chair.";
    }
};

class ModernChair : public Chair {
    string UsefulFunctionA() const override {
        return "The result of the product modern  chair";
    }
};

class Sofa {
public:
    virtual ~Sofa(){};
    virtual string UsefulFunctionB() const = 0;
};


class VictorianSofa : public Sofa {
public:
    string UsefulFunctionB() const override {
        return "The result of the product Victorian sofa";
    }
};

class ModernSofa : public Sofa {
public:
    string UsefulFunctionB() const override {
        return "The result of the product Modern sofa.";
    }
};

class FurnitureFactory {
public:
    virtual Chair *CreateChair() const = 0;
    virtual Sofa *CreateSofa() const = 0;
};

class VictorianFurnitureFactory : public FurnitureFactory {
public:
    Chair *CreateChair() const override {
        return new VictorianChair();
    }
    Sofa *CreateSofa() const override {
        return new VictorianSofa();
    }
};

class ModernFurnitureFactory : public FurnitureFactory {
public:
    ModernChair *CreateChair() const override {
        return new ModernChair();
    }
    ModernSofa *CreateSofa() const override {
        return new ModernSofa();
    }
};

void ClientCode(const FurnitureFactory &factory) {
    const Chair *product_a = factory.CreateChair();
    const Sofa *product_b = factory.CreateSofa();
    cout << product_a->UsefulFunctionA() << endl;
    cout << product_b->UsefulFunctionB() << "\n";
    delete product_a;
    delete product_b;
}

int main() {
    cout << "Client: Testing client code with the victorian factory type:\n";
    VictorianFurnitureFactory *f1 = new VictorianFurnitureFactory();
    ClientCode(*f1);
    delete f1;
    cout << endl;
    
    cout << "Client: Testing the same client code with the modern factory type:\n";
    ModernFurnitureFactory *f2 = new ModernFurnitureFactory();
    ClientCode(*f2);
    delete f2;
    return 0;
}