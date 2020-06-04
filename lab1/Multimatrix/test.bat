@echo off
SET MyProgram = "%~1"

MyProgram && goto err
echo Test empty input passed

MyProgram test_input1.txt
if NOT ERRORLEVEL 1 go to err
echo Test with 2 param

%~1 zero_input.txt normal_matrix2.txt > output.txt || goto err
fc output.txt zeros.txt || goto err
echo test 3 passed

%~1 wrong_matrix1.txt normal_matrix2.txt && goto err
echo test4 passed

%~1 normal_matrix2.txt wrong_matrix1.txt && goto err
echo test5 passed

echo All test passed succesfully
exit /B 0 

:err
echo Tests failed
exit /B 1