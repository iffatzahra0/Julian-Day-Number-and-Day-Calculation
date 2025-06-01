//IFFAT ZAHRA
// CMS ID: 501970 , BEE16C
// ASSIGNMENT QUESTION 3 (ASSIGNMENT MADE ON VISUAL STUDIO 2022)


#include <iostream>
#include<cctype>
using namespace std;

// Function to determine if the date is Gregorian
bool isGregorianDate(int day, int month, int year) {
    if (year > 1582) return true;
    if (year < 1582) return false;
    if (month > 10) return true;
    if (month < 10) return false;
    return (day >= 15);
}

// Function to calculate the Julian Day Number

long calculateJDN(int day, int month, int year) {
    if (month <= 2) {
        month += 12; // correction
        year -= 1;  // correction
    }
    long A = year / 100;// given in question
    long B = isGregorianDate(day, month, year) ? (2 - A + A / 4) : 0; // checking if georgian (given conditions)

    return static_cast<long>(365.25 * (year + 4716)) + static_cast<long>(30.6001 * (month + 1)) + day + B - 1524;
}

// Function to get the name of the day from weekday index
string getDayName(int weekday) {
    switch (weekday) {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        default: return "Invalid day";
    }
}
// main execution
int main() {
    int day, month, year;
    char userinp;

    do {
        cout << "---> ENTER THE GREGORIAN CALENDAR DATE (DD MM YYYY): ";
        cin >> day >> month >> year;

        if (day < 1 || day > 31 || month < 1 || month > 12) {
            cout << "Oops! Please enter a valid date." << endl;
            continue;
        }

        long JDN = calculateJDN(day, month, year);
        int weekday = (JDN + 1) % 7;  // Adjusting so that Sunday = 0

            // output statement

        cout << day << "/" << month << "/" << year<< " was a " << getDayName(weekday) << "." << endl << endl; // PRINTING OUTPUT

        cout << "\n---> Enter Y to continue and N to exit: ";
        cin >> userinp; // USER INPUT TO EXIT OR KEEP RUNNING THE PROGRAM

    }while(toupper(userinp)=='Y');

    return 0;
}