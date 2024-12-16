#pragma once
#ifndef ARRAYD_ARRAYD_HPP_20230330
#define ARRAYD_ARRAYD_HPP_20230330
#include <iosfwd>
#include <cstdint>
#include <cstddef>

class ArrayD {
public:
	ArrayD();
	ArrayD(std::ptrdiff_t ssize);
	ArrayD(const ArrayD& other);
	~ArrayD();

	ArrayD& operator=(const ArrayD& rhs);
	double& operator[](const std::ptrdiff_t i);
	const double& operator[](const std::ptrdiff_t i) const;
	std::ptrdiff_t Size() const noexcept;

	void Insert(const std::ptrdiff_t i, const double value);
	void Resize(const std::ptrdiff_t new_size);
	void Remove(const std::ptrdiff_t i);

private:
	double* data_=nullptr;//указатель на динамический массив
	std::ptrdiff_t size_=0;//текущий размер массива
	std::ptrdiff_t capacity_=0;
};


#endif
