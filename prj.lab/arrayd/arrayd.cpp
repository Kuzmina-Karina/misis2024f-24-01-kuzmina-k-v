#include <arrayd/arrayd.hpp>
#include <iostream>
#include <sstream>

ArrayD::ArrayD() {
	size_ = 0;
	data_ = nullptr;
	capacity_ = 0;
}

ArrayD::ArrayD(std::ptrdiff_t Size) {
	if (Size <= 0) {
		throw std::invalid_argument("ArrayD::ArrayD - non positive size_");
	}
	size_ = Size;
	capacity_ = Size;
	data_ = new double[Size];
	for (std::ptrdiff_t i = 0; i < Size; i++) {
		data_[i] = 0;
	}
}

ArrayD::ArrayD(const ArrayD& other) {
	size_ = other.size_;
	capacity_ = other.capacity_;
	data_ = new double[other.capacity_];
	std::copy(other.data_, other.data_+other.capacity_, data_);
}


ArrayD::~ArrayD() {
	delete[] data_;
}


ArrayD& ArrayD::operator=(const ArrayD& rhs) {
	if (this != &rhs) {
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		data_ = new double[capacity_];
		std::copy(rhs.data_, rhs.data_ + rhs.capacity_, data_);
	}
	return *this;
}

double& ArrayD::operator[](const std::ptrdiff_t i) {
	if (i < size_ && i >= 0) {
		return data_[i];
	}
	else {
		throw std::out_of_range("IndexOutOfRange");
	}
}


const double& ArrayD::operator[](const std::ptrdiff_t i) const {
	if (i < size_ && i >= 0) {
		return data_[i];
	}
	else {
		throw std::out_of_range("IndexOutOfRange");
	}
}


std::ptrdiff_t ArrayD::Size() const noexcept {
	return size_;
}


void ArrayD::Insert(const std::ptrdiff_t i, const double value) {
	if (i < 0 || i >(size_ - 1)) { 
		throw std::out_of_range("Invalid index");
	}
	size_++;
	double* temp = new double[size_];
	for (std::ptrdiff_t j = 0; j < size_ - 1; j++) {
		temp[j] = data_[j];
	}
	for (std::ptrdiff_t j = size_ - 1; j > i; j--) {
		temp[j] = temp[j - 1];
	}
	temp[i] = value;
	delete[] data_;
	data_ = temp;
}


void ArrayD::Resize(const std::ptrdiff_t new_size) {
	if (new_size <= 0) {
		throw std::invalid_argument("Wrong position");
	}
	if (new_size > capacity_) {
		double* new_coords = new double[new_size * 2];
		std::copy(data_, data_ + size_, new_coords);
		delete[] data_;
		std::fill(new_coords + size_, new_coords + new_size, 0);
		data_ = new_coords;
		size_ = new_size;
		capacity_ = new_size * 2;
	}
	else {
		if (new_size > size_) {
			std::fill(data_ + size_, data_ + new_size, 0);
		}
		if (new_size < size_) {
			std::fill(data_ + new_size, data_ + size_, 0);
		}
		size_ = new_size;
	}
}


void ArrayD::Remove(const std::ptrdiff_t i) {
	if (i < 0 || i >(size_ - 1)) { 
        throw std::out_of_range("Invalid index"); 
    }
	for (std::ptrdiff_t j = i; j < size_ - 1; j++) {
		data_[j] = data_[j + 1];
	}
	Resize(Size() - 1);
}
