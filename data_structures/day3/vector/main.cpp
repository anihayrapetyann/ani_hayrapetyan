#include "vector.cpp"

int main () {
    MyVector<int>  vector;
    for(int i = 0; i < 10; i++) {
        vector.Add(i);
    }

    for(int i = 0; i < 10; i++) {
        cout << vector[i] << endl;
    }

    return 0;
}