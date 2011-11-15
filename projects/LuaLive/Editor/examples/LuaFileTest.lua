
SIZE = 1024*1042*4
---------------------------------------------
buffer = SysAlloc(SIZE)
for i = 0,9 do
  SysBufferSetByte(buffer, i, i + 67)
end
SysBufferSetByte(buffer, 10, 0)

str = SysBufferToString(buffer)
print("@@@ "..str)

handle = maCreatePlaceholder()
res = maCreateData(handle, SIZE)
maWriteData(handle, buffer, 0, SIZE)

print("File write start")
FileSys:WriteDataToFile("/sdcard/BigFile.data", handle)
print("File write done")

SysFree(buffer)
maDestroyObject(handle)
--------------------------------------------
print("File read start")
handle2 = FileSys:ReadDataFromFile("/sdcard/BigFile.data")
print("File read done")
buffer2 = SysAlloc(SIZE)
maReadData(handle2, buffer2, 0, SIZE)
str = SysBufferToString(buffer2)
print("@@@ "..str)
SysFree(buffer2)
maDestroyObject(handle2)

