export HISTCONTROL=ignorespace
labsubnet=192.168.32
passw=test
for i in {33..47};
do
	sshpass -p $passw ssh -o StrictHostKeyChecking=no root@$labsubnet.$i "systemctl stop firewalld"
done;

