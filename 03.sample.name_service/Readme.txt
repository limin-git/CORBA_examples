ʹ��Naming Service

1. ��ӻ�������:
OMNINAMES_LOGDIR=C:\OMNINAMES

2. ִ��sample.reg, ����ַ�����ֵ
�ַ�����: 1
�ַ���ֵ: NameService=zhulimin-PC

3. ����������:
   omniNames -start (��һ��ִ��ʱ������, �Ժ󲻴�����)
   �� /? ���鿴���� ( ���԰�װΪwindows���� )

�ο�: http://www.cnblogs.com/findream/archive/2009/02/06/1385331.html


OmniORB Naming Service����:
�������TRANSIT����, ��Ҫ��omninames��ӡ�������ַ����������¸�ʽ���Ƶ�omniORB.cfg��ȥ
Starting omniNames and setting omniORB.cfg
When starting omniNames for the first time, you must specify the TCP port number on which it should listen. This is written to the log file so that on subsequent invocations it will listen on the same port number and thus can be accessible through the same object reference. When omniNames starts up successfully it writes the stringified object reference for its root context on standard error. 
At startup the omniORB runtime tries to read the configuration file omniORB.cfg to obtain the object reference to the root context of the Naming Service. This object reference is returned by the call resolve_initial_references("NameService"). Once you have started omniNames for the first time you have to copy the stringified object reference printed on standard error into omniORB.cfg. The format of the entry is the word NAMESERVICE followed by space and the stringified IOR all on one line. For example: 

NAMESERVICE IOR:010000002b00000049444c3a6f6d672e6f72672f436f734e616d696e672f4e616d696e67436f6e746578744578743a312e300000010000000000000070000000010102000e0000003139322e3136382e312e31353800f90a0b0000004e616d6553657276696365000300000000000000080000000100000000545441010000001c00000001000000010001000100000001000105090101000100000009010100035454410800000055da304a01001570

