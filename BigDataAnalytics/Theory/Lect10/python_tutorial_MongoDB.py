
# coding: utf-8

# In[37]:


from pymongo import MongoClient
from pprint import pprint



connection = MongoClient("mongodb://localhost:27017/admin")

db = connection.test

db.inventory.insert_one(
    {"_id":1,
     "item": "canvas",
     "qty": 100,
     "tags": ["cotton"],
     "size": {"h": 28, "w": 35.5, "uom": "cm"}})

db.inventory.insert_one(
    {"_id":2,
     "item": "painting",
     "qty": 50,
     "tags": ["nature"],
     "size": {"h": 100, "w": 55, "uom": "cm"}})

cursor = db.inventory.find({})


for inventory in cursor:
    pprint(inventory)


# In[38]:


# Subdocument key order matters in a few of these examples so we have
# to use bson.son.SON instead of a Python dict.
from bson.son import SON
db.inventory.insert_many([
    {"_id":3,
     "item": "journal",
     "qty": 25,
     "size": SON([("h", 14), ("w", 21), ("uom", "cm")]),
     "status": "A"},
    {"_id":4,
     "item": "notebook",
     "qty": 50,
     "size": SON([("h", 8.5), ("w", 11), ("uom", "in")]),
     "status": "A"},
    {"_id":5,
     "item": "paper",
     "qty": 100,
     "size": SON([("h", 8.5), ("w", 11), ("uom", "in")]),
     "status": "D"},
    {"_id":6,
     "item": "planner",
     "qty": 75,
     "size": SON([("h", 22.85), ("w", 30), ("uom", "cm")]),
     "status": "D"},
    {"_id":7,
     "item": "postcard",
     "qty": 45,
     "size": SON([("h", 10), ("w", 15.25), ("uom", "cm")]),
     "status": "A"}])


# In[44]:


cursor = db.inventory.find({"status": "D"})


# In[46]:


cursor = db.inventory.find(
    {"size": SON([("h", 14), ("w", 21), ("uom", "cm")])})


# In[48]:


cursor = db.inventory.find({"size.uom": "in"})


# In[49]:


from pprint import pprint

for inventory in cursor:
     pprint(inventory)

