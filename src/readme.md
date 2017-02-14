
include_directories(/path/to/your/dlib)
link_directories(/path/to/your/libdlib.so)
add_executable(xxx main.cpp)
target_link_libraries(xxx dlib)

