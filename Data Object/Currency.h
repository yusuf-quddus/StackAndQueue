#pragma once

#include <iostream>
#include <string>

// base class
class Currency {
protected:

	int wholePart;
	int fractionalPart;
	std::string currencyNote;
	std::string currencyCoin;

public:
	// constructor
	Currency();
	Currency(int, int);

	// getters
	virtual int getWholePart();
	int getFractionalPart();
	std::string getCurrencyNote();
	std::string getCurrencyCoin();

	// setters
	void setWholePart(int);
	void setFractionalPart(int);
	void setCurrencyNote(std::string);
	void setCurrencyCoin(std::string);

	// operator overloads
	void operator= (const Currency* c1);
	friend bool operator> (Currency&, Currency&);
	friend bool operator< (Currency&, Currency&);
	friend bool operator== (Currency&, Currency&);
	friend bool operator>= (Currency&, Currency&);
	friend bool operator<= (Currency&, Currency&);
	friend Currency operator+ (Currency&, Currency&);
	friend Currency operator- (Currency&, Currency&);
	friend Currency operator-(Currency& c1, double d);
	friend Currency operator-(double d, Currency& c1);
	friend Currency operator+ (Currency& c1, double d);
	friend Currency operator+ (double d, Currency& c1);
	friend std::istream& operator>> (std::istream& in, Currency& c);
	friend std::ostream& operator<< (std::ostream& out, const Currency& c);
};

// Derived Classes:
class Dollar : public Currency {
public:
	Dollar();
	Dollar(int, int);
};

class Euro : public Currency {
public:
	Euro();
	Euro(int, int);
};

class Yen : public Currency {
public:
	Yen();
	Yen(int, int);
};

class Rupee : public Currency {
public:
	Rupee();
	Rupee(int, int);
};

class Yuan : public Currency {
public:
	Yuan();
	Yuan(int, int);
};