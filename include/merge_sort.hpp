#pragma once

#include "sort_method.hpp"

template <typename Key>
class MergeSort: public SortMethod<Key> {
  private:
  unsigned inicio_;
  unsigned fin_;

  void Mezcla(staticSequence<Key>& sec, unsigned ini, unsigned cen, unsigned fin) {
   int i = ini; 
   int j = cen + 1; 
   int k = ini;
   
   staticSequence<Key> aux(sec);

   // Compara ambas mitades mientras ninguna se acabe
   while ((i <= cen) && (j <= fin)) {
      if (sec[i] < sec[j]) {
         aux[k] = sec[i];
         i++;
      } else {
         aux[k] = sec[j];
         j++;
      }
      k++;
   }
 
   if (i > cen) {
 
      while (j <= fin) {
         aux[k] = sec[j];
         j++; k++;
      }
   } else {
     
      while (i <= cen) {
         aux[k] = sec[i];
         i++; k++;
      }
   }

   for (int k = ini; k <= fin; k++) {
      sec[k] = aux[k];
   }
}

  void MSort(staticSequence<Key>& k, unsigned ini, unsigned fin) {
      if (ini < fin){
        unsigned cen = (ini + fin) / 2;
        MSort(k, ini, cen);
        MSort(k, cen + 1, fin);
        Mezcla(k, ini, cen, fin);
        if (trace_) secuencia_.print();
      }
    }

  public: 
    MergeSort(staticSequence<Key>& k, unsigned i, unsigned f, bool t) : SortMethod<Key>(k, t), inicio_(i), fin_(f) {}
    
    using SortMethod<Key>::secuencia_;
    using SortMethod<Key>::trace_;

    void Sort() override {
      std::cout << "\n---ALGORITMO DE MERGESORT---\n";
      MSort(secuencia_, inicio_, fin_);
    }
};