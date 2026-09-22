#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class RestaurantSystem {
protected:
    int total_items = 0;
    int number_demand[100] = {0};
    int price_print[100] = {0};
    string food_print[100];
    
    int price[16] = {0, 200, 2300, 3000, 500, 500, 400, 300, 150, 400, 1000, 800, 700, 400, 1500, 900};
    string food[16] = {
        "", "Boiled eggs", "Pizza", "Grilled chicken", "Potatoes", 
        "Cake", "Orange juice", "Milk tea", "Red tea", "Mango juice", 
        "Mix juice", "Rice", "Milkshake", "Falafel", "Burger", "Noodles"
    };

    string username = "maram";
    string password = "123456";

public:
    void displayMenu();
    void chooseOrders();
    void printInvoice();
    void modifyOrder();
};

void RestaurantSystem::displayMenu() {
    cout << "\n\t\t==========================================" << endl;
    cout << "\t\t| No. |       Item Name       |  Price   |" << endl;
    cout << "\t\t==========================================" << endl;
    for (int i = 1; i < 16; i++) {
        cout << "\t\t| " << setw(3) << left << i 
             << " | " << setw(21) << left << food[i] 
             << " | " << setw(8) << right << price[i] << " |" << endl;
    }
    cout << "\t\t==========================================" << endl << endl;
}

void RestaurantSystem::chooseOrders() {
    cout << "Enter the number of distinct items you want to order: ";
    cin >> total_items;

    for (int i = 1; i <= total_items; i++) {
        int item_num;
        cout << "\nEnter item number (" << i << "): ";
        cin >> item_num;

        while (item_num < 1  item_num > 15) {
            cout << "Invalid item number! Please select from 1 to 15: ";
            cin >> item_num;
        }

        cout << "Quantity for [" << food[item_num] << "]: ";
        cin >> number_demand[i];

        food_print[i] = food[item_num];
        price_print[i] = price[item_num];
    }
}

void RestaurantSystem::printInvoice() {
    system("cls");
    float total = 0;
    cout << "\n\t\t=======================================================" << endl;
    cout << "\t\t| No. |     Item Name     | Qty | Price (YER) | Total |" << endl;
    cout << "\t\t=======================================================" << endl;

    for (int j = 1; j <= total_items; j++) {
        float subtotal = price_print[j] * number_demand[j];
        total += subtotal;
        cout << "\t\t| " << setw(3) << left << j 
             << " | " << setw(17) << left << food_print[j] 
             << " | " << setw(3) << right << number_demand[j] 
             << " | " << setw(11) << right << price_print[j] 
             << " | " << setw(5) << right << subtotal << " |" << endl;
    }
    cout << "\t\t-------------------------------------------------------" << endl;
    cout << "\t\t Total Orders: " << total_items << " \t Total Price: " << total << " YER" << endl;
    cout << "\t\t=======================================================" << endl;
}

void RestaurantSystem::modifyOrder() {
    system("cls");
    cout << "\n\t\t--- Current Menu ---" << endl;
    displayMenu();
    cout << "\n\t\t--- Your Current Bill ---" << endl;
    printInvoice();

    int item_to_modify, new_item_num;
    cout << "\nEnter the order line number (No.) you want to modify: ";
    cin >> item_to_modify;

    if (item_to_modify >= 1 && item_to_modify <= total_items) {
        cout << "Select new food item number: ";
        cin >> new_item_num;

        while (new_item_num < 1  new_item_num > 15) {
            cout << "Invalid item number! Choose between 1 and 15: ";
            cin >> new_item_num;
        }

        cout << "Enter new quantity for [" << food[new_item_num] << "]: ";
        cin >> number_demand[item_to_modify];

        food_print[item_to_modify] = food[new_item_num];
        price_print[item_to_modify] = price[new_item_num];

        system("cls");
        cout << "\n\t\t--- Invoice Updated Successfully ---" << endl;
        printInvoice();
    } else {
        cout << "Invalid line number selected!" << endl;
    }
}
class ApplicationManager : public RestaurantSystem {
public:
    void startSystem();
};

void ApplicationManager::startSystem() {
    string u, p;
    system("cls");
    cout << "\n\t\t=================================" << endl;
    cout << "\t\t   Welcome to Order System" << endl;
    cout << "\t\t=================================" << endl;

    bool authenticated = false;
    while (!authenticated) {
        cout << "\nEnter username: ";
        cin >> u;
        cout << "Enter password: ";
        cin >> p;

        if (username == u && password == p) {
            authenticated = true;
        } else {
            cout << "\nWrong username or password!" << endl;
            cout << "1. Try again\n2. Reset username and password\nChoice: ";
            int choice;
            cin >> choice;
            if (choice == 2) {
                cout << "Enter NEW username: ";
                cin >> username;
                cout << "Enter NEW password: ";
                cin >> password;
            }
        }
    }

    int main_loop = 1;
    while (main_loop == 1) {
        system("cls");
        displayMenu();
        chooseOrders();

        system("cls");
        cout << "1. Print Invoice\n2. Adjust Request\nSelect option: ";
        int option;
        cin >> option;

        if (option == 1) {
            printInvoice();
        } else if (option == 2) {
            modifyOrder();
        }

        cout << "\nDo you want to enter another order?\n1. Yes (New Order)\n2. Exit System\nChoice: ";
        cin >> main_loop;
    }
    cout << "\nThank you for using our system!" << endl;
}

int main() {
    ApplicationManager app;
    app.startSystem();
    return 0;
}
