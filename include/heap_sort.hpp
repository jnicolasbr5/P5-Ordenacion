#pragma once

#include "sort_method.hpp"

template <typename Key>
class HeapSort: public SortMethod<Key> {
  private:
    unsigned size_;
    
    void baja(int i, staticSequence<Key>& sec, unsigned size)  {
      int h;
      while (2 * i + 1 < size){
        int h1 = 2 * i + 1; 
        int h2 = h1 + 1;
        if (h2 >= size) {
          h = h1; 
        } 
        else if (sec[h1] > sec[h2]) {
          h = h1; 
        }
        else {
          h = h2;
        }
        if (sec[h] <= sec[i]) {
          break; 
        } else {
          std::swap(sec[i],sec[h]);
          i = h;
        } 
      } 
  }

  public:
    HeapSort(staticSequence<Key>& k, unsigned size, bool t) : SortMethod<Key>(k, t), size_(size) {} 

    using SortMethod<Key>::secuencia_;
    using SortMethod<Key>::trace_;

    void Sort() override {
      std::cout << "\n---ALGORITMO DE HEAPSORT---\n";
      for (int i = (size_ / 2) - 1; i >= 0; i--) {
        baja(i, secuencia_, size_);
        if (trace_) secuencia_.print();
      }
      for (int i = size_ - 1; i >= 0; i--) {
        std::swap(secuencia_[0], secuencia_[i]);
        baja(0, secuencia_, i);
        if (trace_) secuencia_.print();
      }
    }
};