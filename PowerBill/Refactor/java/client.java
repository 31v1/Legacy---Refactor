package powerbill;

/**
 * Class Client
 * Purpose: Validate and save the client information.
 * 
 */
public final class Client {
    // Attributes: name, ID, consumption
    
    private String clientName;
    private String clientID;
    private int kwvConsumed;
    
    // Setters and validation methods
    
    /**
     * Sets the client name after validating input.
     * @param clientName must contain only letters and spaces
     * @throws IllegalArgumentException if invalid
     */    
    public void setClientName(String clientName){
        if (clientName != null){
            clientName = clientName.trim();
            if (clientName.matches("[\\p{L} ]+")){
                this.clientName = clientName;
                return;
            }
        }
        throw new IllegalArgumentException("Invalid name. It must contain only letters and spaces, no numbers or symbols.");
    }
    
    public void setClientID(String clientID){
        if (clientID != null){
            clientID = clientID.trim();
            if (clientID.matches("[a-zA-Z0-9]+")){
                this.clientID = clientID;
                return;
            }   
        }
        throw new IllegalArgumentException ("Invalid Client number. It must contain only letters and numbers, no symbols or spaces.");
    }
    
    /**
    * Sets the amount of KWVs consumed by the client.
    * Validates that the value is greater than 0 and less than 999999.
    
    * @param kwvConsumed the number of KWVs consumed
    * @throws IllegalArgumentException if the value is less than 0 or greater than 999999
    */
    public void setKwvConsumed (int kwvConsumed){
        if (kwvConsumed < 0 || kwvConsumed > 999999){
            throw new IllegalArgumentException ("Invalid number. It must be higher than 0 and less than 999999");          
        }
        this.kwvConsumed = kwvConsumed; 
    }
    
    //Getters
    
    /**
     * Returns the client's name.
     * @return the name of the client.
     */
    public String getClientName(){return clientName;}
    
    
    /**
     * Returns the client's ID.
     * @return the unique identifier of the client.
     */
    public String getClientID(){return clientID;}
    
    
    /**
     * Returns the amount of KWVs consumed by the client.
     * @return the number of Kwvs consumed.
     */
    public int getKwvConsumed(){return kwvConsumed;}
    
    //Constructor with parameters.
    
    /**
    * Creates a new Client with the specified name, ID, and consumption.
    *
    * @param clientName the name of the client
    * @param clientID the unique identifier of the client
    * @param kwvConsumed the amount of KWVs consumed
    */
    public Client (String clientName, String clientID, int kwvConsumed){
        setClientName(clientName);
        setClientID(clientID);
        setKwvConsumed(kwvConsumed);
    }
    
    //Default Constructor
    
    /**
     * Creates a new Client with no initial values. Attributes must be set later
     * using the setter methods.
     */
    public Client (){}
    
    
    
    
}
