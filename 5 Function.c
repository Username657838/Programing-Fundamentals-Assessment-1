#include <stdio.h>
#include <stdlib.h>
#define NUM_ITEMS      5
#define MIN_QTY        1
#define MAX_QTY        10
#define VAT_RATE       0.05
#define DISCOUNT_RATE  0.10
#define DISCOUNT_LIMIT 60.00

/* The code for Task 5 Juancho and Nov 23, 2026
   QuickBite Till split into functions */

/* This reads a whole number. Returns to -1 
if typed string instead of integers. */
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

/* The show_menu() displays the menu to the customer. */
void show_menu(const char *names[], const float prices[], int count) {
    int i;
    printf("\n--- MENU ---\n");
    for (i = 0; i < count; i++) {
        printf("%d. %-14s AED %.2f\n", i + 1, names[i], prices[i]);
    }
    printf("0. Finish order\n");
}

/* The get_choice() asks the customer 
to select the item from the menu. */
int get_choice(void) {
    printf("Enter item number: ");
    return read_int();
}

/* The get_quantity() asks the customer how many 
of the selected food items they want to buy. */
int get_quantity(void) {
    int qty = 0;
    while (qty < MIN_QTY || qty > MAX_QTY) {
        printf("Enter quantity (%d-%d): ", MIN_QTY, MAX_QTY);
        qty = read_int();
        if (qty < MIN_QTY || qty > MAX_QTY) {
            printf("Invalid quantity! Must be between %d and %d.\n",
                   MIN_QTY, MAX_QTY);
        }
    }
    return qty;
}

/* The calc_discount() calculates the 
discount applied to the customer's order. */
float calc_discount(float subtotal) {
    if (subtotal >= DISCOUNT_LIMIT) {
        return subtotal * DISCOUNT_RATE;
    }
    return 0.0;
}

/* The calc_vat() calculates the 5% Value
Added Tax (VAT) onthe amount it receives. */
float calc_vat(float amount) {
    return amount * VAT_RATE;
}

/* The print_receipt() prints the final receipt for the customer. It 
displays the number of items, subtotal,discount, VAT, and final total. */
void print_receipt(int items_ordered, float subtotal, float discount,
                   float discounted, float vat, float total) {
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
}

int main(void) {
    const char *names[NUM_ITEMS] = {"Chicken Wrap", "Beef Burger",
                                    "Falafel Box", "Fries", "Lemonade"};
    float prices[NUM_ITEMS] = {18.00, 22.50, 15.00, 8.00, 6.50};

    int choice, qty;
    int items_ordered = 0;
    float line_cost;
    float subtotal = 0.0, discount, discounted, vat, total;

    printf("=== Welcome to QuickBite Kitchen ===\n");

    /* The show_menu() again keeps taking items until the cashier enters 0 */
    do {
        show_menu(names, prices, NUM_ITEMS);
        choice = get_choice();

        if (choice == 0) {
            /* typyng 0 ends the order and the receipt is printed */
        } else if (choice < 1 || choice > NUM_ITEMS) {
            printf("Invalid choice! Please enter a number from 1 to %d.\n",
                   NUM_ITEMS);
        } else {
            qty = get_quantity();
            line_cost = prices[choice - 1] * qty;
            subtotal = subtotal + line_cost;
            items_ordered = items_ordered + qty;
            printf("Added: %d x %s = AED %.2f\n", qty, names[choice - 1],
                   line_cost);
            printf("Running subtotal: AED %.2f\n", subtotal);
        }
    } while (choice != 0);

    if (items_ordered == 0) {
        printf("\nNo items ordered. Goodbye!\n");
        return 0;
    }

    /* Discount is added first, then VAT on the amount */
    discount   = calc_discount(subtotal);
    discounted = subtotal - discount;
    vat        = calc_vat(discounted);
    total      = discounted + vat;

    print_receipt(items_ordered, subtotal, discount, discounted, vat, total);
    return 0;
}
