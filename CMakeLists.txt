cmake_minimum_required( VERSION 3.0 )

project( "dr_calculator_dbg" )

add_executable( ${PROJECT_NAME} "dr_calculator/main.cpp" )

target_include_directories( ${PROJECT_NAME} PUBLIC "include" )

target_compile_features( ${PROJECT_NAME} PUBLIC cxx_std_20 )

#Install tone_4416.wav to the same dir as the binary
install( FILES "tone_4416.wav" DESTINATION ${CMAKE_BINARY_DIR} )