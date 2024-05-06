# find . -name "a.out" -o -name "objs" -exec rm -rf {} \;
# cd -name "*ex" && make fclean
# find . -name "ex*" -exec $(MAKE) fclean {} \;

# if [ $# -eq 0 ]; then
# 	find . -name "Makefile" -execdir make fclean -C {} \;
# elif
# 	find . -name "Makefile" -execdir make fclean \;


# if [ $# -eq 0 ]; then
#     find . -type f -name "Makefile" -execdir make fclean \;
# else
#     find . -type d -name $1 -exec make -C {} fclean \;
# fi

if [ $# -eq 0 ]; then
	find . -type f -name "Makefile" -execdir make fclean \;
else
	find . -name "$1" -exec make fclean -C {} \;
fi

# if [ $# -eq 0 ]; then
#     find . -type f -name "Makefile" -exec dirname {} \; | xargs -I {} make -C {} fclean
# else
#     find "$1" -type f -name "Makefile" -exec dirname {} \; | xargs -I {} make -C {} fclean
# fi
