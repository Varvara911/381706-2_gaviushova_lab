file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${listtest} ${srcs} ${hdrs})
target_link_libraries(${listtest} ${listlib} gtest)
