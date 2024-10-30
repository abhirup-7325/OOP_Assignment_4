/*
Design a STRING class, which will have the initialization facility similar to array
class. Provide support for
 Assigning one object for another,
 Two string can be concatenated using + operator,
 Two strings can be compared using the relational operators.
*/


#include <iostream>
#include <cstring>


class String {
public:
    String (int size) {
        _size = size;

        _str = new char[_size + 1];
        _str[_size] = '\0';
    }


    String(char *s) {
        _size = strlen(s);

        _str = new char[_size + 1];
        _str[_size] = '\0';

        for (int i = 0; i < _size; i++) {
            _str[i] = s[i];
        }
    }

    String(const String& other) {
        _size = other._size;

        _str = new char[_size + 1];
        for (int i = 0; i < _size; i++) {
            _str[i] = other._str[i];
        }

        _str[_size] = '\0';
    }

    String operator=(const String& other) {
        if (this != &other) {
            _size = other._size;
            delete[] _str;

            _str = new char[_size + 1];
            _str[_size] = '\0';

            for (int i = 0; i < _size; i++) {
                _str[i] = other._str[i];
            }
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

    void print() {
        std::cout << _str << '\n';
    }

private:
    int _size;
    char *_str;
};


int main() {
    char a[] = "hello";
    char b[] = "world";
    String s(a);
    String t(b);

    String p(10);
    p = s + t;

    p.print();

    return 0;
}