echo clear all
cd IDL

set path=%path%;%cd%
for %%f in (*.idl) do omniidl -bcxx -Wbtp %%f
cd ..
 