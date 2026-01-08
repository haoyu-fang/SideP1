#include "orderbook.h"
void OrderBook:: addOrder(const Order& order){
    if(order.getSide() == Order::OrderSide::BUY){
        BidsBooks[order.getPrice()].push(order);
    }else{
        AsksBooks[order.getPrice()].push(order);
    }
}
bool OrderBook::delOrder(const std::string& orderId, Order::OrderSide side){
   if(side == Order::OrderSide::BUY){
       for(auto it = BidsBooks.begin(); it != BidsBooks.end(); ++it){
           std::queue<Order> tempQueue;
           bool found = false;
           while(!it->second.empty()){
               Order currOrder = it->second.front();
               it->second.pop();
               if(currOrder.getOrderId() == orderId){
                   found = true;
                   continue;
               }
               tempQueue.push(currOrder);
           }
           if(found){ 
            if(tempQueue.empty()){
                BidsBooks.erase(it);
            }else{
                it->second = std::move(tempQueue);
            }
            return true;
           }
       }
   }else{
       for(auto it = AsksBooks.begin(); it != AsksBooks.end(); ++it){
           std::queue<Order> tempQueue;
           bool found = false;
           while(!it->second.empty()){
               Order currOrder = it->second.front();
               it->second.pop();
               if(currOrder.getOrderId() == orderId){
                   found = true;
                   continue;
               }
               tempQueue.push(currOrder);
           }
           it->second = std::move(tempQueue);
           if(found) {
            if(tempQueue.empty()){
                AsksBooks.erase(it);
            }else{
                it->second = std::move(tempQueue);
            }
            return true;
           }
       }
   }
   return false;
}
