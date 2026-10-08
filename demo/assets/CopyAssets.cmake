add_custom_target(CopyAssets SOURCES ${CMAKE_CURRENT_LIST_DIR})

message("Copying assets folder")
file(COPY ${CMAKE_CURRENT_LIST_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
