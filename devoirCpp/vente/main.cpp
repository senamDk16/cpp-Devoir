#include <iostream>
#include <string>
using namespace std;




class Product {
public:
    int id;
    string name;
    double price;
    int quantity;

    void addProduct(int id,string name, double price, int quantity){
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    double getPrice()  { return price; }
    int getQuantity()  { return quantity; }


    void setName(string name) { this->name = name; }
    void setPrice(double price) { this->price = price; }
    void setQuantity(int quantity) { this->quantity = quantity; }

    void display() {
        cout << "Product ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Price: " << price << "\n"
                  << "Quantity: " << quantity << endl;
    }

};


class Sale {
public:
    int saleId;
    int productId;
    int quantity;
    string date;

void addSale(int saleId, int productId, int quantity, string date){
    this->saleId = saleId;
    this->productId = productId;
    this->date = date;
}

int getSaleId()  { return saleId; }
int getProductId()  { return productId; }
int getQuantity()  { return quantity; }
string getDate()  { return date; }

void setSaleId(int saleId) { this->saleId = saleId; }
void setProductId(int productId) { this->productId = productId; }
void setQuantity(int quantity) { this->quantity = quantity; }
void setDate(string date) { this->date = date; }

void display() const {
    std::cout << "Sale ID: " << saleId << "\n"
              << "Product ID: " << productId << "\n"
              << "Quantity: " << quantity << "\n"
              << "Date: " << date << std::endl;
}

};




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
