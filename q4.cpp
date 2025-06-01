// IFFAT ZAHRA
// CMS ID: 501970 , BEE16C
// ASSIGNMENT QUESTION 4 (ASSIGNMENT MADE ON VISUAL STUDIO 2022)

#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

// Corrected function to determine if the date is Gregorian
bool isGregorianDate(int day, int month, int year) {
    if (year > 1582) return true;
    if (year < 1582) return false;
    if (month > 10) return true;
    if (month < 10) return false;
    return day >= 15;
}

// Function to calculate the Julian Day Number
double calculateJDN(int day, int month, int year) {
    if (month <= 2) {
        month += 12;
        year -= 1;
    }

    int A = year / 100;
    int B = isGregorianDate(day, month, year) ? (2 - A + A / 4) : 0;

    return floor(365.25 * (year + 4716)) + floor(30.6001 * (month + 1)) + day + B - 1524.5;
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

// Function to get absolute difference in days between two dates
double difference(int day1, int day2, int month1, int month2, int year1, int year2) {
    double jdn1 = calculateJDN(day1, month1, year1);
    double jdn2 = calculateJDN(day2, month2, year2);
    return abs(jdn1 - jdn2);
}

// Main function
int main() {
    int day1, day2, month1, month2, year1, year2;
    char userinp;

    do {
        cout << "---> ENTER THE FIRST DATE (DD MM YYYY): ";
        cin >> day1 >> month1 >> year1;
        cout << "---> ENTER ANOTHER DATE (DD MM YYYY): ";
        cin >> day2 >> month2 >> year2;

        if ((day1 < 1 || day1 > 31 || month1 < 1 || month1 > 12) || (day2 < 1 || day2 > 31 || month2 < 1 || month2 > 12)) {
            cout << "Oops! Please enter a valid date.\n";
            continue;
        }

        double JDN1 = calculateJDN(day1, month1, year1);
        double JDN2 = calculateJDN(day2, month2, year2);
        double day_difference = difference(day1, day2, month1, month2, year1, year2);

        int weekday1 = static_cast<int>(JDN1 + 1) % 7;
        int weekday2 = static_cast<int>(JDN2 + 1) % 7;

        cout << "\nThere are " << day_difference << " days between the two dates.\n\n";
        cout << day1 << "/" << month1 << "/" << year1 << " was a " << getDayName(weekday1) << ".\n";
        cout << day2 << "/" << month2 << "/" << year2 << " was a " << getDayName(weekday2) << ".\n";

        cout << "\n---> Enter Y to continue and N to exit: ";
        cin >> userinp;

    } while (toupper(userinp) == 'Y');

    return 0;
}
