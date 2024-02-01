cmake_minimum_required(VERSION 3.0)
project(interview_prep)

add_executable(rvaluesref coreFeatures/rvaluesref.cpp)

add_executable(move coreFeatures/move.cpp)

add_executable(sharedPtr coreFeatures/sharedPtr.cpp)

add_executable(uniquePtr coreFeatures/uniquePtr.cpp)

add_executable(test coreFeatures/test.cpp)

add_executable(singleton designPatterns/singleton.cpp)

add_executable(factory designPatterns/factory.cpp)
