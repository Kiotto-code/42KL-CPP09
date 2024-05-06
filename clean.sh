 #!/usr/bin/bash

# find . -name ".DS_Store" -exec rm {} \;
# find . -name "a.out" -exec rm {} \;
# find . -name "*.dSYM" -exec rm {} \;
# find . -name "*.gch" -exec rm {} \;
# find . -name "*.obj" -exec rm {} \;
# find . -name "*.o" -exec rm {} \;
# find . -name "*.d" -exec rm {} \;

find . \( -name ".DS_Store" -o -name "tempCodeRunnerFile" -o -name "a.out" -o -name "*.dSYM" -o -name "*.gch" -o -name "*.obj" -o -name "*.o" -o -name "*.d" -o -name "*tempCodeRunnerFile" \) -exec rm {} \;
