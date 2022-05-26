#include <iostream>
#include <list>
#include <string>

using namespace std;

class Ibuyer {
 public:
  virtual ~Ibuyer(){};
  virtual void Update(const string &message_from_subject) = 0;
};

class IShop {
 public:
  virtual ~IShop(){};
  virtual void Attach(Ibuyer *buyer) = 0;
  virtual void Detach(Ibuyer *buyer) = 0;
  virtual void Notify() = 0;
};

class Subject : public IShop {
 public:
  virtual ~Subject() {
    cout << " I have destroyed.\n";
  }

  void Attach(Ibuyer *buyer) override {
    list_buyer_.push_back(buyer);
  }
  void Detach(Ibuyer *buyer) override {
    list_buyer_.remove(buyer);
  }
  void Notify() override {
    list<Ibuyer *>::iterator iterator = list_buyer_.begin();
    HowManybuyer();
    while (iterator != list_buyer_.end()) {
      (*iterator)->Update(message_);
      ++iterator;
    }
  }

  void CreateMessage(string message = "Empty") {
    this->message_ = message;
    Notify();
  }
  void HowManybuyer() {
    cout << "There are " << list_buyer_.size() << " buyers in the list.\n";
  }

  void SomeBusinessLogic() {
    this->message_ = "change message";
    Notify();
    cout << "I'm about to do some thing important\n";
  }

 private:
  list<Ibuyer *> list_buyer_;
  string message_;
};

class buyer : public Ibuyer {
 public:
  buyer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
    cout << "Hi, I'm the buyer \"" << ++buyer::static_number_ << "\".\n";
    this->number_ = buyer::static_number_;
  }
  virtual ~buyer() {
    cout << "Goodbye, I was the buyer \"" << this->number_ << "\".\n";
  }

  void Update(const string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    cout << "buyer \"" << number_ << "\" removed from the list.\n";
  }
  void PrintInfo() {
    cout << "buyer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
  }

 private:
  string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

int buyer::static_number_ = 0;

void ClientCode() {
  Subject *subject = new Subject;
  buyer *buyer1 = new buyer(*subject);
  subject->CreateMessage("The new IPhone is already exists ");
}

int main() {
  ClientCode();
  return 0;
}