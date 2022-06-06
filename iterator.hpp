#pragma once

#include "utils.hpp"

namespace ft {
	//---------------------------ITERATOR_TRAITS------------------------------
	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef Distance 	difference_type;
		typedef T 			value_type;
		typedef Pointer 	pointer;
		typedef Reference 	reference;
		typedef Category 	iterator_category;
	};
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag, public output_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits <T*> {
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef	std::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	struct iterator_traits <const T*> {
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef	std::random_access_iterator_tag			iterator_category;
	};

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last)
	{
		size_t distance = 0;
		for(; first != last; ++first)
			distance++;
		return distance;
	}

	//----------------------------REVERSE_ITERATOR-----------------------------
    template <class Iterator>
    class reverse_iterator {
    public:
		typedef Iterator														iterator_type;
        typedef typename ft::iterator_traits<iterator_type>::value_type         value_type;
        typedef typename ft::iterator_traits<iterator_type>::difference_type    difference_type;
        typedef typename ft::iterator_traits<iterator_type>::pointer            pointer;
        typedef typename ft::iterator_traits<iterator_type>::reference          reference;
        typedef typename ft::iterator_traits<iterator_type>::iterator_category  iterator_category;

        reverse_iterator() {}

		explicit reverse_iterator (iterator_type it) : _position(it) {}

        reverse_iterator(const reverse_iterator &it) : _position(it.base()) {}

        ~reverse_iterator() {}

		iterator_type base() const {return _position;}

		reference operator*() const {
			iterator_type tmp = _position;
			return *(--tmp);
		}

		reverse_iterator operator+ (difference_type n) const {
			return reverse_iterator(_position - n);
		}
		//pre-increment version
		reverse_iterator& operator++()
		{
			_position--;
			return *this;
		}
		//post-increment version
		reverse_iterator  operator++(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator& operator+= (difference_type n)
		{
			_position -= n;
			return *this;
		}

		reverse_iterator operator- (difference_type n) const {
			return reverse_iterator(_position + n);
		}
		//pre-decrement version
		reverse_iterator& operator--(){
			_position++;
			return *this;
		}
		//post-decrement version
		reverse_iterator  operator--(int){
			reverse_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		reverse_iterator& operator-= (difference_type n){
			_position += n;
			return *this;
		}

		pointer operator->() const{
			return &(operator*());
		}

		reference operator[] (difference_type n) const{
			return *(operator-(n));
		}

	private:
		Iterator _position;
    };

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() >= rhs.base();
	}

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it){
		return rev_it + n;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		return lhs.base() - rhs.base();
	}

	//--------------------------RANDOM_ACCESS_ITERATOR-----------------------

	template <typename T>
	class random_access_iterator: ft::iterator<ft::random_access_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type        value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type   difference_type;
		typedef T*																			pointer;
		typedef T&																			reference;

		random_access_iterator() {}
		random_access_iterator(pointer position): _position(position) {}
		random_access_iterator(const random_access_iterator &src) {*this = src;}
		~random_access_iterator() {}

		pointer base() const {return _position;}

		random_access_iterator &operator=(const random_access_iterator &src)
		{
			if (this == &src)
				return (*this);
			_position = src.base();
			return *this;
		}

		reference &operator*() {return (*_position);}

		pointer operator->() const {return &(operator*());}

		random_access_iterator operator+(difference_type n) const
		{
			return _position + n;
		}

		random_access_iterator &operator++()
		{
			_position++;
			return *this;
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		random_access_iterator &operator+=(difference_type n)
		{
			_position += n;
			return *this;
		}

		random_access_iterator operator-(difference_type n) const
		{
			return _position - n;
		}

		random_access_iterator &operator--()
		{
			_position--;
			return (*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		random_access_iterator &operator-=(difference_type n)
		{
			_position -= n;
			return *this;
		}

		reference operator[](difference_type n) const {return *(operator+(n));}

	private:
		pointer _position;
	};

	template<class Iterator>
	bool operator==(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Iterator>
	bool operator!=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Iterator>
	bool operator<(const random_access_iterator<Iterator> &lhs,
				   const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class Iterator>
	bool operator<=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class Iterator>
	bool operator>(const random_access_iterator<Iterator> &lhs,
				   const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class Iterator>
	bool operator>=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<class Iterator>
	random_access_iterator<Iterator> operator+(
			typename random_access_iterator<Iterator>::difference_type n,
			const random_access_iterator<Iterator> &_it)
	{
		return _it + n;
	}

	template<class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator-(
			const random_access_iterator<Iterator> &lhs,
			const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() - rhs.base();
	}
}
