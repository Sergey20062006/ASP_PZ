#include <stdio.h>

int main() {
    int day, month, year;
    int calendar_choice;
    int gold_year = 0;

    while (1) {
        printf("Choose calendar (1 - Gregorian, 2 - Julian): ");
        scanf("%d", &calendar_choice);

        if (calendar_choice == 1 || calendar_choice == 2) {
            break;
        } else {
            printf("Invalid calendar choice. Please enter 1 for Gregorian or 2 for Julian.\n");
        }
    }

    while (1) {
        printf("Enter year: ");
        scanf("%d", &year);

        if (year > 0) {
            break;
        } else {
            printf("Invalid year. Please enter a positive year.\n");
        }
    }

    if (calendar_choice == 1) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            gold_year = 1;
        }
    } else {
        if (year % 4 == 0) {
            gold_year = 1;
        }
    }

    while (1) {
        printf("Enter month: ");
        scanf("%d", &month);

        if (month >= 1 && month <= 12) {
            break;
        } else {
            printf("Invalid month. Please enter a month between 1 and 12.\n");
        }
    }

    int days_in_month;
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        days_in_month = 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        if (gold_year) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    }

    while (1) {
        printf("Enter day: ");
        scanf("%d", &day);

        if (day >= 1 && day <= days_in_month) {
            break;
        } else {
            printf("Invalid day. Please enter a day between 1 and %d.\n", days_in_month);
        }
    }

    day = day + 1;
    if (day > days_in_month) {
        day = 1;
        month = month + 1;
        if (month > 12) {
            month = 1;
            year = year + 1;
        }
    }

    printf("Tomorrow's date: %d.%d.%d\n", day, month, year);

    return 0;
}
