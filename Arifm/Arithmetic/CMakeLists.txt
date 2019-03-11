file(GLOB hdrs "*.h*") #Äîáàâëÿåì â ïåğåìåííóş hdrs âñå ôàéëû ñ ğàñøèğåíèåì .h
file(GLOB srcs "*.cpp")#Äîáàâëÿåì â ïåğåìåííóş srcs âñå ôàéëû ñ ğàñøèğåíèåì .h

add_executable(${Arithmetic} ${srcs} ${hdrs})
target_link_libraries(${Arithmetic})
