/*
Design an ARRAY class with the following features:
a. Array object may be declared for a specific size and a value for initializing
all the elements. If this it is to be assumed as a 0.
b. An array object may be declared and initialized with another object.
c. An array object may be declared and initialized with another array (not the
object, standard array as in C language).
Let a and b are two objects:
i. a+b will add corresponding elements.
ii. a=b will do the assignment.
iii. a[I] will return the ith element of the object.
iv. a*5 or 5*a will multiply the element with 5.
*/


#include <iostream>
#include <stdexcept>


class Array {
public:
    Array(int size, int value = 0) {
        _arr = new int[size];
        _size = size;

        for (int i = 0; i < size; i++) {
            _arr[i] = value;
        }
    }

    Array(const Array& other) {
        _size = other.getSize();
        _arr = new int[_size];

        for (int i = 0; i < _size; i++) {
            _arr[i] = other._arr[i];
        }
    }

    Array(int *arr, int size) {
        _size = size;
        _arr = new int[size];

        for (int i = 0; i < _size; i++) {
            _arr[i] = arr[i];
        }
    }


    int getSize() const {
        return this->_size;
    }

    void print() {
        for (int i = 0; i < _size; i++) {
            std::cout << _arr[i] << " ";
        }
        std::cout << "\n";
    }

    Array operator+(const Array& other) {
        if (_size != other.getSize()) {
            std::runtime_error("Array Sizes in + are unequal!");
        }

        Array result(_size);

        for (int i = 0; i < _size; i++) {
            result[i] = _arr[i] + other._arr[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _arr;
            _size = other._size;
            _arr = new int[_size];
            for (int i = 0; i < _size; i++) {
                _arr[i] = other._arr[i];
            }
        }
        return *this;
    }

    int& operator[](int index) {
        if (index < 0 || index >= _size) {
            throw std::runtime_error("Out of range!");
        }

        return _arr[index];
    }

    Array operator*(int k) const {
        Array result(_size);
        for (int i = 0; i < _size; i++) {
            result._arr[i] = _arr[i] * k;
        }
        return result;
    }

private:
    int _size;
    int *_arr;
};


Array operator*(int scalar, const Array& array) {
    return array * scalar;
}


int main() {
    

    return 0;
}