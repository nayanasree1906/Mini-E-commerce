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
            int getId()
        {
            return id;
        }

        string getName()
        {
            return name;
        }

        int getStock()
        {
            return stock;
        }

        double getPrice()
        {
            return price;
        }

        void reduceStock(int quantity)
        {
            stock = stock - quantity;
        }
        string getCategory()
        {
             return category; 
        }
};

class CartItem
{
private:
    Product product;
    int quantity;

public:
    CartItem(Product p, int q) : product(p), quantity(q)
    { 
    
    }

    void display()
    {
        cout << product.getName()
             << " | Qty: " << quantity
             << " | Price: Rs." << product.getPrice()
             << " | Total: Rs." << product.getPrice() * quantity
             << endl;
    }

    int getProductId()
{
    return product.getId();
}

int getQuantity()
{
    return quantity;
}
void reduceQuantity(int q)
{
    quantity = quantity - q;
}
double getTotal()
{
    return product.getPrice() * quantity;
}
void addQuantity(int q)
{
    quantity += q;
}
};

class Order
{
private:
    int orderId;
    string customerName;
    double total;
    string paymentMethod;

public:
    Order(int id, string name, double t, string payment)
    {
        orderId = id;
        customerName = name;
        total = t;
        paymentMethod = payment;
    }

    void display()
    {
        cout << "Order ID: " << orderId
             << " | Customer: " << customerName
             << " | Total: Rs." << total
             << " | Payment: " << paymentMethod
             << endl;
    }
};


