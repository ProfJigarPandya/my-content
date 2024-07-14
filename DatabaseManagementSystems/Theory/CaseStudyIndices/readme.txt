Here, first we load csv having 10000 rows into table.

Then we check performance execution cost of a given query which comes out to be 137 because of full table scan.

Vs

once we create index on required column and optimizer picks up the index. The cost is 7 with rowid and range scan using index.


