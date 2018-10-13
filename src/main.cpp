#include <iostream>
using namespace std;

int main() {
	unsigned int n;
	uint64_t r;
	cin >> n >> r;
	uint64_t total_mass = 0;
	while (n){
		uint64_t w,h,d;
		cin >> w >> h >> d;
		total_mass += w * h * d * r;
		--n;
	}
	cout << total_mass << endl;
	return 0;
}
