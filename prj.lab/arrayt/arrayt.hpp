#pragma once

#ifndef ARRAYT_ARRAYT_HPP_20230329
#define ARRAYT_ARRAYT_HPP_20230329

#include <sstream>
#include <iostream>
#include <cstddef>

template<typename T>
class ArrayT{
public:
	ArrayT();
	ArrayT(std::ptrdiff_t ssize);

	ArrayT(const ArrayT<T>& other);
	~ArrayT();

	ArrayT& operator=(const ArrayT<T>& rhs);
	T& operator[](const std::ptrdiff_t i);
	const T& operator[](const std::ptrdiff_t i) const;
	std::ptrdiff_t Size() const noexcept;


	void Insert(const std::ptrdiff_t i, const T value);
	void Resize(const std::ptrdiff_t new_size);
	void Remove(const std::ptrdiff_t i);

private:
	T* data_=nullptr;//указатель на динамический массив
	std::ptrdiff_t size_=0;//текущий размер массива
	std::ptrdiff_t capacity_=0;
};

template<typename T>
ArrayT<T>::ArrayT() {
	size_ = 0;
	data_ = nullptr;
	capacity_ = 0;
}

template<typename T>
ArrayT<T>::ArrayT(std::ptrdiff_t Size) {
	if (Size <= 0) {
		throw std::invalid_argument("ArrayT<T>::ArrayT- non positive size_");
	}
	size_ = Size;
	capacity_ = Size;
	data_ = new T[Size];
	for (std::ptrdiff_t i = 0; i < Size; i++) {
		data_[i] = 0;
	}
}

template<typename T>
ArrayT<T>::ArrayT(const ArrayT<T>& other) {
	size_ = other.size_;
	capacity_ = other.capacity_;
	data_ = new T[other.capacity_];
	std::copy(other.data_, other.data_+other.capacity_, data_);
}

template<typename T>
ArrayT<T>::~ArrayT() {
	delete[] data_;
}

template<typename T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& rhs) {
	if (this != &rhs) {
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		data_ = new T[capacity_];
		std::copy(rhs.data_, rhs.data_ + rhs.capacity_, data_);
	}
	return *this;
}

template<typename T>
T& ArrayT<T>::operator[](const std::ptrdiff_t i) {
	if (i < size_ && i >= 0) {
		return data_[i];
	}
	else {
		throw std::out_of_range("IndexOutOfRange");
	}
}

template<typename T>
const T& ArrayT<T>::operator[](const std::ptrdiff_t i) const {
	if (i < size_ && i >= 0) {
		return data_[i];
	}
	else {
		throw std::out_of_range("IndexOutOfRange");
	}
}

template<typename T>
std::ptrdiff_t ArrayT<T>::Size() const noexcept {
	return size_;
}

template<typename T>
void ArrayT<T>::Insert(const std::ptrdiff_t i, const T value) {
	if (i < 0 || i >(size_ - 1)) { 
		throw std::out_of_range("Invalid index");
	}
	size_++;
	T* temp = new T[size_];
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

template<typename T>
void ArrayT<T>::Resize(const std::ptrdiff_t new_size) {
	if (new_size <= 0) {
		throw std::invalid_argument("Wrong position");
	}
	if (new_size > capacity_) {
		T* new_coords = new T[new_size * 2];
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

template<typename T>
void ArrayT<T>::Remove(const std::ptrdiff_t i) {
	if (i < 0 || i >(size_ - 1)) { 
        throw std::out_of_range("Invalid index"); 
    }
	for (std::ptrdiff_t j = i; j < size_ - 1; j++) {
		data_[j] = data_[j + 1];
	}
	Resize(Size() - 1);
}
#endif