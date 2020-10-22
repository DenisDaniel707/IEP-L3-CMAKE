#include <iostream>
#include <square/square.hpp>

using namespace std;

int main() {
	
	int n = 12;
	
	cout << "\n\n The square root of " << n << " is " << square::do_square(n) << "\n\n\n";

	return 0;
}