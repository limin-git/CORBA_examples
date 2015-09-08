CORBA 最简单工程

说明: 此工程使用了环境变量和相对路径, 无论在哪个目录下, 只需要把设置omniorb的环境设置好就可以编译运行.

编译环境: Visual Studio 2005

环境变量:
CORBA_HOME = C:\_perforce\COTS\omniORB\omniORB_4.1.2

路径:
Path = C:\_perforce\COTS\omniORB\omniORB_4.1.2\bin\x86_win32
注: Vista需要用绝对路径, 不能用环境变量: %CORBA_HOME%

以下是工程设置相关的一些说明:

2) outputs: 
$(InputName).h
$(InputName).cpp
$(InputName)._skel.cpp

3) Project Configuration Type: Utility (开始设置为Static Library)
因为如果设置为Static Library会有问题: 当设置项目依赖之后, 会因找不到该工程对应的.lib而报错

2. Corba Project
1) Output Directory: $(ProjectDir)$(ConfigurationName)
   默认为$(SolutionDir)$(ConfigurationName)

2) 将IDL生成的两个cpp包含到工程中
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

