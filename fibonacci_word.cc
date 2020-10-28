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


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "fibonacci_word.h"


// Show error messages in terminal
void ErrorMessage(const int kError) {
  if (kError == 1) {
    std::cerr << "Invalid arguments to function.\n" 
              << "Write ./fibonacci_words --help for more info\n";
  } else if (kError == 2) {
    std::cerr << "Usage: ./fibonacci_word input.txt output.txt" 
              << "\nFor OPTION:\n" 
              << "\t-h,--help\t\tShow this help message\n";
  } else if (kError == 3) {
    std::cerr << "Invalid file names.\n" 
              << "Write ./fibonacci_words --help for more info\n";
  }
}

// Read from file and introduce the data in a vector 
std::vector<FibonacciWord> CreateVector() {
  std::ifstream reader("input.txt");
  if (!reader) {       
    std::cerr << "Error: file could not be opened\n";
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
void WriteOnFile(const std::vector<FibonacciWord> kList) {
  std::ofstream writer("output.txt");
  if (!writer) {       
    std::cerr << "Error: file could not be opened\n";
    exit(1);
  }
  for (unsigned iterator = 0; iterator < kList.size(); iterator++) 
    writer << kList[iterator];
  writer.close();
}

// Class FibbonacciWord constructor 
FibonacciWord::FibonacciWord(const std::string kWord, const unsigned kSize): 
word_(kWord), size_(kSize), is_a_fibonacci_word_(false),
word_number_(0) {}

// Default destructor
FibonacciWord::~FibonacciWord() {}

// Getters
std::string FibonacciWord::get_word() const { return word_; }
unsigned FibonacciWord::get_size() const { return size_; }
bool FibonacciWord::get_is_a_fibonacci_word() const { 
  return is_a_fibonacci_word_; 
}
unsigned FibonacciWord::get_word_number() const { return word_number_; }

// Setters
void FibonacciWord::set_word(const std::string kNewWord) { word_ = kNewWord; }
void FibonacciWord::set_size(const unsigned kNewSize) { size_ = kNewSize; }
void FibonacciWord::set_is_a_fibonacci_word(const bool kNewState) { 
  is_a_fibonacci_word_ = kNewState; 
}
void FibonacciWord::set_word_number(const unsigned kNewNumber) { 
  word_number_ = kNewNumber; 
}

// Search between actual Fibonacci words and return the position
int FibonacciWord::FibonacciSearch(const std::string kFiboRoot1, 
                                   const std::string kFiboRoot2) const {
  if (word_ == kFiboRoot1) {
    return 1;
  } else if (word_ == kFiboRoot2) {
    return 2;
  } 
  std::string first_position = kFiboRoot1;
  std::string second_position = kFiboRoot2;
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
  return - 1;  ///< Position was not found
}

/// Check if the attribute "word_" belongs to the Fibonacci sequence
void FibonacciWord::FibonacciCheck(const std::string kFiboRoot1, 
                                   const std::string kFiboRoot2) { 
  const int kPosition = FibonacciSearch(kFiboRoot1, kFiboRoot2);
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
