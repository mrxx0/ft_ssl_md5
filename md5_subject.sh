#!/bin/bash

echo "42 is nice" | ./ft_ssl md5
echo -e "(stdin)= 35f1d6de0302e2086a4e472266efb3a9\n"

echo "42 is nice" | ./ft_ssl md5 -p
echo -e "(\"42 is nice\")= 35f1d6de0302e2086a4e472266efb3a9\n"

echo "Pity the living." | ./ft_ssl md5 -q -r
echo -e "e20c3b973f63482a778f3fd1869b7f25\n"

echo "And above all," > file
./ft_ssl md5 file
echo -e "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n"

./ft_ssl md5 -r file
echo -e "53d53ea94217b259c11a5a2d104ec58a file\n"

./ft_ssl md5 -s "pity those that aren't following baerista on spotify."
echo -e "MD5 (\"pity those that aren't following baerista on spotify.\") = a3c990a1964705d9bf0e602f44572f5f\n"

echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file
echo "(\"be sure to handle edge cases carefully\")= 3553dc7dc5963b583c056d1b9fa3349c"
echo -e "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n"

echo "some of this will not make sense at first" | ./ft_ssl md5 file
echo -e "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n"

echo "but eventually you will understand" | ./ft_ssl md5 -p -r file
echo -e "(\"but eventually you will understand\")= dcdd84e0f635694d2a943fa8d3905281"
echo -e "53d53ea94217b259c11a5a2d104ec58a file\n"

echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file
echo "(\"GL HF let's go\")= d1e3cc342b6da09480b27ec57ff243e2"
echo "MD5 (\"foo\") = acbd18db4cc2f85cedef654fccc4a4d8"
echo -e "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n"

echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar"
echo "(\"one more thing\")= a0bd1876c6f011dd50fae52827f445f5"
echo "acbd18db4cc2f85cedef654fccc4a4d8 \"foo\""
echo "53d53ea94217b259c11a5a2d104ec58a file"
echo "ft_ssl: md5: -s: No such file or directory"
echo -e "ft_ssl: md5: bar: No such file or directory\n"

echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file
echo "just to be extra clear"
echo "3ba35f1ea0d170cb3b9a752e3360286c"
echo "acbd18db4cc2f85cedef654fccc4a4d8"
echo "53d53ea94217b259c11a5a2d104ec58a"
