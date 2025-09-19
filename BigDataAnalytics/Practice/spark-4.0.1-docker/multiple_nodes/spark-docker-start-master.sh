docker container stop apache-spark-r-master1
docker container remove apache-spark-r-master1
docker run -d --user spark \
--env SPARK_HOME=/opt/spark \
-e SPARK_MASTER_PORT=7077 \
-e SPARK_MASTER_WEBUI_PORT=8080 \
--name apache-spark-r-master1 \
--hostname spark-master1 \
-p 4040:4040 -p 8080:8080 -p 8077:8077 -p 8081:8081 -p 18080:18080 \
-it apache/spark:r bash

docker exec -it apache-spark-r-master1 /opt/spark/sbin/start-master.sh
