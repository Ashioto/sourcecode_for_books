[laputa@localhost chap2_sed详解及用法]$ python script.py 
sed "s/bbb/eee/" input.txt
aaaeeecccddd aaabbbcccddd
AAABBBCCCDDD aaaeeecccddd
1234567890!? !"#$%&'()?/_

sed -e "s/bbb/eee/" input.txt
aaaeeecccddd aaabbbcccddd
AAABBBCCCDDD aaaeeecccddd
1234567890!? !"#$%&'()?/_

sed -e "s/bbb/eee/g" input.txt
aaaeeecccddd aaaeeecccddd
AAABBBCCCDDD aaaeeecccddd
1234567890!? !"#$%&'()?/_

sed -e "2s/bbb/eee/g" input.txt
aaabbbcccddd aaabbbcccddd
AAABBBCCCDDD aaaeeecccddd
1234567890!? !"#$%&'()?/_

sed -e "s/aaa//g" input.txt
bbbcccddd bbbcccddd
AAABBBCCCDDD bbbcccddd
1234567890!? !"#$%&'()?/_

sed -e "s/\//R/" input.txt
aaabbbcccddd aaabbbcccddd
AAABBBCCCDDD aaabbbcccddd
1234567890!? !"#$%&'()?R_

sed -e "s/aaa/+&+/g" input.txt
+aaa+bbbcccddd +aaa+bbbcccddd
AAABBBCCCDDD +aaa+bbbcccddd
1234567890!? !"#$%&'()?/_

sed -e "s/.*/output: &/g" input.txt
output: aaabbbcccddd aaabbbcccddd
output: AAABBBCCCDDD aaabbbcccddd
output: 1234567890!? !"#$%&'()?/_

sed -e 's/bbb/eee/p' input.txt
aaaeeecccddd aaabbbcccddd
aaaeeecccddd aaabbbcccddd
AAABBBCCCDDD aaaeeecccddd
AAABBBCCCDDD aaaeeecccddd
1234567890!? !"#$%&'()?/_

sed -e -n 's/bbb/eee/p' input.txt
sed: -e expression #1, char 1: unknown command: `-'

sed -n -e 's/bbb/eee/p' input.txt
aaaeeecccddd aaabbbcccddd
AAABBBCCCDDD aaaeeecccddd

sed -e 'y/abcde/ABCDE/' input.txt
AAABBBCCCDDD AAABBBCCCDDD
AAABBBCCCDDD AAABBBCCCDDD
1234567890!? !"#$%&'()?/_

sed -e '1,2d' input.txt
1234567890!? !"#$%&'()?/_

sed -e 'd' input.txt

sed -n -e '1,3p' input.txt 
aaabbbcccddd aaabbbcccddd
AAABBBCCCDDD aaabbbcccddd
1234567890!? !"#$%&'()?/_

sed -n -e '2,$p' input.txt
AAABBBCCCDDD aaabbbcccddd
1234567890!? !"#$%&'()?/_

sed -n -e '/^aaa/,/ddd$/p' input.txt
aaabbbcccddd aaabbbcccddd
AAABBBCCCDDD aaabbbcccddd

sed -e '2d;s/aaa/eee/g' input.txt 
eeebbbcccddd eeebbbcccddd
1234567890!? !"#$%&'()?/_

sed '1,2d' input.txt 
1234567890!? !"#$%&'()?/_



[laputa@localhost chap2_sed详解及用法]$ sed -e '
> :loop
> N
> $!b loop
> s/\n//g
> ' input.txt
aaabbbcccddd aaabbbcccdddAAABBBCCCDDD aaabbbcccddd1234567890!? !"#$%&'()?/_

