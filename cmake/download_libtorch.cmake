# Скачивает libtorch заданной версии, ничего не делает, если он уже скачан
# На вход - имя файла с содержимым формата:
# <url>
# <version>
# Пример:
# url = https://download.pytorch.org/libtorch/nightly/libtorch-shared-without-deps-1.2.0.dev20190731%2Bcpu.zip
# version = 1.2.0.dev20190731+cpu , содержимое libtorch/build-version
function(download_libtorch FILENAME)
    FILE(STRINGS ${FILENAME} URL_VERSION)
    IF(UNIX AND NOT APPLE)
        LIST(GET URL_VERSION 0 URL)
        LIST(GET URL_VERSION 2 VERSION)
    ENDIF()
    IF (APPLE)
        LIST(GET URL_VERSION 1 URL)
        LIST(GET URL_VERSION 3 VERSION)
    ENDIF()
    IF (NOT UNIX)
        MESSAGE(FATAL_ERROR "Only linux or macos is supported!")
    ENDIF()

    SET(NEED_DOWNLOAD TRUE)
    SET(LIBTORCH_PATH ${CMAKE_SOURCE_DIR}/third-party/libtorch)
    IF(EXISTS ${LIBTORCH_PATH})
        IF(EXISTS ${LIBTORCH_PATH}/build-version)
            FILE(STRINGS ${LIBTORCH_PATH}/build-version CURR_VERSION)
            IF (${VERSION} STREQUAL ${CURR_VERSION})
                SET(NEED_DOWNLOAD FALSE)
            ENDIF()
        ENDIF()
    ENDIF()

    IF (NEED_DOWNLOAD)
        FILE(REMOVE_RECURSE ${LIBTORCH_PATH})

        SET(LIBTORCH_ARCH ${CMAKE_BINARY_DIR}/libtorch.zip)
        message("Downloading libtorch" ${VERSION} "...")
        execute_process(COMMAND "wget" ${URL} -O ${LIBTORCH_ARCH} -o ${LIBTORCH_ARCH}.download.log)
        message("Extracting libtorch ...")
        execute_process(COMMAND "unzip" -d ${CMAKE_SOURCE_DIR}/third-party ${LIBTORCH_ARCH})
    ENDIF()
endfunction(download_libtorch)
