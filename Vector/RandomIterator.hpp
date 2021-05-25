#ifndef RANDOMITERATOR_HPP
#define RANDOMITERATOR_HPP

#include <iostream>

template <typename T>

class RandomIterator
{
	public:
		// member types
		typedef T value_type;
		typedef std::ptrdiff_t various_type;
		typedef T *pointer;

		RandomIterator(void);
		~RandomIterator();
		RandomIterator(T *ptr);
		RandomIterator &operator=(const RandomIterator &ptr);

		RandomIterator &operator++();
		RandomIterator operator++(int nothing);
		RandomIterator &operator--();
		RandomIterator operator--(int nothing) const;

		RandomIterator &operator+=(various_type add);
		RandomIterator operator+(various_type add) const;
		RandomIterator &operator-=(various_type sou);
		RandomIterator operator-(various_type sou) const;

		bool operator==(const RandomIterator &ptr) const;
		bool operator!=(const RandomIterator &ptr) const;

		pointer ptr;

};

template <typename T>
RandomIterator<T>::RandomIterator() {
	this->ptr = NULL;
}

template <typename T>
RandomIterator<T>::RandomIterator(T *ptr) {
	this->ptr = ptr
}

template <typename T>
RandomIterator<T>::~RandomIterator() {
}

template <typename T>
RandomIterator<T> &RandomIterator<T>::operator=(const RandomIterator &ptr)
{
	if (this != &ptr)
	{
		this->ptr = ptr.ptr;
	}
	return (*this);
};

template <typename T>
RandomIterator<T> &RandomIterator<T>::operator++()
{
	this->ptr++;
	return (*this);
};

template <typename T>
RandomIterator<T> RandomIterator<T>::operator++(int nothing)
{
	(void)nothing;
	RandomIterator<T> copy;
	copy = *this;
	this->ptr++;
	return (copy);
};

template <typename T>
RandomIterator<T> &RandomIterator<T>::operator--()
{
	this->ptr--;
	return (*this);
};

template <typename T>
RandomIterator<T> RandomIterator<T>::operator--(int nothing) const
{
	(void)nothing;
	RandomIterator<T> copy;
	copy = *this;
	this->ptr--;
	return (copy);
};

template <typename T>
RandomIterator<T> &RandomIterator<T>::operator+=(various_type add)
{
	this->ptr += add;
	return (*this);
};

template <typename T>
RandomIterator<T> RandomIterator<T>::operator+(various_type add) const
{
	RandomIterator copy(*this);

	copy.ptr += add;

	return (copy);
};

template <typename T>
RandomIterator<T> &RandomIterator<T>::operator-=(various_type sou)
{
	this->ptr -= sou;
	return (*this);
};

template <typename T>
RandomIterator<T> RandomIterator<T>::operator-(various_type sou) const
{
	RandomIterator copy(*this);

	copy.ptr -= sou;

	return (copy);
};

template <typename T>
bool RandomIterator<T>::operator==(const RandomIterator &ptr) const
{
	return this->ptr == ptr;
};

template <typename T>
bool RandomIterator<T>::operator!=(const RandomIterator &ptr) const
{
	return this->ptr != ptr;
};

#endif