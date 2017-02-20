add_library(func libone.cpp)
# 'targets' 'files' 'destinations' must be written in capital case
install(TARGETS func DESTINATION ~/tmp)
install(FILES libone.h DESTINATION ~/tmp)