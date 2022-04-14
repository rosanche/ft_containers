#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "reverse_iterator.hpp"
#include "tools.hpp"
#include <memory>
#include <vector>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		// member types
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

		typedef pointer iterator;
		typedef const_pointer const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		value_type *arrays;
		allocator_type allocator;
		size_type v_size;
		size_type v_capacity;

	public:
		//  CONSTRUCTOR

		explicit vector(const allocator_type &alloc = allocator_type()) : arrays(NULL),
																		  allocator(alloc),
																		  v_size(0),
																		  v_capacity(0)
		{
		}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : arrays(NULL),
																															 allocator(alloc),
																															 v_size(n),
																															 v_capacity(n)
		{
			arrays = allocator.allocate(v_size);
			assign(n, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : arrays(NULL),
																										  allocator(alloc),
																										  v_size(0),
																										  v_capacity(0)
		{
			for (InputIterator it = first; it != last; ++it)
				v_size++;
			v_capacity = v_size;
			arrays = allocator.allocate(v_size);
			assign(first, last);
		}

		vector(const vector &ptr) : arrays(NULL),
									allocator(ptr.allocator),
									v_size(ptr.size()),
									v_capacity(ptr.size())
		{
			arrays = allocator.allocate(v_size);
			assign(ptr.begin(), ptr.end());
		}

		~vector()
		{
			if (arrays)
			{
				for (iterator i = begin(); i != end(); i++)
					allocator.destroy(&(*i));

				allocator.deallocate(arrays, v_size);
			}
		}

		vector &operator=(const vector &ptr)
		{
			if (this != &ptr)
			{
				allocator = ptr.allocator;
				arrays = NULL;
				v_size = 0;
				v_capacity = 0;

				if (ptr.v_capacity != 0)
					reserve(v_capacity);

				if (ptr.size() != 0)
					assign(ptr.begin(), ptr.end());
			}
			return (*this);
		}

		// ITERATORS

		iterator begin()
		{
			return (iterator(arrays));
		}
		const_iterator begin() const
		{
			return (const_iterator(arrays));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}

		iterator end()
		{
			return (iterator(&arrays[v_size]));
		}
		const_iterator end() const
		{
			return (const_iterator(&arrays[v_size]));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}

		// CAPACITY
		size_type size() const
		{
			return (v_size);
		}

		void resize(size_type n, value_type val = value_type())
		{
			while (n > v_size)
			{
				push_back(val);
			}
			if (n < v_size)
			{
				while (v_size != n)
					pop_back();
			}
		}

		void reserve(size_type n)
		{

			if (n > max_size())
				throw(std::length_error("n greater than maximum size"));
			if (n > v_capacity)
			{
				value_type *new_array;
				size_type old_capacity = v_capacity;
				v_capacity = n;
				new_array = allocator.allocate(v_capacity);
				for (size_t i = 0; i < v_size; ++i)
					allocator.construct(&new_array[i], arrays[i]);
				for (iterator it = begin(); it != end(); ++it)
					allocator.destroy(it);
				allocator.deallocate(arrays, old_capacity);
				arrays = new_array;
				// v_capacity = n;
			}
		}

		size_type max_size() const
		{
			size_type max_size = 0;
			try
			{
				max_size = allocator.max_size();
			}
			catch (std::exception &e)
			{
				std::cout
					<< "Error appeared with vector.max_size() :" << e.what() << std::endl;
			}
			return (max_size);
		}

		bool empty() const
		{
			return (!v_size);
		}

		size_type capacity() const
		{
			return (v_capacity);
		}

		// MODIFIERS

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			insert(begin(), first, last);
		}

		void assign(size_type n, const value_type &val)
		{
			clear();
			resize(n, val);
		}

		void push_back(const value_type &val)
		{
			if (v_size == v_capacity)
			{
				size_type oldCapacity = v_capacity;
				v_capacity = v_size == 0 ? 1 : v_capacity * 2;
				value_type *newArray = allocator.allocate(v_capacity);
				for (size_type i = 0; i < v_size; ++i)
					allocator.construct(&newArray[i], arrays[i]);
				for (iterator it = begin(); it != end(); ++it)
					allocator.destroy(it);
				allocator.deallocate(arrays, oldCapacity);
				arrays = newArray;
			}
			allocator.construct(&arrays[v_size], val);
			v_size++;
		}

		void pop_back()
		{
			if (v_size > 0)
			{
				allocator.destroy(&arrays[v_size]);
				v_size--;
			}
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_t dist = position - begin();
			insert(position, 1, val);
			return (&arrays[dist]);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			if (n)
			{
				vector tmp;
				tmp.reserve(n + v_size);
				int i = 0;
				iterator it = begin();
				while (it != position)
				{
					tmp.push_back(*it);
					it++;
					i++;
				}
				while (n--)
				{
					tmp.push_back(val);
					i++;
				}
				while (it != end())
				{
					tmp.push_back(*it);
					it++;
					i++;
				}
				swap(tmp);
			}
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			vector tmp;
			iterator it = begin();
			if (begin() != NULL)
			{
				while (it != position)
				{
					tmp.push_back(*it);
					it++;
				}
			}
			while (first != last)
			{
				tmp.push_back(*first);
				first++;
			}
			while (it != end())
			{
				tmp.push_back(*it);
				it++;
			}
			swap(tmp);
		}

		iterator erase(iterator position)
		{
			iterator it = position;

			allocator.destroy(position);
			for (iterator tmp = position; tmp != end() - 1; tmp++)
			{
				allocator.construct(tmp, *(tmp + 1));
				if (tmp + 1 != end())
					allocator.destroy(tmp + 1);
			}
			v_size--;

			return (it);
		}

		iterator erase(iterator first, iterator last)
		{
			for (; first != last; --last)
				first = erase(first);
			return (last);
		}

		void swap(vector &x)
		{
			swap(v_size, x.v_size);
			swap(v_capacity, x.v_capacity);
			swap(allocator, x.allocator);
			swap(arrays, x.arrays);
		}

		void clear()
		{
			for (size_t i = 0; i < v_size; i++)
			{
				allocator.destroy(&arrays[i]);
			}
			v_size = 0;
		}

		// ELEMENT ACCESS

		reference operator[](size_type n)
		{
			return (arrays[n]);
		}

		const_reference operator[](size_type n) const
		{
			return (arrays[n]);
		}

		reference at(size_type n)
		{
			if (n >= v_size || n < 0 || v_size == 0)
				throw(std::out_of_range("the element is out of range"));
			else
				return (arrays[n]);
		}

		const_reference at(size_type n) const
		{
			if (n >= v_size || n < 0 || v_size == 0)
				throw(std::out_of_range("the element is out of range"));
			else
				return (arrays[n]);
		}

		reference front()
		{
			return (arrays[0]);
		}

		const_reference front() const
		{
			return (arrays[0]);
		}

		reference back()
		{
			return (arrays[v_size - 1]);
		}

		const_reference back() const
		{
			return (arrays[v_size - 1]);
		}

	private:
		template <typename F>
		void swap(F &x, F &y)
		{
			F tmp;
			tmp = x;
			x = y;
			y = tmp;
		}
	};

	// NON-MEMBERS FUNCTIONS

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	// using the lexicographical comparaison wich returns true if vect1 is < to vect2
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	// is v1 >= v2, then !v1 < v2
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	// if v1 > v2, !v2 >= v1
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs >= lhs);
	}

	// if v1 <= v2, then !v1 > v2
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs > rhs);
	}

	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc> &lhs, ft::vector<T, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
};

#endif
