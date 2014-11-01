Enumeration algorithm and pruning optimization
==


Enumeration algorithm:
--

 - let p = first block -> last block
	- enumerate 3 to 1
		 - check now state's correctness

 pruning optmization:
--
  - if (The current carrying capacity)+(Undetermined number of houses)*(Capacity of the average expectation)<(Max capacity has been calculated) , thenPruning.
  -  Here (Capacity of the average expectation)=2.3 , while I think the value calculated by a mathematical method should be 2.4.

> using
> 33
> 321
> to fill middle part

---

 U can using my city_7_ctdp_nopath.cpp to get a way building 7*100 city which average capacity is larger than 2.3

Record method
--
All of the following zero one number are binary.
using 100 to represent 3
using 010 to represent 2
using 001 to represent 1

using 01 to represent need 1
using 10 to represent need 2

Example:
11 100 means : value=3 need 1 and 2
11 010 means : value=2 need 1 and 2 [This situation does not exist in reality]

> Written with [StackEdit](https://stackedit.io/).
