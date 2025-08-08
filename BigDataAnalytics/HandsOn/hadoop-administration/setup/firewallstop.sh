echo "Usage: mycmdname subnet iprangestart iprangeend username"
if [[ -z $1 ]]
then
	echo "Enter subnet"
	read subnet
	echo "Enter iprangestart (only computer node identifier)"
	read iprangestart
	echo "Enter iprangeend (only computer node identifier)" 
	read iprangeend
	echo "Enter username"
	read username
else
	subnet=$1
	iprangestart=$2
	iprangeend=$3
	username=$4
fi

echo "Enter password"
read -s password
echo "Result"
 export SSHPASS="$password"

for ipn in $(eval echo "{$iprangestart..$iprangeend}");
do
	echo "Processing on $subnet.$ipn"
	sshpass -e ssh -o StrictHostKeyChecking=no $username@$subnet.$ipn "systemctl status firewalld"
	echo
done

echo "Complete"
