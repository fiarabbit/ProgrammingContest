cmake_minimum_required(VERSION 3.6)

file(GLOB subdirs *)
foreach (subdir ${subdirs})
    get_filename_component(stem ${subdir} NAME)
    if (IS_DIRECTORY ${subdir} AND NOT ${stem} MATCHES cmake-.*|CMakeFiles.*|.idea)
        message(STATUS ${subdir})
        add_subdirectory(${subdir})
    endif (IS_DIRECTORY ${subdir} AND NOT ${stem} MATCHES cmake-.*|CMakeFiles.*|.idea)
endforeach (subdir)
