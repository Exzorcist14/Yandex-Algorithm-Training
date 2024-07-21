#include <bits/stdc++.h>

using namespace std;

int findDaysPerYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 366;
    } else {
        return 365;
    }
}

int determineDayIndex(const string& day) {
    if (day == "Monday") {
        return 0;
    }

    if (day == "Tuesday") {
        return 1;
    }

    if (day == "Wednesday") {
        return 2;
    }

    if (day == "Thursday") {
        return 3;
    }

    if (day == "Friday") {
        return 4;
    }

    if (day == "Saturday") {
        return 5;
    }

    if (day == "Sunday") {
        return 6;
    }
}

int findPastDaysBeforeMonth(const string& month, int year) {
    vector<int> daysPerMonth{31, (findDaysPerYear(year) == 365 ? 28 : 29), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> daysBefore(12);

    int sum = 0;
    for (int i = 0; i < 12; i++) {
        daysBefore[i] = sum;
        sum += daysPerMonth[i];
    }

    if (month == "January") {
        return daysBefore[0];
    }

    if (month == "February") {
        return daysBefore[1];
    }

    if (month == "March") {
        return daysBefore[2];
    }

    if (month == "April") {
        return daysBefore[3];
    }

    if (month == "May") {
        return daysBefore[4];
    }

    if (month == "June") {
        return daysBefore[5];
    }

    if (month == "July") {
        return daysBefore[6];
    }

    if (month == "August") {
        return daysBefore[7];
    }

    if (month == "September") {
        return daysBefore[8];
    }

    if (month == "October") {
        return daysBefore[9];
    }

    if (month == "November") {
        return daysBefore[10];
    }

    if (month == "December") {
        return daysBefore[11];
    }
}

string findDay(const int& dayIndex) {
    vector<string> days {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    return days[dayIndex];
}

string findBestWeekendDay(const vector<int>& workDays) {
    int maximum = workDays[0];
    int bestWeekendDayIndex = 0;

    for (int i = 1; i < 7; i++) {
        if (maximum < workDays[i]) {
            maximum = workDays[i];
            bestWeekendDayIndex = i;
        }
    }

    return findDay(bestWeekendDayIndex);
}

string findWorstWeekendDay(const vector<int>& workDays) {
    int minimum = workDays[0];
    int worstWeekendDayIndex = 0;

    for (int i = 1; i < 7; i++) {
        if (minimum > workDays[i]) {
            minimum = workDays[i];
            worstWeekendDayIndex = i;
        }
    }

    return findDay(worstWeekendDayIndex);
}

void solve(int& year, vector<pair<int, string>>& holidays, string& startDay) {
    vector<int> workDays(7, 0);

    int daysPerYear = findDaysPerYear(year);
    int startDayIndex = determineDayIndex(startDay);

    for (int day = 0; day < daysPerYear; day++) {
        workDays[(day + startDayIndex) % 7]++;
    }

    vector<int> holidaysNumber(holidays.size());
    for (auto& holiday : holidays) {
        workDays[(findPastDaysBeforeMonth(holiday.second, year) + (holiday.first - 1)
                  + startDayIndex) % 7]--;
    }

    cout << findBestWeekendDay(workDays) << " " << findWorstWeekendDay(workDays) << "\n";
}

int main() {
    int n, year;
    cin >> n >> year;

    vector<pair<int, string>> holidays(n);

    for (int i = 0; i < n; i++) {
        cin >> holidays[i].first >> holidays[i].second;
    }

    string startDay;
    cin >> startDay;

    solve(year, holidays, startDay);

    return 0;
}