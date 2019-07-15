#include <gtest/gtest.h>

#include "NoiseAwareTransformation.hpp"
#include "XACC.hpp"
#include "qcor.hpp"
#include "xacc_service.hpp"
#include "DigitalGates.hpp"

using namespace qcor;
using namespace qcor::transformations;

//first way
const std::string uccsdSrc = R"uccsdSrc(def foo():
  H(0)
  CNOT(0,1)
  )uccsdSrc";

TEST(NoiseAwareTransformationTester, checkSimple) {
  if (xacc::hasCompiler("xacc-py")) {
    auto c = xacc::getService<xacc::Compiler>("xacc-py");
    auto f = c->compile("def foo(buffer):\n H(0)\n CNOT(0,1)\n")->getKernels()[0];
    auto ir = std::make_shared<GateIR>();
    ir->addKernel(f);

    NoiseAwareTransform nat;
    auto newir = nat.transform(ir);
    auto natF = newir->getKernels()[0];

    EXPECT_EQ(2, natF->nInstructions());

    EXPECT_EQ(std::vector<int>{1}, natF->getInstruction(0)->bits());
    EXPECT_EQ(std::vector<int>{0,1}, natF->getInstruction(1)->bits());

  }
}

int main(int argc, char **argv) {
  qcor::Initialize(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  auto ret = RUN_ALL_TESTS();
  return ret;
}