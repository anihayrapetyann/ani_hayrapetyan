#include <iostream>

using namespace std;

class Database {
   static Database* dataBaseConnection;
   int data;
   Database() {
      data = 0;
      cout << "Connection to DB" << endl;
   }
public:
   static Database *getConnection() {
      if (!dataBaseConnection)
      dataBaseConnection = new Database;
      return dataBaseConnection;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
      cout << "New data " << data << " inserted to the DB" << endl;
   }
};

Database *Database::dataBaseConnection = 0;

int main(){
   Database *s = s->getConnection();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   s->setData(150);
   cout << s->getData() << endl;
   return 0;
}