CORBA ��򵥹���

˵��: �˹���ʹ���˻������������·��, �������ĸ�Ŀ¼��, ֻ��Ҫ������omniorb�Ļ������úþͿ��Ա�������.

���뻷��: Visual Studio 2005

��������:
CORBA_HOME = C:\_perforce\COTS\omniORB\omniORB_4.1.2

·��:
Path = C:\_perforce\COTS\omniORB\omniORB_4.1.2\bin\x86_win32
ע: Vista��Ҫ�þ���·��, �����û�������: %CORBA_HOME%

�����ǹ���������ص�һЩ˵��:

2) outputs: 
$(InputName).h
$(InputName).cpp
$(InputName)._skel.cpp

3) Project Configuration Type: Utility (��ʼ����ΪStatic Library)
��Ϊ�������ΪStatic Library��������: ��������Ŀ����֮��, �����Ҳ����ù��̶�Ӧ��.lib������

2. Corba Project
1) Output Directory: $(ProjectDir)$(ConfigurationName)
   Ĭ��Ϊ$(SolutionDir)$(ConfigurationName)

2) ��IDL���ɵ�����cpp������������
       echo.cpp
       echo_skel.cpp

3) Additional Include Directories: $(CORBA_HOME)\include

3. Project Setting
1) Additional Include Directories: $(CORBA_HOME)\include

2) Preprocessor Definitions: 
__x86__
__NT__
__OSVERSION__=4
__WIN32__

3) Additional Library Directories: 
$(CORBA_HOME)\lib\x86_win32
..\echo_corba_lib\Debug

4) Additional Dependencies:
omniORB412_rtd.lib
omniDynamic412_rtd.lib
omnithread33_rtd.lib
echo_corba_lib.lib

