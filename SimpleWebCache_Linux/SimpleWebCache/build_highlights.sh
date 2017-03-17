ls -l ./*.cpp ./sources/*.cpp ./headers/*.h  | awk '{print "highlight -O rtf -d highlight " $9}' > highlight.sh
