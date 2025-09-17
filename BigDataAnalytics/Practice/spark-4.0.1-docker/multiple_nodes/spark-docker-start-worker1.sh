docker container stop apache-spark-r-w1
docker container remove apache-spark-r-w1
docker run -d --user spark \
--env SPARK_HOME=/opt/spark \
-e SPARK_UI_PORT=9140 \
-e SPARK_MASTER_PORT=9177 \
-e SPARK_MASTER_WEBUI_PORT=9180 \
-e SPARK_WORKER_WEBUI_PORT=9181 \
--name apache-spark-r-w1 \
--hostname spark-worker1 \
-p 9140:9140 -p 9180:9180 -p 9177:9177 -p 9181:9181 -p 19180:19180 \
-it apache/spark:r bash

docker exec -it apache-spark-r-w1 /opt/spark/sbin/start-worker.sh spark://172.17.0.2:7077
