ASADAS Inventory & Order Management System
--

A console-based C++ application developed for the Programming I course at UNED.
This system manages spare parts inventory and orders for ASADAS (Associations Administering Aqueduct and Sewer Systems). It demonstrates fundamental programming concepts: file persistence, data validation, modular design with functions, and menu-driven user interaction.
🚀 Features
Inventory Management

    Add new spare parts with:

        Unique part code (P followed by up to 8 digits, e.g., P00000890)

        Part name, unit cost, quantity

        Supplier company name and invoice number

        ID of the person adding the part (9-digit Costa Rican ID)

    Search parts by code and display all details.

    Modify existing parts (only cost and quantity allowed).

    Delete parts after confirmation (shows details first).

    Data stored in INVENTARIO.TXT.

Order Management

    Create orders with:

        Unique order code (PE followed by up to 8 digits, e.g., PE00000890)

        Part code, quantity requested

        Employee ID, request date (DD/MM/YYYY)

        Status: automatically set to "En proceso" (In process)

    Search orders by code.

    Cancel orders (change status to "Cancelado").

    Mark as delivered (change status to "Entregado").

    Data stored in PEDIDOS.TXT.

Reports

    Inventory Report: tabulated list of all parts with full details.

    Orders Report: tabulated list of all orders with current status.

Persistence & Data Handling

    Data is loaded from text files into matrices (2D arrays) at startup.

    All operations are performed on in-memory arrays.

    On exit (menu option 6), arrays are saved back to the corresponding files.

    Files are plain text and can be inspected/modified externally.

User Interface & Validation

    Clean console menu with numbered options.

    All inputs are validated:

        Codes follow exact format (P/PE + 8 digits).

        IDs must be 9 digits.

        Numeric fields reject letters.

        No empty fields allowed.

        Yes/No prompts accept only S or N (case-insensitive).

    User-friendly messages and confirmations.

    Option to return to main menu after each operation.

🛠️ Technologies

    Language: C++ (C++11 standard)

    IDE: Code::Blocks (recommended, but any C++ compiler works)

    Persistence: Plain text files (INVENTARIO.TXT, PEDIDOS.TXT)

    Paradigm: Procedural with heavy use of functions

    Data structures: 2D arrays (matrices) for in-memory storage
