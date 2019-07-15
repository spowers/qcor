include_directories(${CMAKE_SOURCE_DIR}/ir/transformation/NoiseAware)

add_xacc_test(NoiseAwareTransformation)
target_link_libraries(NoiseAwareTransformationTester qcor-noiseaware-transformation qcor)
~
