hadoop dfs -rm -r /user/hadoop/projects/WordCount
hadoop dfs -mkdir -p /user/hadoop/projects/WordCount/input
echo "Hello World of Hadoop" > file01.txt
echo "Hello Again. Learning MapReduce programming with Hadoop. Hadoop enables horizontal scalling." > file02.txt
hadoop dfs -put file*.txt /user/hadoop/projects/WordCount/input
hadoop dfs -cat /user/hadoop/projects/WordCount/input/file*.txt


