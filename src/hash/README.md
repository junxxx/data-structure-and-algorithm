#### Hash function
A hash function is any function that can be used to 
map data of arbitrary size to data of a fixed size. 

#### Hash tables
Hash function are used in hash tables, 
to quickyly locate a data record given its search key.

Specifically, the hash function is used to map the search key to a list; 
the index gives the place in the hash table 
where the corresponding record should be stored. 
Hash tables are also used to implement associative arrays and dynamic sets.

#### To resolve Collision

##### Separate Chaining

##### Open Addressing
* Linear Probing
* Quadratic Probing
* Double Hashing


#### Implemetation:

hash(k, m) - m is size of hash table

add(key, value) -if key already exists,update value

exists(key)

get(key)

remove(key)

