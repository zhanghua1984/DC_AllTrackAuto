# Microsoft Developer Studio Project File - Name="ALLTRACKAUTO" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ALLTRACKAUTO - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ALLTRACKAUTO.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ALLTRACKAUTO.mak" CFG="ALLTRACKAUTO - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ALLTRACKAUTO - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ALLTRACKAUTO - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ALLTRACKAUTO - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "ALLTRACKAUTO - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ALLTRACKAUTO - Win32 Release"
# Name "ALLTRACKAUTO - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ALLTRACKAUTO.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\ALLTRACKAUTO.hpj

!IF  "$(CFG)" == "ALLTRACKAUTO - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__ALLTR="hlp\AfxCore.rtf"	"hlp\AfxPrint.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Release
TargetName=ALLTRACKAUTO
InputPath=.\hlp\ALLTRACKAUTO.hpj
InputName=ALLTRACKAUTO

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ALLTRACKAUTO - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__ALLTR="hlp\AfxCore.rtf"	"hlp\AfxPrint.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Debug
TargetName=ALLTRACKAUTO
InputPath=.\hlp\ALLTRACKAUTO.hpj
InputName=ALLTRACKAUTO

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTO.odl
# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTO.rc
# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTODoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTOSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTOView.cpp
# End Source File
# Begin Source File

SOURCE=.\ANTENNA.cpp
# End Source File
# Begin Source File

SOURCE=.\APR.cpp
# End Source File
# Begin Source File

SOURCE=.\Carriage.cpp
# End Source File
# Begin Source File

SOURCE=.\CntrItem.cpp
# End Source File
# Begin Source File

SOURCE=.\Com.cpp
# End Source File
# Begin Source File

SOURCE=.\COMPORT.CPP
# End Source File
# Begin Source File

SOURCE=.\DIALOGCARRAYTEST.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes.cpp
# End Source File
# Begin Source File

SOURCE=.\MACRO.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MSG.cpp
# End Source File
# Begin Source File

SOURCE=.\OTHERSET.cpp
# End Source File
# Begin Source File

SOURCE=.\PARPINFO.cpp
# End Source File
# Begin Source File

SOURCE=.\PROMPTINFO.cpp
# End Source File
# Begin Source File

SOURCE=.\READER.cpp
# End Source File
# Begin Source File

SOURCE=.\RUNNINGMSG.cpp
# End Source File
# Begin Source File

SOURCE=.\SETHD.cpp
# End Source File
# Begin Source File

SOURCE=.\SetPAPR.cpp
# End Source File
# Begin Source File

SOURCE=.\Setview.cpp
# End Source File
# Begin Source File

SOURCE=.\SHOWMSG.cpp
# End Source File
# Begin Source File

SOURCE=.\SpeedLine.cpp
# End Source File
# Begin Source File

SOURCE=.\SpeedTable.cpp
# End Source File
# Begin Source File

SOURCE=.\Station.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\STOPFLAG.cpp
# End Source File
# Begin Source File

SOURCE=.\symbol.cpp
# End Source File
# Begin Source File

SOURCE=.\TOOLBARDIY.cpp
# End Source File
# Begin Source File

SOURCE=.\TRACKCODE.cpp
# End Source File
# Begin Source File

SOURCE=.\TRACKCODECHANGE.cpp
# End Source File
# Begin Source File

SOURCE=.\Train.cpp
# End Source File
# Begin Source File

SOURCE=.\TRAINSET.cpp
# End Source File
# Begin Source File

SOURCE=.\wheel.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ALLDEFINE.H
# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTO.h
# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTODoc.h
# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTOSet.h
# End Source File
# Begin Source File

SOURCE=.\ALLTRACKAUTOView.h
# End Source File
# Begin Source File

SOURCE=.\ANTENNA.h
# End Source File
# Begin Source File

SOURCE=.\APR.h
# End Source File
# Begin Source File

SOURCE=.\Carriage.h
# End Source File
# Begin Source File

SOURCE=.\CntrItem.h
# End Source File
# Begin Source File

SOURCE=.\Com.h
# End Source File
# Begin Source File

SOURCE=.\COMPORT.H
# End Source File
# Begin Source File

SOURCE=.\DIALOGCARRAYTEST.h
# End Source File
# Begin Source File

SOURCE=.\Includes.h
# End Source File
# Begin Source File

SOURCE=.\MACRO.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MSG.h
# End Source File
# Begin Source File

SOURCE=.\OTHERSET.h
# End Source File
# Begin Source File

SOURCE=.\PARPINFO.h
# End Source File
# Begin Source File

SOURCE=.\PROMPTINFO.h
# End Source File
# Begin Source File

SOURCE=.\READER.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "ALLTRACKAUTO - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=ALLTRACKAUTO
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ALLTRACKAUTO - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=ALLTRACKAUTO
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RUNNINGMSG.h
# End Source File
# Begin Source File

SOURCE=.\SETHD.h
# End Source File
# Begin Source File

SOURCE=.\SetPAPR.h
# End Source File
# Begin Source File

SOURCE=.\Setview.h
# End Source File
# Begin Source File

SOURCE=.\SHOWMSG.h
# End Source File
# Begin Source File

SOURCE=.\SpeedLine.h
# End Source File
# Begin Source File

SOURCE=.\SpeedTable.h
# End Source File
# Begin Source File

SOURCE=.\Station.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\STOPFLAG.h
# End Source File
# Begin Source File

SOURCE=.\symbol.h
# End Source File
# Begin Source File

SOURCE=.\TOOLBARDIY.h
# End Source File
# Begin Source File

SOURCE=.\TRACKCODE.h
# End Source File
# Begin Source File

SOURCE=.\TRACKCODECHANGE.h
# End Source File
# Begin Source File

SOURCE=.\Train.h
# End Source File
# Begin Source File

SOURCE=.\TRAINSET.h
# End Source File
# Begin Source File

SOURCE=.\wheel.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ALLTRACKAUTO.ico
# End Source File
# Begin Source File

SOURCE=.\res\ALLTRACKAUTO.rc2
# End Source File
# Begin Source File

SOURCE=.\res\ALLTRACKAUTODoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbard.bmp
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\hlp\AfxCore.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AfxDb.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AfxOleCl.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AfxPrint.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\ALLTRACKAUTO.cnt

!IF  "$(CFG)" == "ALLTRACKAUTO - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Release
InputPath=.\hlp\ALLTRACKAUTO.cnt
InputName=ALLTRACKAUTO

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "ALLTRACKAUTO - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\hlp\ALLTRACKAUTO.cnt
InputName=ALLTRACKAUTO

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\AppExit.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw2.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw4.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurHelp.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCopy.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCut.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditPast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditUndo.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileNew.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FilePrnt.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileSave.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpSBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecFirst.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecLast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecNext.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecPrev.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\ScMenu.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmin.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ALLTRACKAUTO.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
