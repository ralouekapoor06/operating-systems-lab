#!usr/bin/sh

for y in `find -name "*.txt"`;do
	t="${y/.txt/.text}"
	`mv "$y" "$t"` 
done
