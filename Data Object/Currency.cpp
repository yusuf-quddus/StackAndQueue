#include <iostream>
#include <string>
#include "Currency.h"

// base class:
// constructors
Currency::Currency() : wholePart(0), fractionalPart(0), currencyNote(" "), currencyCoin(" ") {}
Currency::Currency(int w, int f) : wholePart(w), fractionalPart(f), currencyNote(" "), currencyCoin(" ")
{
	// adds excess fractional part to whole part
	if (f > 100) {
		wholePart += (fractionalPart / 100);
		fractionalPart = fractionalPart % 100;
	}
}

// member function
std::string Currency::getCurrencyNote()
{
	return currencyNote;
}

std::string Currency::getCurrencyCoin()
{
	return currencyCoin;
}

int Currency::getWholePart()
{
	return wholePart;
}

int Currency::getFractionalPart()
{
	return fractionalPart;
}

void Currency::setCurrencyNote(std::string n)
{
	currencyNote = n;
}

void Currency::setCurrencyCoin(std::string c)
{
	currencyCoin = c;
}

void Currency::setWholePart(int w)
{
	wholePart = w;
}

void Currency::setFractionalPart(int f)
{
	// adds excess fractional part to whole part
	if (f > 100) {
		wholePart += (fractionalPart / 100);
		fractionalPart = fractionalPart % 100;
	}
	fractionalPart = f;
}

// Derived Classes: 
// Dollar class
Dollar::Dollar()
{
	currencyNote = "Dollar";
	currencyCoin = "Cent";
}

Dollar::Dollar(int w, int f) : Currency(w, f)
{
	currencyNote = "Dollar";
	currencyCoin = "Cent";
}

// Euro Class
Euro::Euro()
{
	currencyNote = "Euro";
	currencyCoin = "Cent";
}

Euro::Euro(int w, int f) : Currency(w, f)
{
	currencyNote = "Euro";
	currencyCoin = "Cent";
}

// Yen Class
Yen::Yen()
{
	currencyNote = "Yen";
	currencyCoin = "Sen";
}

Yen::Yen(int w, int f) : Currency(w, f)
{
	currencyNote = "Yen";
	currencyCoin = "Sen";
}

// Rupee Class
Rupee::Rupee()
{
	currencyNote = "Rupee";
	currencyCoin = "Paise";
}

Rupee::Rupee(int w, int f) : Currency(w, f)
{
	currencyNote = "Rupee";
	currencyCoin = "Paise";
}

// Yuan Class
Yuan::Yuan()
{
	currencyNote = "Yuan";
	currencyCoin = "Fen";
}

Yuan::Yuan(int w, int f) : Currency(w, f)
{
	currencyNote = "Yuan";
	currencyCoin = "Fen";
}

// operator overloading
std::ostream & operator<<(std::ostream&out, const Currency &c)
{
	out << c.wholePart << " " << c.currencyNote << " " << c.fractionalPart
		<< " " << c.currencyCoin << std::endl;
	return out;
}

std::istream & operator>>(std::istream&in, Currency& c)
{
	std::cout << "Enter Note Amount ";
	in >> c.wholePart;
	std::cout << "Enter Coin Amount ";
	in >> c.fractionalPart;
	if (c.fractionalPart > 100) {
		c.wholePart += (c.fractionalPart / 100);
		c.fractionalPart = c.fractionalPart % 100;
	}
	return in;
}

Currency operator+(Currency& c1, Currency& c2)
{
	c1.wholePart = c1.wholePart + c2.wholePart;
	c1.fractionalPart = c1.fractionalPart + c2.fractionalPart;

	// adds excess fractional part to whole part
	if (c1.fractionalPart > 100) {
		c1.wholePart += (c1.fractionalPart / 100);
		c1.fractionalPart = c1.fractionalPart % 100;
	}

	return c1;
}

Currency operator+ (Currency& c1, double d)
{
	// seperate whole and fractional part
	int i;
	double i2;
	i = d / 1;
	i2 = d - i;
	c1.wholePart = c1.wholePart + i;
	c1.fractionalPart = c1.fractionalPart + (i2 * 100);

	// adds excess fractional part to whole part
	if (c1.fractionalPart > 100) {
		c1.wholePart += (c1.fractionalPart / 100);
		c1.fractionalPart = c1.fractionalPart % 100;
	}

	return c1;
}

