labsubnet=192.168.32
samplesshd=/home/hadoop/cluster/passphraseless
echo -n "" > known_hosts

for i in {33..47};
do
 echo "$labsubnet.$i ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBIZvYIS32cOo7ibuatBHDs6pTfZTPsUUoBjilSkMhLja+3PzcdUmn9mULcmVvIIvd/bpnrpODjc8LRBD6tt8L2c=" >> known_hosts
 echo "hadoop-clone-$i ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBIZvYIS32cOo7ibuatBHDs6pTfZTPsUUoBjilSkMhLja+3PzcdUmn9mULcmVvIIvd/bpnrpODjc8LRBD6tt8L2c=" >> known_hosts
done
cp /home/hadoop/.ssh/* $samplesshd
mv known_hosts $samplesshd
cp $samplesshd/known_hosts ~/.ssh/

for i in {33..47};
do
	rsync -rv $samplesshd/ $labsubnet.$i:/home/hadoop/.ssh
done;
