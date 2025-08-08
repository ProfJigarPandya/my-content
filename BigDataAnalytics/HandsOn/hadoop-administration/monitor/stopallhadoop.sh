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
	if test $ipn -eq 31 -o $ipn -eq 52 -o $ipn -eq 53 -o $ipn -eq 54
	then
		continue
	fi
	echo "Processing on $subnet.$ipn"
	sshpass -e ssh -o StrictHostKeyChecking=no $username@$subnet.$ipn "/opt/hadoop/sbin/stop-dfs.sh"
	echo
done

echo "Complete"
