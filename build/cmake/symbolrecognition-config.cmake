# symbolrecognition CMake config file
#
# This file sets the following variables:
# symbolrecognition_FOUND - Always TRUE.
# symbolrecognition_INCLUDE_DIRS - Directories containing the symbolrecognition include files.
# symbolrecognition_IDL_DIRS - Directories containing the symbolrecognition IDL files.
# symbolrecognition_LIBRARIES - Libraries needed to use symbolrecognition.
# symbolrecognition_DEFINITIONS - Compiler flags for symbolrecognition.
# symbolrecognition_VERSION - The version of symbolrecognition found.
# symbolrecognition_VERSION_MAJOR - The major version of symbolrecognition found.
# symbolrecognition_VERSION_MINOR - The minor version of symbolrecognition found.
# symbolrecognition_VERSION_REVISION - The revision version of symbolrecognition found.
# symbolrecognition_VERSION_CANDIDATE - The candidate version of symbolrecognition found.

message(STATUS "Found symbolrecognition-1.0.0")
set(symbolrecognition_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(symbolrecognition_INCLUDE_DIRS
#    "C:/Program Files (x86)/symbolrecognition/include/symbolrecognition-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(symbolrecognition_IDL_DIRS
#    "C:/Program Files (x86)/symbolrecognition/include/symbolrecognition-1/idl")
set(symbolrecognition_INCLUDE_DIRS
    "C:/Program Files (x86)/symbolrecognition/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(symbolrecognition_IDL_DIRS
    "C:/Program Files (x86)/symbolrecognition/include//idl")


if(WIN32)
    set(symbolrecognition_LIBRARIES
        "C:/Program Files (x86)/symbolrecognition/components/lib/symbolrecognition.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(symbolrecognition_LIBRARIES
        "C:/Program Files (x86)/symbolrecognition/components/lib/symbolrecognition.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(symbolrecognition_DEFINITIONS ${<dependency>_DEFINITIONS})

set(symbolrecognition_VERSION 1.0.0)
set(symbolrecognition_VERSION_MAJOR 1)
set(symbolrecognition_VERSION_MINOR 0)
set(symbolrecognition_VERSION_REVISION 0)
set(symbolrecognition_VERSION_CANDIDATE )

