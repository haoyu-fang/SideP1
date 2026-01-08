#pragma once
#include <iostream>
#include <chrono>

class Order{
    public :
        enum class OrderSide {BUY,SELL};
        enum class OrderStatus {Pending,Completed,PartiallyFilled,Cancelled};
    private:
        std::string orderId;
        int price;
        int quantity;
        int remainquan;
        OrderSide side;
        OrderStatus status;
        std::chrono::steady_clock::time_point timestamp;
    public:
        Order(int p, int q, std::string id,OrderSide Oside,OrderStatus os)
            : price(p), quantity(q), remainquan(q), orderId(id), side(Oside), status(os) {}
    //==============Geter==============
    int getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    std::string getOrderId() const { return orderId; }
    OrderSide getSide() const { return side; }
    OrderStatus getStatus() const { return status; }
    //==============fill===============
    void fillOrder(int qty) {
        remainquan -= qty;
        if(remainquan == 0){
            status = OrderStatus::Completed;
        }
        status = OrderStatus::PartiallyFilled;
    }
    void cancelOrder() {
        status = OrderStatus::Cancelled;
    }

};