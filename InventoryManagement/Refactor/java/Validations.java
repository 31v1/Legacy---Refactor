package managementsystem;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;



/**
 * Class Validations
 * Purpose: Static class that validates data before creation
 */

public class Validations {
    
/** Validates the format of a piece code.
* A valid code must start with 'P' followed by exactly 8 digits.
* @param code the piece code to validate (can be null)
* @return true if the code is not null, has the correct format and length; false otherwise
*/
    public static boolean isValidPieceCode(String code) {
        if ( code == null){
            return false;
        }
        String trimmed = code.trim();
        return trimmed.matches("^P\\d{8}$");
    }    
    
/* Validates the format of a piece name.
* A valid name can have letters and simbols but not null.
* @param name the piece name to validate (can be null)
* @return true if the code is not null, has the correct format; false otherwise
*/ 
    public static boolean isValidPieceName(String name) {
        if ( name == null){
            return false;
        }
        String trimmed = name.trim();
        return trimmed.matches("[\\p{L}\\d #\\-/]+");
    }
    
 /* Validates that the piece cost is a non‑negative number.
 * (Upper limit beyond a safe maximum for the system.)
 *
 * @param value the piece cost to validate
 * @return true if value >= 0; false otherwise
 */
    public static boolean isValidPieceValue(double value) {
        if ( value < 0 || value > 99999999){
            return false;
        }
        
        return true;
    }
    
/* Validates that the piece quantity is a positive integer.
 * Quantity must be greater than zero to be considered valid.
 *
 * @param quantity the piece quantity to validate
 * @return true if quantity > 0; false otherwise
 */
    public static boolean isValidPieceQuantity(int quantity) {
        if ( quantity <= 0 ){
            return false;
        }
        
        return true;
    }
    
/* Validates the company name format.
*  A valid name can have letters and space but not null.
* @param companyName the company name to validate (can be null)
* @return true if the companyName is not null, has the correct format; false otherwise
 */
    public static boolean isValidCompanyName(String companyName) {
        if ( companyName == null){
            return false;
        }
        String trimmed = companyName.trim();
        return trimmed.matches("[\\p{L} ]+");
    }
    
 /* Validates the format of the company invoice.
 *  A valid name can have letters and space but not null.
* @param companyInvoice the company invoice to validate (can be null)
* @return true if the companyInvoice is not null, has the correct format; false otherwise
 */
    public static boolean isValidCompanyInvoice(String companyInvoice) {
        if ( companyInvoice == null){
            return false;
        }
        String trimmed = companyInvoice.trim();
        return trimmed.matches("[\\p{L}\\d \\-/]+");
    }
    
 /* Validates that the employee ID is a 9-digit number.
 * @param id the employee ID to validate (can be null)
 * @return true if id is not null, has 9 digits; false otherwise
 */
    public static boolean isValidEmployeeId(String id) {
        if ( id == null){
            return false;
        }
        String trimmed = id.trim();
        return trimmed.matches("^\\d{9}$");
    }
    
/* Validates the order format code.
* A valid code must start with 'PE' followed by exactly 8 digits.
* @param orderCode the piece code to validate (can be null)
* @return true if the code is not null, has the correct format and length; false otherwise
*/
    public static boolean isValidOrderCode(String code) {
        if ( code == null){
            return false;
        }
        String trimmed = code.trim();
        return trimmed.matches("^PE\\d{8}$");
    }
  
/* Validates that the employee number is an alphanumeric number.
 * @param id the employee number to validate (can be null)
 * @return true if id is not null; false otherwise
 */
    public static boolean isValidEmployeeUser(String id) {
        if ( id == null){
            return false;
        }
        String trimmed = id.trim();
        return trimmed.matches("[\\p{L} ]+");
    }
    
/**
* Converts a String into a LocalDate using the format dd/MM/yyyy.
* If the input is null or empty, returns false.
* @param date the date in format dd/MM/yyyy
* @throws IllegalArgumentException if the format is invalid
*/
    public static boolean isValidDate(String date){
        if (date == null || date.trim ().isEmpty()) {
            return false;
        }
        
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            
        try {
             LocalDate.parse(date.trim(), formatter);
             return true;
        } catch (DateTimeParseException e) {
            return false;
        }
    }
        
}
