#!/bin/sh
git add -u
git commit -a -m \'$1\'
git push upstream
