@echo off

if not exist bin mkdir bin
if not exist build mkdir build
if not exist lib_first mkdir lib_first

@REM Engine
g++ .\src\main.cpp -c -o .\build\main.o
g++ .\src\Engine\Engine.cpp -fPIC -shared -o .\lib_first\SpartanEngine.dll

@REM User
g++ .\src\User\UserMain.cpp -fPIC -shared -o .\lib_first\UserMain.dll

@REM Link
g++ .\build\main.o .\lib\raylib.dll .\lib_first\UserMain.dll .\lib_first\SpartanEngine.dll -o .\bin\game

copy .\lib\raylib.dll .\bin
copy .\lib_first\SpartanEngine.dll .\bin
copy .\lib_first\UserMain.dll .\bin
xcopy .\assets .\bin\assets /E /I /Y

@echo on