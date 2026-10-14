#include "coins.hpp" 
#include <iostream>

using namespace std;

Coins::Coins(int q, int d, int n, int p) : quarters(q), dimes(d), nickels(n), pennies(p)
{
	cout << "Coins constructor is born" << endl;
}

void Coins::print(ostream& out) const
{
	out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, "
	<< pennies << " pennies";
}

ostream& operator<<(ostream& out, const Coins& coins)
{
	coins.print(out);
	return out;
}
