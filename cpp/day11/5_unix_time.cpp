#include <iostream>
#include <ctime>

using namespace std;

int main() {
    long int input_seconds;
    cout << "input the number of seconds: ";
    cin >> input_seconds;

    time_t seconds = input_seconds;
    string date = ctime (&seconds);
    string mm = "";
    string day = "";
    string time = "";
    string yy = "";
    for (int i = 0; date[i] != '\0'; i++) {
        if (i > 3 && i < 7) {
            mm += date[i];
        }
        else if (i > 7 && i < 10) {
            day += date[i];
        }
        else if (i > 10 && i < 16) {
            time += date[i];
        }
        else if (i > 19 && date[i] != '\0') {
            yy += date[i];
        }
    }
    cout << "date: " << mm << " " << day << " " <<  yy << " " << time << endl;

	return 0;
}
