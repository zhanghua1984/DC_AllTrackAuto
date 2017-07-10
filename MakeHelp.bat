@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by ALLTRACKAUTO.HPJ. >"hlp\ALLTRACKAUTO.hm"
echo. >>"hlp\ALLTRACKAUTO.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\ALLTRACKAUTO.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\ALLTRACKAUTO.hm"
echo. >>"hlp\ALLTRACKAUTO.hm"
echo // Prompts (IDP_*) >>"hlp\ALLTRACKAUTO.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\ALLTRACKAUTO.hm"
echo. >>"hlp\ALLTRACKAUTO.hm"
echo // Resources (IDR_*) >>"hlp\ALLTRACKAUTO.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\ALLTRACKAUTO.hm"
echo. >>"hlp\ALLTRACKAUTO.hm"
echo // Dialogs (IDD_*) >>"hlp\ALLTRACKAUTO.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\ALLTRACKAUTO.hm"
echo. >>"hlp\ALLTRACKAUTO.hm"
echo // Frame Controls (IDW_*) >>"hlp\ALLTRACKAUTO.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\ALLTRACKAUTO.hm"
REM -- Make help for Project ALLTRACKAUTO


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\ALLTRACKAUTO.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\ALLTRACKAUTO.hlp" goto :Error
if not exist "hlp\ALLTRACKAUTO.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\ALLTRACKAUTO.hlp" Debug
if exist Debug\nul copy "hlp\ALLTRACKAUTO.cnt" Debug
if exist Release\nul copy "hlp\ALLTRACKAUTO.hlp" Release
if exist Release\nul copy "hlp\ALLTRACKAUTO.cnt" Release
echo.
goto :done

:Error
echo hlp\ALLTRACKAUTO.hpj(1) : error: Problem encountered creating help file

:done
echo.