Currency operator+(double d, Currency& c1)
{
	// seperate whole and fractional part
	int i;
	double i2;
	i = d / 1;
	i2 = d - i;
	c1.wholePart = c1.wholePart + i;
	c1.fractionalPart = c1.fractionalPart + (i2 * 100);

	// adds excess fractional part to whole part
	if (c1.fractionalPart > 100) {
		c1.wholePart += (c1.fractionalPart / 100);
		c1.fractionalPart = c1.fractionalPart % 100;
	}

	return c1;
}

Currency operator-(Currency& c1, Currency& c2)
{
	c1.wholePart = c1.wholePart - c2.wholePart;
	c1.fractionalPart = c1.fractionalPart - c2.fractionalPart;

	// adds excess fractional part to whole part
	if (c1.fractionalPart > 100) {
		c1.wholePart += (c1.fractionalPart / 100);
		c1.fractionalPart = c1.fractionalPart % 100;
	}

	// if fraction is negative, make positive
	if (c1.fractionalPart < 0 && c1.wholePart >= 1) {
		c1.wholePart -= 1;
		c1.fractionalPart += 100;
	}

	// if whole is negative, turn everything to 0.00
	if (c1.wholePart < 0) {
		c1.wholePart = 0;
		c1.fractionalPart = 0;
	}
	return c1;
}

Currency operator-(double d, Currency& c1)
{
	// seperate whole and fractional part
	int i;
	double i2;
	i = d / 1;
	i2 = d - i;
	c1.wholePart = i - c1.wholePart;
	c1.fractionalPart = (i2 * 100) - c1.fractionalPart;

	// adds excess fractional part to whole part
	if (c1.fractionalPart > 100) {
		c1.wholePart += (c1.fractionalPart / 100);
		c1.fractionalPart = c1.fractionalPart % 100;
	}

	// if fraction is negative, make positive
	if (c1.fractionalPart < 0 && c1.wholePart >= 1) {
		c1.wholePart -= 1;
		c1.fractionalPart += 100;
	}

	// if whole is negative, turn everything to 0.00
	if (c1.wholePart < 0) {
		c1.wholePart = 0;
		c1.fractionalPart = 0;
	}

	return c1;
}

Currency operator-(Currency& c1, double d)
{
	// seperate whole and fractional part
	int i;
	double i2;
	i = d / 1;
	i2 = d - i;
	c1.wholePart = c1.wholePart - i;
	c1.fractionalPart = c1.fractionalPart - (i2 * 100);

	// adds excess fractional part to whole part
	if (c1.fractionalPart > 100) {
		c1.wholePart += (c1.fractionalPart / 100);
		c1.fractionalPart = c1.fractionalPart % 100;
	}

	// if fraction is negative, make positive
	if (c1.fractionalPart < 0 && c1.wholePart >= 1) {
		c1.wholePart -= 1;
		c1.fractionalPart += 100;
	}

	// if whole is negative, turn everything to 0.00
	if (c1.wholePart < 0) {
		c1.wholePart = 0;
		c1.fractionalPart = 0;
	}

	return c1;
}

bool operator==(Currency& c1, Currency& c2)
{
	bool equal;
	equal = (c1.wholePart == c2.wholePart && c1.fractionalPart == c2.fractionalPart);
	return equal;
}

bool operator > (Currency& c1, Currency& c2)
{
	if (c1.wholePart > c2.wholePart)
		return true;

	else if (c1.wholePart == c2.wholePart && c1.fractionalPart > c2.fractionalPart)
		return true;

	else
		return false;
}

bool operator < (Currency& c1, Currency& c2)
{
	if (c1.wholePart < c2.wholePart)
		return true;

	else if (c1.wholePart == c2.wholePart && c1.fractionalPart < c2.fractionalPart)
		return true;

	else
		return false;
}

bool operator >= (Currency& c1, Currency& c2)
{
	if (c1.wholePart > c2.wholePart)
		return true;

	else if (c1.wholePart == c2.wholePart && c1.fractionalPart >= c2.fractionalPart)
		return true;

	else
		return false;
}

bool operator <= (Currency& c1, Currency& c2)
{
	if (c1.wholePart < c2.wholePart)
		return true;

	else if (c1.wholePart == c2.wholePart && c1.fractionalPart <= c2.fractionalPart)
		return true;

	else
		return false;
}

void Currency::operator = (const Currency* c1)
{
	wholePart = c1->wholePart;
	fractionalPart = c1->fractionalPart;
	currencyCoin = c1->currencyCoin;
	currencyNote = c1->currencyNote;
}