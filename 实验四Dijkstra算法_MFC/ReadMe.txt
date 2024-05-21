========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : ShortestPath
========================================================================


AppWizard has created this ShortestPath application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your ShortestPath application.

ShortestPath.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

ShortestPath.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CShortestPathApp application class.

ShortestPath.cpp
    This is the main application source file that contains the application
    class CShortestPathApp.

ShortestPath.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

ShortestPath.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\ShortestPath.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file ShortestPath.rc.

res\ShortestPath.rc2
    This file contains resources that are not edited by Microsoft 
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.




/////////////////////////////////////////////////////////////////////////////

AppWizard creates one dialog class:

ShortestPathDlg.h, ShortestPathDlg.cpp - the dialog
    These files contain your CShortestPathDlg class.  This class defines
    the behavior of your application's main dialog.  The dialog's
    template is in ShortestPath.rc, which can be edited in Microsoft
	Visual C++.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named ShortestPath.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is 
in a language other than the operating system's current language, you
will need to copy the corresponding localized resources MFC42XXX.DLL
from the Microsoft Visual C++ CD-ROM onto the system or system32 directory,
and rename it to be MFCLOC.DLL.  ("XXX" stands for the language abbreviation.
For example, MFC42DEU.DLL contains resources translated to German.)  If you
don't do this, some of the UI elements of your application will remain in the
language of the operating system.

/////////////////////////////////////////////////////////////////////////////

========================================================================

΢���������:ShortestPath

========================================================================





AppWizard�Ѿ�Ϊ�������������·��Ӧ�ó������Ӧ�ó���

������ʾ��ʹ��Microsoft Foundation��Ļ���֪ʶ

ͬʱҲ�Ǳ�дӦ�ó������㡣



���ļ�����������ÿ���ļ����ҵ���ժҪ

��������ShortestPathӦ�ó���



ShortestPath.dsp

���ļ�(��Ŀ�ļ�)������Ŀ�����

�������ɵ�����Ŀ������Ŀ�������û����Թ���

��Ŀ(.dsp)�ļ���������Ӧ���ڱ��ص���makefile�ļ���



ShortestPath.h

����Ӧ�ó������Ҫͷ�ļ�������������

��Ŀ�ض���ͷ�ļ�(����Resource.h)��������

CShortestPathAppӦ�ó����ࡣ



ShortestPath.cpp

���ǰ���Ӧ�ó������Ӧ�ó���Դ�ļ�

��CShortestPathApp��



ShortestPath.rc

��������Microsoft Windows��Դ���б�

����ʹ�á����������洢��ͼ�ꡢλͼ���α�

��RES��Ŀ¼�¡����ļ�������΢����ֱ�ӱ༭

Visual c++��



ShortestPath.clw

���ļ�����ClassWizard���ڱ༭���е�

���������ࡣClassWizardҲʹ������ļ����洢

�����ͱ༭��Ϣӳ��ͶԻ��������������Ϣ

ӳ��ʹ���ԭ�ͳ�Ա������



res \ ShortestPath.ico

����һ��ͼ���ļ�������Ӧ�ó����ͼ�ꡣ��

ͼ�����������Դ�ļ�ShortestPath.rc�С�



res \ ShortestPath.rc2

���ļ�����Microsoftδ�༭����Դ

Visual c++����Ӧ�÷������в��ɱ༭����Դ

���ļ��е���Դ�༭����









/////////////////////////////////////////////////////////////////////////////



AppWizard����һ���Ի�����:



shortestpathdll .h, shortestpathdll .cpp -�Ի���

��Щ�ļ�����CShortestPathDlg�ࡣ����ඨ����

Ӧ�ó������Ի������Ϊ���Ի����

ģ����ShortestPath�С�rc��������Microsoft�б༭

Visual c++��





/////////////////////////////////////////////////////////////////////////////

������׼�ļ�:



StdAfx.h, StdAfx.cpp

��Щ�ļ����ڹ���Ԥ����ͷ�ļ�(PCH)

ShortestPath������һ����ΪStdAfx.obj��Ԥ���������ļ���



Resource.h

���Ǳ�׼��ͷ�ļ������������µ���Դid��

Microsoft Visual c++��ȡ����������ļ���



/////////////////////////////////////////////////////////////////////////////

��ע:



AppWizardʹ�á�TODO:����ָʾ����Ҫִ�еĲ���Դ����

Ӧ����ӵ����Զ��塣



�������Ӧ�ó����ڹ���DLL��ʹ��MFC����ô����Ӧ�ó������

�ڲ���ϵͳ��ǰ��������������У�������

�Ƿ���Ҫ������Ӧ�ı��ػ���Դmfc42 . xxx . dll

��Microsoft Visual c++ CD-ROM���ص�system��system32Ŀ¼��

������������Ϊmfccc . dll��(��XXX���������Ե���д��

���磬MFC42DEU.DLL��������ɵ������Դ��)�����

�������������Ӧ�ó����һЩUIԪ�ؽ�������

����ϵͳ���ԡ�



/////////////////////////////////////////////////////////////////////////////

 
