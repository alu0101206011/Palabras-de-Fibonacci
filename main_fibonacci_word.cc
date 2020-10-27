///
/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad y algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 27 Oct 2020
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
  if (argc != 3 && argc != 2) { ErrorMessage(1); return 1; }     
  if ((std::string)argv[1] == "--help" || (std::string)argv[1] == "-h")
    if (argv[2] == NULL) {
      ErrorMessage(2);
      return 1;
    }
  if (argv[2] == NULL) { ErrorMessage(1); return 1; }
  if (((std::string)argv[1] != "input.txt") || 
      ((std::string)argv[2] != "output.txt")) {
    ErrorMessage(3);
    return 1;
  }
  std::vector<FibonacciWord> list = CreateVector();
  
  for (unsigned iterator = 0; iterator < list.size(); iterator++)
    list[iterator].FibonacciCheck(list[0].get_word(), list[1].get_word());
  WriteOnFile(list);

  return 0;
}