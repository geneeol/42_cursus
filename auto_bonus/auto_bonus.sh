#!/bin/sh

set -e

find . -name "*.c" | sed s/\\.c$// | xargs -I {} sh -c "python3 ../../auto_bonus/bonus.py < {}.c > {}_bonus.c"
find . -name "*.h" | sed s/\\.h$// | xargs -I {} sh -c "python3 ../../auto_bonus/bonus.py < {}.h > {}_bonus.h"
