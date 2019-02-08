// Permutation Generation Alorithms
// Implemented by : Amirabbas Asadi
#include <iostream>
// Interface for Permutation Generator Alorithms
template <typename T> class PermutationGenerator {
public:
  // Set Elements Array For Generating Permutations
  void setArray(T *elements, size_t size) {
    this->elements = new T[size];
    // copy elements
    for (int i = 0; i < size; i++)
      this->elements[i] = elements[i];
    this->size = size;
  }
  // generate permutation and print them
  virtual void generatePermutation() = 0;

protected:
  // swap two array elements
  void swap(T& a, T& b){
      T temp = a;
      a = b;
      b = temp;
  }
  // proccess which will be applied on each permutation
  void process() {
    // print permutation
    for (int i = 0; i < size; i++)
      std::cout << elements[i] << " ";
    std::cout << std::endl;
  }
  // array of elements
  T *elements;
  // number of elements
  size_t size;
};
