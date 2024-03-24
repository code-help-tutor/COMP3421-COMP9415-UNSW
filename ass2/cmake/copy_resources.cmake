function(copy_resources RES_PATH DEST_PATH)
    file(GLOB_RECURSE res_list RELATIVE ${RES_PATH} CONFIGURE_DEPENDS ${RES_PATH}/*)

    foreach(res ${res_list})
        configure_file(${RES_PATH}/${res} "${DEST_PATH}/${res}" COPYONLY)
    endforeach()
endfunction()
