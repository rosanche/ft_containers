#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "RandomIterator.hpp"
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
		typedef ft::RandomIterator<iterator> reverse_iterator;
		typedef ft::RandomIterator<const_iterator> const_reverse_iterator;


	private:
		value_type *arrays;
		allocator_type allocator;
		int v_size;
		int v_capacity;

	public:
		// explicit vector(const allocator_type &alloc = allocator_type()) : allocator(alloc),
		// 																  arrays(NULL),
		// 																  v_size(0),
		// 																  v_capacity(0)
		// {
		// }
		// vector(void) : allocator(NULL),
		// 			   arrays(NULL),
		// 			   v_size(0),
		// 			   v_capacity(0)
		// {
		// }
		//  CONSTRUCTOR

		explicit vector(const allocator_type &alloc = allocator_type()) : allocator(alloc),
																		  arrays(NULL),
																		  v_size(0),
																		  v_capacity(0)
		{
		}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : allocator(alloc),
																															 arrays(NULL),
																															 v_size(0),
																															 v_capacity(0)
		{
			assign(n, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : allocator(alloc),
																										  arrays(NULL),
																										  v_size(0),
																										  v_capacity(0)
		{
			assign(first, last);
		}

		vector(const vector &ptr) : allocator(ptr.allocator),
									arrays(NULL),
									v_size(0),
									v_capacity(0)
		{
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
			return (reverse_iterator(arrays));
		}

		iterator end()
		{
			return (iterator(&arrays[v_size]));
		}
		const_iterator end() const
		{
			return (const_iterator(&arrays[v_size]));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(&arrays[v_size]));
		}

		// CAPACITY
		int size()
		{
			return (v_size);
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n > size())
			{
				for (int i = n; n > size(); i--)
					pop_back();
			}
			else
			{
				for (int i = n; n < size(); i++)
					push_back(val);
			}
		}

		void reserve(size_type n)
		{
			if (n > max_size())
				throw(std::length_error("n greater than maximum size"));
			if (n > v_capacity)
			{
				value_type *new_array;
				new_array = allocator.allocate(n);
				for (size_t i = 0; i < v_size; i++)
					allocator.construct(&new_array[i], arrays[i]);
				allocator.deallocate(arrays, v_capacity);
				allocator.destroy(arrays);
				arrays = new_array;
				v_capacity = n;
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
			return (!!v_size);
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
			if (v_size + 1 > v_capacity)
				reserve(v_size + 1);
			allocator.construct(&arrays[v_size + 1], val);
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
		typename ft::enable<!ft::integral<InputIterator>::value >::type* = 0)
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
			for (pointer tmp = position; tmp != end(); tmp++)
			{
				allocator.construct(tmp, *(tmp + 1));
			}
			v_size--;
			return (it);
		}

		iterator erase(iterator first, iterator last)
		{
			iterator it = first;
			iterator tmp = first;
			while (tmp != first)
			{
				erase(first);
				tmp++;
			}
			return (it);
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
};

#endif