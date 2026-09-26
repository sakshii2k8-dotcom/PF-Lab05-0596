#include <stdio.h>

int main()
{
    int category;
    int customercategory;
    int deliverydistance;
    int ordernumber;
    int discountrate;

    float orderamount;
    float discountamount;
    float finalbill;
    float deliverycharge;
    float prioritycharge;
    float totalamount;

    printf("Enter category:\n");
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Books\n");
    printf("4. Household\n");
    scanf("%d", &category);

    printf("\nEnter customer category:\n");
    printf("1. Regular\n");
    printf("2. Premium\n");
    printf("3. Corporate\n");
    scanf("%d", &customercategory);

    printf("\nEnter order amount: ");
    scanf("%f", &orderamount);

    printf("Enter delivery distance: ");
    scanf("%d", &deliverydistance);

    printf("Enter order number: ");
    scanf("%d", &ordernumber);

    /* Product category and customer category */
    switch(category)
    {
        case 1:
            switch(customercategory)
            {
                case 1:
                    discountrate = 5;
                    break;

                case 2:
                    discountrate = 10;
                    break;

                case 3:
                    discountrate = 15;
                    break;
            }
            break;

        case 2:
            switch(customercategory)
            {
                case 1:
                    discountrate = 10;
                    break;

                case 2:
                    discountrate = 15;
                    break;

                case 3:
                    discountrate = 20;
                    break;
            }
            break;

        case 3:
            switch(customercategory)
            {
                case 1:
                    discountrate = 8;
                    break;

                case 2:
                    discountrate = 12;
                    break;

                case 3:
                    discountrate = 18;
                    break;
            }
            break;

        case 4:
            switch(customercategory)
            {
                case 1:
                    discountrate = 7;
                    break;

                case 2:
                    discountrate = 14;
                    break;

                case 3:
                    discountrate = 20;
                    break;
            }
            break;

        default:
            printf("Invalid category\n");
            return 0;
    }

    /* Calculate discount */
    discountamount = orderamount * discountrate / 100;
    finalbill = orderamount - discountamount;

    /* Free shipping */
    if(finalbill >= 5000 || customercategory == 2 || customercategory == 3)
    {
        deliverycharge = 0;
    }
    else
    {
        deliverycharge = deliverydistance * 10;
    }

    /* Priority delivery */
    if((customercategory == 2 || customercategory == 3) &&
       orderamount >= 10000)
    {
        prioritycharge = 500;
    }
    else
    {
        prioritycharge = 0;
    }

    /* Total amount */
    totalamount = finalbill + deliverycharge + prioritycharge;

    /* Final report */
    printf("\n========== FINAL REPORT ==========\n");

    printf("Product Category: ");

    if(category == 1)
        printf("Electronics\n");
    else if(category == 2)
        printf("Clothing\n");
    else if(category == 3)
        printf("Books\n");
    else
        printf("Household\n");

    printf("Customer Category: ");

    if(customercategory == 1)
        printf("Regular\n");
    else if(customercategory == 2)
        printf("Premium\n");
    else
        printf("Corporate\n");

    printf("Original Order Amount: Rs. %.2f\n", orderamount);
    printf("Discount: %d%%\n", discountrate);
    printf("Discount Amount: Rs. %.2f\n", discountamount);
    printf("Final Payable Amount: Rs. %.2f\n", finalbill);

    printf("Delivery Distance: %d km\n", deliverydistance);

    printf("Shipping Status: %s\n",
           (deliverycharge == 0) ? "Free Shipping" : "Shipping Charges Apply");

    printf("Delivery Charges: Rs. %.2f\n", deliverycharge);

    printf("Priority Delivery: %s\n",
           (prioritycharge == 500) ? "Eligible" : "Not Eligible");

    printf("Priority Charges: Rs. %.2f\n", prioritycharge);

    printf("Processing Group: ");

    if(ordernumber % 4 == 0)
        printf("Group A\n");
    else if(ordernumber % 4 == 1)
        printf("Group B\n");
    else if(ordernumber % 4 == 2)
        printf("Group C\n");
    else
        printf("Group D\n");

    printf("Total Amount Payable: Rs. %.2f\n", totalamount);

    return 0;
}
		

			
	

	

