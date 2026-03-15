# ASADAS Inventory & Orders System (Legacy C++)

This repository contains the **legacy implementation** of the ASADAS project in C++, developed as part of the course *Introducción a la Programación (UNED)*.

## 📂 Project Context
- Developed for the **Associaciones Administradoras de los Sistemas de Acueductos y Alcantarillados (ASADAS)**.
- Purpose: manage spare parts inventory and employee orders for repairs.
- Based on official academic requirements (functions, arrays/vectors, file I/O, pointers, exception handling).

## 🛠️ Features (Legacy Implementation)
- **Inventory Management**
  - Add new spare parts.
  - Consult parts by code.
  - Modify part details (cost, quantity, provider info).
  - Delete parts with confirmation.
  - Data stored in `Inventario.txt`.

- **Orders Management**
  - Register new orders (default status: *En proceso*).
  - Validate employee ID and date format.
  - Save orders in `Pedidos.txt`.

- **Reports**
  - Inventory report with all fields (code, name, cost, quantity, provider, invoice, employee ID).
  - Orders report with all fields (order code, piece code, quantity, employee ID, date, status).

- **Menu System**
  - Console menu with options 1–6.
  - Validations for input, formats, and S/N responses.
  - Menu repeats until option #6 (Exit).

## ⚙️ Technical Notes
- Developed in **C++** using CodeBlocks IDE.
- Uses **classes** (`Pieza`, `Pedido`) and **functions** for modularity.
- Validations included: numeric fields, ID formats, empty inputs, code formats (P########, PE########).
- Persistence: inventory and orders stored in text files.

## 📜 Status
- This is the **legacy version**: functional but still monolithic in some parts.
- Refactor planned: cleaner separation of classes (`InventoryManager`, `OrderManager`, `Report`), improved file handling, and more robust error management.

## 🐛 Epic Fails & 🏆 Victories Log
- 🐛 Fails: Handling file I/O and vectors was messy and time-consuming.  
- 🏆 Victories: Completed all required menu options and validations.  
- 🔮 Next Steps: Refactor into modular managers and improve persistence.  
- ⏱️ Estimated Time: “soon… or maybe next millennium.”
