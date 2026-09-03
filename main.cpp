#include <iostream>
#include <string>
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
             << category << " | ₹"
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

    Product p1(101, "Wireless Mouse", "Electronics", 799, 25);
    p1.display();
    return 0;
}