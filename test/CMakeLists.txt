set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
target_link_libraries(main ${PROJECT_NAME})

add_executable(algo_test algo_test.cpp)
target_link_libraries(algo_test ${PROJECT_NAME})

add_executable(algo_test_onng algo_test_onng.cpp)
target_link_libraries(algo_test_onng ${PROJECT_NAME})