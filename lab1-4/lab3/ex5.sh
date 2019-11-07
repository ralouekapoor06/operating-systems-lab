#!usr/bin/sh

read ext
read fold

for y in `find -maxdepth 1 -name "*"$ext""`;do
	`mv "$y" "$fold" `
done