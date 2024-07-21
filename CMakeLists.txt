# VARIABLE GLOSSARY
# Boost_NO_BOOST_CMAKE - Disables the search for BoostConfig.cmake that is installed by boost as a cmake package configuration.


cmake_minimum_required( VERSION 3.0 )


# debug variant by default - can be altered with $CMAKE_BUILD_TYPE
project( "dr_calculator_dbg" )


add_executable( ${PROJECT_NAME} "dr_calculator/main.cpp" )


include( FetchContent )
FetchContent_Declare(
    BOOST_1.81.0
    URL https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.tar.gz
    URL_HASH SHA256=205666dea9f6a7cfed87c7a6dfbeb52a2c1b9de55712c9c1a87735d7181452b6
    DOWNLOAD_EXTRACT_TIMESTAMP true )


FetchContent_MakeAvailable( BOOST_1.81.0 )


set( Boost_NO_SYSTEM_PATHS ON )  # only look in the user-specified location - nowhere else!

set( Boost_NO_BOOST_CMAKE ON )
set( BOOST_ROOT _deps/boost_1.81.0-src )
find_package( Boost 1.81 )

if ( Boost_FOUND )
    message( STATUS "BOOST FOUND: ${Boost_INCLUDE_DIRS}" )
else()
    message( STATUS "BOOST NOT FOUND" )
endif()


target_include_directories( ${PROJECT_NAME} PUBLIC "include" )

target_compile_features( ${PROJECT_NAME} PUBLIC cxx_std_20 )

#Install tone_4416.wav to the same dir as the binary
#Can be executed as separate 'install' step
#install( FILES "tone_4416.wav" DESTINATION ${CMAKE_BINARY_DIR} )

# This should take care of the copy in a 'post-build' stage
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${CMAKE_CURRENT_SOURCE_DIR}/tone_4416.wav
                    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)


# note: to specify a library to link in your exe
# target_link_directories( <exe name> PRIVATE ${CMAKE_SOURCE_DIR}/path )
# target_link_libraries( <exe name> <library_name> )
# where library name is w/o 'lib' prefix and .a suffix
