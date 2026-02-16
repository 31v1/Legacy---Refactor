package powerbill;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.UUID;

 /**
 * Class Invoice
 * Represents a billing invoice, including client information,
 * calculation details, invoice number, and issue date.
 */

public class Invoice {
    //Atributes: Client, Calculator
    
    private String numberInvoice;
    private LocalDate dateInvoice;   
    private Client client;
    private Calculator calculator;
    
    //Setters and validations
    
    /**
    * Generates the invoice number automatically.
    * Creates a UUID, takes 8 characters from it,
    * and adds the prefix "INV-".     
    */
    
    public void setNumberInvoice(){
        String uuid = UUID.randomUUID().toString();
        String shortUuid = uuid.substring(4,12);
        this.numberInvoice = "INV-" + shortUuid;
    }
    
   /**
    * Converts a String into a LocalDate using the format dd/MM/yyyy.
    * If the input is null or empty, assigns the current date.
    * @param dateInvoice the date in format dd/MM/yyyy
    * @throws IllegalArgumentException if the format is invalid
    */

    public void setDateInvoice (String dateInvoice){
        if (dateInvoice == null || dateInvoice.trim ().isEmpty()) {
            this.dateInvoice = LocalDate.now();
        } else {
            try { 
                DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
                this.dateInvoice = LocalDate.parse(dateInvoice.trim(), formatter);
            } catch (DateTimeParseException e) {
              throw new IllegalArgumentException ("Invalid date, must be format: dd/mm/aaaa");
            } 
        }
    }
    
    /**
     * Sets the client instance of Client class as not null.
     * @throws IllegalArgumentException if invalid
     */
    
    public final void setClient(Client client){
        if (client != null){
            throw new IllegalArgumentException ("Client is empty.");
        }
            this.client = client;
    }
    
    /**
     * Sets the calculator instance of Calculator class as not null.
     * @throws IllegalArgumentException if invalid
     */
    
    public final void setCalculator(Calculator calculator){
        if (calculator != null){
            throw new IllegalArgumentException ("Calculator is empty.");
        }
            this.calculator = calculator;
    }
    
    //Getters
    
    /**
     * Returns the invoice number.
     * @return the invoice number
     */
    public String getNumberInvoice (){return numberInvoice;}
    
    /**
     * Returns the invoice date.
     * @return the invoice date 
     */
    public LocalDate getDateInvoice(){return dateInvoice;}
    
    /**
     * Returns the client information.
     * @return the information of the client.
     */
    public Client getClient(){return client;}
    
    /**
     * Returns the calculator information.
     * @return the information of the calculator.
     */
    public Calculator getCalculator(){return calculator;}
    
    //Constructor with parameters
    
    /**
        * Creates a new Invoice with the specified information for client.
    *
    * 
    */
    
    public Invoice (String dateInvoice, Client client, Calculator calculator){
        setNumberInvoice();
        setDateInvoice(dateInvoice);
        setClient(client);
        setCalculator(calculator);
    }
    
    //Default Constructor
    
    /**
     * Creates a new invoice with no initial values. Attributes must be set later
     * using the setter methods.
     */
    public Invoice (){}
    
    //Methods
    
    /** 
    * Prints the invoice for the client using the information from Calculator.
    * Note: The consumption charge already includes IVA, so the total
    * shown at the end reflects IVA + Red Cross tax + fixed service fee.
    */
    public String getInvoice(){
        StringBuilder sb = new StringBuilder ();
            sb.append("Invoice number: ").append(getNumberInvoice()).append("\n")
              .append("Invoice date: ").append(getDateInvoice()).append("\n")
              .append("Client name: ").append(client.getClientName()).append("\n")
              .append("Client number: ").append(client.getClientID()).append("\n")
              .append("KWVs comsumed: ").append(client.getKwvConsumed()).append("\n")
              .append("Fixed service fee: ").append(Calculator.FIXED_SERVICE_FEE).append("\n")
              .append("Consumption Charge amount IVA included: ").append(calculator.calculateConsumptionCharge()).append("\n")
              .append("Red Cross tax amount: ").append(calculator.taxRedCross()).append("\n")
              .append("Total: ").append(calculator.totalBill()).append("\n");
            return sb.toString();
    }
    
    
    /**
    * Overrides the default toString() method from Object.
    * Returns the formatted invoice string by calling getInvoice(),
    * so printing the Invoice object shows the full invoice details.
    */
    @Override
    public String toString(){
        return getInvoice();
    }                    
                
}
