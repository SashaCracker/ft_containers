#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterator.hpp"
#include "utils.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef ft::random_access_iterator<value_type>					iterator;
		typedef ft::random_access_iterator<const value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef size_t													size_type;

		explicit vector(const allocator_type& alloc = allocator_type()) :
				_arr(nullptr), _size(0), _capacity(0), _alloc(alloc) {}
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) :
				_arr(nullptr), _size(n), _capacity(n), _alloc(alloc)
		{
			_arr = _alloc.allocate(n);
			try
			{
				size_type i = 0;
				while (i < n)
				{
					_alloc.construct(_arr + i, val);
					++i;
				}
			}
			catch (...)
			{
				_alloc.deallocate(_arr, n);
				_arr = nullptr;
				throw std::logic_error("Error: Constructor failed!");
			}
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value
				>::type* = 0) : _arr(nullptr), _size(0), _capacity(0), _alloc(alloc) {
			insert(begin(), first, last);
		}
		vector(const vector& x) : _arr(nullptr), _size(0), _capacity(0),
		_alloc(x._alloc)
		{
			insert(begin(), x.begin(), x.end());
		}
		~vector() {
			clear();
			if (_arr || _capacity)
				_alloc.deallocate(_arr, _capacity);
		}
		vector& operator=(const vector& x) {
			if (this != &x)
			{
				clear();
				_alloc.deallocate(_arr, _capacity);
				_capacity = x.capacity();
				_arr = _alloc.allocate(_capacity);
				insert(begin(), x.begin(), x.end());
			}
			return *this;
		}
		iterator begin() {return &_arr[0];}
		const_iterator begin() const {return &_arr[0];}
		iterator end() {return &_arr[_size];}
		const_iterator end() const {return &_arr[_size];}
		reverse_iterator rbegin() {return reverse_iterator(end());}
		const_reverse_iterator rbegin() const {return reverse_iterator(end());}
		reverse_iterator rend() {return reverse_iterator(begin());}
		const_reverse_iterator rend() const {return reverse_iterator(begin());}
		size_type size() const {return _size;}
		size_type max_size() const {return _alloc.max_size();}
		void resize (size_type n, value_type val = value_type())
		{
			if (n < _size)
				for (; _size > n; _size--)
					_alloc.destroy(&_arr[_size]);
			else if (n > _size && n < max_size())
			{
				if (n > _capacity && n <= _capacity * 2)
					reserve(_capacity * 2);
				else if (n > _capacity * 2)
					reserve(n);
				for (; _size < n; _size++)
					_alloc.construct(&_arr[_size], val);
			}
		}
		size_type capacity() const { return _capacity; }
		bool empty() const { return size() == 0;}
		void reserve (size_type n) {
			if (n > _capacity && n < max_size())
			{
				pointer temp = _alloc.allocate(n);
				try
				{
					std::uninitialized_copy(_arr, _arr + _size, temp);
				}
				catch (...)
				{
					_alloc.deallocate(temp, n);
					throw;
				}
				_alloc.deallocate(_arr, _capacity);
				_arr = temp;
				_capacity = n;
			}
		}
		reference operator[] (size_type n) { return _arr[n];}
		const_reference operator[] (size_type n) const {return _arr[n];}
		reference at (size_type n) {
			if (n >= _size)
				throw std::out_of_range("Out of range");
			return _arr[n];
		}
		const_reference at (size_type n) const {
			if (n >= _size)
				throw std::out_of_range("Out of range");
			return _arr[n];
		}
		reference front (){ return _arr[0]; }
		const_reference front () const {return _arr[0]; }
		reference back () { return _arr[_size - 1]; }
		const_reference back () const { return _arr[_size - 1]; }
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value
		>::type* = 0){
			clear();
			insert(begin(), first, last);
		}
		void assign (size_type n, const value_type& val) {
			clear();
			insert(begin(), n, val);
		}
		void push_back (const value_type& val) {
			if (!_size)
				reserve(1);
			else if (_size == _capacity)
				reserve(_capacity * 2);
			_alloc.construct(&(*end()), val);
			_size++;
		}
		void pop_back() {
			if (_size) {
				_size--;
				_alloc.destroy(_arr + _size);
			}
		}
		iterator insert (iterator position, const value_type& val) {
			if (position > end() || position < begin())
				throw std::logic_error("Bad position index!");
			size_type distance = static_cast<size_type>(ft::distance(begin(),
																   position));
			if (_capacity == _size && _capacity)
				reserve(_capacity * 2);
			else if (_capacity < _size + 1)
				reserve(_size + 1);
			for (size_type i = 0; distance + i < _size; ++i) {
				_alloc.construct(_arr + _size - i, _arr[_size - i - 1]);
				_alloc.destroy(_arr + _size - i - 1);
			}
			_alloc.construct(_arr + distance, val);
			_size++;
			return iterator(begin() + distance);
		}
		void insert (iterator position, size_type n, const value_type& val) {
			if (position > end() || position < begin())
				throw std::logic_error("Bad position index!");
			size_type distance = static_cast<size_type>(ft::distance(begin(),position));
			if (_capacity == _size && _capacity)
				reserve(_capacity * 2);
			if (_capacity < _size + n)
				reserve(_size + n);
			for (size_type i = 0; _size - i != distance; ++i) {
				_alloc.construct(_arr + _size - 1 - i + n, _arr[_size - i -
				1]);
				_alloc.destroy(_arr + _size - i - 1);
			}
			for (size_type i = 0; i < n; i++) {
				_alloc.construct(_arr + distance + i, val);
				_size++;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator
		last, typename ft::enable_if<!ft::is_integral<InputIterator>::value
		>::type* = 0) {
			size_type n = static_cast<size_type>(ft::distance(first, last));
			size_type distance = static_cast<size_type>(ft::distance(begin(), position));
			if (position > end() || position < begin())
				throw std::logic_error("Bad position index!");
			pointer tmp = _alloc.allocate(n);
			try {
				for (size_type i = 0; i < n; i++)
					_alloc.construct(tmp + i, *first++);
			}
			catch(...) {
				for (size_type i = 0; tmp + i != 0 && i < n; i++) {
					_alloc.destroy(tmp + i);
				}
				_alloc.deallocate(tmp, n);
				throw std::logic_error("Error: Common error");
			}
			if (_capacity == _size && _capacity)
				reserve(_capacity * 2);
			if (_capacity < _size + n)
				reserve(_size + n);
			for (size_type i = 0; _size - i != distance; ++i){
				_alloc.construct(_arr + _size - 1 - i + n, _arr[_size - i -
				1]);
				_alloc.destroy(_arr + _size - i - 1);
			}
			for (size_type i = 0; i < n; i++) {
				_alloc.construct(_arr + distance + i, tmp[i]);
				_alloc.destroy(tmp + i);
				_size++;
			}
			_alloc.deallocate(tmp, n);
		}
		iterator erase (iterator position) {
			if (position > end() || position < begin())
				throw std::logic_error("Bad position index!");
			if (_size == 0)
				return end();
			size_type distance = static_cast<size_type>(ft::distance(begin(),
																   position));
			_alloc.destroy(_arr + distance);
			size_type i = 0;
			while (distance + i != _size - 1) {
				_alloc.construct(_arr + distance + i, _arr[distance + i + 1]);
				_alloc.destroy(_arr + distance + i + 1);
				++i;
			}
			_size--;
			return begin() + distance;
		}
		iterator erase (iterator first, iterator last) {
			if (first > end() || first < begin() || last > end() || last < begin())
				throw std::logic_error("Bad position index!");
			if (_size == 0)
				return end();
			size_type n = static_cast<size_type>(ft::distance(first, last));
			size_type distance = static_cast<size_type>(ft::distance(begin(),
																   first));
			size_type i = 0;
			while (i != n)
			{
				_alloc.destroy(_arr + distance + i);
				++i;
			}
			_size -= n;
			i = 0;
			while (distance + i != _size) {
				_alloc.construct(_arr + distance + i, _arr[distance + i + n]);
				_alloc.destroy(_arr + distance + i + n);
				++i;
			}
			return begin() + distance;
		}
		void swap (vector& x) {
			ft::swap(_arr, x._arr);
			ft::swap(_size, x._size);
			ft::swap(_capacity, x._capacity);
		}
		void clear() {
			size_type i = 0;
			while (i != _size)
			{
				_alloc.destroy(_arr + i);
				++i;
			}
			_size = 0;
		}
		allocator_type get_allocator() const { return _alloc; }
	private:
		value_type*		_arr;
		size_type       _size;
		size_type       _capacity;
		allocator_type	_alloc;
	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator lb_it = lhs.begin();
		typename ft::vector<T>::const_iterator le_it = lhs.end();
		typename ft::vector<T>::const_iterator rb_it = rhs.begin();
		if (!ft::equal(lb_it, le_it, rb_it))
			return (false);
		return (true);
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return rhs < lhs;
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {return x.swap
	(y);}

}
#endif


