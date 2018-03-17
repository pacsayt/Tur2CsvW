; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Tur2CsvW.h"
LastPage=0

ClassCount=7
Class1=CTur2CsvWApp
Class2=CTur2CsvWDoc
Class3=CTur2CsvWView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CMagassagKulView
Resource2=IDR_MAINFRAME
Class7=CCloseTaining
Resource3=IDD_CLOSE_TRAIN_DLG

[CLS:CTur2CsvWApp]
Type=0
HeaderFile=Tur2CsvW.h
ImplementationFile=Tur2CsvW.cpp
Filter=N

[CLS:CTur2CsvWDoc]
Type=0
HeaderFile=Tur2CsvWDoc.h
ImplementationFile=Tur2CsvWDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_FILE_OPEN

[CLS:CTur2CsvWView]
Type=0
HeaderFile=Tur2CsvWView.h
ImplementationFile=Tur2CsvWView.cpp
Filter=C
LastObject=CTur2CsvWView
BaseClass=CView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=Tur2CsvW.cpp
ImplementationFile=Tur2CsvW.cpp
Filter=D
LastObject=IDOK
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_CLOSE
Command3=ID_FILE_PRINT
Command4=ID_FILE_PRINT_PREVIEW
Command5=ID_FILE_PRINT_SETUP
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_MOVEZOOM_LEFT
Command9=ID_MOVEZOOM_RIGHT
Command10=ID_MOVEZOOM_SHRINK
Command11=ID_MOVEZOOM_STRETCH
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_PRINT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_NEXT_PANE
Command8=ID_PREV_PANE
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Command1=ID_FILE_OPEN
Command2=ID_MOVEZOOM_LEFT
Command3=ID_MOVEZOOM_STRETCH
Command4=ID_MOVEZOOM_SHRINK
Command5=ID_MOVEZOOM_RIGHT
Command6=ID_APP_ABOUT
CommandCount=6

[CLS:CMagassagKulView]
Type=0
HeaderFile=MagassagKulView.h
ImplementationFile=MagassagKulView.cpp
BaseClass=CView
Filter=C
LastObject=CMagassagKulView

[DLG:IDD_CLOSE_TRAIN_DLG]
Type=1
Class=CCloseTaining
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_OPEN_TRAIN_ST,button,1342177287
Control4=IDC_BETOLT_EDZ_LST,listbox,1352728971

[CLS:CCloseTaining]
Type=0
HeaderFile=CloseTaining.h
ImplementationFile=CloseTaining.cpp
BaseClass=CDialog
Filter=D
LastObject=CCloseTaining

