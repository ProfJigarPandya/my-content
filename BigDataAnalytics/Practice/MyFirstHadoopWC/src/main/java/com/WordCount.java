package com;


import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class WordCount {
	
	
	
	public static class TokenizerMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
		private final static IntWritable one = new IntWritable(1);
		private Text word = new Text();
		
		public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
			StringTokenizer tokenizer = new StringTokenizer(value.toString());
			while (tokenizer.hasMoreTokens()) {
				word.set(tokenizer.nextToken());
				context.write(word, one);
			}
		}
		
	
	}

	public static class IntSumReducer extends Reducer<Text, IntWritable, Text, IntWritable> {
		private IntWritable result = new IntWritable();
		
		
		public void reduce(Text key, Iterable<IntWritable> values, Context context)
				throws IOException, InterruptedException {
			int sum = 0;
			for (IntWritable val : values) {
				sum += val.get();
			}
			result.set(sum);
			context.write(key, result);
		}
		
			}

	public static void main(String[] args) throws Exception {
		
		
		//Input Data verification: hdfs dfs -ls /projects/wordcount/input
		//Clean up command:    hdfs dfs -rm -r  /projects/wordcount/output
        //Output Result Verification: hdfs dfs -ls /projects/wordcount/output
		//hdfs dfs -cat /projects/wordcount/output/*
		//hdfs dfs -get /projects/wordcount/output .
		
		
		Configuration conf = new Configuration();
		conf.addResource(new Path("/opt/hadoop/etc/hadoop/core-site.xml"));
		conf.addResource(new Path("/opt/hadoop/etc/hadoop/hdfs-site.xml"));
		conf.addResource(new Path("/opt/hadoop/etc/hadoop/mapred-site.xml"));
		conf.addResource(new Path("/opt/hadoop/etc/hadoop/yarn-site.xml"));

		//conf.set("mapreduce.job.jar", "/Users/JigarPandya/eclipse-workspacejun2020/MyFirstHadoopWC/target/MyFirstMavennArtifactID-0.0.1-SNAPSHOT.jar");

		
		//https://hadoop.apache.org/docs/stable/hadoop-mapreduce-client/hadoop-mapreduce-client-core/mapred-default.xml
		//mapreduce.output.fileoutputformat.compress	false	Should the job outputs be compressed?
		//mapreduce.output.fileoutputformat.compress.codec	org.apache.hadoop.io.compress.DefaultCodec	If the job outputs are compressed, how should they be compressed?

        conf.setBoolean("mapreduce.output.fileoutputformat.compress",true);
		conf.setClass("mapreduce.output.fileoutputformat.compress.codec",org.apache.hadoop.io.compress.GzipCodec.class, org.apache.hadoop.io.compress.CompressionCodec.class);


		
		Job job = Job.getInstance(conf, "word count");
		job.setJarByClass(WordCount.class);
		job.setMapperClass(TokenizerMapper.class);
		job.setCombinerClass(IntSumReducer.class);
		job.setReducerClass(IntSumReducer.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);
		System.out.println("Input path: "+args[0]);
		FileInputFormat.addInputPath(job, new Path(args[0]));
		System.out.println("Output Path: "+args[1]);

		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		int status = job.waitForCompletion(true) ? 0 : 1;
		
		System.out.print("Job completed");
		System.out.print("Status "+status);
		System.exit(status);
	}
}
