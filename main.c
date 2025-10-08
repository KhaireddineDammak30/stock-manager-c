#include <stdio.h>
#include "stock.h"

void displayMenu() {
    printf("\n");
    printf("╔═══════════════════════════════════════════════╗\n");
    printf("║           📦 STOCK MANAGEMENT SYSTEM          ║\n");
    printf("╠═══════════════════════════════════════════════╣\n");
    printf("║ 1. ➕ Add a product                           ║\n");
    printf("║ 2. 📋 Show all products                       ║\n");
    printf("║ 3. ✏️  Edit a product                         ║\n");
    printf("║ 4. ❌ Delete a product                        ║\n");
    printf("║ 5. 🔍 Search by ID                            ║\n");
    printf("║ 6. 🔎 Search by name                          ║\n");
    printf("║ 7. 🟰 Sort products                           ║\n");
    printf("║ 8. 🧾 Sell a product (Invoice)                ║\n");
    printf("║ 9. 💾 Save data                               ║\n");
    printf("║ 0. 🚪 Exit                                    ║\n");
    printf("╚═══════════════════════════════════════════════╝\n");
    printf("➡️  Enter your choice: ");
}

int main() {
    Product stock[MAX_PRODUCTS];
    int count = 0, choice;

    loadData(stock, &count);

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // to consume the newline

        switch (choice) {
            case 1: addProduct(stock, &count); break;
            case 2: displayProducts(stock, count); break;
            case 3: editProduct(stock, count); break;
            case 4: deleteProduct(stock, &count); break;
            case 5: searchById(stock, count); break;
            case 6: searchByName(stock, count); break;
            case 7: sortProducts(stock, count); break;
            case 8: sellProduct(stock, &count); break;
            case 9: saveData(stock, count); break;
            case 0:
                printf("\n👋 Thank you for using Stock Manager. See you soon!\n");
                break;
            default:
                printf("❌ Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
