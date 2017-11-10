#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void move(double *array, int size, int move) {
    double *array_B = new double[size - move];
    double *array_C = new double[move];
    for (unsigned int i = 0; i < size; ++i) {
        if (i < size - move) {
            array_B[i] = array[i];
        } else {
            array_C[i + move - size] = array[i];
        }
    }
    for (unsigned int i = 0; i < (size - move) / 2; i++) {
        swap(array_B[i], array_B[size - move - 1 - i]);
    }
    for (unsigned int i = 0; i < move / 2; i++) {
        swap(array_C[i], array_C[move - 1 - i]);
    }
    for (unsigned int i = 0; i < size; i++) {
        if (i < size - move) {

            array[i] = array_B[i];
        } else {
            array[i] = array_C[i + move - size];
        }
    }
    for (unsigned int i = 0; i < size / 2; i++) {
        swap(array[i], array[size - 1 - i]);
    }
}

bool read(double *array, unsigned int size){
    char x;
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    for (unsigned int i = 0; i<size; ++i){
        if (!(stream >> array[i])){
            cout << "error" << endl;
            return false;

        }
    }
    if (stream>>x) {
        cout << "An error has occured while reading input data.";
        exit(0);
    }
    return true;
}

int main(){
    unsigned int size;
    cin >> size;
    cin.get();
    double *array = new double[size];
    if (read(array, size)){
        int move;
        move(array, size, move);
        for (unsigned int i = 0; i<size; ++i)
            cout << array[i] << " ";
    }
    else {
        cout << "An error has occured while reading input data.";
    }
    delete[]array;
    return 0;
    }
