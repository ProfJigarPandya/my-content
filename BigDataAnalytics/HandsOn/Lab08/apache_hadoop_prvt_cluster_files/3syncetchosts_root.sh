export HISTCONTROL=ignorespace
labsubnet=192.168.32
passw=test
for i in {33..51};
do
	sshpass -p $passw rsync hosts root@$labsubnet.$i:/etc/
done;

