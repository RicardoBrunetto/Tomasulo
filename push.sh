#!/bin/sh
git add -u
git status
git commit -m \'$1\'
git push upstream
