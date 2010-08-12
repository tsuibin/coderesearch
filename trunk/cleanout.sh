#find . -name "a.out" |xargs rm -f
#find . -name "a.out" |xargs ls -lh
#find -name a.out -exec ls -lh '{}'
find -name a.out -exec rm -f '{}'
svn add ./* > /dev/null
svn commit
