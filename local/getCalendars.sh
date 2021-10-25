#!/bin/sh

awk '/\)/ { gsub(")", "") }; /else if \(txt ==/ {print $6}' inst/include/RcppQuantuccia_types.h
