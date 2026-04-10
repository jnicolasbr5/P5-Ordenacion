#pragma once 

#include "static_sequence.hpp"

template <typename Key>
class SortMethod {
  private:
    staticSequence<Key> secuencia_;
    
  public:
    virtual void SortMethod<Key>::Sort() = 0;

};