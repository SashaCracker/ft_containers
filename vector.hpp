#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterator.hpp"
#include "utils.hpp"
#include <iostream>

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
		typedef ft::random_access_iterator<T*>							iterator;
		typedef ft::random_access_iterator<const T*>					const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef size_t													size_type;

		explicit vector(const allocator_type& alloc = allocator_type()) :
		_size(0), _capacity(0), _alloc(alloc), _arr(nullptr) {}
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) :
						_size(n), _capacity(n), _alloc(alloc), _arr(nullptr)
		{
			if (n < 0)
				throw std::logic_error("Error: Incorrect size!");
			reserve(n);
			for (size_type i = 0; i < n; ++i)
				_alloc.construct(_arr + i, val);
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const
		allocator_type& alloc = allocator_type()) : _size(0), _capacity(0),
		_alloc(alloc), _arr(nullptr)
		{
			insert(begin(), first, last);
		}
		vector(const vector& x) : _size(0), _capacity(0), _alloc(x._alloc),
		_arr(nullptr)
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
		size_type max_size() const {return _allocator.max_size();}
		void resize (size_type n, value_type val = value_type()){
			if (!val)
				val = 0;
			if (n < 0)
				throw std::logic_error("Error: Incorrect size!");
			else if (n == _size)
				return;
			else if (n < _size)
			{
				erase(&_arr[n]; end());
				_size = n;
			}
			else if (n > _capacity)
			{
				reserve(n);
				for (size_type i = _size; i <= n; ++i)
					_alloc.construct(_arr + i, val);
				_size = n;
				_capacity = n;
			}
			else
			{
				for (size_type i = _size; i <= n; ++i)
					_alloc.construct(_arr + i, val);
				_size = n;
			}
		}
		size_type capacity() const { return _capacity; }
		bool empty() const { return size() == 0;}
		void reserve (size_type n) {
			if (n < 0)
				throw std::logic_error("Error: Incorrect size!");
			if (n <= _capacity)
				return;
			value_type* newarr = _alloc.allocate(n);
			for (size_type i = 0; i < _size; ++i)
				newarr[i] = _arr[i];
			erase(begin(), end());
			_alloc.deallocate(_arr, _capacity);
			_arr = newarr;
			_capacity = n;
		}
		reference operator[] (size_type n) { return _arr[n];}
		const_reference operator[] (size_type n) const {return _arr[n];}
		reference at (size_type n) {
			if (n >= _size || n < 0)
				throw std::out_of_range("Error: Out of range");
			return _arr[n];
		}
		const_reference at (size_type n) const {
			if (n >= _size || n < 0)
				throw std::out_of_range("Error: Out of range");
			return _arr[n];
		}
		reference front (){ return _arr[0]; }
		const_reference front () const {return _arr[0]; }
		reference back () { return _arr[_size]; }
		const_reference back () const { return _arr[_size]; }
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last){
			clear();
			insert(begin(), first, last);
		}
		void assign (size_type n, const value_type& val) {
			clear();
			insert(begin(), n, val);
		}
		void push_back (const value_type& val) {
			reserve(_size + 1);
			_alloc.construct(_arr + _size, val);
			++_size;
		}
		void pop_back() {
			if (_size) {
				_size--;
				_alloc.destroy(_arr + _size);
			}
		}
		iterator insert (iterator position, const value_type& val) {
			if (position > end() || position < begin())
				throw std::logic_error("Error: Bad position index!/n");
			size_type distance = static_cast<size_type>(ft::distance(begin(),
																   position));
			if (_capacity < _size + 1)
				reserve(_size + 1);
			for (size_type i = 0; _size - i != distance; ++i) {
				_alloc.construct(_arr + _size - i, _arr[_size - i - 1]);
				_alloc.destroy(_arr + _size - i - 1);
			}
			_alloc.construct(_arr + distance, val);
			_size++;
			return iterator(begin() + distance);
		}
		void insert (iterator position, size_type n, const value_type& val) {
			if (position > end() || position < begin())
				throw std::logic_error("Error: Bad position index!");
			size_type distance = static_cast<size_type>(ft::distance(begin(),position));
			if (_capacity < _size + n)
				reserve(_size + n);
			for (size_type i = 0; _size - i != distance; ++i) {
				_alloc.construct(_arr + _size - 1 - i + n, _arr[_size - i - 1]);
				_alloc.destroy(_arr + _size - i - 1);
			}
			for (size_type i = 0; i < n; i++) {
				_alloc.construct(_arr + distance + i, val);
				_size++;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator
		last) {
			if (position > end() || position < begin())
				throw std::logic_error("Error: Bad position index!");
			size_type n = static_cast<size_type>(ft::distance(first, last));
			size_type distance = static_cast<size_type>(ft::distance(begin(), position));
			if (_capacity < _size + n)
				reserve(_size + n);
			for (size_type i = 0; _size - i != distance; ++i){
				_alloc.construct(_arr + _size - 1 - i + n, _arr[_size - i - 1]);
				_alloc.destroy(_arr + _size - i - 1);
			}
			for (size_type i = 0; i < n; i++) {
				_alloc.construct(_arr + distance + i, tmp[i]);
				_alloc.destroy(tmp + i);
				_size++;
			}
		}
		iterator erase (iterator position) {
			if (_size == 0)
				return end();
			size_type distance = static_cast<size_type>(ft::distance(begin(),
																   position));
			_alloc.destroy(_arr + distance);
			for (size_type i = 0; distance + i != _size; ++i) {
				_alloc.construct(_arr + distance + i, _arr[distance + i + 1]);
				_alloc.destroy(_arr + distance + i + 1);
			}
			_size--;
			return begin() + distance;
		}
		iterator erase (iterator first, iterator last) {
			if (_size == 0)
				return end();
			size_type n = static_cast<size_type>(ft::distance(first, last));
			size_type distance = static_cast<size_type>(ft::distance(begin(),
																   first));
			for (size_type i = 0; i != n; ++i)
				_alloc.destroy(_arr + distance + i);
			_size -= n;
			for (size_type i = 0; distance + i != _size; ++i) {
				_alloc.construct(_arr + distance + i, _arr[distance + i + n]);
				_alloc.destroy(_arr + distance + i + n);
			}
			return begin() + distance;
		}
		void swap (vector& x) {
			allocator_type tmp_alloc = _alloc;
			value_type* tmp_arr = _arr;
			size_type tmp_size = _size;
			size_type tmp_capacity = _capacity;
			_alloc = x._alloc;
			_arr = x._arr;
			_size = x._size;
			_capacity = x._capacity;
			x._alloc = tmp_alloc;
			x._arr = tmp_arr;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
		}
		void clear() {
			for (size_type i = 0; i != _size; ++i)
				_alloc.destroy(_arr + i);
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

	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

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
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}

#endif
