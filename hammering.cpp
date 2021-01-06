#include<bits/stdc++.h>
#define N 32
using namespace std;

typedef vector<int> vi;

void hammering(vi &data, int n) {
	// 1, 2, 4;
	
	vi bits(n, 0);

	for(int i=0; i<n; i++)  cin >> bits[i];

	data[3] = bits[0];
	data[5] = bits[1];
	data[6] = bits[2];
	data[7] = bits[3];

	data[1] = data[3] ^ data[5] ^ data[7];

	data[2] = data[3] ^ data[6] ^ data[7];

	data[4] = data[5] ^ data[6] ^ data[7];
	
	int k = n + 3 + 1;
	for(int i=1; i<k; i++) {
		cout << data[i] << " ";
	}

	
}
void correct_hammering(vi data, int n, bool t) {
	// 1, 2, 4;
	
	int k = n + 3 + 1;
	if(!t)
		for(int i=1; i<k; i++) cin >> data[i];

	int a, b, c;
	
	a = data[1] ^ data[3] ^ data[5] ^ data[7];

	b = data[2] ^ data[3] ^ data[6] ^ data[7];

	c = data[4] ^ data[5] ^ data[6] ^ data[7];

	if(a + b + c == 0) {
		cout << "RECIEVED DATA IS CORRECT \n";
		return;
	}

	int pos = a + b * 2 + c * 4; //decimal;

	data[pos] = !data[pos];
	
	cout << "CORRECT OUTPUT \n";
	for(int i=1; i<k; i++) {
		cout << data[i] << " ";
	}
	
}

int main() {
	vi data(N, -1);

	int n;
	n = 4; // DATA SIZE;

	
	//CREATE PARITY BITS;
	hammering(data, n);
	data[1] = !data[1];
	//CORREC THE RECIEVED DATA;
	correct_hammering(data, n, true);
}
