#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "RandomIterator.hpp"
#include <iostream>
#include <vector>

namespace ft {
	template <typename T>

	class vector
	{
		public:
			// member types
			template < class T, class Alloc = allocator<T> >
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef std::ptrdiff_t difference_type;
			typedef size_t size_type;

			typedef RandomIterator<T> iterator;
			typedef RandomIterator<const T> const_iterator;
			typedef RandomIterator<iterator> reverse_iterator;
			typedef RandomIterator<const_iterator> const_reverse_iterator;

		private: 
			value_type* arrays;
			allocator_type allocator;
			int v_size;
			int v_capacity;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()): 
				allocator(alloc),
				arrays(NULL),
				v_size(0),
				v_capacity(0)  
			{
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): 
				allocator(alloc),
				arrays(NULL),
				v_size(0),
				v_capacity(0)  
			{
				assign(n. val);
			}


			template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): 
				allocator(alloc),
				arrays(NULL),
				v_size(0),
				v_capacity(0)  
			{
				assign(first, last)
			}

			vector (const vector &ptr): 
				allocator(ptr.allocator),
				arrays(NULL),
				v_size(0),
				v_capacity(0)  
			{
				assign(x.begin, x.last)
			}

			vector(void): 
				allocator(NULL),
				arrays(NULL),
				v_size(0),
				v_capacity(0)  
			{
			}

			~vector() 
			{
				clear();
				allocator.deallocate(arrays, v_size)
			}

			vector &operator=(const vector &ptr)
			{
				if (this != &ptr)
				{
					clear();
					allocator = ptr.allocator;
					array = NULL;
					v_size = 0;
					v_capacity = 0;
					
					if (ptr.v_capacity != 0)
						reserve(v_capacity);
				
					if (ptr.size() != 0)
						assign(ptr.begin(), ptr.end());
				
				}
				return(*this);

			// ITERATORS

			iterator begin() {
				return (iterator(this->arrays));
			}
			reverse_iterator rbegin() {
				return (reverse_iterator(this->arrays))
			}

			iterator end() {
				return (iterator(this->arrays[v_size]));
			}
			reverse_iterator rend() {
				return (reverse_iterator(this->arrays[v_size]))
			}

			// CAPACITY
			int size() {
				return (v_size);
			}
			void resize(size_type n, value_type val = value_type()) {
				return ();
			}
	};
};

#endif