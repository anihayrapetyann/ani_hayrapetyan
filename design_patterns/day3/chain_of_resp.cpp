#include<iostream>
 
class AtmHandler {
AtmHandler* m_suc;
public:
    AtmHandler(AtmHandler* s = nullptr) {
        m_suc = s;
    }
    ~AtmHandler(){} 
    virtual void HandleRequest(int amt);
};
void AtmHandler::HandleRequest(int amt) { 
    if(m_suc)
    m_suc->HandleRequest(amt);
}
 
class Dollar50Handler: public AtmHandler {
 
public:
    Dollar50Handler(AtmHandler* s = nullptr): AtmHandler(s){}
    ~Dollar50Handler(){}
    void HandleRequest(int amt);
};
void Dollar50Handler::HandleRequest(int amt) {
    if(amt%50 == 0) {
        std::cout<<"Number of 50 Dollar:"<<amt/50<<std::endl;
        std::cout<<"Request is completed so no need to forward it"<<std::endl;
    }
    else {
        int numberOf50Dollar= amt/50;
        std::cout<<"Number of 50 Dollar:"<<numberOf50Dollar<<std::endl;
        amt = amt-numberOf50Dollar*50;
        AtmHandler::HandleRequest(amt);
    }
}

class Dollar20Handler: public AtmHandler {
public:
        Dollar20Handler(AtmHandler* s = nullptr): AtmHandler(s){}
        ~Dollar20Handler(){}
        void HandleRequest(int amt);
};
void Dollar20Handler::HandleRequest(int amt){
    if (amt%20 == 0) {
        std::cout<<"Number of 20 Dollar:"<<amt/20<<std::endl;
        std::cout<<"Request is completed so no need to forward it"<<std::endl;
    }
    else {
        int numberOf20Dollar= amt/20;
        std::cout<<"Number of 20 Dollar:"<<numberOf20Dollar<<std::endl;
        amt = amt-numberOf20Dollar*20;
        AtmHandler::HandleRequest(amt);
    }
}
 
class Dollar10Handler: public AtmHandler {
public:
    Dollar10Handler(AtmHandler* s = nullptr): AtmHandler(s){}
    ~Dollar10Handler(){}
    void HandleRequest(int amt);
};

void Dollar10Handler::HandleRequest(int amt) {
    if (amt%10 == 0) {
        std::cout<<"Number of 10 Dollar:"<<amt/10<<std::endl;
        std::cout<<"Request is completed so no need to forward it"<<std::endl;
    }
    else {
        std::cout<<"!!!!!!Can Not with draw this amout please enter correct amount"<<std::endl;
    }
}
 
int main() {
    std::cout<<"Chain of Responsibility"<<std::endl;
    Dollar10Handler* p10 = new Dollar10Handler;
    Dollar20Handler* p20 = new Dollar20Handler(p10);
    Dollar50Handler* p50 = new Dollar50Handler(p20);
    AtmHandler* atm = new AtmHandler(p50);
    std::cout<<"Please withdraw 530 Dollar"<<std::endl;
    atm->HandleRequest(530);
 
    std::cout<<"Please withdraw 545 Dollar"<<std::endl;
    atm->HandleRequest(545);
 
    return 0;
}