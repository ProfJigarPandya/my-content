labsubnet=192.168.32
echo -n "" > slaves
for i in {33..51};
do
	echo hadoop-clone-$i >> slaves
done;
mv slaves conf/slaves
