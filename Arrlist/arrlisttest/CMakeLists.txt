file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${arrlisttest} ${srcs} ${hdrs})
target_link_libraries(${arrlisttest} ${arrlistlib} gtest)
