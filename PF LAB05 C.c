#include <stdio.h>

int main()
{
    int status = 0;
    int operation;
    int device;
    int mode;
    int flag;

    printf("===== SMART HOME SECURITY CONTROLLER =====\n");

    printf("\nSelect Operation:\n");
    printf("1. Activate Device\n");
    printf("2. Deactivate Device\n");
    printf("3. Check Device Status\n");
    printf("4. Toggle Device\n");
    printf("5. Security Mode\n");
    printf("Enter operation: ");
    scanf("%d", &operation);

    /*
       Device flags:
       Door Lock     = 1  = 1 << 0
       Alarm System  = 2  = 1 << 1
       CCTV Camera   = 4  = 1 << 2
       Motion Sensor = 8  = 1 << 3
    */

    switch(operation)
    {
        case 1:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch(device)
            {
                case 1:
                    flag = 1 << 0;
                    status = status | flag;
                    break;

                case 2:
                    flag = 1 << 1;
                    status = status | flag;
                    break;

                case 3:
                    flag = 1 << 2;
                    status = status | flag;
                    break;

                case 4:
                    flag = 1 << 3;
                    status = status | flag;
                    break;

                default:
                    printf("Invalid device\n");
            }
            break;


        case 2:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch(device)
            {
                case 1:
                    flag = 1 << 0;
                    status = status & ~flag;
                    break;

                case 2:
                    flag = 1 << 1;
                    status = status & ~flag;
                    break;

                case 3:
                    flag = 1 << 2;
                    status = status & ~flag;
                    break;

                case 4:
                    flag = 1 << 3;
                    status = status & ~flag;
                    break;

                default:
                    printf("Invalid device\n");
            }
            break;


        case 3:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch(device)
            {
                case 1:
                    flag = 1 << 0;

                    printf("Main Door Lock: %s\n",
                           (status & flag) ? "Active" : "Inactive");
                    break;

                case 2:
                    flag = 1 << 1;

                    printf("Alarm System: %s\n",
                           (status & flag) ? "Active" : "Inactive");
                    break;

                case 3:
                    flag = 1 << 2;

                    printf("CCTV Camera: %s\n",
                           (status & flag) ? "Active" : "Inactive");
                    break;

                case 4:
                    flag = 1 << 3;

                    printf("Motion Sensor: %s\n",
                           (status & flag) ? "Active" : "Inactive");
                    break;

                default:
                    printf("Invalid device\n");
            }
            break;


        case 4:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch(device)
            {
                case 1:
                    flag = 1 << 0;
                    status = status ^ flag;
                    break;

                case 2:
                    flag = 1 << 1;
                    status = status ^ flag;
                    break;

                case 3:
                    flag = 1 << 2;
                    status = status ^ flag;
                    break;

                case 4:
                    flag = 1 << 3;
                    status = status ^ flag;
                    break;

                default:
                    printf("Invalid device\n");
            }
            break;


        case 5:
            printf("\nSelect Security Mode:\n");
            printf("1. Home Mode\n");
            printf("2. Away Mode\n");
            printf("3. Night Mode\n");
            printf("Enter mode: ");
            scanf("%d", &mode);

            switch(mode)
            {
                case 1:
                    /* Home Mode: Door + CCTV */
                    status = status | (1 << 0) | (1 << 2);
                    printf("Home Mode activated.\n");
                    break;

                case 2:
                    /* Away Mode: All devices */
                    status = status | (1 << 0) |
                                     (1 << 1) |
                                     (1 << 2) |
                                     (1 << 3);

                    printf("Away Mode activated.\n");
                    break;

                case 3:
                    /* Night Mode: Door + Alarm + Motion */
                    status = status | (1 << 0) |
                                     (1 << 1) |
                                     (1 << 3);

                    printf("Night Mode activated.\n");
                    break;

                default:
                    printf("Invalid security mode\n");
            }
            break;


        default:
            printf("Invalid operation\n");
    }


    /* Display complete device status */

    printf("\n===== DEVICE STATUS =====\n");

    printf("Main Door Lock: %s\n",
           (status & (1 << 0)) ? "Active" : "Inactive");

    printf("Alarm System: %s\n",
           (status & (1 << 1)) ? "Active" : "Inactive");

    printf("CCTV Camera: %s\n",
           (status & (1 << 2)) ? "Active" : "Inactive");

    printf("Motion Sensor: %s\n",
           (status & (1 << 3)) ? "Active" : "Inactive");


    /* Display four-bit binary status */

    printf("\nBinary Status: ");

    printf("%d", (status & (1 << 3)) ? 1 : 0);
    printf("%d", (status & (1 << 2)) ? 1 : 0);
    printf("%d", (status & (1 << 1)) ? 1 : 0);
    printf("%d", (status & (1 << 0)) ? 1 : 0);


    /* Fully armed when all four bits are set */

    if((status & (1 << 0)) &&
       (status & (1 << 1)) &&
       (status & (1 << 2)) &&
       (status & (1 << 3)))
    {
        printf("\nSecurity System: FULLY ARMED\n");
    }
    else
    {
        printf("\nSecurity System: NOT FULLY ARMED\n");
    }

    return 0;
}
