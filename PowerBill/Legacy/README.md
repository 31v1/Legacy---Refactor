# Legacy - PowerBill (PSeInt)

## Context
This is the original pseudocode implementation of the **PowerBill** project, developed in **PSeInt** during the Logic for Computing course.  
It represents the first version of the electricity billing system before being migrated and refactored into Java or other programming languages.

## Purpose
The goal of this program is to simulate the billing process for the **Compañía de Fuerza y Luz (CFL)**, which provides electricity service to thousands of subscribers.  
The pseudocode calculates invoices for each client based on:

- **Fixed Service Fee:** 5,400 colones for all subscribers.  
- **Consumption Charge:** Progressive billing depending on kilowatt-volts (KWVs) consumed.  
- **Cruz Roja Tax:** 10 colones per KWV consumed.  
- **Value Added Tax (VAT):** 13% applied if consumption exceeds 25 KWVs.  
- **Income Tax:** 10% of the sum of fixed service fees and consumption charges, paid by CFL to the government.  

## Features
- Input subscriber data: name, ID, and monthly consumption.  
- Validate that inputs are greater than zero.  
- Calculate all billing components (fixed fee, consumption, Cruz Roja tax, VAT, total).  
- Print a detailed invoice for each client.  
- Allow processing multiple clients until the user decides to stop.  
- Generate a final report with totals: number of
