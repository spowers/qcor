#ifndef QCOR_IR_TRANSFORM_NOISE_HPP_
#define QCOR_IF_TRANSFORM_NOISE_HPP_

#include "IRTransformation.hpp"

using namespace xacc;

namespace qcor {
namespace transformations {
  class NoiseAwareTransform : public IRTransformation {
    public:
      std::shared_ptr<IR> transform(std::shared_ptr<IR> ir) override;

      const std::string name() const override {return "NoiseAware"; }

      const std::string description() const override {return ""; }


  };
}
}

#endif