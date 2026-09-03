#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product
{
private:
    int id;
    string name;
    string category;
    double price;
    int stock;

public:
    Product(int i, string n, string c, double p, int s)
    {
        id = i;
        name = n;
        category = c;
        price = p;
        stock = s;
    }

    void display()
    {
        cout << id << " | "
             << name << " | "
             << category << " | Rs."
             << price << " | Stock: "
             << stock << endl;
    }
};


int main()
{
    cout << "==================================" << endl;
    cout << "       MINI E-COMMERCE SYSTEM     " << endl;
    cout << "==================================" << endl;

    cout << "Welcome to Cherrys store!" << endl;

    vector<Product> products;

    products.push_back(Product(101, "Wireless Mouse", "Electronics", 799, 25));
    products.push_back(Product(102, "Keyboard", "Electronics", 1299, 15));
    products.push_back(Product(103, "Water Bottle", "Home", 499, 30));
    products.push_back(Product(104, "Notebook", "Stationery", 99, 50));

    cout << "\n---------- PRODUCT CATALOGUE ----------" << endl;

    for (Product p : products)
    {
        p.display();
    }
    return 0;
}