#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {

	//---------------------------ITERATOR_TRAITS------------------------------
	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T *, class Reference = T &>
	struct iterators
	{
		typedef Distance 	difference_type;
		typedef T 			value_type;
		typedef Pointer 	pointer;
		typedef Reference 	reference;
		typedef Category 	iterator_category;
	};

//	struct input_iterator_tag {};
//	struct output_iterator_tag {};
//	struct forward_iterator_tag : public input_iterator_tag, public output_iterator_tag {};
//	struct bidirectional_iterator_tag : public forward_iterator_tag {};
//	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

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
}
#endif
