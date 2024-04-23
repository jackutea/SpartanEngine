set "buildType=%1"
set "dll_raylib=.\lib\raylib.dll"

@REM User
prebuild g++ .cpp ./src/User ./build

@REM Engine
prebuild g++ .cpp ./src/Engine ./build

@REM Editor
if "%buildType%" neq "--runtime" (
    prebuild g++ .cpp ./src/Editor ./build
)

@REM Main
g++ .\src\main.cpp -c -o .\build\main.o

@REM Link
g++ .\build\*.o %dll_raylib% -o .\bin\game

copy %dll_raylib% .\bin

xcopy .\assets .\bin\assets /E /I /Y /Q
@echo on
@echo Copied assets directory to bin
@echo off