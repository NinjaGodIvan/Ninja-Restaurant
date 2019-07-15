#ifndef NinjaRestaurant_h
#define NinjaRestaurant_h

#include <iostream>
#include <vector>
using namespace std;

class NinjaRestaurant{
public:
    NinjaRestaurant(string n)
    {customer.name = n;}
    void addFood();
    void addTotal();
    void addCustomerFood(int, int, int);
    void displayMenu(int);
    double foodSize(int);
    void receipt();
private:
    //All Ninja Restaurant foods and prices
    struct Food{
        string name;   //Name of the food
        double price;  //Price of the food
    };
    //Customer's food and its price
    struct CustomerFood{
        
        string name;
        double price;
        int quantity; //amount of same food
    };
    //Customer's name and their foods
    struct Customer{
        
        string name; //Customer's name
        vector <CustomerFood> food; //Customer's foods
        double total_price; //total price of customer's foods
        double final_price; //total price of customer's foods plus tax
        double tax_price; //total tax price from all customer's foods
    };
    //Declaration of Customer struct
    Customer customer;
    
    //Tax
    double tax = 0.10;
    
    //Vectors are the types of foods
    vector <Food> breakfast;    //List of breakfast foods
    vector <Food> sandwiches;   //List of sandwiches
    vector <Food> favorites;    //List of Ivan's favorite foods
    vector <Food> pizzas;       //List of pizzas
    vector <Food> sides;        //List of sides
    vector <Food> beverages;    //List of beverages
};

#endif /* NinjaRestaurant_h */
