package waterbill;
import java.util.Scanner;

/**
 * Class Menu
 * Purpose: Responsible for controlling the interface between the system and the user.
 */


public class Menu {
    private Scanner scanner;

    public Menu() {
        this.scanner = new Scanner(System.in);
    }

    public void run() {
        int totalClients = 0;
        int totalKWV = 0;
        double totalBaseConsumption = 0;
        double totalIVA = 0;
        double totalRedCross = 0;
        double totalBilled = 0;

        int option;
        do {
            showMainMenu();
            option = getIntInput();

            switch (option) {
                case 1:
                    // Process a new client
                    try {
                        System.out.print("Client name: ");
                        String name = scanner.nextLine();

                        System.out.print("Client ID: ");
                        String id = scanner.nextLine();

                        System.out.print("KWVs consumed: ");
                        int kwv = getIntInput();

                        Client client = new Client(name, id, kwv);
                        Calculator calculator = new Calculator(client);
                        Invoice invoice = new Invoice("", client, calculator); // empty date = today

                        // Display invoice
                        System.out.println("\n" + invoice);

                        // Update totals
                        totalClients++;
                        totalKWV += kwv;
                        totalBaseConsumption += calculator.calculateBaseConsumptionCharge();
                        totalIVA += calculator.IVAcharge();
                        totalRedCross += calculator.taxRedCross();
                        totalBilled += calculator.totalBill();

                        // Ask if user wants to continue
                        System.out.print("\nDo you want to process another client? (Y/N): ");
                        String answer = scanner.nextLine();
                        if (answer.equalsIgnoreCase("N")) {
                            option = 2; // force exit to show report
                        }
                    } catch (IllegalArgumentException e) {
                        System.out.println("Error: " + e.getMessage());
                    }
                    break;

                case 2:
                    // Show final report and exit
                    showFinalReport(totalClients, totalKWV, totalBaseConsumption,
                                    totalIVA, totalRedCross, totalBilled);
                    break;

                default:
                    System.out.println("Invalid option. Please choose 1 or 2.");
            }
        } while (option != 2);

        scanner.close();
    }

    private void showMainMenu() {
        System.out.println("\n=== BILLING SYSTEM ===");
        System.out.println("1. Process new client");
        System.out.println("2. Exit and show final report");
        System.out.print("Choose an option: ");
    }

    private int getIntInput() {
        while (!scanner.hasNextInt()) {
            System.out.print("Invalid input. Please enter a number: ");
            scanner.next(); // discard invalid input
        }
        int value = scanner.nextInt();
        scanner.nextLine(); // clear buffer
        return value;
    }

    private void showFinalReport(int totalClients, int totalKWV, double totalBaseConsumption,
                                 double totalIVA, double totalRedCross, double totalBilled) {
        double totalFixed = totalClients * Calculator.FIXED_SERVICE_FEE;
        double incomeTax = (totalBaseConsumption + totalFixed) * 0.10;

        System.out.println("\n=== FINAL REPORT ===");
        System.out.println("Total clients processed: " + totalClients);
        System.out.println("Total KWVs consumed: " + totalKWV);
        System.out.println("Total base consumption: " + totalBaseConsumption);
        System.out.println("Total IVA: " + totalIVA);
        System.out.println("Total Red Cross tax: " + totalRedCross);
        System.out.println("Total billed: " + totalBilled);
        System.out.println("Total fixed service fee: " + totalFixed);
        System.out.println("Income tax (10% on base consumption + fixed): " + incomeTax);
    }
}
