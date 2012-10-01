# Script to generate bindings with tolua.
# First concatenates header files, then generates bindings.

require "FileUtils"

def sh(cmd)
  #TODO: optimize by removing the extra shell
  #the Process class should be useful.
  $stderr.puts cmd
  if (!system(cmd)) then
    error "Command failed: '#{$?}'"
  end
end

# Use void* for all pointer types (except const char*)
# We do not want the user defined Lua types, because
# they cause problems).
def convertPointerTypesToVoid(data)
  data.
    gsub("MAEvent*", "void*").
    gsub("MAPoint2d*", "void*").
    gsub("MARect*", "void*").
    gsub("MACopyData*", "void*").
    gsub("MAConnAddr*", "void*")
end

# Out buffer os type char* must not be converted to
# Lua string type. Use void* for char*.
# const char* will be Lua string type. Perhaps
# we should change this in the future?
def convertCharPointerTypeToVoid(data)
  data.
    gsub("(char*", "(void*").
    gsub(", char*", ", void*")
end

docFiles = 
  [
  "lua_maapi.h",
  "lua_special_bindings.h",
  "lua_systemapi.h",
  "lua_internal_functions.h"
  ]
  
# Generate .txt file for use with ZeroBrane Studio
# documentation generation tool.
File.open("lua_maapi.txt", "w") do |outFile|
  data = docFiles.map { |fileName| 
    IO.read(fileName)
  }
  outFile.puts "module mosync"
  outFile.puts "{"
  outFile.puts data
  outFile.puts "}"
end

pkgFiles = 
  [
  "lua_maapi.h",
  "lua_special_bindings.h", 
  "lua_systemapi.h"
  ]

# Generate .pkg file for use with tolua.
File.open("lua_maapi.pkg", "w") do |outFile|
  data = pkgFiles.map { |fileName| 
    convertCharPointerTypeToVoid(
      convertPointerTypesToVoid(
        IO.read(fileName)))
  }
  outFile.puts "module mosync"
  outFile.puts "{"
  outFile.puts data
  outFile.puts "}"
end

# Run tolua.
sh "../../../tolua/bin/tolua.exe -o lua_maapi.c lua_maapi.pkg"
