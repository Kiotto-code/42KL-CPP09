# find . -name "ex*" -exec make re -C {} \;

if [ $# -eq 0 ]
then
   find . -name "ex*" -exec make re -C {} \;
else
   find . -name "$1" -exec make re -C $1 \;
fi
