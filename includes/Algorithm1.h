// Permutation Generation Alorithms
// Implemented by : Amirabbas Asadi
#include "PermutationGenerator.h"
// Algorithm 1
template <typename T> class Algorithm1: public PermutationGenerator<char>{
public:
    void generatePermutation(){
        // call recursive permutation generator
        std::cout << "size : " << size << "\n";
        permutationUtil(0);
    }
protected:
    void permutationUtil(int index){
        if(index == size){
            process();
            return;
        }
        for(int i=index; i<size; i++){
            swap(elements[i], elements[index]);
            permutationUtil(index+1);
            swap(elements[i], elements[index]);
        }
    }
};
