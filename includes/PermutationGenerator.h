// Permutation Generation Alorithms
// Implemented by : Amirabbas Asadi
#include <iostream>
#include <random>
#include <ctime>
// random engine
std::default_random_engine engine(static_cast<unsigned int>(std::time(0)));
// Interface for Permutation Generator Alorithms
template <typename T> class PermutationGenerator {
public:
  // Set Elements Array For Generating Permutations
  void setArray(T *elements, int size) {
    this->elements = new T[size];
    // copy elements
    for (int i = 0; i < size; i++)
      this->elements[i] = elements[i];
    this->size = size;
  }
  // shuffle the array
  void shuffleArray(){
      for(int i=size-1; i>=1; i--){
          // set dist param
          dist = std::uniform_int_distribution<int>(0, i);
          int j = dist(engine);
          swap(elements[i], elements[j]);
      }
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
  int size;
  // uniform distriution used to generate random
  std::uniform_int_distribution<int> dist;
};
