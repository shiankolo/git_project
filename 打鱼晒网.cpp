#include <stdio.h>
bool SB(int year){
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
int main(){
    int year, month, day, sum = 0, monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    printf("Input year, month, day: \n");
    scanf("%d%d%d", &year, &month, &day);
    if(month < 1 || month > 12){
        printf("Invalid month! \n");
        return 0;
    }
    if(month == 2){
        if(SB(year)){
            if(day < 1 || day > 29){
                printf("Invalid day! \n");
                return 0;
            }
        }
        else{
            if(day < 1 || day > 28){
                printf("Invalid day! \n");
                return 0;
            }
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day < 1 || day > 30){
            printf("Invalid day! \n");
            return 0;
        }
    }
    else{
        if(day < 1 || day > 31){
            printf("Invalid day! \n");
            return 0;
        }
    }
    if(year<1990){
        printf("Invalid year! \n");
        return 0;
    }
    for(int i=1990;i<year;i++){
        if(SB(i))
            sum+=366;
        else
            sum+=365;
    }
    for(int i=0; i<month-1;i++)sum+=monthDays[i];
    if(month>2 && SB(year))
        sum++;
    sum+=day-1;
    if(sum%5<3)
        printf("Today is for fishing! \n");
    else
        printf("Today is for sunning the net! \n");
    return 0;
}