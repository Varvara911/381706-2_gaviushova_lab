file(GLOB hdrs "*.h*") #Äîáàâëÿåì â ïåğåìåííóş hdrs âñå ôàéëû ñ ğàñøèğåíèåì .h
file(GLOB srcs "*.cpp")#Äîáàâëÿåì â ïåğåìåííóş srcs âñå ôàéëû ñ ğàñøèğåíèåì .h

add_executable(${stack_and_queue} ${srcs} ${hdrs})
target_link_libraries(${stack_and_queue})
