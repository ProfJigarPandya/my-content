labsubnet=192.168.32
cat hosts.bak > hosts
for i in {33..51};
do
	echo $labsubnet.$i hadoop-clone-$i >> hosts
done;
