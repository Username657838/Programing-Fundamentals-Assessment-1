/* The code for Task 6, Reg: 1025013 Juancho and Nov 24, 2026
   QuickBite Till split into functions */
#include <stdio.h>
#include <stdlib.h>
#define NUM_ITEMS        5       /* The number of items on the menu */
#define FINISH_CHOICE    0       /* The menu number to finish order */
#define MIN_QUANTITY     1       /* The smallest quantity allowed per item */
#define MAX_QUANTITY     10      /* The largest quantity allowed per item */
#define VAT_PERCENT      5       /* The VAT as a whole-number percentage */
#define DISCOUNT_PERCENT 10      /* The discount as a whole-number percentage */
#define VAT_RATE         (VAT_PERCENT / 100.0)
#define DISCOUNT_RATE    (DISCOUNT_PERCENT / 100.0)
#define DISCOUNT_LIMIT   60.00   /* The subtotal needed for the discount */

/* This reads a whole number. Returns to -1 
if typed string instead of integers. */
int read_whole_number(void) {
    int number_read;
    int scan_result;
    int leftover_char;

    scan_result = scanf("%d", &number_read);
    if (scan_result == EOF) {
        exit(0);                       /* If theres no more input, it stop the program */
    }
    if (scan_result != 1) {
        /* This throws away the non-input */
        while ((leftover_char = getchar()) != '\n' && leftover_char != EOF) {
        }
        return -1;
    }
    return number_read;
}

/* The show_menu() displays the menu to the customer. */
void show_menu(const char *item_names[], const float item_prices[],
               int item_count) {
    int item_index;

    printf("\n--- MENU ---\n");
    for (item_index = 0; item_index < item_count; item_index++) {
        printf("%d. %-14s AED %.2f\n", item_index + 1,
               item_names[item_index], item_prices[item_index]);
    }
    printf("%d. Finish order\n", FINISH_CHOICE);
}

/* The get_menu_choice() is the same as get_choice,
asks the customer to select the item from the menu. */
int get_menu_choice(void) {
    printf("Enter item number: ");
    return read_whole_number();
}

/* The get_quantity() asks the customer how many 
of the selected food items they want to buy. */
int get_quantity(void) {
    int quantity = 0;

    while (quantity < MIN_QUANTITY || quantity > MAX_QUANTITY) {
        printf("Enter quantity (%d-%d): ", MIN_QUANTITY, MAX_QUANTITY);
        quantity = read_whole_number();
        if (quantity < MIN_QUANTITY || quantity > MAX_QUANTITY) {
            printf("Invalid quantity! Must be between %d and %d.\n",
                   MIN_QUANTITY, MAX_QUANTITY);
        }
    }
    return quantity;
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
                   float discounted_amount, float vat, float total) {
    printf("\n========== RECEIPT ==========\n");
    printf("Items ordered:     %d\n", items_ordered);
    printf("Subtotal:          AED %.2f\n", subtotal);
    if (discount > 0) {
        printf("Discount (%d%%):    AED %.2f\n", DISCOUNT_PERCENT, discount);
        printf("Discounted amount: AED %.2f\n", discounted_amount);
    } else {
        printf("Discount:          none (subtotal under AED %.0f)\n",
               DISCOUNT_LIMIT);
    }
    printf("VAT (%d%%):          AED %.2f\n", VAT_PERCENT, vat);
    printf("TOTAL:             AED %.2f\n", total);
    printf("=============================\n");
    printf("Thank you for choosing QuickBite!\n");
}

/* Runs the till: takes items until the cashier finishes, then works out
   the discount, VAT and total, and prints the receipt. */
int main(void) {
    const char *item_names[NUM_ITEMS] = {"Chicken Wrap", "Beef Burger",
                                         "Falafel Box", "Fries", "Lemonade"};
    float item_prices[NUM_ITEMS] = {18.00, 22.50, 15.00, 8.00, 6.50};

    int menu_choice;
    int quantity;
    int items_ordered = 0;
    float line_total;
    float subtotal = 0.0;
    float discount;
    float discounted_amount;
    float vat;
    float total;

    printf("=== Welcome to QuickBite Kitchen ===\n");

    /* The show_menu() again keeps taking items until the cashier enters 0 */
    do {
        show_menu(item_names, item_prices, NUM_ITEMS);
        menu_choice = get_menu_choice();

        if (menu_choice == FINISH_CHOICE) {
            /* If order is finished: the order
            ends and the receipt is printed */
        } else if (menu_choice < 1 || menu_choice > NUM_ITEMS) {
            printf("Invalid choice! Please enter a number from 1 to %d.\n",
                   NUM_ITEMS);
        } else {
            quantity = get_quantity();
            /* menu start at 1 but the 
            array positions start at 0 */
            line_total = item_prices[menu_choice - 1] * quantity;
            subtotal = subtotal + line_total;
            items_ordered = items_ordered + quantity;
            printf("Added: %d x %s = AED %.2f\n", quantity,
                   item_names[menu_choice - 1], line_total);
            printf("Running subtotal: AED %.2f\n", subtotal);
        }
    } while (menu_choice != FINISH_CHOICE);

    if (items_ordered == 0) {
        printf("\nNo items ordered. Goodbye!\n");
        return 0;
    }

    /* Discount is added first, then VAT on the amount */
    discount          = calc_discount(subtotal);
    discounted_amount = subtotal - discount;
    vat               = calc_vat(discounted_amount);
    total             = discounted_amount + vat;

    print_receipt(items_ordered, subtotal, discount, discounted_amount,
                  vat, total);
    return 0;
}
