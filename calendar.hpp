#ifndef TO_ASSIGN_CALENDAR_H_
#define TO_ASSIGN_CALENDAR_H_


namespace calendar{

int main() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;

    int days_in_month;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }

    tm start_of_month = *now;
    start_of_month.tm_mday = 1;
    mktime(&start_of_month);
    int starting_day = start_of_month.tm_wday;

    cout << year << "              " << setw(2) << setfill('0') << month << endl;
    cout << "Su Mo Tu We Th Fr Sa" << endl;

    int day = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == 0 && j < starting_day) {
                cout << "   ";
            } else if (day > days_in_month) {
                break;
            } else {
                cout << setw(2) << setfill('0') << day << " ";
                day++;
            }
        }
        cout << endl;
        if (day > days_in_month) {
            break;
        }
    }
	getch();
    return 0;
}

}

#endif