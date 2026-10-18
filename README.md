# Mini E-Commerce System

A console-based e-commerce application built using C++. The program simulates a simple shopping experience, allowing customers to browse products, manage their cart, complete checkout, choose a payment method, and view their order history.

## Features

- **Product Catalogue:** View available products, prices, categories, and stock quantities.
- **Product Search:** Search for products by name or category.
- **Shopping Cart:** Add products, update quantities by adding more items, and remove quantities from the cart.
- **Stock Management:** Track product availability and update stock when items are added to or removed from the cart.
- **Checkout:** Enter customer details and review the order summary.
- **Phone Number Validation:** Check that the phone number contains exactly 10 digits.
- **Payment Selection:** Choose UPI, card, or cash on delivery.
- **Order History:** View previously placed orders during the current session.

## Technologies Used

- C++
- Standard Template Library (STL)
- `vector` for managing products, cart items, and order history
- Object-oriented programming

## C++ Concepts Demonstrated

- Classes and objects
- Constructors and encapsulation
- Member functions and data access
- Vectors and dynamic collections
- Loops and conditional statements
- Searching and modifying collection elements
- Basic input validation

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/nayanasree1906/Mini-E-commerce.git
cd Mini-E-commerce
```

### 2. Compile the program

Using GCC:

```bash
g++ main.cpp -o ecommerce
```

### 3. Run the program

On Windows:

```powershell
.\ecommerce.exe
```

On Linux or macOS:

```bash
./ecommerce
```

## Current Limitations

- Products are predefined in the source code.
- Cart and order history are stored in memory and reset when the program exits.
- Payment methods are simulated; no real transactions are processed.
- The application uses a console interface rather than a graphical interface.

## Future Improvements

- Store products and orders persistently using a database or file storage.
- Add customer accounts and authentication.
- Improve input validation and error handling.
- Introduce product administration and inventory management.

## Author

**Nayanasree M. S.**

GitHub: [nayanasree1906](https://github.com/nayanasree1906)
