#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void reverse(double * & array, unsigned int size) {
    for (unsigned int i = 0; i < size/2; i++) {
        swap(array[i], array[size - 1 - i]);
    }
}

bool read(double *array, unsigned int size){
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	for (unsigned int i = 0; i<size; ++i){
		if (!(stream >> array[i])){
			cout << "error" << endl;
                return false;
		}
	}
	return true;
}

int main(){
	unsigned int size;
	cin >> size;
	cin.get();
	double *array = new double[size];
	if (read(array, size)){
		reverse(array, size);
		for (unsigned int i = 0; i<size; ++i)
		cout << array[i] << " ";
	}
	else {
		cout << "An error has occured while reading input data.";
	}
	delete[]array;
	return 0;
}
