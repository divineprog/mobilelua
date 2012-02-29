---------------------------------------------
-- Test script for Lua File API
---------------------------------------------

-- Use a big chunk on data.
SIZE = 1024*1042

-- Android specific path.
PATH = "/sdcard/BigFile.data"

-- First write.

buffer1 = mosync.SysAlloc(SIZE)
-- Add some string data to the beginning of the buffer.
for i = 0,9 do
  mosync.SysBufferSetByte(buffer1, i, i + 67)
end
mosync.SysBufferSetByte(buffer1, 10, 0)

str1 = mosync.SysBufferToString(buffer1)
--print("@@@ "..str1)

handle1 = mosync.maCreatePlaceholder()
mosync.maCreateData(handle1, SIZE)
mosync.maWriteData(handle1, buffer1, 0, SIZE)

mosync.FileSys:WriteDataToFile(PATH, handle1)

mosync.SysFree(buffer1)
mosync.maDestroyObject(handle1)

-- Then read.

handle2 = mosync.FileSys:ReadDataFromFile(PATH)
size = mosync.maGetDataSize(handle2)
buffer2 = mosync.SysAlloc(size)
mosync.maReadData(handle2, buffer2, 0, size)

str2 = mosync.SysBufferToString(buffer2)
--print("@@@ "..str2)

mosync.SysFree(buffer2)
mosync.maDestroyPlaceholder(handle2)

-- Delete the file.

file = mosync.maFileOpen(PATH, mosync.MA_ACCESS_READ_WRITE)
mosync.maFileDelete(file)
mosync.maFileClose(file)

-- Finally, print the test result.

if str1 == str2 and SIZE == size then
  print("File test passed")
else
  print("File test failed")
end

---------------------------------------------

-- Test from forum post: http://www.mosync.com/node/7601
function ReadEmptyFileShouldFail()
  local path = mosync.FileSys:GetLocalPath()
  path = path.."testfile.txt"
  local buffer = mosync.SysAlloc(100)
  local file = mosync.maFileOpen(path, mosync.MA_ACCESS_READ_WRITE)
  if file < 0 then
    print("Error opening file")
    print("Empty file test failed")
    return
  end
  if mosync.maFileCreate(file) < 0 then
    print ("Error on mosync.maFileCreate")
    print("Empty file test failed")
    mosync.maFileClose(file)
    return
  end
  if mosync.maFileRead(file, buffer, 100) < 0 then
    print("mosync.maFileRead failed. This is GOOD!")
    print("Empty file test passed")
  else
    print("mosync.maFileRead succeeded on an empty file. This is BAD!")
    print("Empty file test failed")
  end
  mosync.maFileDelete(file)
  mosync.maFileClose(file)
  mosync.SysFree(buffer)
end

ReadEmptyFileShouldFail()
