---------------------------------------------
-- Test script for Lua File API
---------------------------------------------

-- Use a big chunk on data.
SIZE = 1024*1042

-- Android specific path.
PATH = "/sdcard/BigFile.data"

-- First write.

buffer1 = SysAlloc(SIZE)
-- Add some string data to the beginning of the buffer.
for i = 0,9 do
  SysBufferSetByte(buffer1, i, i + 67)
end
SysBufferSetByte(buffer1, 10, 0)

str1 = SysBufferToString(buffer1)
print("@@@ "..str1)

handle1 = maCreatePlaceholder()
maCreateData(handle1, SIZE)
maWriteData(handle1, buffer1, 0, SIZE)

FileSys:WriteDataToFile(PATH, handle1)

SysFree(buffer1)
maDestroyObject(handle1)

-- Then read.

handle2 = FileSys:ReadDataFromFile(PATH)
size = maGetDataSize(handle2)
buffer2 = SysAlloc(size)
maReadData(handle2, buffer2, 0, size)

str2 = SysBufferToString(buffer2)
print("@@@ "..str2)

SysFree(buffer2)
maDestroyObject(handle2)

-- Delete the file.

file = maFileOpen(PATH, MA_ACCESS_READ_WRITE)
maFileDelete(file)
maFileClose(file)

-- Finally, print the test result.

if str1 == str2 and SIZE == size then
  print("File test passed")
else
  print("File test failed")
end

---------------------------------------------

-- Test from forum post: http://www.mosync.com/node/7601
function ReadEmptyFileShouldFail()
  local path = FileSys:GetLocalPath()
  path = path.."testfile.txt"
  local buffer = SysAlloc(100)
  local file = maFileOpen(path, MA_ACCESS_READ_WRITE)
  if file < 0 then
    print("Error opening file")
    print("Empty file test failed")
    return
  end
  if maFileCreate(file) < 0 then
    print ("Error on maFileCreate")
    print("Empty file test failed")
    maFileClose(file)
    return
  end
  if maFileRead(file, buffer, 100) < 0 then
    print("maFileRead failed. This is GOOD!")
    print("Empty file test passed")
  else
    print("maFileRead succeeded on an empty file. This is BAD!")
    print("Empty file test failed")
  end
  maFileDelete(file)
  maFileClose(file)
  SysFree(buffer)
end

ReadEmptyFileShouldFail()
