//
// pair.h
//
// Example from Jonathan Traugott
// define the Pair template class
//
#ifndef PAIR
#define PAIR
#include <iostream>
using namespace std;

template <typename T> class Pair
{
    // all methods and friend << functions must be defined inside the template
    friend ostream & operator<<(ostream & out, const Pair<T> & p) {
        out << "( " << p._first << ", " << p._second << " )";
        return out;
    }
private:
    T _first, _second;
public:
    Pair(T first = T(), T second = T()) {
        _first = first;
        _second = second;
    }
    T getFirst() const {
        return _first;
    }
    T getSecond() const {
        return _second;
    }
    void setFirst(T first) {
        _first = first;
    }
    void setSecond(T second) {
        _second = second;
    }
    bool operator==(const Pair<T> & other) const {
        return _first == other._first && _second == other._second;
    }
    bool operator!=(const Pair<T> & other) const {
        return !(*this == other);
    }
    void swap() {
        T temp = _first;
        _first = _second;
        _second = temp;
    }
};
#endif
