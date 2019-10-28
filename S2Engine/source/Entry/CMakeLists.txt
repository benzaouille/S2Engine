INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/S2Engine/include/)

FILE(GLOB_RECURSE ENTRY_SOURCE *.cpp *.c)

ADD_EXECUTABLE(S2Engine ${ENTRY_SOURCE} ${ManagerFileCpp} ${ManagerFileH} ${SingletonH} ${LoggerFileH} ${LoggerFileCpp} ${MemoryFileCpp}
                        ${MemoryFileH})
