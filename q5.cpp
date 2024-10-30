/*
Modify the STRING class so that assigning/initializing a string by another will not
copy it physically but will keep a reference count, which will be incremented.
Reference value 0 means the space can be released
*/


#include <iostream>
#include <cstring>


class String {
public:
    String (int size) {
        _size = size;

        _str = new char[_size + 1];
        _str[_size] = '\0';

        _atomicCtr = new int;
        *_atomicCtr = 1;
    }


    String(const char *s) {
        _size = strlen(s);

        _str = new char[_size + 1];
        _str[_size] = '\0';

        for (int i = 0; i < _size; i++) {
            _str[i] = s[i];
        }

        _atomicCtr = new int;
        *_atomicCtr = 1;
    }

    ~String() {
        _deallocate();
    }

    String(const String& other) {
        _size = other._size;
        _str = other._str;
        _atomicCtr = other._atomicCtr;
        (*_atomicCtr)++;
    }

    String operator=(const String& other) {
        if (this != &other) {
            _deallocate();

            _size = other._size;
            _str = other._str;
            _atomicCtr = other._atomicCtr;

            (*_atomicCtr)++;
        }

        return (*this);
    }

    String operator+(const String& other) {
        char *result = new char[_size + other._size + 1];
        result[_size + other._size] = '\0';

        for (int i = 0; i < _size; i++) {
            result[i] = _str[i];
        }

        for (int i = 0; i < other._size; i++) {
            result[i + _size] = other._str[i];
        }

        String ans(result);
        return ans;
    }

    bool operator==(const String& other) const {
        return strcmp(_str, other._str) == 0;
    }

    bool operator<(const String& other) const {
        return strcmp(_str, other._str) < 0;
    }

    bool operator>(const String& other) const {
        return strcmp(_str, other._str) > 0;
    }

    void print() const {
        std::cout << _str << "\n";
    }

private:
    int _size;
    char *_str;
    int *_atomicCtr;

    void _deallocate() {
        (*_atomicCtr)--;
        if (*_atomicCtr == 0) {
            delete[] _str;
            delete _atomicCtr;
        }
    }
};


int main() {
    

    return 0;
}