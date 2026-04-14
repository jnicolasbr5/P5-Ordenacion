#pragma once 

#include <algorithm>

#include "static_sequence.hpp"

template <typename Key>
class SortMethod {
  protected:
    staticSequence<Key> secuencia_;
    bool trace_;
    
  public:
    SortMethod(staticSequence<Key> k, bool t) : secuencia_(k), trace_(t) {}
    virtual ~SortMethod() {}
    virtual void Sort() = 0;
};