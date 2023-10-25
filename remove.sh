# find . -name "a.out" -o -name "objs" -exec rm -rf {} \;
# cd -name "*ex" && make fclean
# find . -name "ex*" -exec $(MAKE) fclean {} \;
find . -name "ex*" -exec make -C  {} fclean \;
