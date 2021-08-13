#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> sellers;
map<string, double> seller_amount_sold;

void register_sellers() {
  sellers.push_back("Marcos A.");
  sellers.push_back("Bianca G.");
  sellers.push_back("Thomaz K.");
  sellers.push_back("Denis W.");
  sellers.push_back("Daniel F.");
};

bool is_seller_registered(string &seller_name) {
  for (auto seller: sellers) 
    if (seller == seller_name)
      return true;

  return false;
}

struct Sale {
  string seller_name;
  string customer_name;
  string date;
  string item_name;
  double value;

  Sale(string _seller_name, string _customer_name, string _date, string _item_name, double _value) {
    seller_name = _seller_name;
    customer_name = _customer_name;
    date = _date;
    item_name = _item_name;
    value = _value;
  }

  bool operator<(const Sale&other) const {
    return seller_amount_sold[seller_name] > seller_amount_sold[other.seller_name];
  }
};
vector<Sale> sales;

void add_sale(Sale &sale) {
  seller_amount_sold[sale.seller_name] += sale.value;
  sales.push_back(sale);
  sort(sales.begin(), sales.end());
}

int main() {
  register_sellers();


  cout << "Welcome to Sales Painel\n";

  while (true) {
    cout << "Seller name: ";
    string seller_name;
    getline(cin, seller_name);

    if (!is_seller_registered(seller_name)) {
      cout << seller_name << " is not registred as a seller\n";
      continue;
    }
    
    cout << "Customer name: ";
    string customer_name;
    getline(cin, customer_name);

    cout << "Date of sale (day/month/year): ";
    string date;
    cin >> date;
    cin.ignore();

    cout << "Item name: ";
    string item_name;
    getline(cin, item_name);

    cout << "Sale value: ";
    double value;
    cin >> value;
    cin.ignore();

    cout << "\nAdding sale...\n";
    Sale sale = Sale(seller_name, customer_name, date, item_name, value);
    add_sale(sale);

    cout << "\nListing sales...\n\n";

    for (auto sale: sales) cout << sale.seller_name << " " << sale.customer_name << " " << sale.date << " " << sale.item_name << " " << sale.value << "\n";
    cout << "\n\n";
  }

  return 0;
}