#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "symbolrecognition" for configuration "Release"
set_property(TARGET symbolrecognition APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(symbolrecognition PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/components/lib/symbolrecognition.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "RTC112_vc14;coil112_vc14;omniORB421_rt;omniDynamic421_rt;omnithread40_rt;advapi32;ws2_32;mswsock"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/components/bin/symbolrecognition.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS symbolrecognition )
list(APPEND _IMPORT_CHECK_FILES_FOR_symbolrecognition "${_IMPORT_PREFIX}/components/lib/symbolrecognition.lib" "${_IMPORT_PREFIX}/components/bin/symbolrecognition.dll" )

# Import target "symbolrecognitionComp" for configuration "Release"
set_property(TARGET symbolrecognitionComp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(symbolrecognitionComp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/components/bin/symbolrecognitionComp.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS symbolrecognitionComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_symbolrecognitionComp "${_IMPORT_PREFIX}/components/bin/symbolrecognitionComp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
