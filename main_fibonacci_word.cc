///
/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad de algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 24 Oct 2020
/// @brief Program that verifies if what is entered per file belongs to the Fibonacci sequence
/// 
/// @see https://es.wikipedia.org/wiki/Sucesi%C3%B3n_de_Fibonacci
/// 
/// To compile: make 
/// To clean files: make clean
///

#include <iostream>
#include <vector>

#include "fibonacci_word.h"


int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 2) { error_message(1); return 1; }     
  if ((std::string)argv[1] == "--help" || (std::string)argv[1] == "-h")
    if (argv[2] == NULL) {
      error_message(2);
      return 1;
    }
  if (argv[2] == NULL) { error_message(1); return 1; }
  if (((std::string)argv[1] != "input.txt") || 
      ((std::string)argv[2] != "output.txt")) {
    error_message(3);
    return 1;
  }
  std::vector<FibonacciWord> list = create_vector();
  for (unsigned iterator = 0; iterator < list.size(); iterator++)
    list[iterator].FibonacciCheck();
  WriteOnFile(list);

  return 0;
}