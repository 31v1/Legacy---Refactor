package managementsystem;

/**
 * Class Piece
 * Purpose: Save the piece information
 */

public class Piece {
    //Atributes: code, name, value, quantity, company name, company billing, employeeId.
    
    private String pieceCode;
    private String pieceName;
    private double pieceValue;
    private int pieceQuantity;
    private String companyName;
    private String companyInvoice;
    private String employeeId;
    
    // Setters

    public void setPieceCode(String pieceCode) {
        this.pieceCode = pieceCode;
    }

    public void setPieceName(String pieceName) {
        this.pieceName = pieceName;
    }

    public void setPieceValue(double pieceValue) {
        this.pieceValue = pieceValue;
    }

    public void setPieceQuantity(int pieceQuantity) {
        this.pieceQuantity = pieceQuantity;
    }

    public void setCompanyName(String companyName) {
        this.companyName = companyName;
    }

    public void setCompanyInvoice(String companyInvoice) {
        this.companyInvoice = companyInvoice;
    }

    public void setEmployeeId(String employeeId) {
        this.employeeId = employeeId;
    }
    
    // Getters

    public String getPieceCode() {
        return pieceCode;
    }

    public String getPieceName() {
        return pieceName;
    }

    public double getPieceValue() {
        return pieceValue;
    }

    public int getPieceQuantity() {
        return pieceQuantity;
    }

    public String getCompanyName() {
        return companyName;
    }

    public String getCompanyInvoice() {
        return companyInvoice;
    }

    public String getEmployeeId() {
        return employeeId;
    }
    
     //Constructor with parameters.

    public Piece(String pieceCode, String pieceName, double pieceValue, int pieceQuantity, String companyName, String companyInvoice, String employeeId) {
        this.pieceCode = pieceCode;
        this.pieceName = pieceName;
        this.pieceValue = pieceValue;
        this.pieceQuantity = pieceQuantity;
        this.companyName = companyName;
        this.companyInvoice = companyInvoice;
        this.employeeId = employeeId;
    }
    
    //Default Constructor
    public Piece(){};

    
}
