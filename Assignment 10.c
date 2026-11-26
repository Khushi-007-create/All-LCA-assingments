#include <stdio.h>

int main() {
    int year, month, day, d;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Enter year: ");
    scanf("%d", &year);

   
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

   
    int y = year - 1;
    int startDay = (y + y/4 - y/100 + y/400 + 1) % 7;

    
    for (month = 0; month < 12; month++) {
        printf("\n\n--- %s %d ---\n", months[month], year);
        printf("Su Mo Tu We Th Fr Sa\n");

        
        for (d = 0; d < startDay; d++) {
            printf("   ");
        }

        
        for (day = 1; day <= daysInMonth[month]; day++) {
            printf("%2d ", day);
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
