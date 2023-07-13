hadoop fs -rm -r apriori/retail/output
hadoop jar ap_mr.jar Apriori_MapReduce apriori/retail/input apriori/retail/output
