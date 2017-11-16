/*
* File: main.cpp
* Developer: Erick Torres
* Email: erickt@rocketmail.com
* Description: This is the second submission of homework Project P6.13, it was edited to complete results.
*/
#include<iostream>
#include<string>
#include<vector>

class Transaction
{
public:
   	Transaction();
   	void read();
   	int get_day();
   	double get_amount();
   	void print() const;
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

int Transaction::get_day()
{
	return day;
}

double Transaction::get_amount()
{
	return amount;
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

class Balance
{
public:
	Balance();
	void add_trans(Transaction t); 
 	void get_balance();
 	void print();
 	double get_avg();
 	double get_min();
	double get_int();
private:
	std::vector<Transaction> trans;
	std::vector<double> balances;
	double balance;
	double I;
	double int_total;
};

Balance::Balance()
{
	balance = 0.0;
	double int_total = 0.0;
	I = 0.005;
}

void Balance::add_trans(Transaction t)
{
	trans.push_back(t);
}

void Balance::get_balance()
{
	double sum = 0.0;
	for(int i=0; i<=trans.size(); i++)
	{
	sum+= trans[i].get_amount();
	}
	balance = sum;
	get_int();
}

void Balance::print()
{
	std::cout<< "your interest is:" << int_total <<  "\n your balance is" << balance << std::endl;
} 

double Balance::get_avg()
{
	double b_sum = 0.0;
	for(int day = 0; day < balance.size(); day++)
	{
	 b_sum += balance[day];
	}
	
	return b_sum/
}

double Balance::get_min()
{
}

double Balance::get_int()
{
	int prv = trans[trans.size()-2].get_day() / 30;
	int current = trans[trans.size()-1].get_day() / 30;

	if(current > prv) 
	{
	balance = (balance * I) + balance;
	int_total += I * balance;
	}

	return int_total;

	
}

int main()
{
	Balance b;
 	bool more = true;
  	while(more)
   	{
       	 Transaction t;
       	 t.read();
      	 b.add_trans(t);
	 b.get_balance();
	// b.get_int();
	 std::cout << "Enter another (Y/N)";
         char response;
      	 std::cin >> response;
      	 if(response != 'y' && response != 'Y')
    	 more = false;	
   	}
	b.print();
 return 0;
}
