@echo off
call build_win_x64_gcc
cd .\bin
game
cd ..
@echo on