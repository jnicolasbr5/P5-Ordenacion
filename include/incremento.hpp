#pragma once

#include "sort_method.hpp"

template <typename Key>
class Incremento: public SortMethod<Key> {
  private:
    unsigned size_;
    float alpha_;

    void deltasort(int delta, staticSequence<Key>& sec, unsigned n) {
      for (unsigned i = delta; i < n; i++) {
        Key x = sec[i];
        unsigned j = i;
        
      while (j >= delta && x < sec[j - delta]) {
        sec[j] = sec[j - delta];
        j = j - delta;
      } 
      sec[j] = x; 
    }
  }

  public: 
    Incremento(staticSequence<Key>& k, unsigned size, float alpha, bool t) : SortMethod<Key>(k, t), alpha_(alpha), size_(size) {} 

    using SortMethod<Key>::secuencia_;
    using SortMethod<Key>::trace_;

    void Sort() override {
      std::cout << "\n---ALGORITMO DE INCREMENTOS---\n";
      unsigned delta = size_;
      while (delta > 1) {
        delta = delta * alpha_;
        if (delta < 1) delta = 1;
        deltasort(delta, secuencia_, size_);
        if (trace_) secuencia_.print();
        if (delta == 1) break;
      }
    }
    
};