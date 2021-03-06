#pragma once
#include <iostream>
using namespace std;

template<typename T>
class GrowArray {
private:
	int used;
	int capacity;
	T* data;
	void checkGrow() {
		if (used < capacity)
			return; // don't grow unless you have to
		T* old = data;
		//TODO: every time the list grows, double it!!!
		data = new T[used*2]; // calls T::T()
		for (int i = 0; i < used; i++)
			data[i] = old[i];
		used++;
	}
public:
	GrowArray() : used(0), capacity(1), data(nullptr) {}
	GrowArray(int  initialCapacity)
		: used(0), capacity(initialCapacity), data(new T[used]){}
	//TODO: add destructor, copy constructor, operator =
	~GrowArray(){
        delete [] data;
    }
    GrowArray& operator =(const GrowArray& g){
        GrowArray copy(g);
        used=g.used;
        capacity=g.capacity;
		swap(data,g.data);
        return*this;
	}
	void addEnd(const T& v) {
		checkGrow();
		data[used-1] = v;
	}

	T removeEnd() {
		used--;
		return data[used];
	}
	T operator [](int i) const {
		return data[i];
	}

	T& operator [](int i) {
		return data[i];
	}

	friend ostream& operator <<(ostream& s, const GrowArray<T>& list) {
    for (int i = 0; i < list.used; i++)
			s << list[i] << ' ';
		return s;
	}
};
