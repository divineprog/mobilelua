require "fileutils"

def sh(cmd)
    #TODO: optimize by removing the extra shell
    #the Process class should be useful.
    $stderr.puts cmd
    if(!system(cmd)) then
        error "Command failed: '#{$?}'"
    end
end

def build
    FileUtils.rm_rf(["classes"])
    FileUtils.mkpath(["classes"])
    sh "javac -sourcepath src -d classes -classpath lib:classes:lib/rsyntaxeditarea/rsyntaxtextarea.jar src/mosync/lualiveeditor/*.java"
end

def run
    sh "java -classpath lib:classes:lib/rsyntaxeditarea/rsyntaxtextarea.jar mosync.lualiveeditor.LuaLiveEditor"
end

if ((ARGV.include? "build") or (ARGV.include? "b"))
    build
elsif ((ARGV.include? "all") or (ARGV.include? "a"))
    build
    run
else
    run
end
