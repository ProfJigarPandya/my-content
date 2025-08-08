labsubnet=192.168.32
passw=test
for i in {11..51};
do
	sshpass -p $passw ssh -o StrictHostKeyChecking=no root@$labsubnet.$i "touch /usr/lib/python3.6/site-packages/imongo/imongo_kernel.log"
	sshpass -p $passw ssh -o StrictHostKeyChecking=no root@$labsubnet.$i "chown hadoop:hadoop /usr/lib/python3.6/site-packages/imongo/imongo_kernel.log"
	

done;

