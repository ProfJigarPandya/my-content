for i in {1..10}; do  touch "file"$i; echo "data is $i">"file$i"; done;

for i in {1..10}; do echo -n "file"$i" "; done;

./a.out file1 file2 file3 file4 file5 file6 file7 file8 file9 file10 file11
