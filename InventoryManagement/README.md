# ASADAS Inventory & Order Management System

A console-based C++ application developed for the Programming I course at UNED.
This system manages spare parts inventory and orders for ASADAS (Associations Administering Aqueduct and Sewer Systems).

Demonstrates:
- File persistence
- Data validation
- Modular design with functions
- Menu-driven user interaction

------------------------------------------------------------
🚀 Features
------------------------------------------------------------

Inventory Management
--------------------
- Add new spare parts:
  Code: P + 8 digits (e.g., P00000890)
  Name, unit cost, quantity
  Supplier company + invoice number
  Employee ID (9 digits)

- Search parts by code
- Modify cost/quantity
- Delete parts (confirmation required)
- Data stored in INVENTARIO.TXT

Order Management
----------------
- Create orders:
  Code: PE + 8 digits (e.g., PE00000890)
  Part code + quantity
  Employee ID + date (DD/MM/YYYY)
  Status: "En proceso"

- Search orders by code
- Cancel orders → "Cancelado"
- Mark delivered → "Entregado"
- Data stored in PEDIDOS.TXT

Reports
-------
- Inventory Report: all parts
- Orders Report: all orders + status

------------------------------------------------------------
💾 Persistence & Data Handling
------------------------------------------------------------
- Load data from text files into 2D arrays
- Operate in memory
- Save back to files on exit
- Files are plain text (editable externally)

------------------------------------------------------------
🖥️ User Interface & Validation
------------------------------------------------------------
- Console menu with numbered options
- Input validation:
  Codes: P/PE + 8 digits
  IDs: 9 digits
  Numeric fields reject letters
  No empty fields
  Yes/No prompts: S or N
- User-friendly messages and confirmations
- Option to return to main menu after each operation

------------------------------------------------------------
🛠️ Technologies
------------------------------------------------------------
Language: C++ (C++11)
IDE: Code::Blocks (recommended)
Persistence: Plain text files
Paradigm: Procedural (functions)
Data structures: 2D arrays
