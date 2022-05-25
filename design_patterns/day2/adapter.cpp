#include <iostream>

using namespace std;

class USASocket {
public:
    void usaCharge(){
        cout << "USA plug is charging" << endl;
    }
};

class ArmenianSocket {
public:
    virtual void armenianCharge(USASocket* socket) = 0;
};


class SocketAdapter:public ArmenianSocket, public USASocket {
public:
    void armenianCharge(USASocket* socket) override {
        socket->usaCharge();
    }
};

int main() {
    USASocket* socket = new USASocket();
    SocketAdapter * adapter = new SocketAdapter();
    adapter->armenianCharge(socket);

    
}