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
#include <string>
#include <vector>
#include <fstream>

#include "fibonacci_word.h"


// Show error messages in terminal
void error_message(int error) {
  if (error == 1) {
    std::cerr << "Invalid arguments to function.\n" 
              << "Write ./fibonacci_words --help for more info\n";
  } else if (error == 2) {
    std::cerr << "Usage: ./fibonacci_word input.txt output.txt" 
              << "\nFor OPTION:\n" 
              << "\t-h,--help\t\tShow this help message\n";
  } else if (error == 3) {
    std::cerr << "Invalid file names.\n" 
              << "Write ./fibonacci_words --help for more info\n";
  } else if (error == 4) {
    std::cerr << "Error opening the file.\n" 
              << "Write ./fibonacci_words --help for more info\n";
  }
}

// Read from file and introduce the data in a vector 
std::vector<FibonacciWord> create_vector() {
  std::ifstream reader("input.txt");
  if (!reader) {       
    std::cerr << "Error: file could not be opened" << "\n";
    exit(1);
  }
  std::string data;
  std::vector<FibonacciWord> list;
  while (!reader.eof()) { 
    reader >> data;
    FibonacciWord block(data, data.length());
    list.push_back(block);
  }
  reader.close();
  return list;
}

// Write the sequence in a file
void WriteOnFile(std::vector<FibonacciWord> list) {
  std::ofstream writer("output.txt");
  if (!writer) {       
    std::cerr << "Error: file could not be opened" << "\n";
    exit(1);
  }
  for (unsigned iterator = 0; iterator < list.size(); iterator++) 
    writer << list[iterator];
  writer.close();
}

// Class FibbonacciWord constructor 
FibonacciWord::FibonacciWord(std::string word, unsigned size): 
word_(word), size_(size), is_a_fibonacci_word_(false),
word_number_(0) {}

// Default destructor
FibonacciWord::~FibonacciWord() {}

// Getters
std::string FibonacciWord::get_word() const { return word_; }
unsigned FibonacciWord::get_size() const { return size_; }
bool FibonacciWord::get_is_a_fibonacci_word() const { return is_a_fibonacci_word_; }
unsigned FibonacciWord::get_word_number() const { return word_number_; }

// Setters
void FibonacciWord::set_word(std::string new_word) { word_ = new_word; }
void FibonacciWord::set_size(unsigned new_size) { size_ = new_size; }
void FibonacciWord::set_is_a_fibonacci_word(bool new_state) { 
  is_a_fibonacci_word_ = new_state; 
}

// Search between actual Fibonacci words and return the position
int FibonacciWord::FibonacciSearch() const {
  if (word_ == "a") {
    return 1;
  } else if (word_ == "b") {
    return 2;
  } 
  std::string first_position = "a";
  std::string second_position = "b";
  unsigned counter = 3;
  std::string aux_position = first_position + second_position;
  while (aux_position.length() < size_) {
    first_position = second_position;
    second_position = aux_position;
    aux_position = first_position + second_position;
    counter++;
  }
  if (word_ == aux_position) {
    return counter;
  }
  return - 1;
}

/// Check if the attribute "word_" belongs to the Fibonacci sequence
void FibonacciWord::FibonacciCheck() { 
  const int kPosition = FibonacciSearch();
  if (kPosition > 0) {
    is_a_fibonacci_word_ = true;
    word_number_ = kPosition;
  } 
}

// Write using an ostream as a parameter
std::ostream& FibonacciWord::Write(std::ostream& os) const{ 
  if (is_a_fibonacci_word_) {
    return os << word_ << " is the word number " << word_number_ << "\n";
  } else {
    return os << word_ << " is not a Fibonacci word\n";
  }
}

// Friend function is used to operate with "<<"
std::ostream& operator<<(std::ostream& os, const FibonacciWord sequence) {
  sequence.Write(os);
  return os;
}
