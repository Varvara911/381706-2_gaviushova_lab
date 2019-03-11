file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${matrixtest} ${srcs} ${hdrs})
target_link_libraries(${matrixtest} ${matrixtlib} gtest)
