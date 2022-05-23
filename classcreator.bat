@echo off
set /p classname="Class Name: "
echo class %classname%{}; > .\include\%classname%.h
echo #include %classname%.h > .\src\%classname%.cpp
start .\..\..\.tools\.project_builders\vs19_win.bat