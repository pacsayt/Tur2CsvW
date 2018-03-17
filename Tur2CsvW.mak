# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Tur2CsvW - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Tur2CsvW - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Tur2CsvW - Win32 Release" && "$(CFG)" !=\
 "Tur2CsvW - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Tur2CsvW.mak" CFG="Tur2CsvW - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Tur2CsvW - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Tur2CsvW - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Tur2CsvW - Win32 Debug"
MTL=mktyplib.exe
RSC=rc.exe
CPP=cl.exe

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"

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
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\Tur2CsvW.exe"

CLEAN : 
	-@erase "$(INTDIR)\CBinPar.obj"
	-@erase "$(INTDIR)\CCsvFile.obj"
	-@erase "$(INTDIR)\CDiagram.obj"
	-@erase "$(INTDIR)\CEdzDiagram.obj"
	-@erase "$(INTDIR)\CEdzes.obj"
	-@erase "$(INTDIR)\CKonverter.obj"
	-@erase "$(INTDIR)\CloseTaining.obj"
	-@erase "$(INTDIR)\CMagassagKulView.obj"
	-@erase "$(INTDIR)\CMagKulDiagram.obj"
	-@erase "$(INTDIR)\CPar.obj"
	-@erase "$(INTDIR)\CSzovPar.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Tur2CsvW.obj"
	-@erase "$(INTDIR)\Tur2CsvW.pch"
	-@erase "$(INTDIR)\Tur2CsvW.res"
	-@erase "$(INTDIR)\Tur2CsvWDoc.obj"
	-@erase "$(INTDIR)\Tur2CsvWView.obj"
	-@erase "$(OUTDIR)\Tur2CsvW.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Tur2CsvW.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Tur2CsvW.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Tur2CsvW.pdb" /machine:I386 /out:"$(OUTDIR)/Tur2CsvW.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CBinPar.obj" \
	"$(INTDIR)\CCsvFile.obj" \
	"$(INTDIR)\CDiagram.obj" \
	"$(INTDIR)\CEdzDiagram.obj" \
	"$(INTDIR)\CEdzes.obj" \
	"$(INTDIR)\CKonverter.obj" \
	"$(INTDIR)\CloseTaining.obj" \
	"$(INTDIR)\CMagassagKulView.obj" \
	"$(INTDIR)\CMagKulDiagram.obj" \
	"$(INTDIR)\CPar.obj" \
	"$(INTDIR)\CSzovPar.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Tur2CsvW.obj" \
	"$(INTDIR)\Tur2CsvW.res" \
	"$(INTDIR)\Tur2CsvWDoc.obj" \
	"$(INTDIR)\Tur2CsvWView.obj"

"$(OUTDIR)\Tur2CsvW.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

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
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\Tur2CsvW.exe" "$(OUTDIR)\Tur2CsvW.bsc"

CLEAN : 
	-@erase "$(INTDIR)\CBinPar.obj"
	-@erase "$(INTDIR)\CBinPar.sbr"
	-@erase "$(INTDIR)\CCsvFile.obj"
	-@erase "$(INTDIR)\CCsvFile.sbr"
	-@erase "$(INTDIR)\CDiagram.obj"
	-@erase "$(INTDIR)\CDiagram.sbr"
	-@erase "$(INTDIR)\CEdzDiagram.obj"
	-@erase "$(INTDIR)\CEdzDiagram.sbr"
	-@erase "$(INTDIR)\CEdzes.obj"
	-@erase "$(INTDIR)\CEdzes.sbr"
	-@erase "$(INTDIR)\CKonverter.obj"
	-@erase "$(INTDIR)\CKonverter.sbr"
	-@erase "$(INTDIR)\CloseTaining.obj"
	-@erase "$(INTDIR)\CloseTaining.sbr"
	-@erase "$(INTDIR)\CMagassagKulView.obj"
	-@erase "$(INTDIR)\CMagassagKulView.sbr"
	-@erase "$(INTDIR)\CMagKulDiagram.obj"
	-@erase "$(INTDIR)\CMagKulDiagram.sbr"
	-@erase "$(INTDIR)\CPar.obj"
	-@erase "$(INTDIR)\CPar.sbr"
	-@erase "$(INTDIR)\CSzovPar.obj"
	-@erase "$(INTDIR)\CSzovPar.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\Tur2CsvW.obj"
	-@erase "$(INTDIR)\Tur2CsvW.pch"
	-@erase "$(INTDIR)\Tur2CsvW.res"
	-@erase "$(INTDIR)\Tur2CsvW.sbr"
	-@erase "$(INTDIR)\Tur2CsvWDoc.obj"
	-@erase "$(INTDIR)\Tur2CsvWDoc.sbr"
	-@erase "$(INTDIR)\Tur2CsvWView.obj"
	-@erase "$(INTDIR)\Tur2CsvWView.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Tur2CsvW.bsc"
	-@erase "$(OUTDIR)\Tur2CsvW.exe"
	-@erase "$(OUTDIR)\Tur2CsvW.ilk"
	-@erase "$(OUTDIR)\Tur2CsvW.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Tur2CsvW.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Tur2CsvW.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CBinPar.sbr" \
	"$(INTDIR)\CCsvFile.sbr" \
	"$(INTDIR)\CDiagram.sbr" \
	"$(INTDIR)\CEdzDiagram.sbr" \
	"$(INTDIR)\CEdzes.sbr" \
	"$(INTDIR)\CKonverter.sbr" \
	"$(INTDIR)\CloseTaining.sbr" \
	"$(INTDIR)\CMagassagKulView.sbr" \
	"$(INTDIR)\CMagKulDiagram.sbr" \
	"$(INTDIR)\CPar.sbr" \
	"$(INTDIR)\CSzovPar.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\Tur2CsvW.sbr" \
	"$(INTDIR)\Tur2CsvWDoc.sbr" \
	"$(INTDIR)\Tur2CsvWView.sbr"

