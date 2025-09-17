docker container stop apache-spark-r-w4
docker container remove apache-spark-r-w4
docker run -d --user spark \
--env SPARK_HOME=/opt/spark \
-e SPARK_UI_PORT=9440 \
-e SPARK_MASTER_PORT=9477 \
-e SPARK_MASTER_WEBUI_PORT=9480 \
-e SPARK_WORKER_WEBUI_PORT=9481 \
-e SPARK_UI_PORT=9440 \
-e SPARK_HISTORY_UI_PORT=19480 \
--name apache-spark-r-w4 \
--hostname spark-worker4 \
-p 9440:9440 -p 9480:9480 -p 9477:9477 -p 9481:9481 -p 19480:19480 \
-it apache/spark:r bash

docker exec -it apache-spark-r-w4 /opt/spark/sbin/start-worker.sh spark://172.17.0.2:7077

