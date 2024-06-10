#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Food {
    string name;
    string ingredients;
    double price;
    double averageRating;
    int totalOrders;

    Food(string n, string ing, double p) : name(n), ingredients(ing), price(p), averageRating(0), totalOrders(0) {}
};

class Restaurant {
private:
    vector<Food> menu;

public:
    void addFood() {
        string name, ingredients;
        double price;

        setColor(13);
        cout << "Enter food name: ";
        cin >> name;
        cout << "Enter ingredients: ";
        cin >> ingredients;
        cout << "Enter price: ";
        cin >> price;

        menu.push_back(Food(name, ingredients, price));
    }

    void editFood() {
        string name, newIngredients;
        double newPrice;

        setColor(12);
        cout << "Enter the name of the food you want to edit: ";
        cin >> name;

        for (auto& food : menu) {
            if (food.name == name) {
                cout << "Enter new ingredients: ";
                cin >> newIngredients;
                cout << "Enter new price: ";
                cin >> newPrice;
                food.ingredients = newIngredients;
                food.price = newPrice;
                break;
            }
        }
    }

    void displayMenuByRating() {
        setColor(11);
        sort(menu.begin(), menu.end(), [](const Food& a, const Food& b) {
            return a.averageRating > b.averageRating;
        });

        cout << "Menu sorted by average rating:\n";
        for (const auto& food : menu) {
            cout << food.name << " - Average Rating: " << food.averageRating << endl;
        }
    }

    void placeOrder() {
        setColor(10);
        string foodName;
        int quantity;

        cout << "Enter food name: ";
        cin >> foodName;
        cout << "Enter quantity: ";
        cin >> quantity;

        for (auto& food : menu) {
            if (food.name == foodName) {
                food.totalOrders += quantity;
                cout << "Order placed: " << quantity << "x " << food.name << ", Amount Due: " << quantity * food.price << endl;
                break;
            }
        }
    }

    void displayDailyOrders() {
        setColor(9);
        cout << "Daily Orders:\n";
        for (const auto& food : menu) {
            cout << "Food: " << food.name << ", Orders: " << food.totalOrders << ", Total Amount: " << food.totalOrders * food.price << endl;
        }
    }

    void conductSurvey() {
        setColor(8);
        string foodName;
        int customers, rating;

        cout << "Enter food name: ";
        cin >> foodName;
        cout << "Enter number of customers for survey: ";
        cin >> customers;
        cout << "Enter rating (1-5): ";
        cin >> rating;

        for (auto& food : menu) {
            if (food.name == foodName) {
                food.averageRating = (food.averageRating * food.totalOrders + rating) / (food.totalOrders + customers);
                break;
            }
        }
    }


    void setColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
};

int main() {
    Restaurant restaurant;
    int choice;

    restaurant.setColor(14);
    cout << "\n===== Restaurant Management System =====\n";
    cout << "1. Add Food\n";
    cout << "2. Edit Food\n";
    cout << "3. Display Menu by Rating\n";
    cout << "4. Place Order\n";
    cout << "5. Display Daily Orders\n";
    cout << "6. Conduct Survey\n";
    cout << "7. Exit\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                restaurant.addFood();
                break;
            case 2:
                restaurant.editFood();
                break;
            case 3:
                restaurant.displayMenuByRating();
                break;
            case 4:
                restaurant.placeOrder();
                break;
            case 5:
                restaurant.displayDailyOrders();
                break;
            case 6:
                restaurant.conductSurvey();
                break;
            case 7:
                return 0;
            default:
                restaurant.setColor(12);
                cout << "Invalid choice. Please try again.\n";
                restaurant.setColor(14);
                break;
        }
    }

    return 0;
}
