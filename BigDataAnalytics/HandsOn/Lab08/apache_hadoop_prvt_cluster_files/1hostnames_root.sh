export HISTCONTROL=ignorespace
labsubnet=192.168.32
passw=test
for i in {33..51};
do
	sshpass -p $passw ssh -o StrictHostKeyChecking=no root@$labsubnet.$i "hostnamectl set-hostname hadoop-clone-$i"
done;
