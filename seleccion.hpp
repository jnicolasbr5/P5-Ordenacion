#pragma once

#include "sort_method.hpp"
#include "ordenacion.hpp"

template <typename Key>
class Seleccion: public SortMethod<Key> {
  public: 
    void Sort() override {
      Seleccion(secuencia_, secuencia_.size());
    }
    
};