///
/// @class FibonacciWord
///
/// @brief This class compares the attribute "word_" with a real Fibonacci Word
/// to verify if it is. Once verified, the class can also provide more 
/// information about the word.
///
/// @example word_ == actualFibonacciWord ? (Save information) : (reject this word)
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @version Version 2: class with string of file
/// @date 27 Oct 2020
///

#ifndef FIBONACCIWORD_H
#define FIBONACCIWORD_H

class FibonacciWord {
  private:
    std::string word_;
    unsigned size_;
    bool is_a_fibonacci_word_;
    unsigned word_number_;

  public:

    /// A constructor.
    /// @brief Initialize all attributes using the following parameters
    /// @param word 
    /// @param size 
    FibonacciWord(const std::string, const unsigned);

    /// A destructor.
    /// @brief Default destructor
    ~FibonacciWord(void);

    /// Getters.
    /// @brief Helps access the attributes
    std::string get_word(void) const;
    unsigned get_size(void) const;
    bool get_is_a_fibonacci_word(void) const;
    unsigned get_word_number(void) const;

    /// Setters.
    /// @brief Replace the old attribute with a new one
    void set_word(const std::string);
    void set_size(const unsigned);
    void set_is_a_fibonacci_word(const bool);
    void set_word_number(const unsigned);

    /// @brief Verify if the attribute word is an actual Fibonacci Word
    /// @param kFiboRoot1
    /// @param kFiboRoot2
    void FibonacciCheck(const char*, const char*);

    /// @brief Write using an ostream as a parameter
    /// @param os
    /// @return os
    std::ostream& Write(std::ostream&) const;

    /// @brief Friend function is used to operate with "<<"
    /// @param os
    /// @param sequence
    /// @see Write()
    /// @return os
    friend std::ostream& operator<<(std::ostream&, const FibonacciWord);

  private:

    /// @brief Search between actual Fibonacci words and return the position
    /// @param kFiboRoot1
    /// @param kFiboRoot2
    /// @return Position
    int FibonacciSearch(const char*, const char*) const;
}; 

/// @brief Show error messages in terminal
/// @param error
void ErrorMessage(const int); 

/// @brief Create a vector and reads it from a file
/// @return list
std::vector<FibonacciWord> CreateVector(void);

/// @brief Write from a vector using the friend function "<<"
/// @param list
void WriteOnFile(std::vector<FibonacciWord>); 

#endif  // FIBONACCIWORD_H