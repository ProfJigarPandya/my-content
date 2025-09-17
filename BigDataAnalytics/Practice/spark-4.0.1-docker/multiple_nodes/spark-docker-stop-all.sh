docker exec -it apache-spark-r-w1 /opt/spark/sbin/stop-worker.sh
docker container stop apache-spark-r-w1
docker container remove apache-spark-r-w1
docker exec -it apache-spark-r-w2 /opt/spark/sbin/stop-worker.sh
docker container stop apache-spark-r-w2
docker container remove apache-spark-r-w2
docker exec -it apache-spark-r-w3 /opt/spark/sbin/stop-worker.sh
docker container stop apache-spark-r-w3
docker container remove apache-spark-r-w3
docker exec -it apache-spark-r-w4 /opt/spark/sbin/stop-worker.sh
docker container stop apache-spark-r-w4
docker container remove apache-spark-r-w4
docker exec -it apache-spark-r-master1 /opt/spark/sbin/stop-worker.sh
docker container stop apache-spark-r-master1
docker container remove apache-spark-r-master1
