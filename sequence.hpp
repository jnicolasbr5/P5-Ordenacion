#pragma once 

template <class Key>
class Sequence {
	public:
		virtual bool search(const Key& k) const = 0;
		virtual bool insert(const Key& k) = 0;

		// P5
		virtual Key Sequence<Key>::operator[](const unsigned) const = 0;
		virtual Key& Sequence<Key>::operator[](const unsigned) = 0;
};