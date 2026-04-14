#pragma once

#include "sort_method.hpp"

template <typename Key>
class Seleccion: public SortMethod<Key> {
  private: 
  unsigned size_;
  
  public:
    using SortMethod<Key>::secuencia_;
    using SortMethod<Key>::trace_;

    Seleccion(staticSequence<Key> k, unsigned size, bool t) : SortMethod<Key>(k, t), size_(size) {}

    void Sort() override {
      std::cout << "\n---ALGORITMO DE SELECCIÓN---\n";
      for (unsigned i = 0; i < size_ - 1; i++) {
        unsigned min = i; 
        for (unsigned j = i + 1; j < size_; j++) {
          if (secuencia_[j] < secuencia_[min]) {
            min = j; // Si un numero es menor que el de la posicion i
          }
        }
    
        // En caso de que se haya encontrado un menor, se intercambian las posiciones
        if (min != i) {
          std::swap(secuencia_[i], secuencia_[min]);
        }
        secuencia_.print();
      }
    }  
};