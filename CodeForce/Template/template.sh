#!/bin/sh

# filename
filename=$1
number=$2
# file extension
extension="${filename##*.}"

if [ "$extension" == "cpp" ]; then
   cp -n ~/Documents/Programming/Practice/C++/CP/codeforce/Template/template.cpp $PWD/$filename;
else
  echo "Template not found"
  exit
fi

