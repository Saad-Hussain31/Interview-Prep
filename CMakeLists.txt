cmake_minimum_required(VERSION 3.0)
project(interview_prep)

add_executable(rvaluesref coreFeatures/rvaluesref.cpp)

add_executable(move coreFeatures/move.cpp)

add_executable(sharedPtr coreFeatures/sharedPtr.cpp)

add_executable(uniquePtr coreFeatures/uniquePtr.cpp)

add_executable(test coreFeatures/test.cpp)

add_executable(copies coreFeatures/copies.cpp)

add_executable(condition_variable concurrency/condition_variable.cpp)
target_link_libraries(condition_variable pthread)

add_executable(avoiding_copies coreFeatures/avoiding_copies.cpp)

add_executable(operator_overloading coreFeatures/operator_overloading.cpp)

add_executable(templates coreFeatures/templates.cpp)

add_executable(raii coreFeatures/raii.cpp)

add_executable(varidic_function_templates coreFeatures/variadic_function_templates.cpp)

add_executable(lambdas coreFeatures/lambdas.cpp)

add_executable(Static coreFeatures/Static.cpp)

add_executable(singleton designPatterns/singleton.cpp)

add_executable(factory designPatterns/factory.cpp)

add_executable(array stl/array.cpp)

add_executable(vector stl/vector.cpp)

add_executable(set stl/set.cpp)

add_executable(map stl/map.cpp)

add_executable(iterator exceptional_cpp/iterator.cpp)

add_executable(ci_string exceptional_cpp/ci_string.cpp)

add_executable(reusable_generic_containers exceptional_cpp/reusable_generic_containers.cpp)

add_executable(temporary_objects exceptional_cpp/temporary_objects.cpp)

add_executable(Stack exceptional_cpp/ExceptionSafetyTechniques/Stack.cpp)

add_executable(two_sum leetcode/hashing/two_sum.cpp)

add_executable(top_k_elems leetcode/hashing/top_k_elems.cpp)

add_executable(ProdArrayExceptSelf leetcode/arrays/ProdArrayExceptSelf.cpp)

add_executable(EncodeDecodeString leetcode/arrays/EncodeDecodeString.cpp)

add_executable(LongConsecSeq leetcode/arrays/LongConsecSeq.cpp)

add_executable(ValidPalindrome leetcode/TwoPointers/ValidPalindrome.cpp)