int main()
{
    cout << "==================================" << endl;
    cout << "       MINI E-COMMERCE SYSTEM     " << endl;
    cout << "==================================" << endl;

    cout << "Welcome to Cherrys store!" << endl;

    vector<Product> products;
    vector<CartItem> cart;
    vector<Order> orderHistory;

    products.push_back(Product(101, "Wireless Mouse", "Electronics", 799, 25));
    products.push_back(Product(102, "Keyboard", "Electronics", 1299, 15));
    products.push_back(Product(103, "Water Bottle", "Home", 499, 30));
    products.push_back(Product(104, "Notebook", "Stationery", 99, 50));

    cout << "\n---------- PRODUCT CATALOGUE ----------" << endl;

    for (Product p : products)
    {
        p.display();
    }

    int choice;
    int orderId = 1001;
    string customerName;
    string phone;
    string address;

while (true)
{
    cout << "\n---------- MENU ----------" << endl;
    cout << "1. View Products" << endl;
    cout << "2. Add to Cart" << endl;
    cout << "3. Search Products" << endl;
    cout << "4. View Cart" << endl;
    cout << "5. Remove from Cart" << endl;
    cout << "6. Checkout" << endl;
    cout << "7. Order History" << endl;
    cout << "8. Exit" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "\n---------- PRODUCT CATALOGUE ----------" << endl;

            for (Product p : products)
            {
                p.display();
            }
            break;

        case 2:
{
char addMore = 'y';

    while (addMore == 'y' || addMore == 'Y')
    {
        int productId;
        int quantity;

        cout << "\n---------- PRODUCT CATALOGUE ----------" << endl;

        for (Product p : products)
        {
            p.display();
        }

        cout << "\nEnter product ID: ";
        cin >> productId;

        cout << "Enter quantity: ";
        cin >> quantity;

        bool found = false;

        for (Product &p : products)
        {
            if (p.getId() == productId)
            {
                found = true;

                if (quantity > 0 && quantity <= p.getStock())
                {
                    bool alreadyInCart = false;

                    // Check if product is already in cart
                    for (CartItem &item : cart)
                    {
                        if (item.getProductId() == productId)
                        {
                            item.addQuantity(quantity);
                            alreadyInCart = true;
                            break;
                        }
                    }

                    // If product is not already in cart
                    if (!alreadyInCart)
                    {
                        cart.push_back(CartItem(p, quantity));
                    }

                    p.reduceStock(quantity);

                    cout << p.getName()
                         << " added to cart!" << endl;
                }
                else
                {
                    cout << "Invalid quantity or insufficient stock!" << endl;
                }

                break;
            }
        }

        if (!found)
        {
            cout << "Product not found!" << endl;
        }

        cout << "\nDo you want to add anything else? (y/n): ";
        cin >> addMore;
    }

    break;
}
    

        case 3:
{
    string search;

    cout << "\n---------- SEARCH PRODUCTS ----------" << endl;
    cout << "Enter product name or category: ";
    cin.ignore();
    getline(cin, search);

    bool found = false;

    for (Product p : products)
    {
        if (p.getName().find(search) != string::npos ||
            p.getCategory().find(search) != string::npos)
        {
            p.display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching products found!" << endl;
    }

    break;
}

case 4:
{
    cout << "\n---------- YOUR CART ----------" << endl;

    if (cart.empty())
    {
        cout << "Your cart is empty!" << endl;
    }
    else
    {
        for (CartItem item : cart)
        {
            item.display();
        }
    }

    break;
}

case 5:
{
    int productId;
    int removeQuantity;

    cout << "\nEnter product ID to remove: ";
    cin >> productId;

    cout << "Enter quantity to remove: ";
    cin >> removeQuantity;

    bool found = false;

    for (int i = 0; i < cart.size(); i++)
    {
        if (cart[i].getProductId() == productId)
        {
            found = true;

            if (removeQuantity > 0 &&
                removeQuantity <= cart[i].getQuantity())
            {
                for (Product &p : products)
                {
                    if (p.getId() == productId)
                    {
                        p.reduceStock(-removeQuantity);
                        break;
                    }
                }

                cart[i].reduceQuantity(removeQuantity);

                if (cart[i].getQuantity() == 0)
                {
                    cart.erase(cart.begin() + i);
                }

                cout << "Quantity removed from cart!" << endl;
            }
            else
            {
                cout << "Invalid quantity!" << endl;
            }

            break;
        }
    }

    if (!found)
    {
        cout << "Product not found in cart!" << endl;
    }

    break;
}

            
        case 6:
{
    if (cart.empty())
    {
        cout << "\nYour cart is empty! Add products before checkout." << endl;
        break;
    }

    cout << "\n---------- CHECKOUT ----------" << endl;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Enter phone number: ";
cin >> phone;

bool validPhone = false;

while (!validPhone)
{
    validPhone = true;

    if (phone.length() != 10)
    {
        validPhone = false;
    }
    else
    {
        for (char digit : phone)
        {
            if (digit < '0' || digit > '9')
            {
                validPhone = false;
                break;
            }
        }
    }

    if (!validPhone)
    {
        cout << "Invalid phone number! Please enter exactly 10 digits: ";
        cin >> phone;
    }
}


    cin.ignore();
    cout << "Enter address: ";
    getline(cin, address);

    double total = 0;

    for (CartItem item : cart)
    {
        total += item.getTotal();
    }

    cout << "\n---------- ORDER SUMMARY ----------" << endl;

    for (CartItem item : cart)
    {
        item.display();
    }

    cout << "\nTotal Amount: Rs." << total << endl;

    int paymentChoice;

    cout << "\n---------- PAYMENT ----------" << endl;
    cout << "1. UPI" << endl;
    cout << "2. Card" << endl;
    cout << "3. Cash on Delivery" << endl;
    cout << "Enter payment method: ";
    cin >> paymentChoice;

    string paymentMethod;

    if (paymentChoice == 1)
    {
        paymentMethod = "UPI";
    }
    else if (paymentChoice == 2)
    {
        paymentMethod = "Card";
    }
    else if (paymentChoice == 3)
    {
        paymentMethod = "Cash on Delivery";
    }
    else
    {
        cout << "Invalid payment method!" << endl;
        break;
    }

    orderHistory.push_back(
        Order(orderId, customerName, total, paymentMethod)
    );

    cout << "\n==================================" << endl;
    cout << "       ORDER PLACED SUCCESSFULLY!" << endl;
    cout << "==================================" << endl;

    cout << "Order ID: " << orderId << endl;
    cout << "Customer: " << customerName << endl;
    cout << "Total: Rs." << total << endl;
    cout << "Payment: " << paymentMethod << endl;

    orderId++;

    cart.clear();

    cout << "\nThank you for shopping at Cherrys store!" << endl;

    break;
}

case 7:
{
    cout << "\n---------- ORDER HISTORY ----------" << endl;

    if (orderHistory.empty())
    {
        cout << "No previous orders found!" << endl;
    }
    else
    {
        for (Order order : orderHistory)
        {
            order.display();
        }
    }

    break;
}

case 8:
    cout << "\nThank you for visiting Cherrys store!" << endl;
    return 0;

        default:
            cout << "Invalid choice!" << endl;
    }
}

return 0;
}
