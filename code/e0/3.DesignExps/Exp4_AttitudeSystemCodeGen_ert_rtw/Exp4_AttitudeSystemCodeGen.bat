
cd .

if "%1"=="" ("D:\MATLAB~1\bin\win64\gmake"  -f Exp4_AttitudeSystemCodeGen.mk postdownload_preexecute all) else ("D:\MATLAB~1\bin\win64\gmake"  -f Exp4_AttitudeSystemCodeGen.mk postdownload_preexecute %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1