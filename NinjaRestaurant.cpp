#include <iostream>
#include <fstream>
#include <iomanip>
#include "NinjaRestaurant.h"
using namespace std;

//Function that adds food items to assigning vectors
void NinjaRestaurant::addFood(){
    
    fstream file; //Accesses files
    string extract; //gets the string from the file
    Food temp; //temporary struct
    
    //Opens ninjaFood.txt file (Change the directory path depending on the location of the file)
    file.open("/Users/ninjagodivan/Documents/C++/NinjaRestaurant/NinjaRestaurant/ninjaFood.txt", ios::in);
    
    //Exits if the file does not exist
    if(!file){
        cout <<"File does not exist\n";
        exit(EXIT_FAILURE);
    }
    
    string foodType = "breakfast";
    
    //Traverses through the name and price of food
    int traverse = 0;

    //Goes through all foods in the ninjaFood.txt
    while(getline(file, extract)){
        
        //Skips the string containing the type of food
        if(extract == "Breakfast" || extract == "Sandwiches" || extract == "Pizzas" || extract == "Favorites" || extract == "Sides" || extract == "Beverages" || extract == ""){
            
            if(extract == "Sandwiches")
                foodType = "sandwiches";
            else if(extract == "Pizzas")
                foodType = "pizzas";
            else if(extract == "Favorites")
                foodType = "favorites";
            else if(extract == "Sides")
                foodType = "sides";
            else if(extract == "Beverages")
                foodType = "beverages";
            
            continue;
        }
        
        /*
         Every even number is the name of the food
         Every odd number is the price of the food
         */
        int val = traverse % 2;
        
        //False, if all food informations has not been inserted yet
        bool done = false;
        
        if(val == 0)
            //Adds the name of the food
            temp.name = extract;
        else{
            //Converts the variable from string to double
            double toDouble = stod(extract);
            //Adds the price of the food
            temp.price = toDouble;
            done = true;
        }
        
        //If done, append the food items in appropriate type
        if(done){
            if(foodType == "breakfast")
                breakfast.push_back(temp);
            else if(foodType == "sandwiches")
                sandwiches.push_back(temp);
            else if(foodType == "favorites")
                favorites.push_back(temp);
            else if(foodType == "pizzas")
                pizzas.push_back(temp);
            else if(foodType == "sides")
                sides.push_back(temp);
            else
                beverages.push_back(temp);
            
        }
        traverse++;
    }
}

//Function that displays food items
void NinjaRestaurant::displayMenu(int choice){
    
    switch(choice){
            
        case 1:{
            cout <<"BREAKFAST:\n";
            for(int i = 0; i < breakfast.size(); i++){
                cout << i + 1 << ". " << breakfast[i].name << endl;
                cout << setprecision(2) << fixed;
                cout << "$" << breakfast[i].price << endl << endl;
            }
            break;
        }
        case 2:{
            cout <<"SANDWICHES:\n";
            for(int i = 0; i < sandwiches.size(); i++){
                cout << i + 1 << ". " << sandwiches[i].name << endl;
                cout << setprecision(2) << fixed;
                cout << "$" << sandwiches[i].price << endl << endl;
            }
            break;
        }
        case 3:{
            cout <<"FAVORITES:\n";
            for(int i = 0; i < favorites.size(); i++){
                cout << i + 1 << ". " << favorites[i].name << endl;
                cout << setprecision(2) << fixed;
                cout << "$" << favorites[i].price << endl << endl;
            }
            break;
        }
        case 4:{
            cout <<"PIZZAS:\n";
            for(int i = 0; i < pizzas.size(); i++){
                cout << i + 1 << ". " << pizzas[i].name << endl;
                cout << setprecision(2) << fixed;
                cout << "$" << pizzas[i].price << endl << endl;
            }
            break;
        }
        case 5:{
            cout <<"SIDES:\n";
            for(int i = 0; i < sides.size(); i++){
                cout << i + 1 << ". " << sides[i].name << endl;
                cout << setprecision(2) << fixed;
                cout << "$" << sides[i].price << endl << endl;
            }
            break;
        }
        case 6:{
            cout <<"BEVERAGES:\n";
            for(int i = 0; i < beverages.size(); i++){
                cout << i + 1 << ". " << beverages[i].name << endl;
                cout << setprecision(2) << fixed;
                cout << "$" << beverages[i].price << endl << endl;
            }
            break;
        }
        default:{
            cout <<"Uhh...something's not right ._.\n";
            break;
        }
    }
}

