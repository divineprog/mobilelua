---------------------------------------------------
-- Welcome to the Wonderful World of Mobile Lua! --
---------------------------------------------------

-- This script tests calling database syscalls.
-- No error handling is done!
-- Note that this example works on Android and iOS,
-- and NOT on Windows Phone.

-- Utility function that gets column data as text.
-- Gets the value from a query, at the current cursor position.
-- You can use this function also to get columns that are not
-- of type text, in this case the value will be converted to
-- a string.
function DBCursorGetColumnText(cursor, column)
  local buffer = mosync.SysAlloc(4096)
  mosync.maDBCursorGetColumnText(cursor, column, buffer, 4096)
  local text = mosync.SysBufferToString(buffer)
  mosync.SysFree(buffer)
  return text
end

-- Utility function that gets column data as int.
-- Gets the value from a query, at the current cursor position.
function DBCursorGetColumnInt(cursor, column)
  -- First param is the cursor that points to the result set.
  -- Second param is which column to get (zero means first one).
  -- Third param is just a dummy, it is not used. Lua returns
  -- the value as multiple values in this case (this is because
  -- the bindings make with tolua works this way).
  local result,value = mosync.maDBCursorGetColumnInt(cursor, column, 0)
  return value
end

-- Get path to local file system and append name of database
path = mosync.FileSys:GetLocalPath()
path = path .. "mydb"
print("Database path: "..path)

-- Open the database
print("Opening database")
db = mosync.maDBOpen(path)

-- Create table and insert rows
print("Creating data")
mosync.maDBExecSQL(db, "DROP TABLE IF EXISTS pet")
mosync.maDBExecSQL(db, "CREATE TABLE pet (name TEXT(50), age INTEGER, curiosity DOUBLE)")
mosync.maDBExecSQL(db, "INSERT INTO pet VALUES ('Charmy', 7, 0.75)")
mosync.maDBExecSQL(db, "INSERT INTO pet VALUES ('Sporty', 4, 0.99)")

-- Count the number of rows
cursor = mosync.maDBExecSQL(db, "SELECT COUNT(*) FROM (SELECT * FROM pet)")
result = mosync.maDBCursorNext(cursor)
if mosync.MA_DB_OK ~= result then
  mosync.maPanic(-1, "maDBCursorNext failed")
end
count = DBCursorGetColumnInt(cursor, 0)
-- Display the result.
print("Number of rows: " .. count)
mosync.maDBCursorDestroy(cursor)

-- Get all rows and display data.
print("Querying database data (all rows)")
cursor = mosync.maDBExecSQL(db, "SELECT * FROM pet")
while mosync.MA_DB_OK == mosync.maDBCursorNext(cursor) do
  local name = DBCursorGetColumnText(cursor, 0)
  local age = DBCursorGetColumnText(cursor, 1)
  local curiosity = DBCursorGetColumnText(cursor, 2)
  print("Got row: "..name.." "..age.." "..curiosity)
end
mosync.maDBCursorDestroy(cursor)

print("Closing database")
mosync.maDBClose(db)
print("Done")
