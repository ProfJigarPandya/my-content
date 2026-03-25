'''
Created on 25-March-2026

@author: jigarpandya
pip install scikit-learn

'''
from sklearn.cluster import kmeans_plusplus
from sklearn.cluster import k_means
import numpy as np
#X = np.array([[1, 2], [1, 4], [1, 0],[10, 2], [10, 4], [10, 0]])
A1=[2,10]
A2=[2,5]
A3=[8,4]
B1=[5,8]
B2=[7,5]
B3=[6,4]
C1=[1,2]
C2=[4,9]
X = np.array([A1, A2, A3, B1, B2, B3, C1, C2])

print()
print("Attempt # A  KM lloyd default")
for k in range(1,len(X)+1):
	centroid, label, inertia = k_means(X, n_clusters=k)
	print("K VALUE : ",k)
	print("centroid",centroid)
	print("label",label)
	print("inertia",inertia)

print()
print()

centroid, label, inertia = k_means(X, n_clusters=3,init=np.array([A1,B1,C1]),max_iter=1)
print("centroid",centroid)
print("label",label)
print("inertia",inertia)
