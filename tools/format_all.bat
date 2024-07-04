@echo off
for /r %%i in (*.c *.h) do (
    clang-format -i "%%i"
)