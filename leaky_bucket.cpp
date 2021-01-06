#include<bits/stdc++.h>
using namespace std;


int main() {
	int storage, bucket_size, output, input;

	int queries;

	cin >> queries >> bucket_size >> input >> output;

	storage = 0;

	int size_left;
	while(queries--) {
		size_left = bucket_size - storage;

		if(input <= size_left) {
			storage += input;
		        cout << "STORAGE IS " <<  storage << endl;	
		}

		else {
			storage = bucket_size;	
		        cout << "STORAGE IS " <<  storage << endl;	
			cout << "DATA LOSS " << input - size_left;
		}

		if(storage >= output)
			storage -= output;
		else 
			storage = 0;
	}


}
