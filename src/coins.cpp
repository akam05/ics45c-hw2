#include "coins.hpp" 
#include <iostream>

using namespace std;

Coins::Coins(int q, int d, int n, int p) : quarters(q), dimes(d), nickels(n), pennies(p)
{
}

void Coins::deposit_coins(Coins& coins)
{
	quarters -= coins.quarters;
	dimes -= coins.dimes;
	nickels -=coins.nickels;
	pennies -= coins.pennies;
}

bool Coins::has_exact_change_for_coins(const Coins& coins) const 
{
	int need4 = 0;
	if (quarters >= coins.quarters) {
		need4 += 1;
	}
	if (dimes >= coins.dimes) {
		need4 += 1;
	}
	if (nickels >= coins.nickels) {
		need4 += 1;
	}
	if (pennies >= coins.pennies) {
		need4 += 1;
	}

	if (need4 == 4) {
		return true;
	}
	return false;
}

Coins Coins::extract_exact_change(const Coins& coins) const
{
	if (!has_exact_change_for_coins(coins)) 
	{
		return Coins(0,0,0,0);
	}

	quarters -= coins.quarters;
    dimes -= coins.dimes;
    nickels -= coins.nickels;
    pennies -= coins.pennies;

	return coins;
}

int Coins::total_value_in_cents()
{
	int total = 0;
	total += quarters * CENTS_PER_QUARTER;
	total += dimes * CENTS_PER_DIME;
	total += nickels * CENTS_PER_NICKEL;
	total += pennies;

	return total;
}

void Coins::print(ostream& out) const
{
	out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, "
	<< pennies << " pennies";
}

// ICS 45c Classes, slide 11
ostream& operator<<(ostream& out, const Coins& coins)
{
	coins.print(out);
	return out;
}

Coins coins_required_for_cents(int amount_in_cents)
{
	int q = 0;
	int d = 0;
	int n = 0;
	int p = 0;

	q = amount_in_cents / CENTS_PER_QUARTER;
	amount_in_cents %= CENTS_PER_QUARTER;
	
	d = amount_in_cents / CENTS_PER_DIME;
	amount_in_cents %= CENTS_PER_DIME;

	n = amount_in_cents / CENTS_PER_NICKEL;
	amount_in_cents %= CENTS_PER_NICKEL;

	p = amount_in_cents;

	return Coins(q, d, n, p);
}


