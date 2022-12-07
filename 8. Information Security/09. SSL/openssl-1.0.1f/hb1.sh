#!/bin/bash

cd demos/ssl
echo directory changed to demos/ssl
pwd
echo ./hb -s 165.246.38.151 -p 12500 -f out -t 1
./hb -s 165.246.38.151 -p 12500 -f out -t 1

exit 0
