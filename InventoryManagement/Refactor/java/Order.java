package managementsystem;

import java.time.LocalDate;

/**
 * Class Order
 * Purpose: Save the order information
 */

public class Order {
    
    public enum OrderStatus{
        EN_PROCESO,
        CANCELADO,
        ENTREGADO        
    }
    
    //Atributes: code, quantity, employee Id, request date, status.
    
    private String orderCode;
    private String pieceCode;
    private int orderQuantityRequest;
    private String employeeUser;
    private LocalDate requestDate;
    private OrderStatus orderStatus;

    //Setters
    
    public void setOrderCode(String orderCode) {
        this.orderCode = orderCode;
    }

    public void setPieceCode(String pieceCode) {
        this.pieceCode = pieceCode;
    }

    public void setOrderQuantityRequest(int orderQuantityRequest) {
        this.orderQuantityRequest = orderQuantityRequest;
    }

    public void setEmployeeUser(String employeeUser) {
        this.employeeUser = employeeUser;
    }

    public void setRequestDate(LocalDate requestDate) {
        this.requestDate = requestDate;
    }

    public void setOrderStatus(OrderStatus orderStatus) {
        this.orderStatus = orderStatus;
    }

    //Getters    

    public String getOrderCode() {
        return orderCode;
    }

    public String getPieceCode() {
        return pieceCode;
    }

    public int getOrderQuantityRequest() {
        return orderQuantityRequest;
    }

    public String getEmployeeUser() {
        return employeeUser;
    }

    public LocalDate getRequestDate() {
        return requestDate;
    }

    public OrderStatus getOrderStatus() {
        return orderStatus;
    }
    
    //Constructor with parameters.

        public Order(String orderCode, String pieceCode, int orderQuantityRequest, String employeeUser, LocalDate requestDate, OrderStatus orderStatus) {
        this.orderCode = orderCode;
        this.pieceCode = pieceCode;
        this.orderQuantityRequest = orderQuantityRequest;
        this.employeeUser = employeeUser;
        this.requestDate = requestDate;
        this.orderStatus = orderStatus;
    }

    //Default Constructor    
        
    // If there's an empty order, it will have a valid status by default.
    public Order() {
        this.orderStatus = OrderStatus.EN_PROCESO;
    }
    
}
