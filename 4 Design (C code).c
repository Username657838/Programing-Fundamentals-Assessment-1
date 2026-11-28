#include <stdio.h>
#include <stdlib.h>
#define NUM_ITEMS      5
#define MIN_QTY        1
#define MAX_QTY        10
#define VAT_RATE       0.05
#define DISCOUNT_RATE  0.10
#define DISCOUNT_LIMIT 60.00

/* The code for Task 4 Juancho and Nov 22, 2026 */
int read_int(void) {
    int value, result, c;
    result = scanf("%d", &value);
    if (result == EOF) {
        exit(0);
    }
    if (result != 1) {
        while ((c = getchar()) != '\n' && c != EOF) { }
        return -1;
    }
    return value;
}

int main(void) {
    const char *names[NUM_ITEMS] = {"Chicken Wrap", "Beef Burger",
                                    "Falafel Box", "Fries", "Lemonade"};
    float prices[NUM_ITEMS] = {18.00, 22.50, 15.00, 8.00, 6.50};

    int choice, qty, i;
    int items_ordered = 0;
    float line_cost;
    float subtotal = 0.0, discount = 0.0, discounted, vat, total;

    printf("=== Welcome to QuickBite Kitchen ===\n");

    /* The list of the code menu, contains name and prices,*/
    do {
        printf("\n--- MENU ---\n");
        for (i = 0; i < NUM_ITEMS; i++) {
            printf("%d. %-14s AED %.2f\n", i + 1, names[i], prices[i]);
        }
        printf("0. Finish order\n");
        printf("Enter item number: ");
        choice = read_int();

        if (choice == 0) {
            /* Selecting the number 0 will end 
            the menu,and print the reciept */
        } else if (choice < 1 || choice > NUM_ITEMS) {
            /* A message appears upon entering any number 1-4, then
            enter an amount 1-10 message appears*/
            printf("Invalid choice! Please enter a number from 1 to %d.\n",
                   NUM_ITEMS);
        } else {
            /* This will keep appearing to invalidate under, over, 
            or non-integers until the qunatity has been ordered*/
            qty = 0;
            while (qty < MIN_QTY || qty > MAX_QTY) {
                printf("Enter quantity (%d-%d): ", MIN_QTY, MAX_QTY);
                qty = read_int();
                if (qty < MIN_QTY || qty > MAX_QTY) {
                    printf("Invalid quantity! Must be between %d and %d.\n",
                           MIN_QTY, MAX_QTY);
                }
            }
            line_cost = prices[choice - 1] * qty;
            subtotal = subtotal + line_cost;
            items_ordered = items_ordered + qty;
            printf("Added: %d x %s = AED %.2f\n", qty, names[choice - 1],
                   line_cost);
            printf("Running subtotal: AED %.2f\n", subtotal);
        }
    } while (choice != 0);

    /* If the reciept is over 60 Dirhams, then the discount will be added 
    first */
    if (items_ordered == 0) {
        printf("\nNo items ordered. Goodbye!\n");
        return 0;
    }

    if (subtotal >= DISCOUNT_LIMIT) {
        discount = subtotal * DISCOUNT_RATE;
    }
    discounted = subtotal - discount;
    vat = discounted * VAT_RATE;
    total = discounted + vat;
    /*VAT will always add with or without
    discount on subtotal amount always 5%*/
    printf("\n========== RECEIPT ==========\n");
    printf("Items ordered:     %d\n", items_ordered);
    printf("Subtotal:          AED %.2f\n", subtotal);
    if (discount > 0) {
        printf("Discount (10%%):    AED %.2f\n", discount);
        printf("Discounted amount: AED %.2f\n", discounted);
    } else {
        printf("Discount:          none (subtotal under AED 60)\n");
    }
    printf("VAT (5%%):          AED %.2f\n", vat);
    printf("TOTAL:             AED %.2f\n", total);
    printf("=============================\n");
    printf("Thank you for choosing QuickBite!\n");
    return 0;
}
