// Permutation Generation Alorithms
// Implemented by : Amirabbas Asadi
#include "PermutationGenerator.h"
// Algorithm 1
template <typename T> class Algorithm1: public PermutationGenerator<char>{
public:
    void generatePermutation(){
        // call recursive permutation generator
        permutationUtil(0);
    }
protected:
    void permutationUtil(size_t index){
        if(index==size-1){
            process();
            return;
        }
        for(int i=index; i<size; i++){
            swap(elements[index], elements[i]);
            permutationUtil(index+1);
            swap(elements[index], elements[i]);
        }
    }
};