"$(OUTDIR)\Tur2CsvW.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Tur2CsvW.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/Tur2CsvW.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CBinPar.obj" \
	"$(INTDIR)\CCsvFile.obj" \
	"$(INTDIR)\CDiagram.obj" \
	"$(INTDIR)\CEdzDiagram.obj" \
	"$(INTDIR)\CEdzes.obj" \
	"$(INTDIR)\CKonverter.obj" \
	"$(INTDIR)\CloseTaining.obj" \
	"$(INTDIR)\CMagassagKulView.obj" \
	"$(INTDIR)\CMagKulDiagram.obj" \
	"$(INTDIR)\CPar.obj" \
	"$(INTDIR)\CSzovPar.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Tur2CsvW.obj" \
	"$(INTDIR)\Tur2CsvW.res" \
	"$(INTDIR)\Tur2CsvWDoc.obj" \
	"$(INTDIR)\Tur2CsvWView.obj"

"$(OUTDIR)\Tur2CsvW.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Tur2CsvW - Win32 Release"
# Name "Tur2CsvW - Win32 Debug"

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"

!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"

!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Tur2CsvW.cpp
DEP_CPP_TUR2C=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\MainFrm.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvW.h"\
	".\Tur2CsvWDoc.h"\
	".\Tur2CsvWView.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\Tur2CsvW.obj" : $(SOURCE) $(DEP_CPP_TUR2C) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\Tur2CsvW.obj" : $(SOURCE) $(DEP_CPP_TUR2C) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\Tur2CsvW.sbr" : $(SOURCE) $(DEP_CPP_TUR2C) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /Fp"$(INTDIR)/Tur2CsvW.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Tur2CsvW.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3 /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\StdAfx.sbr" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Tur2CsvW.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CMagassagKulView.h"\
	".\CMagKulDiagram.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\MainFrm.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvW.h"\
	".\Tur2CsvWDoc.h"\
	".\Tur2CsvWView.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Tur2CsvWDoc.cpp
DEP_CPP_TUR2CS=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CloseTaining.h"\
	".\CMagassagKulView.h"\
	".\CMagKulDiagram.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvW.h"\
	".\Tur2CsvWDoc.h"\
	".\Tur2CsvWView.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\Tur2CsvWDoc.obj" : $(SOURCE) $(DEP_CPP_TUR2CS) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\Tur2CsvWDoc.obj" : $(SOURCE) $(DEP_CPP_TUR2CS) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\Tur2CsvWDoc.sbr" : $(SOURCE) $(DEP_CPP_TUR2CS) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Tur2CsvWView.cpp

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"

DEP_CPP_TUR2CSV=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvW.h"\
	".\Tur2CsvWDoc.h"\
	".\Tur2CsvWView.h"\
	
NODEP_CPP_TUR2CSV=\
	".\m_cEdzDiagram"\
	

