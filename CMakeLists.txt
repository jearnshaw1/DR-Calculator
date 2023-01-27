cmake_minimum_required( VERSION 3.0 )

project( "dr_calculator_dbg" )

add_executable( ${PROJECT_NAME} "dr_calculator/main.cpp" )

target_include_directories( ${PROJECT_NAME} PUBLIC "include" )

target_compile_features( ${PROJECT_NAME} PUBLIC cxx_std_20 )

#Install tone_4416.wav to the same dir as the binary
#Has to be executed as separate 'install' step
#install( FILES "tone_4416.wav" DESTINATION ${CMAKE_BINARY_DIR} )

# This should take care of the copy in a 'post-build' stage
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       ${CMAKE_CURRENT_SOURCE_DIR}/tone_4416.wav
                       $<TARGET_FILE_DIR:${PROJECT_NAME}>
                   )