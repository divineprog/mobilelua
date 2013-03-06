require "FileUtils"

def sh(cmd)
	#TODO: optimize by removing the extra shell
	#the Process class should be useful.
	$stderr.puts cmd
	if(!system(cmd)) then
		error "Command failed: '#{$?}'"
	end
end

FileUtils.rm_rf(["classes"])
FileUtils.mkpath(["classes"])
sh "javac -sourcepath src -d classes -classpath lib:classes:lib/rsyntaxeditarea/rsyntaxtextarea.jar src/mosync/mobilelualiveditor/*.java src/mosync/mobilelualiveditor/ui/*.java"

sh "java -classpath lib:classes:lib/rsyntaxeditarea/rsyntaxtextarea.jar mosync.mobilelualiveditor.MobileLuaLiveEditor"