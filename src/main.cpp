#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <print>

#include "seleccion.hpp"
#include "burbuja.hpp"
#include "merge_sort.hpp"
#include "heap_sort.hpp"
#include "incremento.hpp"
#include "nif.hpp"

struct Datos {
  unsigned size;
  std::string metodo;
  std::string tipo;
  std::string file = "";
  bool trace;
};

Datos LeerComandos(std::vector<std::string> vec) {
  Datos datos;
  for (int i = 1; i < vec.size(); i++) {
		if (vec[i] == "-size") { 
			++i;
			datos.size = static_cast<unsigned int>(std::stoul(vec[i]));
		} else if (vec[i] == "-ord") {
			++i;
			datos.metodo = vec[i];
		}	else if (vec[i] == "-init") {
			++i;
			datos.tipo = vec[i];
      if (datos.tipo == "file") {
        i++;
        datos.file = vec[i];
      }
		}	else if (vec[i] == "-trace") {
			++i;
			if (vec[i] == "y") datos.trace = true;
      else datos.trace = false;
		}
	}
	return datos;
}

int main(int argc, char* argv[]) {
  if (argc < 9 || argc > 10) {
    std::cerr << "Error en el n de argumentos" << std::endl;
    return 1;
  }
  std::vector<std::string> v_args(argv, argv + argc);
  Datos datos = LeerComandos(v_args);
  
  using Key = nif;
  
  // Secuencia
  staticSequence<Key> sec(datos.size);

  // Datos de la secuencia
  if (datos.tipo == "manual") {
    for (unsigned i = 0; i < datos.size; i++) {
      nif valor;
      std::cout << "Introduce el NIF (" << i << "/" << datos.size - 1 << "): ";
      std::cin >> valor;
      sec.insert(valor);
    }
  } else if (datos.tipo == "random") {
    for (unsigned i = 0; i < datos.size; i++) {
      sec.insert(nif());
    }
  } else if (datos.tipo == "file") {
    std::ifstream file(datos.file);
    if (!file) {
      std::cerr << "Error: no se abrió el fichero -> " << datos.file << std::endl;
      return 1;
    }
    nif valor;
    for (unsigned i = 0; i < datos.size; i++) {
      file >> valor;
      sec.insert(valor);
    }
  }

  // Método de ordenación
  SortMethod<Key> *metodo = nullptr;
  if (datos.metodo == "s") { // Secuencial
    metodo = new Seleccion<Key>(sec, datos.size, datos.trace);
  } else if (datos.metodo == "b") { // Burbuja
    metodo = new Burbuja<Key>(sec, datos.size, datos.trace);
  } else if (datos.metodo == "m") { // MergeSort
    metodo = new MergeSort<Key>(sec, 0, datos.size - 1, datos.trace);
  } else if (datos.metodo == "h") { // HeapSort
    metodo = new HeapSort<Key>(sec, datos.size, datos.trace);
  } else if (datos.metodo == "i") { // Incremento
    std::cout << "Introduce un alpha (0 < alpha < 1): ";
    float alfa;
    std::cin >> alfa;
    metodo = new Incremento<Key>(sec, datos.size, alfa, datos.trace);
  }

  // Muestra secuencia inicial
  std::cout << "Secuencia inicial:" << std::endl;
  sec.print();

  // Ejecuta la ordenación
  metodo->Sort();

  return 0;
}