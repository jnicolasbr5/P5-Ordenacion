#pragma once 

#include "static_sequence.hpp"

template <typename Key>
void Seleccion(staticSequence<Key>& sec, unsigned size) {
  for (unsigned i = 0; i < size - 1; i++) {
    unsigned min = i; 
    for (unsigned j = i + 1; j < size; j++) {
      if (sec[j] < sec[min]) {
        min = j; // Si un numero es menor que el de la posicion i
      }
    }
    
    // En caso de que se haya encontrado un menor, se intercambian las posiciones
    if (min != i) {
      Key x = sec[i];
      sec[i] = sec[min];
      sec[min] = x;
    }
  }
}

template <typename Key>
void Burbuja(staticSequence<Key>& sec, unsigned size) {
  for (unsigned i = 1; i < size; i++) {
    for (unsigned j = size - 1; j >= i; j--) {
      if (sec[j] < sec[j - 1]) {
        Key x = sec[j];
        sec[j] = sec[j - 1];
        sec[j - 1] = x;
      }
    }
  }
}

template <typename Key>
void Seleccion(staticSequence<Key>& sec, unsigned ini, unsigned fin);

template <typename Key>
void Seleccion(staticSequence<Key>& sec, unsigned ini, unsigned fin);

template <typename Key>
void Seleccion(staticSequence<Key>& sec, unsigned ini, unsigned fin);

template <typename Key>
void Seleccion(staticSequence<Key>& sec, unsigned ini, unsigned fin);