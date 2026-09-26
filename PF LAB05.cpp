#include <stdio.h>

int main()
{
    int theorymarks;
    int practicalmarks;
    float attendancepercentage;
    int department;

    printf("Enter theory marks: ");
    scanf("%d", &theorymarks);

    printf("Enter practical marks: ");
    scanf("%d", &practicalmarks);

    printf("Enter attendance percentage: ");
    scanf("%f", &attendancepercentage);

    printf("Enter department: ");
    scanf("%d", &department);

    switch(department)
    {
        case 1:
            if(theorymarks >= 50 &&
               practicalmarks >= 40 &&
               attendancepercentage >= 75)
            {
                printf("Computer Science: Passed\n");
            }
            else
            {
                printf("Computer Science: Failed\n");
            }
            break;

        case 2:
            if(theorymarks >= 55 &&
               practicalmarks >= 45 &&
               attendancepercentage >= 75)
            {
                printf("Electrical Engineering: Passed\n");
            }
            else
            {
                printf("Electrical Engineering: Failed\n");
            }
            break;

        case 3:
            if(theorymarks >= 50 &&
               practicalmarks >= 35 &&
               attendancepercentage >= 80)
            {
                printf("Business Administration: Passed\n");
            }
            else
            {
                printf("Business Administration: Failed\n");
            }
            break;

        case 4:
            if(theorymarks >= 60 &&
               practicalmarks >= 40 &&
               attendancepercentage >= 75)
            {
                printf("Mathematics: Passed\n");
            }
            else
            {
                printf("Mathematics: Failed\n");
            }
            break;

        default:
            printf("Invalid department\n");
            return 0;
    }

    /* Distinction */
    if(theorymarks >= 85 &&
       practicalmarks >= 80 &&
       attendancepercentage >= 90)
    {
        printf("Distinction: Eligible\n");
    }
    else
    {
        printf("Distinction: Not Eligible\n");
    }

    /* Seat Category */
    if(theorymarks % 3 == 0)
    {
        printf("Seat Category: A\n");
    }
    else if(theorymarks % 3 == 1)
    {
        printf("Seat Category: B\n");
    }
    else
    {
        printf("Seat Category: C\n");
    }

    return 0;
}
