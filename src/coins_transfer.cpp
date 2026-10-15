#include <iostream>
#include "coins.hpp"

using namespace std;

int main()
{
    Coins piggyBank(50, 50, 50, 50);
    Coins pocket(8, 3, 6, 8);

    cout << "Piggy bank: " << piggyBank << "Pocket: " << pocket << endl;
	
	Coins chipCost = pocket.extract_exact_change(coins_required_for_cents(149));
	cout << "Bought chips with " << chipCost << endl;

	Coins transfer = piggyBank.extract_exact_change(coins_required_for_cents(405));
	cout << "Transferred " << transfer;
	pocket.deposit_coins(transfer);

	Coins sofa(10,10,10,10);
	piggyBank.deposit_coins(sofa);
	cout << "Sofa now has " << sofa << "." << endl;
	cout << "Piggy bank now has " << piggyBank << "." << endl;
	print_cents(piggyBank.total_value_in_cents(), cout);
}	
