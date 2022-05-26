#include <iostream>

using namespace std;

class vim;

class mode {
 protected:
  vim *vim_;
 public:
  virtual ~mode() {
  }
  void set_vim(vim *vim) {
    this->vim_ = vim;
  }
  virtual void Normal() = 0;
  virtual void Insert() = 0;
};

class vim {
 private:
  mode *mode_;

 public:
  vim(mode *mode) : mode_(nullptr) {
    this->TransitionTo(mode);
  }
  ~vim() {
    delete mode_;
  }

  void TransitionTo(mode *mode) {
    cout << "vim: Transition to " << typeid(*mode).name() << ".\n";
    if (this->mode_ != nullptr)
      delete this->mode_;
    this->mode_ = mode;
    this->mode_->set_vim(this);
  }
 
  void changeMode1() {
    this->mode_->Normal();
  }
  void changeMode2() {
    this->mode_->Insert();
  }
};

class NormalMode : public mode {
 public:
  void Normal() override;
  void Insert() override {
    cout << "Normal mode handles changeMode2.\n";
  }
};

class InsertMode : public mode {
 public:
  void Normal() override {
    cout << "Insert mode handles changeMode1.\n";
  }
  void Insert() override {
    cout << "Insert mode handles changeMode2.\n";
    cout << "Insert mode wants to change the mode of the vim.\n";
    this->vim_->TransitionTo(new NormalMode);
  }
};

void NormalMode::Normal() {
    cout << "Normal mode handles changeMode1.\n";
    cout << "Normal mode wants to change the mode of the vim.\n";
    this->vim_->TransitionTo(new InsertMode);
}

void ClientCode() {
  vim *vim1 = new vim(new NormalMode);
  vim1->changeMode1();
  vim1->changeMode2();
  delete vim1;
}

int main() {
  ClientCode();
  return 0;
}