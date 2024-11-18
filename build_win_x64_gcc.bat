set "buildType=%1"
set "dll_raylib=.\lib\raylib.dll"
set "link_editor="
set "prebuild=.\BuildTools\Prebuild\prebuild.exe"

@REM Delete old build
if exist build rmdir /s /q build
if not exist bin mkdir bin
if not exist build mkdir build

@REM User
%prebuild% g++ .cpp ./src/User ./build

@REM Engine
%prebuild% g++ .cpp ./src/Engine ./build

@REM Editor
if "%buildType%" equ "--editor" (
    %prebuild% g++ .cpp ./src/Editor ./build
)

@REM Main
if "%buildType%" equ "--editor" (
    g++ .\src\main.cpp -c -o .\build\main.o
) else (
    g++ -D SPARTAN_RUNTIME_ONLY .\src\main.cpp -c -o .\build\main.o
)

@REM Link
g++ .\build\*.o %dll_raylib% -o .\bin\game

copy %dll_raylib% .\bin

xcopy .\assets .\bin\assets /E /I /Y /Q
@echo on
@echo Copied assets directory to bin
@echo off