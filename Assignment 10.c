#include <stdio.h>

int main() {
    int year, month, day, i;
    int totalDays = 0, startDay;

    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Enter year: ");
    scanf("%d", &year);

    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29; // Change February to 29 days
    }

    
    for (i = 1900; i < year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }

    
    startDay = (totalDays + 1) % 7;

   
    for (month = 0; month < 12; month++) {
        printf("\n\n  ------------ %s %d ------------\n", months[month], year);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        
        for (i = 0; i < startDay; i++) {
            printf("     ");
        }

        
        for (day = 1; day <= daysInMonth[month]; day++) {
            printf("%5d", day);
            startDay++;

            
            if (startDay > 6) {
                startDay = 0;
                printf("\n");
            }
        }
    }

    printf("\n");
    return 0;
}
