#include <iostream>
#include <curl/curl.h>
#include <string>

using namespace std;

string httpGET(const string &url){
	
}
class Product{
	private:
		string product_name;
		
	public:
		Product(){
			cout<<"Enter product name: ";
			cin>> product_name;
		}
		
		Product(const string &name) : product_name(name){}
		
		friend float amazon_price(const Product &name);
		friend float flipcart_price(const Product &name);
};

float amazon_price(const Product &name){
	string amazon_URL = "https://www.amazon.com/search?q=" + name.product_name;
	string amazon_Response = httpGET(amazon_URL);
	
	float price;
	cout<<"Enter amazon price You Wish: ";
	cin>> price;
	
	cout << "Amazon Price: Rs. " << price << endl;
	return price;
}

float flipcart_price(const Product &name){
	string flipcart_URL = "https://www.flipcart.com/search?q=" + name.product_name;
	string flipcart_Response = httpGET(flipcart_URL);
	
	float price;
	cout<<"Enter flipcart price You Wish: ";
	cin>> price;
	
	cout << "Flipcart Price: Rs. " << price << endl;
	return price;
}

int main() {
    int choice;
    Product name;
    cout << "Menu:"<< endl;
    cout << "1. Get Amazon Price: "<< endl;
    cout << "2. Get Flipcart Price: "<< endl;
    cout << "3. Exit "<< endl;
    
    cout << "Enter choice: ";
    cin >> choice;
    
    switch(choice){
    	case 1:
    		amazon_price(name);
    		
    	case 2:
    		flipcart_price(name);
    		
    	case 3:
    		cout << "Process Terminated..." << endl;
    		break;
    		
    		
    	default:
    		cout << "Invalid Choice!!" << endl << "Please Try Again..." << endl;
	}
	
	return 0;
}
