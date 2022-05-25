#include <iostream> 

using namespace std;
 
class IceCream {
public:
  virtual void Make() = 0;
  virtual string getDescription() = 0;
  virtual ~IceCream() {}
};
 
class SimpleIceCream : public IceCream {
public:
    void Make() {}
    string getDescription() {
        return "simple icecream\n";
    }
};

class IceCreamDecorator : public IceCream {
protected:
	IceCream *m_decoratedIceCream; 
public:
	IceCreamDecorator (IceCream *decoratedIceCream): 
	  m_decoratedIceCream(decoratedIceCream) {}
    void Make () {
        m_decoratedIceCream->Make();
    }
};

class IceCreamWithFruits : public IceCreamDecorator {
public:
	IceCreamWithFruits (IceCream *decoratedIceCream): 
		IceCreamDecorator(decoratedIceCream) {}
	void Make() {
        IceCreamDecorator::Make();
    }
    string getDescription() {
        return m_decoratedIceCream->getDescription() + "with fruits\n";
    }
};

class IceCreamWithWafers : public IceCreamDecorator {
public:
	IceCreamWithWafers (IceCream *decoratedIceCream): 
		IceCreamDecorator(decoratedIceCream) {}
	void Make() {
        IceCreamDecorator::Make();
    }
    string getDescription() {
        return m_decoratedIceCream->getDescription() + "with wafers\n";
    }
};

int main() {
    IceCream *simple = new SimpleIceCream();
    cout << simple -> getDescription() << endl;

    IceCream *withFruits = new IceCreamWithFruits ( new SimpleIceCream());
    cout << withFruits -> getDescription() << endl;

    IceCream *withwafer = new IceCreamWithWafers ( new SimpleIceCream());
    cout << withwafer -> getDescription() << endl;

    IceCream *fruitandwafer = new IceCreamWithWafers ( new IceCreamWithFruits ( new SimpleIceCream()));
    cout << fruitandwafer -> getDescription() << endl;

    return 0;
}