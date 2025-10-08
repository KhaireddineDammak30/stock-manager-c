# 📦 Stock Manager — Inventory Management Application (C)

A console-based application written in **C language** to manage product inventory using CRUD operations (Create, Read, Update, Delete).  
It includes automatic file saving, UTF-8 display support, and a clean, user-friendly terminal interface.

---

## 🖥️ Console Preview
<img width="732" height="432" alt="interface" src="https://github.com/user-attachments/assets/41c06bb5-e0c7-4008-9af6-12ce9738b2d2" />

---

## ⚙️ Main Features

- ➕ **Add, edit, and delete** products  
- 🔍 **Search** products by ID or by (partial) name  
- 🟰 **Sort** by name, price, or quantity  
- ⚠️ **Low-stock alerts** (when quantity < 5)  
- 🧾 **Generate invoices** automatically (reduces quantity after sale)  
- 💾 **Persistent storage** in `data.txt`  
- 📂 **Automatic loading** of saved data at startup  

---

## 🧰 Technologies Used

| Component | Description |
|------------|--------------|
| 💻 Language | C (ANSI C compatible) |
| 🧠 Recommended IDE | Visual Studio Code |
| 🔧 Compiler | MinGW / GCC |
| 📁 Data Storage | Text file `data.txt` |
| 🌍 Encoding | UTF-8 (`chcp 65001` on Windows) |

---

## 🚀 Installation & Usage

### 1️⃣ Prerequisites
- Install a **C compiler** (e.g., MinGW or GCC).  
- On **Windows**, enable UTF-8 mode for proper display, then compile and run the program using the commands below 👇  

        **Enable UTF-8 encoding (Windows only):**  
        chcp 65001  
        **Compile the project:**  
        gcc main.c stock.c -o stock-manager.exe  
        **Run the program:**  
        stock-manager.exe 



## 👥 How Others Can Use It

Any user can clone, compile, and run the project directly from GitHub using the following commands 👇  

    # Clone the repository
    git clone https://github.com/KhaireddineDammak30/stock-manager-c.git
    # Enter the project directory
    cd stock-manager-c
    # Enable UTF-8 encoding (Windows only)
    chcp 65001
    # Compile the project
    gcc main.c stock.c -o stock-manager.exe
    # Run the program
    stock-manager.exe

💡 The application is **portable** and works on any system with a C compiler (Windows, Linux, or macOS).
