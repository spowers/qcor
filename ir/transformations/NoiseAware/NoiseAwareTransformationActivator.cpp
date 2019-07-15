#include "NoiseAwareTransformation.hpp"

#include "cppmicroservices/BundleActivator.h"
#include "cppmicroservices/BundleContext.h"
#include "cppmicroservices/ServiceProperties.h"

#include <memory>
#include <set>

using namespace cppmicroservices;

namespace {

class US_ABI_LOCAL NoiseAwareTransformationActivator : public BundleActivator {

  public:
    NoiseAwareTransformationActivator() {}

    void Start(BundleContext context) {
      auto c = std::make_shared<qcor::transformations::NoiseAwareTransform>();
      context.RegisterService<xacc::IRTransformation>(c);
    }

    void Stop(BundleContext /*context*/) {}
};

} //namespace

CPPMICROSERVICES_EXPORT_BUNDLE_ACTIVATOR(NoiseAwareTransformationActivator)
