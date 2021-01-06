#include<bits/stdc++.h>
using namespace std;

void crc(string a, string b, string &q, string org) {
	if(a.length() > b.length()) {
		cout << "QUOTIENT: "  << q;
		cout << "\n";
		cout << "REMAINDER: " << b;
		cout << "\n";

		int i = 0;
		reverse(b.begin(), b.end());
		int j = org.length() - 1;
		while(i < b.length()) {
			org[j--] = b[i];
			i++;
		}
		cout << "ENCODED STRING: " << org;
		return;
	}
	if(b[0] == '1') {
		q += '1';
	}
	else {
		q += '0';
	}
	string bb = "";
	int i = 1;
	while(i < b.length()) {
		if(i <= a.length() - 1) {
			if(b[0] == '1')
				bb += to_string(stoi(to_string(a[i])) ^ stoi(to_string(b[i])));
			else {
				bb += b[i];
			}
		}
		else {
			bb += b[i];
		}
		i++;
	}

	crc(a, bb, q, org);		
}

int main() {
	string a, b;
	cin >> a >> b;	
	// a is divisor and b is dividend;
	
	int p = a.length() - 1;

	while(p--) {
		b += "0";
	}
	
	string q = "";
	crc(a, b, q, b);
}
