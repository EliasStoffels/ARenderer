set(SHADER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/shaders)
set(SHADER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/assets/shaders)
set(VULKAN_VERSION 1.4.357.0)

file(GLOB SHADER_FILES CONFIGURE_DEPENDS 
    ${SHADER_SOURCE_DIR}/*.vert
    ${SHADER_SOURCE_DIR}/*.frag
    ${SHADER_SOURCE_DIR}/*.comp
    ${SHADER_SOURCE_DIR}/*.geom
    ${SHADER_SOURCE_DIR}/*.tesc
    ${SHADER_SOURCE_DIR}/*.tese
)

set(SPIRV_FILES "")

foreach(shader ${SHADER_FILES})
    get_filename_component(fileName ${shader} NAME)
    set(spv ${SHADER_BINARY_DIR}/${fileName}.spv)
    add_custom_command(
        OUTPUT ${spv}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${SHADER_BINARY_DIR}
        COMMAND C:/VulkanSDK/${VULKAN_VERSION}/Bin/glslc.exe
                ${shader}
                -o ${spv}
        DEPENDS ${shader}
        COMMENT "Compiling shader ${fileName}"
        VERBATIM
    )

    list(APPEND SPIRV_FILES ${spv})
endforeach()


add_custom_target(CompileShaders
    DEPENDS ${SPIRV_FILES}
)