"$(INTDIR)\Tur2CsvWView.obj" : $(SOURCE) $(DEP_CPP_TUR2CSV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

DEP_CPP_TUR2CSV=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvW.h"\
	".\Tur2CsvWDoc.h"\
	".\Tur2CsvWView.h"\
	
# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\Tur2CsvWView.obj" : $(SOURCE) $(DEP_CPP_TUR2CSV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\Tur2CsvWView.sbr" : $(SOURCE) $(DEP_CPP_TUR2CSV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Tur2CsvW.rc
DEP_RSC_TUR2CSVW=\
	".\res\icon1.ico"\
	".\res\Toolbar.bmp"\
	".\res\Tur2CsvW.ico"\
	".\res\Tur2CsvW.rc2"\
	".\res\Tur2CsvWDoc.ico"\
	

"$(INTDIR)\Tur2CsvW.res" : $(SOURCE) $(DEP_RSC_TUR2CSVW) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CTur2Csv.cpp
DEP_CPP_CTUR2=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CKonverter.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\CTur2Csv.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	
# PROP Exclude_From_Build 1
# End Source File
################################################################################
# Begin Source File

SOURCE=.\CCsvFile.cpp
DEP_CPP_CCSVF=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CCsvFile.obj" : $(SOURCE) $(DEP_CPP_CCSVF) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CCsvFile.obj" : $(SOURCE) $(DEP_CPP_CCSVF) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CCsvFile.sbr" : $(SOURCE) $(DEP_CPP_CCSVF) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CKonverter.cpp
DEP_CPP_CKONV=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CKonverter.obj" : $(SOURCE) $(DEP_CPP_CKONV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CKonverter.obj" : $(SOURCE) $(DEP_CPP_CKONV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CKonverter.sbr" : $(SOURCE) $(DEP_CPP_CKONV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CPar.cpp
DEP_CPP_CPAR_=\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CPar.obj" : $(SOURCE) $(DEP_CPP_CPAR_) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CPar.obj" : $(SOURCE) $(DEP_CPP_CPAR_) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CPar.sbr" : $(SOURCE) $(DEP_CPP_CPAR_) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CSzovPar.cpp
DEP_CPP_CSZOV=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CSzovPar.obj" : $(SOURCE) $(DEP_CPP_CSZOV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CSzovPar.obj" : $(SOURCE) $(DEP_CPP_CSZOV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CSzovPar.sbr" : $(SOURCE) $(DEP_CPP_CSZOV) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CBinPar.cpp
DEP_CPP_CBINP=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CEdzes.h"\
	".\CPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CBinPar.obj" : $(SOURCE) $(DEP_CPP_CBINP) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CBinPar.obj" : $(SOURCE) $(DEP_CPP_CBINP) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CBinPar.sbr" : $(SOURCE) $(DEP_CPP_CBINP) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CEdzes.cpp
DEP_CPP_CEDZE=\
	".\CEdzes.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CEdzes.obj" : $(SOURCE) $(DEP_CPP_CEDZE) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CEdzes.obj" : $(SOURCE) $(DEP_CPP_CEDZE) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CEdzes.sbr" : $(SOURCE) $(DEP_CPP_CEDZE) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CDiagram.cpp
DEP_CPP_CDIAG=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvWDoc.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CDiagram.obj" : $(SOURCE) $(DEP_CPP_CDIAG) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CDiagram.obj" : $(SOURCE) $(DEP_CPP_CDIAG) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CDiagram.sbr" : $(SOURCE) $(DEP_CPP_CDIAG) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MagassagKulView.cpp
DEP_CPP_MAGAS=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvW.h"\
	".\Tur2CsvWDoc.h"\
	
NODEP_CPP_MAGAS=\
	".\CMagassagKulView.h"\
	
# PROP Exclude_From_Build 1
# End Source File
################################################################################
# Begin Source File

SOURCE=.\CEdzDiagram.cpp
DEP_CPP_CEDZD=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvWDoc.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CEdzDiagram.obj" : $(SOURCE) $(DEP_CPP_CEDZD) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CEdzDiagram.obj" : $(SOURCE) $(DEP_CPP_CEDZD) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CEdzDiagram.sbr" : $(SOURCE) $(DEP_CPP_CEDZD) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMagassagKulView.cpp
DEP_CPP_CMAGA=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CMagassagKulView.h"\
	".\CMagKulDiagram.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvW.h"\
	".\Tur2CsvWDoc.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CMagassagKulView.obj" : $(SOURCE) $(DEP_CPP_CMAGA) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CMagassagKulView.obj" : $(SOURCE) $(DEP_CPP_CMAGA) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CMagassagKulView.sbr" : $(SOURCE) $(DEP_CPP_CMAGA) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CMagKulDiagram.cpp
DEP_CPP_CMAGK=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CDiagram.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CMagKulDiagram.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvWDoc.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CMagKulDiagram.obj" : $(SOURCE) $(DEP_CPP_CMAGK) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"

# ADD CPP /W3

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Tur2CsvW.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\CMagKulDiagram.obj" : $(SOURCE) $(DEP_CPP_CMAGK) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

"$(INTDIR)\CMagKulDiagram.sbr" : $(SOURCE) $(DEP_CPP_CMAGK) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CloseTaining.cpp
DEP_CPP_CLOSE=\
	".\CBinPar.h"\
	".\CCsvFile.h"\
	".\CEdzes.h"\
	".\CKonverter.h"\
	".\CloseTaining.h"\
	".\CPar.h"\
	".\CSzovPar.h"\
	".\SEgyMinta.h"\
	".\StdAfx.h"\
	".\Tur2CsvW.h"\
	".\Tur2CsvWDoc.h"\
	

!IF  "$(CFG)" == "Tur2CsvW - Win32 Release"


"$(INTDIR)\CloseTaining.obj" : $(SOURCE) $(DEP_CPP_CLOSE) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"


!ELSEIF  "$(CFG)" == "Tur2CsvW - Win32 Debug"


"$(INTDIR)\CloseTaining.obj" : $(SOURCE) $(DEP_CPP_CLOSE) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"

"$(INTDIR)\CloseTaining.sbr" : $(SOURCE) $(DEP_CPP_CLOSE) "$(INTDIR)"\
 "$(INTDIR)\Tur2CsvW.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
