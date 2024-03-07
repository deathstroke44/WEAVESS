set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
target_link_libraries(main ${PROJECT_NAME})

add_executable(algo_test algo_test.cpp)
target_link_libraries(algo_test ${PROJECT_NAME})

add_executable(algo_test_efanna algo_test_efanna.cpp)
target_link_libraries(algo_test_efanna ${PROJECT_NAME})

add_executable(algo_test_dpg algo_test_dpg.cpp)
target_link_libraries(algo_test_dpg ${PROJECT_NAME})