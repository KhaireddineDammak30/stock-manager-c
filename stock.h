#ifndef STOCK_H
#define STOCK_H

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Core CRUD operations
void addProduct(Product stock[], int *count);
void displayProducts(Product stock[], int count);
void editProduct(Product stock[], int count);
void deleteProduct(Product stock[], int *count);

// Search and sorting
void searchById(Product stock[], int count);
void searchByName(Product stock[], int count);
void sortProducts(Product stock[], int count);

// File operations
void saveData(Product stock[], int count);
void loadData(Product stock[], int *count);

// Sales and alerts
void sellProduct(Product stock[], int *count);
void checkLowStock(Product stock[], int count);

#endif
