#pragma once 

#include <print>
#include <vector>
#include "sequence.hpp"

template <class Key>
class staticSequence: public Sequence<Key> {
	private:
		unsigned block_size_;
		std::vector<Key> arreglo_;

		bool isFull() const {
			if (arreglo_.size() == block_size_) return true;
			return false;
		}

	public:
		staticSequence(unsigned size) : block_size_(size) {
			arreglo_.reserve(size);
		}

		bool search(const Key& k) const override {
			for (unsigned i = 0; i < arreglo_.size(); i++) {
				if (arreglo_[i] == k) return true;
			}
			return false;
		}

		bool insert(const Key& k) override {
			if (search(k)) return true;
			if (isFull()) return false;
			arreglo_.push_back(k);
			return true;
		}
	
		// P5
		Key operator[](const unsigned num) const override {
			if (num >= block_size_) {
				std::println("No se puede indexar ({})", block_size_);
				std::exit(1);
			}
			return arreglo_[num];
		}

		Key& operator[](const unsigned num) override {
			if (num >= block_size_) {
				std::println("No se puede indexar ({})", block_size_);
				std::exit(1);
			}
			return arreglo_[num];
		}

		// P5 
		unsigned size() const {return arreglo_.size();}
};