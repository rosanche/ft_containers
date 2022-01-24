#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "RandomIterator.hpp"
#include <iostream>
#include <vector>

namespace ft {
	// template <typename T>

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
				assign(n, val);
			}


			template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): 
				allocator(alloc),
				arrays(NULL),
				v_size(0),
				v_capacity(0)  
			{
				assign(first, last);
			}

			vector (const vector &ptr): 
				allocator(ptr.allocator),
				arrays(NULL),
				v_size(0),
				v_capacity(0)  
			{
				assign(ptr.begin, ptr.last);
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
				allocator.deallocate(arrays, v_size);
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
				return(*this);
			}

			// ITERATORS

			iterator begin() {
				return (iterator(this->arrays));
			}
			reverse_iterator rbegin() {
				return (reverse_iterator(this->arrays));
			}

			iterator end() {
				return (iterator(this->arrays[v_size]));
			}
			reverse_iterator rend() {
				return (reverse_iterator(this->arrays[v_size]));
			}

			// CAPACITY
			int size() {
				return (v_size);
			}
			void resize(size_type n, value_type val = value_type()) {
				return ();
			}

			void reserve (size_type n) {

			}

			size_type max_size() const {
				size_type max_size = 0;
				try
					max_size = allocator.max_size();
				catch (std::exception &e)
					std::cout << "Error appeared with vector.max_size() :" << e.what() << std::endl;
				return (max_size);
			}

			bool empty() const {
				return (!!v_size);
			}

			size_type capacity() const {
				return (v_capacity)''
			}

			// MODIFIERS

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) {
				
			}

			void assign (size_type n, const value_type& val) {

			}

			void push_back (const value_type& val) {
				if (v_size + 1 > v_capacity)
					reserve(v_size + 1 )
				allocator.constuct(&arrays[v_size + 1], val)
				v_size++;
			}

			void pop_back() {
				if (v_size > 0) {
					allocator.destroy(&arrays[v_size]);
					v_size--;
				}
			}

			iterator insert (iterator position, const value_type& val) {

			}

			void insert (iterator position, size_type n, const value_type& val) {

			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last) {
					
			}

			iterator erase (iterator position) {

			}
			
			iterator erase (iterator first, iterator last) {

			}

			void swap (vector& x) {
				swap(v_size, x.v_size);
				swap(v_capacity, x.v_capacity);
				swap(allocator, x.allocator);\
				swap(arrays, x.arrays)
			}

			void clear() {
				for (size_t i = 0; i < v_size; i++)
				{
					allocator.destroy(&arrays[i]);
				}
				v_size = 0;
			}

			private :
				template <typename T>
				void swap(T& x, T& y) {
					T& tmp;
					tmp = x;
					x = y;
					y = T;
				}
	};
};

#endif