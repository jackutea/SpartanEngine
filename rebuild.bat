cmake -D CMAKE_BUILD_TYPE:STRING=Debug -D CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -D CMAKE_C_COMPILER:FILEPATH=C:\mingw\bin\gcc.exe -D CMAKE_CXX_COMPILER:FILEPATH=C:\mingw\bin\g++.exe --no-warn-unused-cli -S D:/SpartanEngine/src -B d:/SpartanEngine/build -G "MinGW Makefiles"
cmake --build ./build