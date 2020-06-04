@echo off
SET MyProgram = "%~1"

%~1 && goto err
echo Test emty input

%~1 letter && goto err
echo Test without number

%~1 -32 && goto err
echo Test with negative number

%~1 1024 && goto err
echo Out of range Test

%~1 0 > output.txt || goto err
fc output.txt 0_output.txt || goto err
echo LimitTest1 passed

%~1 255 > output.txt || goto err
fc output.txt 255_output.txt || goto err
echo LimitTest2 passed

%~1 6 > output.txt || goto err
fc output.txt 96_output.txt  || goto err
echo normal test passed

echo All test passed succesfully
exit /B 0 

:err
echo Tests failed
exit /B 1