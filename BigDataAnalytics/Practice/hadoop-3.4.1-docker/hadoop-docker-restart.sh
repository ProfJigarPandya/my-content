export HADOOP_HOME=/opt/hadoop
docker-compose down
docker-compose up -d
echo "Attempt # 1"
docker ps
echo "Attempt # 2"
docker ps
echo "Attempt # 3"
docker ps
echo "Attempt # 4"
docker ps
echo "LOG"
docker-compose logs
