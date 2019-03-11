file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${arithmetictest} ${srcs} ${hdrs})
target_link_libraries(${arithmetictest} ${arithmeticlib} gtest)
