labsubnet=192.168.32
sampleconfd=/home/hadoop/cluster/conf
for i in {33..47};
do
	rsync -rv $sampleconfd/ $labsubnet.$i:/opt/hadoop/etc/hadoop/
done;

