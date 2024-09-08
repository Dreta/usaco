// USACO 2021 February Contest, Bronze
// Problem 1. Year of the Cow

#include <cmath>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> zodiacs = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

string getZodiac(int year) {
    return zodiacs[(year - 5) % 12];
}

int main() {
    map<string, int> birth;
    birth["Bessie"] = 2021;

    int n;
    cin >> n;
    while (n--) {
        string targetCow, born, in, type, zodiac, year, from, sourceCow;
        cin >> targetCow >> born >> in >> type >> zodiac >> year >> from >> sourceCow;

        if (type == "previous") {
            int currentYear = birth[sourceCow] - 1;
            while (getZodiac(currentYear) != zodiac) {
                currentYear--;
            }
            birth[targetCow] = currentYear;
        } else {
            int currentYear = birth[sourceCow] + 1;
            while (getZodiac(currentYear) != zodiac) {
                currentYear++;
            }
            birth[targetCow] = currentYear;
        }
    }
    cout << abs(birth["Bessie"] - birth["Elsie"]) << endl;
}
