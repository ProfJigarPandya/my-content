'''
Created on 25-March-2026

@author: jigarpandya
pip install scikit-learn

'''
from sklearn.cluster import kmeans_plusplus
from sklearn.cluster import k_means
import numpy as np
#X = np.array([[1, 2], [1, 4], [1, 0],[10, 2], [10, 4], [10, 0]])

print()
print("Attempt # A  KM lloyd default")
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
for k in range(1,len(X)+1):
	centroid, label, inertia = k_means(X, n_clusters=k)
	print("K VALUE : ",k)
	print("centroid",centroid)
	print("label",label)
	print("inertia",inertia)
