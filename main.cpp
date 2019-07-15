#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "NinjaRestaurant.h"
using namespace std;

int main() {
    
    string name;
    int goAgain;
    
    //App begins here
    cout <<"Welcome to Ninja Restaurant!\n";
    cout <<"Enter your name: ";
    getline(cin, name);
    
    NinjaRestaurant restaurant(name);
    restaurant.addFood();
    
    int choice, choice2, choice3;
    
    do{
    
    //1. Have user select the type of food
    do{
        //Food options
        cout <<"1. Breakfast\n";
        cout <<"2. Sandwiches\n";
        cout <<"3. Favorites\n";
        cout <<"4. Pizzas\n";
        cout <<"5. Sides\n";
        cout <<"6. Beverages\n";
        cout <<"Enter choice (1-6): ";
        cin >> choice;
        
        //Error message
        if(choice < 1 || choice > 6)
            cout <<"Invalid choice. Please re-enter\n";
        
    }while(choice < 1 || choice > 6);
    
    //Gets the food list's size depending on the user's choice
    double maxSize;
        
        //2. Have user select the food
        do{
            restaurant.displayMenu(choice);
            maxSize = restaurant.foodSize(choice);
            
            cout <<"Enter a choice (1-" << maxSize << "): ";
            cin >> choice2;
            
            //Error message
            if(choice2 < 1 || choice2 > maxSize)
                cout <<"Invalid choice. Please re-enter\n\n";
            
        }while(choice2 < 1 || choice2 > maxSize);
            
        //3. Have user select the quantity size of the food
        do{
                
            cout <<"Select quantity size of the item: ";
            cin >> choice3;
                
            if(choice3 == 0)
                cout <<"Error: Cannot enter a zero quantity\n";
            else if(choice3 < 0)
                cout <<"Error: Cannot enter a negative quantity\n";
                
        }while(choice3 <= 0);
            
        
        restaurant.addCustomerFood(choice, choice2, choice3);
        
        do{
        
            cout <<"1. Yes\n";
            cout <<"2. No\n";
            cout <<"Do you want to enter another item: ";
            cin >> goAgain;
            
            if(goAgain < 1 || goAgain > 2)
                cout <<"Error: Please enter 1 or 2\n";
            
        }while(goAgain < 1 || goAgain > 2);
            
    }while(goAgain == 1);
    
    restaurant.addTotal();
    restaurant.receipt();
    return 0;
}
