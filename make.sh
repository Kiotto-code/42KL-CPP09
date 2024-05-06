# find . -name "ex*" -exec make re -C {} \;

# if [ $# -eq 0 ]
# then
#    find . -name "ex*" -exec make re -C {} \;
# else
#    find . -name $1 -exec make re -C $1 \;
# fi

# if [ $# -eq 0 ];
# then
#    find . -name "Makefile" -exec make -C {} re \;
# elif [ "$1" == "all" ];
# then
#    find . -name "Makefile" -exec make -C {} all \;
# else
#    find . -name $1 -exec make re -C $1 \;
# fi


# if [ $# -eq 0 ]; then
#    find . -name "ex*" -exec make -C {} all \;
# elif [ "$1" == "re" ]; then
#    find . -name "ex*" -exec make -C {} re \;
# else
#    find . -name "$1" -exec make -C {} re \;
# fi


# if [ $# -eq 0 ]
# then
#    for dir in $(find . -name "Makefile")
#    do
#     make re -C "$(dirname "$dir")"
#    done 
# else
#    find . -name $1 -exec make re -C $1 \;
# fi

# if [ $# -eq 0 ]; then
#    find . -name "Makefile" -exec dirname {} \; | xargs -I {} make -C {} re
# else
#    find . -name "$1" -exec make -C {} re \;
# fi

if [ $# -eq 0 ]; then
   find . -type f -name "Makefile" -execdir make re {} \;
else
   find . -type d -name $1 -exec make -C {} \;
fi



# if [ $# -eq 0 ]; then
# 	find . -name "Makefile" -execdir make {} re \;
# else
# 	find . -type d -name $1 -exec make -C {} \;
# fi
