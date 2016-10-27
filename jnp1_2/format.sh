for f in `find -name '*.c' -or -name '*.h' -or -name '*.cc'`
do
	echo 'formatting ' $f
	clang-format $f > $f.formatted
	mv $f.formatted $f
done
