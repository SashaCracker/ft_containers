#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template <class Node>
	struct node
	{
		Node		pair;
		node*		left;
		node*		right;
		node*		parent;
		bool		isBlack;

		node() : pair(Node()), left(0), right(0), parent(0), isBlack(false) {}

		node(const Node& p_pair) : pair(p_pair), left(0), right(0), parent
		(0), isBlack(false) {}

		node& operator=(const node& node) {
			pair = node.pair;
			left = node.left;
			right = node.right;
			parent = node.parent;
			isBlack = node.isBlack;
			return *this;
		}
	};

	template <class Key, class Val>
	struct pair
	{
	public:
		Key first;
		Val second;

		pair() : first(), second() {}

		pair(const Key& a, const Val& b) : first(a), second(b) {}

		template<typename U, typename V>
		pair(const pair<U, V>& other) : first(other.first), second(other
		.second) {}

		~pair() {}

		pair &operator=(const pair &other) {
			if (this != &other)
			{
				first = other.first;
				second = other.second;
			}
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator==(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return ft::pair<T1, T2>(x, y);
	}
}

#endif