file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${stacktest} ${srcs} ${hdrs})
target_link_libraries(${stacktest} ${stacklib} gtest)
