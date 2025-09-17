docker container stop apache-spark-r-w2
docker container remove apache-spark-r-w2
docker run -d --user spark \
--env SPARK_HOME=/opt/spark \
-e SPARK_UI_PORT=9240 \
-e SPARK_MASTER_PORT=9277 \
-e SPARK_MASTER_WEBUI_PORT=9280 \
-e SPARK_WORKER_WEBUI_PORT=9281 \
-e SPARK_UI_PORT=9240 \
-e SPARK_HISTORY_UI_PORT=19280 \
--name apache-spark-r-w2 \
--hostname spark-worker2 \
-p 9240:9240 -p 9280:9280 -p 9277:9277 -p 9281:9281 -p 19280:19280 \
-it apache/spark:r bash

docker exec -it apache-spark-r-w2 /opt/spark/sbin/start-worker.sh spark://172.17.0.2:7077
