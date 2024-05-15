

#!/bin/bash

# Default value for tmp
tmp=3000

# Check if a command-line argument is provided
if [ $# -ne 0 ]; then
    tmp=$1
fi

# Compile the program using make
make

# Run the program with the generated numbers
./Pmergeme $(jot -r $tmp 1 1000 | tr '\n' ' ')
