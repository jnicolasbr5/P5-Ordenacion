#pragma once

#include "sort_method.hpp"

template <typename Key>
class Burbuja: public SortMethod<Key> {
  private: 
    unsigned size_;

  public: 
    Burbuja(staticSequence<Key> k, unsigned size, bool t) : SortMethod<Key>(k, t), size_(size) {} 

    using SortMethod<Key>::secuencia_;
    using SortMethod<Key>::trace_;

    void Sort() override {
      std::cout << "\n---ALGORITMO DE BURBUJA---\n";
      for (unsigned i = 1; i < size_; i++) {
        for (unsigned j = size_ - 1; j >= i; j--) {
          if (secuencia_[j] < secuencia_[j - 1]) {
            std::swap(secuencia_[j], secuencia_[j - 1]);
          }
        }
        if (trace_) secuencia_.print();
      }
    }
};