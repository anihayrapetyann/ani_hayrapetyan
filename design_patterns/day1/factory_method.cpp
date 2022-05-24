#include <iostream>

using namespace std;

class Transport {
public:
    virtual ~Transport() {}
    virtual string Operation() const = 0;
};

class Truck : public Transport {
public:
    string Operation() const override {
        return "{Result of the Truck}";
    }
};

class Ship : public Transport {
public:
    string Operation() const override {
        return "{Result of the Ship}";
    }
};

class Logistics {
public:
    virtual ~Logistics(){};
    virtual Transport* FactoryMethod() const = 0;
    string SomeOperation() const {
        Transport* transport = this->FactoryMethod();
        string result = "Creator: The same creator's code has just worked with " + transport->Operation();
        delete transport;
        return result;
    }
};

class RoadLogistics : public Logistics {
public:
    Transport* FactoryMethod() const override {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* FactoryMethod() const override {
        return new Ship();
    }
};

void ClientCode(const Logistics& logistics) {
    cout << logistics.SomeOperation() << endl;
}

int main() {
    cout << "App: Launched with the RoadLogistics.\n";
    Logistics* logistics = new RoadLogistics();
    ClientCode(*logistics);
    cout << endl;
    cout << "App: Launched with the SeaLogistics.\n";
    Logistics* logistics2 = new SeaLogistics();
    ClientCode(*logistics2);

    delete logistics;
    delete logistics2;
    return 0;
    }