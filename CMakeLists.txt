project(S2Engine)
cmake_minimum_required(VERSION 3.1)

#Setting
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

######MANAGER######
set(ManagerFileCpp
    ${CMAKE_SOURCE_DIR}/S2Engine/source/Manager/EnvironmentManager.cpp
    ${CMAKE_SOURCE_DIR}/S2Engine/source/Manager/LoggerManager.cpp
    ${CMAKE_SOURCE_DIR}/S2Engine/source/Manager/MemoryManager.cpp
)

set(ManagerFileH
    ${CMAKE_SOURCE_DIR}/S2Engine/include/Manager/EnvironmentManager.h
    ${CMAKE_SOURCE_DIR}/S2Engine/include/Manager/MemoryManager.h
)
##################


######CORE######
set(CoreFileH
    ${CMAKE_SOURCE_DIR}/S2Engine/include/Core/Singleton.h
)
##################

######LOGGER######
set(LoggerFileH
    ${CMAKE_SOURCE_DIR}/S2Engine/include/Logger/Logger.h
    ${CMAKE_SOURCE_DIR}/S2Engine/include/Logger/FileLog.h
)

set(LoggerFileCpp
    ${CMAKE_SOURCE_DIR}/S2Engine/source/Logger/Logger.cpp
    ${CMAKE_SOURCE_DIR}/S2Engine/source/Logger/FileLog.cpp
)
##################


######MEMORY######
set(MemoryFileH
    ${CMAKE_SOURCE_DIR}/S2Engine/include/Memory/Memory.h
    ${CMAKE_SOURCE_DIR}/S2Engine/include/Memory/StackAllocator.h
)

set(MemoryFileCpp
    ${CMAKE_SOURCE_DIR}/S2Engine/source/Memory/Memory.cpp
    ${CMAKE_SOURCE_DIR}/S2Engine/source/Memory/StackAllocator.cpp
)
##################



#INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/S2Engine/include/)

#adding_Other_CMakeLists.txt
ADD_SUBDIRECTORY(S2Engine/source/Entry)
