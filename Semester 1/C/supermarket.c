#include <stdio.h>
#include <string.h>

#define ITEMS 10

typedef struct {
    char id[10], name[20], size[10];
    double price;
    int qty;
} Product;

Product stock[ITEMS] = {
    {"P01", "Milk", "1L", 1200, 50},    {"P02", "Bread", "500g", 600, 30},
    {"P03", "Eggs", "Crate", 2500, 20}, {"P04", "Rice", "1kg", 1500, 40},
    {"P05", "Beans", "1kg", 1100, 35},  {"P06", "Sugar", "500g", 400, 60},
    {"P07", "Salt", "250g", 250, 100},  {"P08", "Water", "75cl", 200, 120},
    {"P09", "Noodles", "Pack", 350, 80},{"P10", "Tomato", "Tin", 300, 45}
};

int main() {
    char id[10];
    int buy_qty, cart_idx[ITEMS] = {0}, cart_qty[ITEMS] = {0}, c_size = 0;
    double total = 0.0;

    // 1. Display Products
    printf("---  OJAY'S SUPERMARKET STOCK ---\n");
    for (int i = 0; i < ITEMS; i++)
        printf("[%s] %s (%s) - ₦%.2f [Qty: %d]\n", stock[i].id, stock[i].name, stock[i].size, stock[i].price, stock[i].qty);

    // 2. Shopping Loop
    while (1) {
        printf("\nEnter Product ID to buy (or 'pay'): ");
        scanf("%s", id);
        if (strcmp(id, "pay") == 0) 
            break;

        for (int i = 0; i < ITEMS; i++) {
            if (strcmp(stock[i].id, id) == 0) {
                printf("Enter quantity: ");
                scanf("%d", &buy_qty);
                if (buy_qty <= stock[i].qty) {
                    cart_idx[c_size] = i;
                    cart_qty[c_size++] = buy_qty;
                    stock[i].qty -= buy_qty; // Balance stock
                    printf("Added to cart.\n");
                } else printf("Not enough stock!\n");
                break;
            }
        }
    }

    // 3. Generate Receipt & Save Files
    if (c_size > 0) {
        FILE *f_rec = fopen("supermarket receipt.txt", "w");
        FILE *f_stk = fopen(" supermarket stock.txt", "w");
        
        printf("\n====== RECEIPT ======\n");
        fprintf(f_rec, "====== RECEIPT ======\n");

        for (int i = 0; i < c_size; i++) {
            int idx = cart_idx[i];
            double sub = stock[idx].price * cart_qty[i];
            total += sub;
            printf("%s x%d = ₦%.2f\n", stock[idx].name, cart_qty[i], sub);
            fprintf(f_rec, "%s x%d = ₦%.2f\n", stock[idx].name, cart_qty[i], sub);
        }

        printf("TOTAL: ₦%.2f\n=====================\n", total);
        fprintf(f_rec, "TOTAL: ₦%.2f\n=====================\n", total);

        // 4. Save and Show Remaining Stock
        printf("\n--- REMAINING STOCK ---\n");
        for (int i = 0; i < ITEMS; i++) {
            printf("%s: %d left\n", stock[i].name, stock[i].qty);
            fprintf(f_stk, "%s,%s,%s,%.2f,%d\n", stock[i].id, stock[i].name, stock[i].size, stock[i].price, stock[i].qty);
        }

        fclose(f_rec);
        fclose(f_stk);
    }
    return 0;
}