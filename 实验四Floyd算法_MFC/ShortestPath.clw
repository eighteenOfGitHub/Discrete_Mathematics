; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShortestPathDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ShortestPath.h"

ClassCount=3
Class1=CShortestPathApp
Class2=CShortestPathDlg

ResourceCount=3
Resource2=IDD_SHORTESTPATH_DIALOG
Resource1=IDR_MAINFRAME
Class3=CDlgInput
Resource3=IDD_DIALOG_INPUT

[CLS:CShortestPathApp]
Type=0
HeaderFile=ShortestPath.h
ImplementationFile=ShortestPath.cpp
Filter=N

[CLS:CShortestPathDlg]
Type=0
HeaderFile=ShortestPathDlg.h
ImplementationFile=ShortestPathDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_DRAW



[DLG:IDD_SHORTESTPATH_DIALOG]
Type=1
Class=CShortestPathDlg
ControlCount=14
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_INFO,edit,1350633600
Control4=IDC_BUTTON_VERT,button,1342242816
Control5=IDC_BUTTON_EDGE,button,1342242816
Control6=IDC_BUTTON_MOVE,button,1342242816
Control7=IDC_BUTTON_DEL,button,1342242816
Control8=IDC_BUTTON_FROM,button,1342242816
Control9=IDC_BUTTON1,button,1342242816
Control10=IDC_STATIC,button,1342177287
Control11=IDC_RADIO_Floyd,button,1342177289
Control12=IDC_BUTTON_CAL,button,1342242816
Control13=IDC_DRAW,button,1342177287
Control14=IDC_EDIT_RES,edit,1352732804

[DLG:IDD_DIALOG_INPUT]
Type=1
Class=CDlgInput
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350639744

[CLS:CDlgInput]
Type=0
HeaderFile=DlgInput.h
ImplementationFile=DlgInput.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

