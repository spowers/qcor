#include "NoiseAwareTransformation.hpp"

#include <iostream>

namespace qcor {
  namespace transformations {

    std::shared_ptr<IR> NoiseAwareTransform::transform(std::shared_ptr<IR> ir) {
    
      //TODO: expand to handle more than 1 function
      auto function = ir->getKernels()[0];

      //check that there is a kernel
      //if (!kernelExists(ir->getKernels())) return;

      //do stuff with that function

      //check that the function is not null
      if (function == nullptr) return NULL;

      //iterate to get instructions in the function
      for (int i = 0; i < function->nInstructions(); i++) {
        auto inst = function->getInstruction(i);

        //get index of qubit involved -vector<int>
        auto bitIdx = inst->bits();

        //increase index by 1
        for (int j = 0; j < bitIdx.size(); j++) {
          bitIdx[j]++;
        }

        //set the new bits
        inst->setBits(bitIdx);
      }

      return ir;
    }
  } //namespace transformations
} //namespace qcor
