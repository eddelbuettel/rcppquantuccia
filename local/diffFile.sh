#!/bin/bash

set -u

if [ $# -lt 1 ]; then
    echo "Usage: $0 file [cpp]"
    exit 1
fi

match=$(echo "$1" | grep cpp -)
if [ "x${match}" == "x" ]; then
    hppfile=$1
    cppfile=$1
else
    hppfile=$(echo $1 | sed -e 's/cpp$/hpp/')
    cppfile=$1
fi
echo "hpp: ${hppfile}"
echo "cpp: ${cppfile}"

qlcalfile="${HOME}/git/rcppqlcal/inst/include/ql/${hppfile}"
if [ ! -f ${qlcalfile} ]; then
    echo "Error: No file '${qlcalfile}' found"
    exit 1
fi

qlfile="${HOME}/git/quantlib/ql/${cppfile}"

if [ ! -f ${qlfile} ]; then
    echo "Error: No file '${qlfile}' found"
    exit 1
fi

colordiff -wu ${qlcalfile} ${qlfile} | batcat