//Function that returns the size of food type
double NinjaRestaurant::foodSize(int choice){

    cout << setprecision(0) << fixed;
    if(choice == 1)
        return breakfast.size();
    else if(choice == 2)
        return sandwiches.size();
    else if(choice == 3)
        return favorites.size();
    else if(choice == 4)
        return pizzas.size();
    else if(choice == 5)
        return sides.size();
    else
        return beverages.size();
}

//Function that adds foods to the Customer's order
void NinjaRestaurant::addCustomerFood(int food_type, int food_choice, int quantity){
    
    CustomerFood temp;
    
    if(food_type == 1){
        
        for(int i = 1; i <= breakfast.size(); i++){
            
            if(i == food_choice){
                
                temp.name = breakfast[i - 1].name;
                temp.price = breakfast[i - 1].price;
                temp.quantity = quantity;
                customer.food.push_back(temp);
                break;
            }
        }
    }
    else if(food_type == 2){
        
        for(int i = 1; i <= sandwiches.size(); i++){
            
            if(i == food_choice){
                
                temp.name = sandwiches[i - 1].name;
                temp.price = sandwiches[i - 1].price;
                temp.quantity = quantity;
                customer.food.push_back(temp);
                break;
            }
        }
    }
    else if(food_type == 3){
        
        for(int i = 1; i <= favorites.size(); i++){
            
            if(i == food_choice){
                
                temp.name = favorites[i - 1].name;
                temp.price = favorites[i - 1].price;
                temp.quantity = quantity;
                customer.food.push_back(temp);
                break;
            }
        }
    }
    else if(food_type == 4){
        
        for(int i = 1; i <= pizzas.size(); i++){
            
            if(i == food_choice){
                
                temp.name = pizzas[i - 1].name;
                temp.price = pizzas[i - 1].price;
                temp.quantity = quantity;
                customer.food.push_back(temp);
                break;
            }
        }
    }
    else if(food_type == 5){
        
        for(int i = 1; i <= sides.size(); i++){
            
            if(i == food_choice){
                
                temp.name = sides[i - 1].name;
                temp.price = sides[i - 1].price;
                temp.quantity = quantity;
                customer.food.push_back(temp);
                break;
            }
        }
    }
    else{
        
        for(int i = 1; i < beverages.size(); i++){
            
            if(i == food_choice){
                
                temp.name = beverages[i - 1].name;
                temp.price = beverages[i - 1].price;
                temp.quantity = quantity;
                customer.food.push_back(temp);
                break;
            }
        }
    }
}

//Function that adds up all the foods that the customer bought
void NinjaRestaurant::addTotal(){
    
    double sub_total;
    
    for(int i = 0; i < customer.food.size(); i++){
        
        sub_total = customer.food[i].price * customer.food[i].quantity;
        customer.total_price += sub_total;
    }
    
    //Total price + tax
    customer.tax_price = customer.total_price * tax;
    customer.final_price += customer.total_price + customer.tax_price;
}

//Function that prints the receipt
void NinjaRestaurant::receipt(){
    
    cout <<"----------RECEIPT----------\n";
    cout << "Customer's name: " << customer.name << endl << endl;
    
    //Outputs all customer's foods, prices, and quantities
    cout << setprecision(2);
    for(int i = 0; i < customer.food.size(); i++){
        cout << customer.food[i].name << endl;
        cout << "$" << customer.food[i].price << fixed << setw(2) << "*" << setw(2) << customer.food[i].quantity << endl;
    }
    
    
    cout <<"\nTotal Price: $" << customer.total_price << fixed << endl;
    cout <<"Tax (10%): $" << customer.tax_price << fixed << endl;
    cout <<"Final Price: $" << customer.final_price << endl << endl;
    cout <<"Thank You for Shopping!\n";
    cout <<"---------------------------\n";
}
