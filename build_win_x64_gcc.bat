@echo off

if not exist bin mkdir bin
if not exist build mkdir build
if not exist lib_first mkdir lib_first

@REM Engine
setlocal enabledelayedexpansion
set "engineCPP="
for /R .\src\Engine %%F in (*.cpp) do (
    set "engineCPP=!engineCPP! "%%F""
)
g++ %engineCPP% .\lib\raylib.dll -fPIC -shared -o .\lib_first\SpartanEngine.dll
g++ .\src\main.cpp -c -o .\build\main.o

@REM User
setlocal enabledelayedexpansion
set "userCPP="
for /R .\src\User %%F in (*.cpp) do (
    set "userCPP=!userCPP! "%%F""
)
g++ %userCPP% .\lib\raylib.dll .\lib_first\SpartanEngine.dll -fPIC -shared -o .\lib_first\User.dll

@REM Link
g++ .\build\main.o .\lib\raylib.dll .\lib_first\User.dll .\lib_first\SpartanEngine.dll -o .\bin\game

copy .\lib\raylib.dll .\bin
copy .\lib_first\SpartanEngine.dll .\bin
copy .\lib_first\User.dll .\bin
xcopy .\assets .\bin\assets /E /I /Y

@echo on