file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${stack_test} ${srcs} ${hdrs})
target_link_libraries(${stack_test} ${stack_lib} gtest)