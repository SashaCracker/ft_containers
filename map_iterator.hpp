#ifndef bidirectional_iterator_HPP
# define bidirectional_iterator_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "utils.hpp"

namespace ft
{
	template<class T>
	class map_iterator
	{
	public:
		typedef typename ft::iterator_traits<T *>::difference_type difference_type;
		typedef typename ft::iterator_traits<T *>::value_type value_type;
		typedef typename ft::iterator_traits<T *>::pointer pointer;
		typedef typename ft::iterator_traits<T *>::reference reference;
		typedef ft::node<typename ft::switch_const<T>::type> *node_ptr;
		typedef std::bidirectional_iterator_tag iterator_category;
	private:
		node_ptr _root;
		node_ptr _base;

		node_ptr min_node(node_ptr some) const
		{
			if (some)
			{
				while (some->left)
					some = some->left;
			}
			return some;
		}

		node_ptr max_node(node_ptr some) const
		{
			if (some)
			{
				while (some->right)
					some = some->right;
			}
			return some;
		}

	public:
		map_iterator() : _root(0), _base(0)
		{}

		explicit map_iterator(const node_ptr &root, const node_ptr &node) :
		_root(root), _base(node) {}

		map_iterator(const map_iterator &other) : _root(other._root), _base
		(other._base) {}

		~map_iterator() {}

		template<class Type>
		operator map_iterator<const Type>() const
		{
			return map_iterator<const Type>(_root, _base);
		}

		reference operator*() const
		{
			return _base->pair;
		}

		pointer operator->() const
		{
			return &(_base->pair);
		}

		map_iterator &operator++()
		{
			if (!_base)
				return *this;
			else if (_base->right)
				_base = min_node(_base->right);
			else if (_base == max_node(_root->parent))
				_base = 0;
			else
			{
				while (_base->parent->right == _base)
					_base = _base->parent;
				_base = _base->parent;
			}
			return *this;
		}

		map_iterator operator++(int)
		{
			map_iterator<T> tmp(*this);
			++(*this);
			return tmp;
		}

		map_iterator &operator--()
		{
			if (!_base)
				_base = max_node(_root->parent);
			else if (_base->left)
				_base = max_node(_base->left);
			else
			{
				while (_base->parent->left == _base)
					_base = _base->parent;
				_base = _base->parent;
			}
			return *this;
		}

		map_iterator operator--(int)
		{
			map_iterator<T> tmp(*this);
			--(*this);
			return tmp;
		}

		bool operator==(const map_iterator& it) const
		{ return (it._base == _base); }
		bool operator!=(const map_iterator& it) const
		{ return (it._base != _base); }
	};
}
#endif
