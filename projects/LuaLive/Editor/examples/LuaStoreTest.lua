mosync.FileSys:WriteStoreText("foo", "hello")
text = mosync.FileSys:ReadStoreText("foo")
if nil == text then
  print("nil (fail)")
else
  print("text x: "..text)
  print("len: "..text:len())
end
