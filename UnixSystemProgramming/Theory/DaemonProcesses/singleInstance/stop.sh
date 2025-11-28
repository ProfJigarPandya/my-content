echo "Before stopping"
ps -ajx | grep echodaemon.o
echo "Stopping now ..."
pkill echodaemon.o
echo "After stopping.."
ps -ajx | grep echodaemon.o
echo "Locked by PID"
cat /var/run/echodaemon.pid
rm /var/run/echodaemon.pid
