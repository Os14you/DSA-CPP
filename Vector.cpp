#include "Vector.hpp"

void Vector::expand_capacity() {
    capacity *= 2;
    int* new_arr = new int [capacity] { };

    for (int i=0; i < size; i++) 
        new_arr[i] = arr[i];

    std::swap(arr, new_arr);
    delete[] new_arr;

    std::cout << "Capacity expanded to: " << capacity << std::endl;
}

Vector::Vector(int s) : size(s) {
    if (s < 0) {
        std::cerr << "Size must be greater than 0." << std::endl;
        return;
    }
    capacity = s + 10;
    arr = new int[capacity] { };
}

int Vector::get(const int &idx) {
    assert(idx >= 0 && idx < size);
    return arr[idx];
}

void Vector::set(const int &idx, const int &value) {
    assert(idx >= 0 && idx < size);
    arr[idx] = value;
}

int Vector::getSize() const {
    return size;
}

void Vector::push_back(const int &value) {
    if (size >= capacity) {
        expand_capacity();
    }
    arr[size++] = value;
}

void Vector::insert(const int &idx, const int &value) {
    assert(idx >= 0 && idx <= size);
    if (size >= capacity) {
        expand_capacity();
    }

    for (int i=size; i>=idx; --i) 
        arr[i+1] = arr[i];
    
    arr[idx] = value;
    ++size;
}

void Vector::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << i << ": " << arr[i] << " | ";
    }
    std::cout << std::endl;
}

void Vector::shift_right(int times) {
    assert(times >= 0);
    times %= size;

    if (times == 0) return;
    int* new_arr = new int[size];

    for (int i=0; i < size; ++i) 
        new_arr[(times + i) % size] = arr[i];

    std::swap(arr, new_arr);
    delete[] new_arr;
}

Vector::~Vector() {
    delete[] arr;
    std::cout << "Vector destroyed." << std::endl;
}

int Vector::pop(int idx) {
	assert(idx >= 0 && idx < size);
	int popVal = arr[idx];

	for (int i=idx; i<size; ++i)
		arr[i] = arr[i+1];
	arr[size--];
	return popVal;
}

int Vector::find(const int &value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1; // Not found
}

int Vector::find_transposition(const int &value) {
	int idx = find(value);	
	if(idx == -1) return -1;
    if(idx == 0) return idx; // No transposition needed for the first

	arr[idx] = arr[idx] + arr[idx - 1];
    arr[idx - 1] = arr[idx] - arr[idx - 1];
    arr[idx] = arr[idx] - arr[idx - 1];
	return idx - 1;
}