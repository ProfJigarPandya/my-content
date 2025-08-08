; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDSPView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DSP.h"
LastPage=0

ClassCount=8
Class1=CDSPApp
Class2=CDSPDoc
Class3=CDSPView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_NAMEOFCITY
Class5=CAboutDlg
Resource2=IDD_SELECT_SD_DLG
Class6=CSelectSDView
Resource3=IDD_ABOUTBOX
Class7=CNameOfCityDlg
Resource4=IDR_MAINFRAME
Class8=CRoadInfoDlg
Resource5=IDD_DISTBETCITY

[CLS:CDSPApp]
Type=0
HeaderFile=DSP.h
ImplementationFile=DSP.cpp
Filter=N
LastObject=CDSPApp

[CLS:CDSPDoc]
Type=0
HeaderFile=DSPDoc.h
ImplementationFile=DSPDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CDSPDoc

[CLS:CDSPView]
Type=0
HeaderFile=DSPView.h
ImplementationFile=DSPView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=CDSPView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=DSP.cpp
ImplementationFile=DSP.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_MRU_FILE1
Command2=ID_APP_EXIT
Command3=ID_VIEW_TOOLBAR
Command4=ID_VIEW_STATUS_BAR
Command5=ID_ADD_CITY
Command6=ID_ADD_ROAD
Command7=ID_APP_ABOUT
CommandCount=7

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_ADD_CITY
Command3=ID_ADD_ROAD
Command4=ID_FILE_NEW
Command5=ID_FILE_OPEN
Command6=ID_FILE_PRINT
Command7=ID_FILE_SAVE
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_EDIT_CUT
Command16=ID_EDIT_UNDO
CommandCount=16

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_BUTTON32776
Command2=ID_BUTTON32778
Command3=ID_BUTTON32779
Command4=ID_BUTTON32780
Command5=ID_BUTTON32781
Command6=ID_ADD_CITY
Command7=ID_BUTTON32782
Command8=ID_ADD_ROAD
Command9=ID_BUTTON32783
Command10=ID_BUTTON32784
Command11=ID_BUTTON32785
Command12=ID_BUTTON32786
Command13=ID_BUTTON32787
Command14=ID_BUTTON32788
CommandCount=14

[DLG:IDD_SELECT_SD_DLG]
Type=1
Class=CSelectSDView
ControlCount=9
Control1=IDC_SOURCE_CITY_DB,combobox,1344340227
Control2=IDC_STATIC,static,1342177294
Control3=IDC_STATIC,static,1342177294
Control4=IDC_STATIC,button,1342178055
Control5=IDC_STATIC,button,1342178055
Control6=IDC_DEST_CITY_CB,combobox,1344340227
Control7=IDC_SEARCH,button,1342242816
Control8=IDC_XYZ,static,1342308353
Control9=IDC_SEARCH_TEXT,static,1342308353

[CLS:CSelectSDView]
Type=0
HeaderFile=SelectSDView.h
ImplementationFile=SelectSDView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_SEARCH_TEXT
VirtualFilter=VWC

[DLG:IDD_NAMEOFCITY]
Type=1
Class=CNameOfCityDlg
ControlCount=4
Control1=IDC_NAMEOFCITY,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CNameOfCityDlg]
Type=0
HeaderFile=NameOfCityDlg.h
ImplementationFile=NameOfCityDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CNameOfCityDlg
VirtualFilter=dWC

[DLG:IDD_DISTBETCITY]
Type=1
Class=CRoadInfoDlg
ControlCount=4
Control1=IDC_DISTANCE,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CRoadInfoDlg]
Type=0
HeaderFile=RoadInfoDlg.h
ImplementationFile=RoadInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRoadInfoDlg
VirtualFilter=dWC

