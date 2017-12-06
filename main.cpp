/*
* File: main.cpp
* Developer: Erick Torres
* Email: erickt@rocketmail.com
* Description: This is the second submission of homework Project P6.13, after it was re-opened to submit.
*/
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

class Transaction
{
public:
   	Transaction();
   	void read();
   	int get_day();
   	double get_amount();
	std::string get_des();
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

std::string Transaction::get_des()
{
	return description;
}

void Transaction::read()
{
	std:: cout << "Day || Amount || Description" << std::endl;   
    	std::cin >> day >> amount;
    	std::getline(std::cin,description);
}

void print_transactions(const std::vector<Transaction> t)
{
    	for(int i=0;i<t.size();i++)
        t[i].print();
}

class Balance
{
public:
	Balance(double);
	void add_trans(Transaction t); 
 	void print();
	void calc_avg(); 
	void calc_daily();
	void calc_int();
	void calc_min();
private:
	std::vector<Transaction> trans;
	std::vector<double> balances;
	double initial_bal;
	double balance;
	double I;
	double int_total;
	double avg;
	double min;
};

Balance::Balance(double b)
{
	initial_bal = b;
	balance = b; 
	int_total = 0.0;
	I = 0.005; //given interest
	avg = 0;
}
void Balance::add_trans(Transaction t)
{
	trans.push_back(t);
}

void Balance::print()
{	
	double rbalance = initial_bal;
	std::cout<< "Day || Amount || Description || Balance " << std::endl 
		 << "========================================" << std::endl
		 << "   1                                "<< initial_bal << std::endl;
	for(int i=0; i<trans.size();i++)
	 {
	  rbalance += trans[i].get_amount();
	  std::cout << std::setw(4) << trans[i].get_day() 
		    << std::setw(10) << trans[i].get_amount()
		    << std::setw(15) << trans[i].get_des()
		    << std::setw(11) << rbalance << std::endl;
	 }
	std::cout<< "========================================" << std::endl;

	std::cout<< "Your minimum daily balance is: " << std::setprecision(2)<< std::fixed << std::setw(8) << min << std::endl;
	
	std::cout<< "Your daily average balance is: " << std::setw(8) << avg << std::endl;
}

//this function finds the average by adding all balances stored and dividing by total inputed.
void Balance::calc_avg()
{
	double bb = 0;
	for(int i=0;i<balances.size();i++)
	{
	 bb += balances[i];
	}
	avg= bb/balances.size();

}

//this function calculates and stores balances
void Balance::calc_daily()
{
	for(int i=1;i<=30;i++)
	{
	 for(int j=0; j<trans.size();j++)
	 {
	  if(trans[j].get_day() == i)
	  {
	   balance += trans[j].get_amount();
	  }
	 }
	balances.push_back(balance);
	}
}


void Balance::calc_int()
{
	 int_total = balance * I;
	 balance += int_total;
 	 balances[29] = balance;
}

//this function finds the smallest balance in vector
void Balance::calc_min()
{
	min = balance;
	for(int i=0;i<balances.size();i++)
	{
	 if(balances[i]< min)
	 {
	  min = balances[i];
	 }
	}	

}

int main()
{
	Balance b(1000);
 	bool more = true;
  	while(more)
   	{
       	 Transaction t;
       	 t.read();
      	 b.add_trans(t);
	 std::cout << "Enter another (Y/N)";
         char response;
      	 std::cin >> response;
      	 if(response != 'y' && response != 'Y')
    	 more = false;	
   	}
	b.calc_daily();
	b.calc_avg();
	b.calc_min();
	b.print();
 return 0;
}
