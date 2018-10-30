#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "symbolrecognition" for configuration "Debug"
set_property(TARGET symbolrecognition APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(symbolrecognition PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/components/lib/symbolrecognition.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "RTC112_vc14d;coil112_vc14d;omniORB421_rtd;omniDynamic421_rtd;omnithread40_rtd;advapi32;ws2_32;mswsock"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/components/bin/symbolrecognition.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS symbolrecognition )
list(APPEND _IMPORT_CHECK_FILES_FOR_symbolrecognition "${_IMPORT_PREFIX}/components/lib/symbolrecognition.lib" "${_IMPORT_PREFIX}/components/bin/symbolrecognition.dll" )

# Import target "symbolrecognitionComp" for configuration "Debug"
set_property(TARGET symbolrecognitionComp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(symbolrecognitionComp PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/components/bin/symbolrecognitionComp.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS symbolrecognitionComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_symbolrecognitionComp "${_IMPORT_PREFIX}/components/bin/symbolrecognitionComp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
