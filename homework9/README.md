
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Homework 9: Shortest path</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time class="due_time" datetime="2014-12-14T23:59:59+08:00" style="font-weight: bold;">2014-12-14 23:59 UTC+8</time></span><a class="assignment_ref" href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework9/starter.zip" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background: rgb(204, 204, 204);">start file and test case</a>
<p style="margin: 8px 0px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);"><strong><font color="#FF0000">这次作业可以不使用standford库，但是要求自己实现一个用邻接表实现的图。</font></strong></p>
<p style="margin: 8px 0px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);"><strong><font color="#FF0000">homework 9延期至本周日</font></strong></p>
<p style="margin: 8px 0px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);"><strong><font color="#FF0000">给的测试图定义文件和样例图有不一致，更新的starter文件修复了这个问题。</font></strong></p>
<p style="margin: 8px 0px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);"><strong><font color="#FF0000">如果make失败的话请更新下starter文件。</font></strong></p>
<p style="margin: 8px 0px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);"><strong><font color="#FF0000">如果点０到某一点没有路径，则输出－１表示无穷大。</font></strong></p>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Requirement</h4>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<p style="margin: 8px 0px;">In this homework, you are required to implement Dijkstra's algorithm to find the shortest path from a given node to every other nodes.</p>
<p style="margin: 8px 0px;">For example in the following figure,you are required to print the length of shortest path from node 0 to every other nodes.</p>
<img src="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework9/image1.png" height="200" witdh="200">
<p style="margin: 8px 0px;">Your program will read a file which defines the directed graph.The filename will be passed via command line. For example:</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">./your_program graph.txt</code></p>
<p style="margin: 8px 0px;">So your program must read the graph&nbsp;<codep>from graph.txt</codep>.</p>
<p style="margin: 8px 0px;">We provide a minumal cpp file and makefile.You are free to change the makefile but you should not change the execute file name in makefile.</p>
<br></div>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Sample Input</h4>
<p style="margin: 8px 0px;">The input format is listed below.For example ,the following defines the example graph.</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">10<br>23<br>0 1 7<br>0 4 4<br>...<br></code>
<p style="margin: 8px 0px;">The first line shows the max node num(inclusively).The minumal node number is 0.So for the example above there are 11 nodes marked 0,1,...,10.</p>
<p style="margin: 8px 0px;">The second line shows that how many edges are in this graph.</p>
<p style="margin: 8px 0px;">Next there will be n lines corresponding to the how many edges in the graph.</p>
<p style="margin: 8px 0px;">Each line contains 3 integers seperated by SPACE,the first and second one means the node number and the third dicates the weight of that edge.</p>
<p style="margin: 8px 0px;">For example,the third line means that there is an edge from node 0 to node 1 with weight 7.</p>
<p style="margin: 8px 0px;"><strong>Note: edge weight will always be positive!</strong></p>
<p style="margin: 8px 0px;"></p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Sample Output</h4>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<p style="margin: 8px 0px;">You need to output the shortest path from node 0 to every other nodes (including itself) in ascending order(according to the node number).</p>
<p style="margin: 8px 0px;">The output fomart is defined follows:</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">0 5 7 ...</code>
<p style="margin: 8px 0px;">The above example means that the node 0 to node 0,1,2...'s shortest path length is 0,5,7... .</p>
<br>
<p style="margin: 8px 0px;"><strong>Note that we will use different test graph to test your implementation.</strong></p>
<strong></strong></div>
<strong style="font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You need to submit all the code and the makefile.</p>
<p style="margin: 8px 0px;">Submit your code as a zip file to</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/homework9/<br>Username: azard5, Password: public<br>Filename: 5130379001_homework9.zip</code></p>
<p style="margin: 8px 0px;">If you have any question or find some bugs, please ask on QA or contact&nbsp;<a href="mailto:wxdwfc@sjtu.edu.cn" style="color: rgb(34, 102, 187); text-decoration: none; outline-style: none;">wxdwfc@sjtu.edu.cn</a></p>
</div>
<time class="assigned_time" datetime="2014-12-2T23:59:59+08:00" style="text-align: right; display: block;">2014-12-2</time></strong>
