package powerbill;

/**
 * Class Calculator
 * Purpose: Responsible for applying business rules to client data and producing invoice results.
 */

public class Calculator {
    //Atributes: client
    
    private Client client;
    
    //Setters and validations
    
    /**
     * Sets the client instance of Client class as not null.
     * @throws IllegalArgumentException if invalid
     */
    
    public final void setClient(Client client){
        if (client != null){
            this.client = client;
            return;
        }
        throw new IllegalArgumentException ("Client is empty.");
    }
    
    //Getter
    
    /**
     * Returns the client information.
     * @return the information of the client.
     */
    public Client getClient(){return client;}
    
    //Constructor with parameters
    
    /**
    * Creates a new Calculator with the specified client.
    *
    * @param client the information of the client.
    */
    
    public Calculator (Client client){
        setClient(client);
    }
    
    //Default Constructor
    
    /**
     * Creates a new Calculator with no initial values. Attributes must be set later
     * using the setter methods.
     */
    public Calculator (){}
    
    //Constants
    /** business rules values
     */
    
    private static final int FIXED_SERVICE_FEE = 5400;
    private static final int LOW_KWV = 500;
    private static final int MEDIUM_KWV = 550;
    private static final int HIGH_KWV = 600;
    private static final double IVA_RATE = 0.13;
    private static final double RED_CROSS = 10;
    
    //Methods
    
    /** Calculates the consumption charge based on Kwvs used according to business rules.
     * @return the total consumption charge
     * 
     */
    public double calculateConsumptionCharge(){
    int kwv = client.getKwvConsumed(); 
    double charge = 0;
    
        if (kwv <= 15){
            charge= kwv*LOW_KWV;
        }
            else if (kwv > 15 && kwv <= 30){
                charge = (15*LOW_KWV) + (kwv - 15)*MEDIUM_KWV;
            }
                else if (kwv > 30){
                    charge = (15*LOW_KWV) + (15 * MEDIUM_KWV) + (kwv - 30)*HIGH_KWV;     
                }

            // Apply VAT (IVA) if consumption exceeds 25 KWVs
            if (kwv > 25){
                charge = charge +(charge * IVA_RATE);
            }

        return charge;
    }
    
    /** Calculate Red Cross contribution based on KWVs consumed
     * @return the tax charge
     * 
     */
    public double taxRedCross(){
    int kwv = client.getKwvConsumed(); 
    double charge = 0;

    charge = kwv * RED_CROSS;
    return charge;
    }
    
    /** Calculates the total amount for the bill by adding consumption charge, Red Cross tax, and fixed service fee
     * @return the total bill charge
     * 
     */
    public double totalBill(){
        double total = calculateConsumptionCharge() + taxRedCross() + FIXED_SERVICE_FEE;
        return total;
    }  
}
