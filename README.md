# ppl-assignment-nitesh237
ppl-assignment-nitesh237 created by GitHub Classroom

CREATED BY-
Nitesh Gupta
IIT2015050
SECTION - 'A'

###STEP 1-

generate boys.txt execute testing_boys.cpp
>```
  g++ testing_boys.cpp
  ./a.out
 ```
generate girls.txt execute testing_girls.cpp
>```
  g++ testing_girls.cpp
  ./a.out
 ```
generate gift_store.txt execute testing_gifts.cpp
>```
  g++ testing_gifts.cpp
  ./a.out
 ```
 
###STEP 2-

create library (lets say ppl_lib) execute-

> ```
  g++ -c couple.cpp 
  g++ -c matching.cpp 
  g++ -c out2.cpp
  ar rvs ppl_lib *.o
  ```

###STEP 3-
To run q1 execute the following command:

> ```
  g++ q1.cpp ppl_lib
  ./a.out
  ```

To run q2 execute the following command:

>```
  g++ q2.cpp ppl_lib
  ./a.out
```


Documenation of the project can be found in -

doc/html/index.html
