docker container stop apache-spark-r-w3
docker container remove apache-spark-r-w3
docker run -d --user spark \
--env SPARK_HOME=/opt/spark \
-e SPARK_UI_PORT=9340 \
-e SPARK_MASTER_PORT=9377 \
-e SPARK_MASTER_WEBUI_PORT=9380 \
-e SPARK_WORKER_WEBUI_PORT=9381 \
-e SPARK_UI_PORT=9340 \
-e SPARK_HISTORY_UI_PORT=19380 \
--name apache-spark-r-w3 \
--hostname spark-worker3 \
-p 9340:9340 -p 9380:9380 -p 9377:9377 -p 9381:9381 -p 19380:19380 \
-it apache/spark:r bash

docker exec -it apache-spark-r-w3 /opt/spark/sbin/start-worker.sh spark://172.17.0.2:7077
