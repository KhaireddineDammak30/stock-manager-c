#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stock.h"

void addProduct(Product stock[], int *count) {
    printf("ID: "); scanf("%d", &stock[*count].id);
    printf("Name: "); scanf("%s", stock[*count].name);
    printf("Quantity: "); scanf("%d", &stock[*count].quantity);
    printf("Price: "); scanf("%f", &stock[*count].price);
    (*count)++;
    printf("✅ Product successfully added.\n");
}

void displayProducts(Product stock[], int count) {
    printf("\n📦 Available Products:\n");
    printf("ID\tName\tQuantity\tPrice(DT)\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f", stock[i].id, stock[i].name, stock[i].quantity, stock[i].price);
        if (stock[i].quantity < 5)
            printf(" ⚠️ (Low stock)");
        printf("\n");
    }
}

void editProduct(Product stock[], int count) {
    int id;
    printf("Enter the ID of the product to modify: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (stock[i].id == id) {
            printf("New name: "); scanf("%s", stock[i].name);
            printf("New quantity: "); scanf("%d", &stock[i].quantity);
            printf("New price: "); scanf("%f", &stock[i].price);
            printf("✅ Product updated successfully.\n");
            return;
        }
    }
    printf("❌ Product not found.\n");
}

void deleteProduct(Product stock[], int *count) {
    int id;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (stock[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                stock[j] = stock[j + 1];
            }
            (*count)--;
            printf("🗑️ Product successfully deleted.\n");
            return;
        }
    }
    printf("❌ Product not found.\n");
}

void searchById(Product stock[], int count) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (stock[i].id == id) {
            printf("✅ Found: %d | %s | %d | %.2f DT\n",
                   stock[i].id, stock[i].name, stock[i].quantity, stock[i].price);
            return;
        }
    }
    printf("❌ Product not found.\n");
}

void searchByName(Product stock[], int count) {
    char keyword[50];
    printf("Enter product name (full or partial): ");
    scanf("%s", keyword);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(stock[i].name, keyword)) {
            printf("🔎 %d | %s | %d | %.2f DT\n",
                   stock[i].id, stock[i].name, stock[i].quantity, stock[i].price);
            found = 1;
        }
    }
    if (!found)
        printf("❌ No matching product found.\n");
}

void saveData(Product stock[], int count) {
    FILE *f = fopen("data.txt", "w");
    if (!f) {
        printf("❌ Error: Could not open file for saving.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(f, "%d %s %d %.2f\n",
                stock[i].id, stock[i].name, stock[i].quantity, stock[i].price);
    }
    fclose(f);
    printf("💾 Data saved successfully.\n");
}

void loadData(Product stock[], int *count) {
    FILE *f = fopen("data.txt", "r");
    if (!f) {
        printf("⚠️ File not found. Starting with an empty stock.\n");
        return;
    }
    while (fscanf(f, "%d %s %d %f",
                  &stock[*count].id, stock[*count].name,
                  &stock[*count].quantity, &stock[*count].price) == 4) {
        (*count)++;
    }
    fclose(f);
    printf("📂 Loaded %d products from file.\n", *count);
}

int compareByName(const void *a, const void *b) {
    return strcmp(((Product *)a)->name, ((Product *)b)->name);
}

int compareByPrice(const void *a, const void *b) {
    float diff = ((Product *)a)->price - ((Product *)b)->price;
    return (diff > 0) - (diff < 0);
}

int compareByQuantity(const void *a, const void *b) {
    return ((Product *)a)->quantity - ((Product *)b)->quantity;
}

void sortProducts(Product stock[], int count) {
    int choice;
    printf("1. Sort by name\n2. Sort by price\n3. Sort by quantity\nChoice: ");
    scanf("%d", &choice);
    if (choice == 1) qsort(stock, count, sizeof(Product), compareByName);
    else if (choice == 2) qsort(stock, count, sizeof(Product), compareByPrice);
    else if (choice == 3) qsort(stock, count, sizeof(Product), compareByQuantity);
    else printf("❌ Invalid choice.\n");
}

void sellProduct(Product stock[], int *count) {
    int id, quantity;
    printf("Enter the product ID to sell: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (stock[i].id == id) {
            printf("Quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity > stock[i].quantity) {
                printf("❌ Insufficient stock.\n");
                return;
            }
            float total = quantity * stock[i].price;
            stock[i].quantity -= quantity;
            printf("\n🧾 Invoice\n");
            printf("Product: %s\nQuantity: %d\nUnit Price: %.2f DT\nTotal: %.2f DT\n",
                   stock[i].name, quantity, stock[i].price, total);
            return;
        }
    }
    printf("❌ Product not found.\n");
}
