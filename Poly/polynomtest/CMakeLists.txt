file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${polynomtest} ${srcs} ${hdrs})
target_link_libraries(${polynomtest} ${polynomlib} gtest)
