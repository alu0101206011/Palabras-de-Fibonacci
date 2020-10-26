/////////////////////////////////////////////////////////////////////
/// @class FibonacciWord
///
/// @brief This class compares the attribute "word_" with a real Fibonacci Word
/// to verify if it is. Once verified, the class can also provide more information about the word.
///
/// @example word_ == actualFibonacciWord ? (Save information) : (reject this word)
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @version Version 2: class with string of file
/// @date 23/10/2020
/////////////////////////////////////////////////////////////////////

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
    FibonacciWord(std::string, unsigned);

    /// A destructor.
    /// @brief Default destructor
    ~FibonacciWord(void);

    /// The getters.
    /// @brief Helps access the attributes
    std::string get_word(void) const;
    unsigned get_size(void) const;
    bool get_is_a_fibonacci_word(void) const;
    unsigned get_word_number(void) const;

    /// The setters.
    /// @brief Replace the old attribute with a new one
    void set_word(std::string);
    void set_size(unsigned);
    void set_is_a_fibonacci_word(bool);
    void set_word_number(unsigned);

    /// @brief Verify if the attribute word is an actual Fibonacci Word
    void FibonacciCheck(void);

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
    /// @return Position
    int FibonacciSearch(void) const;
}; 

#endif  // FIBONACCIWORD_H


/// @brief Show error messages in terminal
/// @param error
void error_message(int); 

/// @brief Create a vector and reads it from a file
/// @return list
std::vector<FibonacciWord> create_vector(void);

/// @brief Write from a vector using the friend function "<<"
/// @param list
void WriteOnFile(std::vector<FibonacciWord>); 