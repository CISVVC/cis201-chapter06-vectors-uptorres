/*
* File: main.cpp
* Developer: Erick Torres
* Email: erickt@rocketmail.com
* Description: This is the homework Project P6.13
*/
#include<iostream>
#include<string>
#include<vector>

const int Max = 30;

class Transaction
{
public:
   	Transaction();
   	void read();
   	int get_day();
   	double get_amount();
   	void print() const;
	void get_balance();
	double get_average();
	double get_min();
private:
   	int day;
   	double amount;
   	std::string description;
};

Transaction::Transaction()
{
	day = 0;
	amount = 0.0;
}

void Transaction::read()
{
	std:: cout << "Day || Amount || Description" << std::endl;   
    	std::cin >> day >> amount;
    	std::cin.ignore();
    	std::getline(std::cin,description);
}

void Transaction::print() const
{
   	std::cout << "day:" << day << std::endl;
    	std::cout << "amount:" << amount << std::endl;
    	std::cout << "description:" << description << std::endl;
}

void print_transactions(const std::vector<Transaction> t)
{
    	for(int i=0;i<t.size();i++)
        t[i].print();
}



int main()
{
  std::vector<Transaction> transaction;
  Transaction t;
  bool more = true;
   while(more)
   {
       	 Transaction t;
       	 t.read();
       	 transaction.push_back(t);
      	 std::cout << "Enter another (Y/N)";
         char response;
      	 std::cin >> response;
      	 if(response != 'y' && response != 'Y')
    	 more = false;	
   }
  print_transactions(transaction);

 
 return 0;
}

