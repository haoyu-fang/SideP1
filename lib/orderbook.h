#include <iostream>
#include <map>
#include <queue>
#include "./order.h"
class OrderBook{
    private:
        std::map<int, std::queue<Order>, std::greater<int>> BidsBooks;
        std::map<int, std::queue<Order>> AsksBooks;
    public:
        void addOrder(const Order& order);
        bool delOrder(const std::string& orderId, Order::OrderSide side);

};